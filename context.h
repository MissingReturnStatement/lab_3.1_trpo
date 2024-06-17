#ifndef CONTEXT_H
#define CONTEXT_H
#include "extensioncountersize.h"
#include "filescountersize.h"
#include <memory>


class Context
{
    QMap<QString, qint64> map;
    ExtensionCounterSize *extension_strategy;
    FilesCounterSize *files_strategy;
public:

    Context(ICounterSize *strategy);
    ~Context() = default;
    void set_strategy(ICounterSize *strategy);
    void fill_dict(const QString& path);
    const QMap<QString,qint64>& get_map();
private:
    ICounterSize *pointer;



};


#endif // CONTEXT_H
