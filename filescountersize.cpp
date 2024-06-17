#include "filescountersize.h"

//FilesCounterSize::FilesCounterSize() {}


void fill_dict(const QString &path, QMap<QString, qint64> &directorySizes) {
    QDir directory(path);

    if (!directory.exists()) {
        qDebug() << "Directory does not exist.";
        return;
    }

    directory.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = directory.entryInfoList();

    qint64 size = 0;

    foreach(const QFileInfo &fileInfo, list) {
        if (fileInfo.isDir()) {
            qint64 subdirSize = 0;
            fill_dict(fileInfo.absoluteFilePath(), directorySizes);
            subdirSize = directorySizes.value(fileInfo.absoluteFilePath());
            directorySizes.insert(fileInfo.absoluteFilePath(), subdirSize);
            size += subdirSize;
        } else {
            size += fileInfo.size();
        }
    }

    directorySizes.insert(path, size); // Размер текущей директории в байтах
}

void FilesCounterSize::fill_dict(const QString &path, QMap<QString, qint64> &directorySizes)
{
    QDir directory(path);

    if (!directory.exists()) {
        qDebug() << "Directory does not exist.";
        return;
    }

    directory.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = directory.entryInfoList();

    qint64 size = 0;

    foreach(const QFileInfo &fileInfo, list) {
        if (fileInfo.isDir()) {
            qint64 subdirSize = 0;
            fill_dict(fileInfo.absoluteFilePath(), directorySizes);
            subdirSize = directorySizes.value(fileInfo.absoluteFilePath());
            directorySizes.insert(fileInfo.absoluteFilePath(), subdirSize);
            size += subdirSize;
        } else {
            size += fileInfo.size();
        }
    }

    directorySizes.insert(path, size); // Размер текущей директории в байтах
}
