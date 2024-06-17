#ifndef FILESCOUNTERSIZE_H
#define FILESCOUNTERSIZE_H
#include "icountersize.h"

class FilesCounterSize : public ICounterSize
{
public:
    ~FilesCounterSize() = default;
    void fill_dict(const QString &path, QMap<QString, qint64> &directorySizes) override;
};

#endif // FILESCOUNTERSIZE_H
