#ifndef SQLITE_OP_H
#define SQLITE_OP_H

#include <QObject>
#include <QMutex>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QApplication>
#include <QSql>
#include <QString>
#include <QMessageBox>
#include <QSqlRecord>
#include <vector>
#include <QDateTime>
#include <math.h>

struct WordInfo
{
    int32_t id;
    QString english;
    QString chinese;
    QString sent;
};

struct DayCountInfo
{
    QString lastStudyTime;
    int32_t count;
};

double inline log2(double v)
{
    return log(v)/log(2);
}

//b = 300k/((logt)c+k) k = 1.48 c =1.25 （t取分钟，取5会大于100，所以不考虑）
double inline ebbinghausFunc(double t)
{
    if(t <= 5)
    {
        return 100;
    }
    double k = 1.48;
    double c = 1.25;

    double b = 0;
    b = 300 * k/((log2(t))*c+k);
    return b;
}

class SqliteOp : public QObject
{
    Q_OBJECT
public:
      //单例模式，设置一个数据库连接
    static SqliteOp* getDataBase();

    //cet单词表
    bool queryWords(const QString& key, QStringList& words); //根据关键字查询单词
    bool queryWord(const QString& word, QString& wordMeaning, QString& wordSent); //根据单词查询释义 音标
    bool queryStudyWords(const QString &username,const QString& level, const int32_t& limitNum, std::vector<WordInfo>& words); //随机查询一定数量的单词
    bool queryAbstructWords(const QString& level,const QString& correctChinese, std::vector<QString>& chineses); //随机查询三个不正确的中文释义
    bool queryStudyWordById(const int32_t& id, WordInfo& word);
    bool queryWordCount(const QString& level, int32_t& count); //单词本总数量

    //user用户表
    bool addRegiserUser(const QString &username,const QString &password); //数据库记录注册的账号信息
    bool queryusername(const QString &username);
    bool querypassword(const QString &username,const QString &password);
    bool queryuserLevel(const QString &username,QString &level); //查询用户所选单词本
    bool updateuserLevel(const QString &username,const QString &level); //更新用户所选单词本
    bool queryUserNum(const QString &username,int32_t& wordNum, int32_t& reviewNum); //查询用户学习和复习数量
    bool updateUserNum(const QString &username,const int32_t& wordNum, const int32_t& reviewNum); //更新用户学习和复习数量

    //recite背诵表
    bool addReciteWord(const QString &username,const int32_t &wordId,const QString& level); //增加用户背诵单词信息
    bool queryReciteNum(const QString &username,const QString& level,int32_t &num); //查询用户熟练度不为100的数量
    bool queryTotalReciteNum(const QString &username,const QString& level,int32_t &num); //查询用户总学习的数量
    bool queryTodayReciteNum(const QString &username,const QString& level,int32_t &num); //查询用户当天学习的数量
    bool queryGroupReciteNum(const QString &username,const QString& level,std::vector<DayCountInfo>& dayCountInfos); //分组查询每一天学习的数量
    bool queryReciteWords(const QString &username,const QString& level,const int32_t& limitNum, std::vector<int32_t>& wordIds);
    bool updateReciteWordById(const QString &username,const int32_t &wordId);//复习正确一次更新某个单词熟练度为100
    bool updateReciteWord(const QString &username,const QString& level); //根据遗忘公式更新每个单词的熟练度

    //favorite收藏表
    bool addFavoriteWord(const QString &username,const int32_t &wordId); //增加用户收藏单词信息
    bool deleteFavoriteWord(const QString &username,const int32_t &wordId); //删除用户收藏单词信息
    bool checkFavoriteWordExist(const QString &username,const int32_t &wordId); //检测用户收藏单词信息是否存在
    bool queryFavoriteWords(const QString &username, std::vector<WordInfo>& words); //查询用户收藏单词信息

signals:

public slots:

    //构造函数私有化
private:
    explicit SqliteOp(QObject *parent = nullptr);
    static SqliteOp* userDB;
    static QMutex m_mutex;        // 实例互斥锁
};



#endif // SQLITE_OP_H
