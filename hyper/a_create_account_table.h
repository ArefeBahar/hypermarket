#ifndef A_CREATE_ACC    OUNT_TABLE_H
#define A_CREATE_ACCOUNT_TABLE_H
#include<QTextStream>
#include<QString>
#include<QMap>
#include<QFile>
#include<QStringList>

#define cr_ac "customers.txt"

extern QTextStream qout;
extern QTextStream qin;

class a_create_account_table:public QMap<QString,QString>
{
public:
    a_create_account_table();
    void load();
    void save();
    bool add_account();
    bool login();
    ~a_create_account_table();
};

#endif // A_CREATE_ACCOUNT_TABLE_H
