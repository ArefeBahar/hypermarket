#ifndef A_GROUP_H
#define A_GROUP_H
#include"a_item.h"
#include <QTextStream>
#include <QString>
#include <QFile>
#include <QMap>
#include <QStringList>

#define gr_li "group.txt"

extern QTextStream qout;
extern QTextStream qin;

class a_group_table:QMap<QString,QList<a_item>>
{
public:
    a_group_table();
    void load();
    void save();
    bool add_group();
    bool add_gitem();
    bool delete_gitem();
    void show_group();
    void gsearch();
    ~a_group_table();
};
#endif // A_GROUP_H
