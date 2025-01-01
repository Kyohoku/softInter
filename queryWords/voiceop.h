#ifndef VOICEOP_H
#define VOICEOP_H

#include <QObject>
#include <QTextToSpeech>
#include <QMutex>

class VoiceOp : public QObject
{
    Q_OBJECT
public:
    //单例模式
  static VoiceOp* getInstance();

  void sayWords(const QString& words);

signals:
    //构造函数私有化
private:
   explicit VoiceOp(QObject *parent = nullptr);
   static VoiceOp* userVoice;
   static QMutex m_mutex;        // 实例互斥锁
   QTextToSpeech *tts;
};

#endif // VOICEOP_H
