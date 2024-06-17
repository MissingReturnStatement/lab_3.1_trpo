#include "context.h"



Context::Context( ICounterSize *strategy)
{
    if (!strategy){
        qDebug() <<"strategy in nullptr";
        exit(-1);
    }
    pointer = strategy;

}

void Context::set_strategy( ICounterSize *strategy)
{
    pointer = strategy;
}

void Context::fill_dict(const QString &path)
{
    pointer->fill_dict(path,map);
}

const QMap<QString, qint64> &Context::get_map()
{
    return map;
}
