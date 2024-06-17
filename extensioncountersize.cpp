#include "extensioncountersize.h"

//ExtensionCounterSize::ExtensionCounterSize() {}

void ExtensionCounterSize::fill_dict(const QString &path, QMap<QString, qint64> &directorySizes)
{

    QDir directory(path);

    if (!directory.exists()) {
        qDebug() << "Directory does not exist.";
        return;
    }

    directory.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = directory.entryInfoList();

    foreach(const QFileInfo &fileInfo, list) {
        if (fileInfo.isDir()) {
            qint64 subdirSize = 0;
            fill_dict(fileInfo.absoluteFilePath(), directorySizes);
        } else {
            QString extension = fileInfo.suffix();
            qint64 fileSize = fileInfo.size();
            directorySizes[extension] += fileSize;
        }
    }

    qint64 totalSize = 0;
    foreach (qint64 size, directorySizes) {
        totalSize += size;
    }

}
