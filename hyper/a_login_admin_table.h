#ifndef A_LOGIN_ADMIN_TABLE_H
#define A_LOGIN_ADMIN_TABLE_H
#include<QTextStream>
#include<QString>
#include<QFile>
#include<QMap>
#include<QStringList>

#define lo_ad "admin.txt"

extern QTextStream qout;
extern QTextStream qin;

class a_login_admin_table:public QMap <QString,QString>
{
public:
    a_login_admin_table();
    void load();
    bool admin_login();
    ~a_login_admin_table();
};

#endif // A_LOGIN_ADMIN_TABLE_H
