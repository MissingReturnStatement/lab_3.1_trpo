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

void Context::count_size(const QString &path)
{
    if (pointer)
    pointer->count_size(path,dict);
    else qDebug()<<"strategy in nullptr";
}

const QMap<QString, qint64> &Context::get_dict()
{
    return dict;
}
