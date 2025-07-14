#include "config.h"

Config* Config::m_self=nullptr;
Config *Config::instance()
{
    if(m_self==nullptr)
        m_self=new Config();
    return m_self;
}

bool Config::setConfigFilePath(QString path)
{
    if(!QFile::exists(path)){
        INFO->Show(tr(u8"配置文件")+path+tr(u8"不存在"));
        return false;
    }
    m_config=new QSettings(path,QSettings::IniFormat);
    if(!m_config){
        INFO->Show(tr(u8"配置文件打开失败"));
        return false;
    }
    return true;
}

int Config::getLanguage()
{
    m_config->beginGroup("language");
    int flag=m_config->value("language",0).toInt();
    m_config->endGroup();
    return flag;
}

Config::Config(QObject *parent) :
    QObject(parent)
{
}
