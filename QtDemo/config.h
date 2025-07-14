#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QApplication>
#include <QFile>
#include <QSettings>
#include "infoform.h"

#define Conf  Config::instance()

class Config : public QObject
{
    Q_OBJECT
public:
    static  Config* instance();

    bool setConfigFilePath(QString path);
    int  getLanguage();
private:
    explicit Config(QObject *parent = nullptr);

signals:

private:
    static Config* m_self;

    QSettings    *m_config;
};

#endif // CONFIG_H
