#ifndef EXTENSIONCOUNTERSIZE_H
#define EXTENSIONCOUNTERSIZE_H
#include "icountersize.h"

class ExtensionCounterSize : public ICounterSize
{
public:
    ~ExtensionCounterSize() = default;
    void fill_dict(const QString &path, QMap<QString, qint64> &directory_sizes) override;
};

#endif // EXTENSIONCOUNTERSIZE_H
