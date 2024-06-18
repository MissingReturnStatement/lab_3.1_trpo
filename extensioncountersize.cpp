#include "extensioncountersize.h"

//ExtensionCounterSize::ExtensionCounterSize() {}

void ExtensionCounterSize::count_size(const QString &path, QMap<QString, qint64> &directory_sizes)
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
            count_size(file_info.absoluteFilePath(), directory_sizes);//рекурсия
        } else {
            QString extension = file_info.suffix();
            qint64 file_size = file_info.size();
            directory_sizes[extension] += file_size;
        }
    }
}
