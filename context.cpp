#include "context.h"



Context::Context( ICounterSize *strategy)
{
    if (!strategy){
        qDebug() <<"strategy in nullptr";
    }
    pointer = strategy;

}

void Context::set_strategy( ICounterSize *strategy)
{
    if (!strategy){
        qDebug() <<"strategy in nullptr";
    }
    pointer = strategy;
}

void Context::fill_dict(const QString &path)
{
    if (pointer)
    pointer->fill_dict(path,map);
    else qDebug()<<"strategy in nullptr";
}

const QMap<QString, qint64> &Context::get_map()
{
    return map;
}
