#include "voiceop.h"

QMutex VoiceOp::m_mutex;
VoiceOp* VoiceOp::userVoice = NULL; // 懒汉模式

VoiceOp::VoiceOp(QObject *parent) : QObject(parent)
{
    tts = new QTextToSpeech(this);
    tts->setVolume(1);
    tts->setLocale(QLocale::English);
}

VoiceOp *VoiceOp::getInstance()
{
    if(nullptr == userVoice)
    {
        QMutexLocker locker(&m_mutex);    // 加互斥锁
        if(nullptr == userVoice)
        {
            userVoice=new VoiceOp;
        }
    }
    return userVoice;
}

void VoiceOp::sayWords(const QString& words)
{
    if(tts->state()==QTextToSpeech::Ready)
    {
        tts->say(words);
    }
}
