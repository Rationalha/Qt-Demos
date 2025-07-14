#include "widget.h"

#include <QApplication>
#include <QTranslator>
#include "config.h"
/*
 * 该项目指在实现各类样式的控件，作为样式库，方便后期开发
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString confFile=QApplication::applicationDirPath()+"/config/config.ini";
    if(!Conf->setConfigFilePath(confFile))
        return a.exec();
    if(Conf->getLanguage()==1){
        QTranslator lang;
        lang.load(":/lang_english.qm");
        a.installTranslator(&lang);
    }
    Widget w;
    w.show();
    return a.exec();
}
