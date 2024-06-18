#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <vector>
#include "filescountersize.h"
#include "extensioncountersize.h"
#include "context.h"

QMap<QString,double> count_percentage(QMap<QString,qint64> &dict, double border){
    double counter = 0.0;
    QMap<QString, double> counted_dict;
    foreach(auto item, dict){
        counter+=item;
    }
    if (counter==0) return counted_dict;
    foreach(auto item, dict.keys()){
        double percent = ((double)dict[item])*100.0/counter;
        if (percent > border)  counted_dict[item] = percent;
        else{
            if(counted_dict.count("other") == 0) {
                 counted_dict[item] = percent;

            }
            else{
                 counted_dict[item] += percent;
            }
        }
    }
    return counted_dict;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString, qint64> directory_sizes;
    QString path = "";
    ICounterSize *file_strat = new FilesCounterSize();
    ICounterSize * extension_strat = new ExtensionCounterSize();
    //QMap<QString, vector<QString>> directorys_tests;
    QString current_dir = QDir::currentPath();
    QVector<QString> string_vector;
    string_vector.append("C:\\trpo_labs\\lab_3_1_trpo\\EMPTY_EMBED_EMPTY");
    string_vector.append("C:\\trpo_labs\\lab_3_1_trpo\\EMPTY_EMBED_NOT_EMPTY");
    string_vector.append("C:\\trpo_labs\\lab_3_1_trpo\\NOT_EMPTY_EMBED");
    string_vector.append("C:\\trpo_labs\\lab_3_1_trpo\\EMPTY_NOT_EMBED");
    string_vector.append("C:\\trpo_labs\\lab_3_1_trpo\\NOT_EMPTY_NOT_EMBED");
    foreach(auto item, string_vector){
        path = item; // записал путь
        qDebug()<<item; //вывел
        Context strat(extension_strat); //выбрал стратегию
        strat.count_size(path); //выполнил алгоритм стратегии
        directory_sizes = strat.get_dict(); //получил посчитанный словарь

        qDebug() << "STRAT EXTENSIONS Directory sizes in bytes:";
        if (!directory_sizes.empty()){
            foreach (const QString &str, directory_sizes.keys()) {
                qDebug()<<str<<" "<<directory_sizes.value(str);
            }
        }
        else qDebug()<<item<<"this directory empty";
        QMap<QString,double> counted_dict = count_percentage(directory_sizes, 10);//посчитал процентики
        qDebug()<<"\n";
        qDebug() << "STRAT EXTENSIONS Directory sizes in bytes with percentage:";

        if (!counted_dict.empty()){
            foreach (const QString &str, counted_dict.keys()) {
                qDebug()<<str<<" "<<counted_dict.value(str);
            }
        }
        else qDebug()<<item<<"this directory empty";
        qDebug()<<"\n";
        strat = file_strat; //поменял стратегию
        strat.count_size(path); //выполнил алгоритм стратегии
        directory_sizes = strat.get_dict(); //получил посчитанный словарь

        qDebug() << "STRAT FILES Directory sizes in bytes:";

        foreach (const QString &str, directory_sizes.keys()) {
            qDebug()<<str<<" "<<directory_sizes.value(str);
        }
        qDebug()<<"\n";
        counted_dict = count_percentage(directory_sizes, 10);
        qDebug() << "STRAT FILES Directory sizes in bytes with percentage:";
        if (!counted_dict.empty()){
            foreach (const QString &str, counted_dict.keys()) {
                qDebug()<<str<<" "<<counted_dict.value(str);
            }
        }
        else qDebug()<<item<<"this directory empty";
        qDebug()<<"____________________";
    }

    //ТЕСТ НА ПУСТОТУ
    //C:\Users\mrdea\OneDrive\Рабочий стол\woop_woop

    delete file_strat;
    delete extension_strat;
    return a.exec();
}
