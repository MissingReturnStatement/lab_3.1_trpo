#ifndef ICOUNTERSIZE_H
#define ICOUNTERSIZE_H
#include <QDir>
#include <QMap>
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QTextStream>

class ICounterSize
{
public:
    //ICounterSize(){};
    virtual ~ICounterSize() = default;
    virtual void count_size(const QString &path, QMap<QString, qint64> &directory_sizes) = 0;
};

#endif // ICOUNTERSIZE_H
