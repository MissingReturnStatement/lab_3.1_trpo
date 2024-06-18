#ifndef FILESCOUNTERSIZE_H
#define FILESCOUNTERSIZE_H
#include "icountersize.h"

class FilesCounterSize : public ICounterSize
{
public:
    ~FilesCounterSize() = default;
    void count_size(const QString &path, QMap<QString, qint64> &directory_sizes) override;
};

#endif // FILESCOUNTERSIZE_H
