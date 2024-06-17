#include "extensioncountersize.h"

//ExtensionCounterSize::ExtensionCounterSize() {}

void ExtensionCounterSize::fill_dict(const QString &path, QMap<QString, qint64> &directory_sizes)
{

    QDir directory(path);//берём директорию

    if (!directory.exists()) {
        qDebug() << "Directory does not exist.";
        return;
    }

    directory.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = directory.entryInfoList();//возвращает всё что лежит в папке

    foreach(const QFileInfo &file_info, list) {
        if (file_info.isDir()) {
            fill_dict(file_info.absoluteFilePath(), directory_sizes);
        } else {
            QString extension = file_info.suffix();
            qint64 file_size = file_info.size();
            directory_sizes[extension] += file_size;
        }
    }

    qint64 total_size = 0;
    foreach (qint64 size, directory_sizes) {
        total_size += size;
    }

}
