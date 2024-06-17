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
    virtual void fill_dict(const QString &path, QMap<QString, qint64> &directorySizes) = 0;
};

#endif // ICOUNTERSIZE_H
