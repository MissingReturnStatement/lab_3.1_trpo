#include "filescountersize.h"

//FilesCounterSize::FilesCounterSize() {}


void FilesCounterSize::count_size(const QString &path, QMap<QString, qint64> &directory_sizes)
{
    QDir directory(path);

    if (!directory.exists()) {
        qDebug() << "Directory does not exist.";
        return;
    }

    directory.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = directory.entryInfoList();

    qint64 size = 0;

    foreach(const QFileInfo &file_info, list) {
        if (file_info.isDir()) {
            qint64 subdir_size = 0;
            count_size(file_info.absoluteFilePath(), directory_sizes);
            subdir_size = directory_sizes.value(file_info.absoluteFilePath());
            directory_sizes.insert(file_info.absoluteFilePath(), subdir_size);
            size += subdir_size;
        } else {
            size += file_info.size();
        }
    }

    directory_sizes.insert(path, size); // Размер текущей директории в байтах
}
