#include "a_login_admin_table.h"



a_login_admin_table::a_login_admin_table()
{

}

void a_login_admin_table::load()
{
    QFile file (lo_ad);
    file.open(QFile::Text|QFile::ReadOnly);
    if(!file.isOpen())
        return;
    QTextStream fst (&file);
    while (!fst.atEnd())
    {
        QString line=fst.readLine();
        QStringList b=line.split(',');
        if(b.size()!=2)
            continue;
        QString username= b[0];
        QString password= b[1];
        (*this)[username]=password;
    }
}

bool a_login_admin_table::admin_login()
{
    QString username;
    QString password;
    qout<<"enter username:"<<endl;
    qin>>username;
    for(a_login_admin_table::iterator itr=begin();itr!=end();++itr)
    {
        if(itr.key()==username)
        {
            qout<<"enter password:"<<endl;
            qin>>password;
            if(itr.value()==password)
            {
                qout<<"You are successfully logged in!"<<endl;
                return true;
            }
            else
            {
                qout<<"Username or password is incorrect!"<<endl;
                return false;
            }
        }
    }
    qout<<"this username is not available!"<<endl;
    return false;
}

a_login_admin_table::~a_login_admin_table()
{

}
