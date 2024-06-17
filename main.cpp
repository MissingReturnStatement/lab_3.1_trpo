#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include "filescountersize.h"
#include "extensioncountersize.h"
#include "context.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString, qint64> directorySizes;
    QString path = "C:\\Users\\mrdea\\OneDrive\\Рабочий стол\\Новая папка (2)";
    ICounterSize *file_strat = new FilesCounterSize();
    ICounterSize * extension_strat = new ExtensionCounterSize();
    //FilesCounterSize *file_strat = new ;
    //ExtensionCounterSize *extension_strat;
    Context strat(extension_strat);
    strat.fill_dict(path);
    directorySizes = strat.get_map();
    qDebug() << "Directory sizes in bytes:";
    foreach (const QString &str, directorySizes.keys()) {
        qDebug()<<str<<" "<<directorySizes.value(str);
    }
    strat = file_strat;
    strat.fill_dict(path);
    directorySizes = strat.get_map();
    qDebug() << "Directory sizes in bytes:";
    foreach (const QString &str, directorySizes.keys()) {
        qDebug()<<str<<" "<<directorySizes.value(str);
    }


    return a.exec();
}
