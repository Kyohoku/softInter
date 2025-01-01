#include "sqliteOp.h"

QMutex SqliteOp::m_mutex;
SqliteOp* SqliteOp::userDB=nullptr;

//连接数据库
SqliteOp *SqliteOp::getDataBase()
{
    if(nullptr == userDB)
    {
        QMutexLocker locker(&m_mutex);    // 加互斥锁
        if(nullptr == userDB)
        {
            userDB=new SqliteOp;
        }
    }
    return userDB;
}

bool SqliteOp::queryWords(const QString& key, QStringList& words)
{
    QString strsql = "SELECT english,chinese FROM cet WHERE english LIKE '%1%';";
    strsql = strsql.arg(key);

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryWords  : " << query.lastError().text();
    }

    int k = 0;
    while(query.next())
    {
         QString str0 = query.value(0).toString();
         QString str1 = query.value(1).toString();

         QString word;
         word.append(str0);
         word.append(" ");
         word.append(str1);
         words.append(word);

         k++;
         if(k>=20)
         {//默认只显示前20个
             break;
         }
     }

    return ok;

}

bool SqliteOp::queryWord(const QString& word, QString& wordMeaning, QString& wordSent)
{
    QString strsql = "SELECT chinese,sent FROM cet WHERE english = '%1';";
    strsql = strsql.arg(word);

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryWords  : " << query.lastError().text();
    }

    int k = 0;
    while(query.next())
    {
         wordMeaning = query.value(0).toString();
         wordSent = query.value(1).toString();
         k++;
         if(k>1)
         {//主键查询只会有一条
            qDebug() << "queryWord error" ;
            ok = false;
            break;
         }
    }

    if(0 == k)
    {//定向查找必须返回一条
       ok = false;
    }

    return ok;
}

bool SqliteOp::queryStudyWords(const QString &username,const QString& level,const int32_t& limitNum,std::vector<WordInfo>& words)
{
    QString strsql = "SELECT id,english,chinese,sent FROM cet WHERE LEVEL = '%1' AND id NOT IN(SELECT wordId FROM recite WHERE username = '%2' AND wordLevel = '%3') ORDER BY RANDOM() LIMIT %4;";
    strsql = strsql.arg(level).arg(username).arg(level).arg(limitNum);
    qDebug() << strsql;

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryWords  : " << query.lastError().text();
    }

    int k = 0;
    while(query.next())
    {
         WordInfo info;
         info.id = query.value(0).toInt();
         info.english = query.value(1).toString();
         info.chinese = query.value(2).toString();
         info.sent = query.value(3).toString();

         words.push_back(info);

         k++;
         if(k>limitNum)
         {
             break;
         }
    }

    //如果原表数据不够了，去背诵表里面按熟练度查
    if(k < limitNum)
    {   //联合查询
        int32_t newLimitNum = limitNum - k;
        QString strsql = "SELECT r.wordId,c.id,c.english,c.chinese,c.sent FROM recite AS r INNER JOIN cet AS c ON r.wordId = c.id WHERE r.username = '%1' AND r.wordLevel = '%2' ORDER BY r.proficiency LIMIT %3;";
        strsql = strsql.arg(username).arg(level).arg(newLimitNum);
        qDebug() << strsql;

        QSqlQuery query;
        bool ok = query.exec(strsql);
        if(!ok){
            qDebug() << "Fail queryWords recite : " << query.lastError().text();
        }

        //继续补充剩余的
        while(query.next())
        {
             WordInfo info;
             info.id = query.value(1).toInt();
             info.english = query.value(2).toString();
             info.chinese = query.value(3).toString();
             info.sent = query.value(4).toString();

             words.push_back(info);

             k++;
             if(k>limitNum)
             {
                 break;
             }
        }

    }

    return ok;
}

bool SqliteOp::queryStudyWordById(const int32_t& id, WordInfo& word)
{
    QString strsql = "SELECT id,english,chinese,sent FROM cet WHERE id = '%1';";
    strsql = strsql.arg(id);

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryStudyWordById  : " << query.lastError().text();
    }

    int k = 0;
    while(query.next())
    {
        word.id = query.value(0).toInt();
        word.english = query.value(1).toString();
        word.chinese = query.value(2).toString();
        word.sent = query.value(3).toString();
        k++;
        if(k>1)
        {//主键查询只会有一条
           qDebug() << "queryWord error" ;
           ok = false;
           break;
        }
    }

    if(0 == k)
    {//定向查找必须返回一条
       ok = false;
    }

    return ok;
}

bool SqliteOp::queryWordCount(const QString& level, int32_t& count)
{
    QString strsql = "SELECT count(1) FROM cet WHERE level = '%1';";
    strsql = strsql.arg(level);

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryWordCount  : " << query.lastError().text();
    }

    int k = 0;
    while(query.next())
    {
        count = query.value(0).toInt();
        k++;
        if(k>1)
        {//主键查询只会有一条
           qDebug() << "queryWordCount error" ;
           ok = false;
           break;
        }
    }

    if(0 == k)
    {//定向查找必须返回一条
       ok = false;
    }

    return ok;
}

bool SqliteOp::queryAbstructWords(const QString& level,const QString& correctChinese, std::vector<QString>& chineses)
{
    QString strsql = "SELECT chinese FROM cet WHERE LEVEL = '%1' AND chinese != '%2' ORDER BY RANDOM() LIMIT 3;";
    strsql = strsql.arg(level).arg(correctChinese);
    qDebug() << strsql;

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryWords  : " << query.lastError().text();
    }

    int k = 0;
    while(query.next())
    {
         QString chinese;
         chinese = query.value(0).toString();

         chineses.push_back(chinese);

         k++;
         if(k>3)
         {//默认只显示前3个
             break;
         }
     }

    return ok;
}

//注册账号信息
bool SqliteOp::addRegiserUser(const QString &username, const QString &password)
{
    QSqlQuery  query;
   //将输入username、password的数据插入表中；
    query.prepare("INSERT INTO user (username,pwd,wordNum,reviewNum,selLevel) "
                  "VALUES (?, ?,20,10,'4')");

    query.addBindValue(username);
    query.addBindValue(password);

    bool ok = query.exec(); //加入库中；
    if(!ok){
        qDebug() << "Fail add regiser user : " << query.lastError().text();
    }

    return ok;


}
//登录的用户名检测
bool SqliteOp::queryusername(const QString &username)
{
    QSqlQuery query;
    query.prepare("select * from user where username=? ");
    query.addBindValue(username);

    bool ok=query.exec();

    if(!ok){
        qDebug() << "Fail query username"<< query.lastError().text();
        return false;

    }

    if(query.next()){
            return true;
        }
        else{
            return false;
        }


}
//登录密码检测
bool SqliteOp::querypassword(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("select * from user where username=? and pwd=?");
    query.addBindValue(username);
    query.addBindValue(password);
    bool ok =query.exec();

    if(!ok){
        qDebug() << "Fail query password" << query.lastError().text();
        return false;
    }

    if(query.next()){
            return true;
        }
        else{
            return false;
        }
}

bool SqliteOp::queryuserLevel(const QString &username,QString &level)
{
    QSqlQuery query;
    query.prepare("select selLevel from user where username=?");
    query.addBindValue(username);
    bool ok =query.exec();

    if(!ok){
        qDebug() << "Fail query Level" << query.lastError().text();
        return false;
    }

    if(query.next())
    {
       level = query.value(0).toString();
       return true;
    }else{
            return false;
   }
}

bool SqliteOp::updateuserLevel(const QString &username,const QString &level)
{
    QSqlQuery  query;
   //将输入username、password的数据插入表中；
    query.prepare("UPDATE user SET selLevel = ? WHERE username = ?");
    query.addBindValue(level);
    query.addBindValue(username);

    bool ok = query.exec(); //加入库中；
    if(!ok){
        qDebug() << "Fail update user Level : " << query.lastError().text();
    }

    return ok;
}

bool SqliteOp::queryUserNum(const QString &username,int32_t& wordNum, int32_t& reviewNum)
{
    QSqlQuery query;
    query.prepare("select wordNum,reviewNum from user where username=?");
    query.addBindValue(username);
    bool ok =query.exec();

    if(!ok){
        qDebug() << "Fail query Num" << query.lastError().text();
        return false;
    }

    if(query.next())
    {
       wordNum = query.value(0).toInt();
       reviewNum = query.value(1).toInt();
       return true;
    }else{
        return false;
   }
}

bool SqliteOp::updateUserNum(const QString &username,const int32_t& wordNum, const int32_t& reviewNum)
{
    QSqlQuery  query;
    query.prepare("UPDATE user SET wordNum = ?, reviewNum = ? WHERE username = ?");
    query.addBindValue(wordNum);
    query.addBindValue(reviewNum);
    query.addBindValue(username);

    bool ok = query.exec(); //加入库中；
    if(!ok){
        qDebug() << "Fail update user Num : " << query.lastError().text();
    }

    return ok;
}

bool SqliteOp::addReciteWord(const QString &username,const int32_t &wordId, const QString& level)
{
    QSqlQuery  query;
    query.prepare("INSERT INTO recite (username,wordId,studyTimes,proficiency,wordLevel,lastStudyTime) "
                  "VALUES (?, ?,1,100,?,?)");

    query.addBindValue(username);
    query.addBindValue(wordId);
    query.addBindValue(level);
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    query.addBindValue(dateTime); //上一次学习或复习的时间

    bool ok = query.exec(); //加入库中；
    if(!ok){
        qDebug() << "Fail addReciteWord : " << query.lastError().text();
    }

    return ok;

}

bool SqliteOp::queryReciteNum(const QString &username,const QString& level, int32_t &num)
{
    QSqlQuery query;
    query.prepare("select count(1) from recite where username = ? and wordLevel = ? and proficiency < 100");
    query.addBindValue(username);
    query.addBindValue(level);
    bool ok =query.exec();

    if(!ok){
        qDebug() << "Fail queryReciteNum" << query.lastError().text();
        return false;
    }

    if(query.next())
    {
       num = query.value(0).toInt();
       return true;
    }else{
        return false;
   }
}

bool SqliteOp::queryTotalReciteNum(const QString &username,const QString& level,int32_t &num)
{
    QSqlQuery query;
    query.prepare("select count(1) from recite where username = ? and wordLevel = ?;");
    query.addBindValue(username);
    query.addBindValue(level);
    bool ok =query.exec();

    if(!ok){
        qDebug() << "Fail queryTotalReciteNum" << query.lastError().text();
        return false;
    }

    if(query.next())
    {
       num = query.value(0).toInt();
       return true;
    }else{
        return false;
   }
}

bool SqliteOp::queryTodayReciteNum(const QString &username,const QString& level,int32_t &num)
{
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString strsql = "select count(1) from recite where username = '%1' and wordLevel = '%2' and lastStudyTime LIKE '%3%';";
    strsql = strsql.arg(username).arg(level).arg(dateTime);
    qDebug() << strsql;

    QSqlQuery query;
    bool ok = query.exec(strsql);

    if(!ok){
        qDebug() << "Fail queryTodayReciteNum" << query.lastError().text();
        return false;
    }

    if(query.next())
    {
       num = query.value(0).toInt();
       return true;
    }else{
        return false;
   }
}

bool SqliteOp::queryGroupReciteNum(const QString &username,const QString& level, std::vector<DayCountInfo>& dayCountInfos)
{
    QString strsql = "select lastStudyTime,count(1) from recite where username = '%1' and wordLevel = '%2' and lastStudyTime >= DATE('now', 'localtime', '-30 day') GROUP BY strftime('%Y-%m-%d', lastStudyTime);";
    strsql = strsql.arg(username).arg(level);
    qDebug() << strsql;

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryGroupReciteNum  : " << query.lastError().text();
    }

    while(query.next())
    {
         DayCountInfo info;
         info.lastStudyTime = query.value(0).toString();
         info.count = query.value(1).toInt();
         dayCountInfos.push_back(info);
     }

    return ok;
}

 bool SqliteOp::queryReciteWords(const QString &username,const QString& level,const int32_t& limitNum, std::vector<int32_t>& wordIds)
 {
     QString strsql = "SELECT wordId FROM recite WHERE username = '%1' and wordLevel = '%2' and proficiency < 100 ORDER BY proficiency LIMIT %3;";
     strsql = strsql.arg(username).arg(level).arg(limitNum);
     qDebug() << strsql;

     QSqlQuery query;
     bool ok = query.exec(strsql);
     if(!ok){
         qDebug() << "Fail queryReciteWords  : " << query.lastError().text();
     }

     int k = 0;
     while(query.next())
     {
          int32_t id = query.value(0).toInt();
          wordIds.push_back(id);

          k++;
          if(k>limitNum)
          {//默认只显示前20个
              break;
          }
      }

     return ok;

 }

bool SqliteOp::updateReciteWordById(const QString &username,const int32_t &wordId)
{
    QSqlQuery  query;
    query.prepare("UPDATE recite SET proficiency = 100, lastStudyTime = ? WHERE username = ? and wordId = ?;");
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    query.addBindValue(dateTime); //上一次学习或复习的时间
    query.addBindValue(username);
    query.addBindValue(wordId);

    bool ok = query.exec(); //加入库中；
    if(!ok){
     qDebug() << "Fail update user Num : " << query.lastError().text();
    }

    return ok;
}

bool SqliteOp::updateReciteWord(const QString &username,const QString& level)
{
    //查询每个单词的学习时间
    QSqlQuery query;
    query.prepare("SELECT lastStudyTime,wordId FROM recite WHERE username = ? and wordLevel = ?;");
    query.addBindValue(username);
    query.addBindValue(level);

    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail lastStudyTime  : " << query.lastError().text();
        return ok;
    }

    //获取当前时间
    QDateTime nowDateTime = QDateTime::currentDateTime();

    while(query.next())
    {
       QString strlastStudyTime = query.value(0).toString();
       int32_t wordId = query.value(1).toInt();
       //和当前时间比较
       QDateTime lastStudyTime = QDateTime::fromString(strlastStudyTime, "yyyy-MM-dd hh:mm:ss");

       int minutes = lastStudyTime.secsTo(nowDateTime) / 60;
       if(minutes <= 5)
       {
           continue;
       }

       {
          //更新每个单词的熟练度
          int32_t proficiency =  (int32_t)ebbinghausFunc(minutes);
          QSqlQuery update;
          update.prepare("UPDATE recite SET proficiency = ? WHERE username = ? and wordId = ?;");
          update.addBindValue(proficiency);
          update.addBindValue(username);
          update.addBindValue(wordId);
          bool ok = update.exec();
          if(!ok){
              qDebug() << "Fail UPDATE  : " << update.lastError().text();
              return ok;
          }

       }


    }

    return ok;

}

bool SqliteOp::addFavoriteWord(const QString &username,const int32_t &wordId)
{
    QSqlQuery  query;
    query.prepare("INSERT INTO favorite (username,wordId) "
                  "VALUES (?, ?)");

    query.addBindValue(username);
    query.addBindValue(wordId);

    bool ok = query.exec(); //加入库中；
    if(!ok){
        qDebug() << "Fail addFavoriteWord : " << query.lastError().text();
    }

    return ok;
}

bool SqliteOp::deleteFavoriteWord(const QString &username,const int32_t &wordId)
{
    QSqlQuery  query;
    query.prepare("DELETE FROM favorite WHERE username = ? AND wordId = ?; ");

    query.addBindValue(username);
    query.addBindValue(wordId);

    bool ok = query.exec(); //加入库中；
    if(!ok){
        qDebug() << "Fail deleteFavoriteWord : " << query.lastError().text();
    }

    return ok;
}

bool SqliteOp::checkFavoriteWordExist(const QString &username,const int32_t &wordId)
{
    QSqlQuery  query;
    query.prepare("select count(1) from favorite WHERE username = ? AND wordId = ?; ");

    query.addBindValue(username);
    query.addBindValue(wordId);

    bool ok = query.exec();

    if(!ok){
        qDebug() << "Fail checkFavoriteWordExist" << query.lastError().text();
        return false;
    }

    int32_t num = 0;
    if(query.next())
    {
       num = query.value(0).toInt();
       if(num == 1)
       {
           return true;
       }
    }else{
        return false;
   }

    return false;
}

bool SqliteOp::queryFavoriteWords(const QString &username, std::vector<WordInfo>& words)
{
    //联合查询
    QString strsql = "SELECT f.wordId,c.id,c.english,c.chinese,c.sent FROM favorite AS f INNER JOIN cet AS c ON f.wordId = c.id WHERE f.username = '%1';";
    strsql = strsql.arg(username);
    qDebug() << strsql;

    QSqlQuery query;
    bool ok = query.exec(strsql);
    if(!ok){
        qDebug() << "Fail queryFavoriteWords : " << query.lastError().text();
    }

    //继续补充剩余的
    while(query.next())
    {
         WordInfo info;
         info.id = query.value(1).toInt();
         info.english = query.value(2).toString();
         info.chinese = query.value(3).toString();
         info.sent = query.value(4).toString();
         words.push_back(info);
    }

    return ok;
}

SqliteOp::SqliteOp(QObject *parent) : QObject(parent)
{
    //qDebug() <<ebbinghausFunc(600);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath()+"/words.db");

    if (!db.open())
    {
        QMessageBox::warning(0, QObject::tr("Database Error"),
                             db.lastError().text());
    }
    else{
        qDebug() <<"数据库连接成功"<<endl;
    }



}
