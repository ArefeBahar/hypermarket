#include "a_create_account_table.h"



a_create_account_table::a_create_account_table()
{

}

void a_create_account_table::load()
{
    QFile file (cr_ac);
    file.open(QFile::Text|QFile::ReadOnly);
    if(!file.isOpen())
        return;
    QTextStream fst (&file);
    while (!fst.atEnd())
    {
        QString line=fst.readLine();
        QStringList a=line.split(',');
        if(a.size()!=2)
            continue;
        QString username= a[0];
        QString password= a[1];
        (*this)[username]=password;
    }

}

void a_create_account_table::save()
{
    QFile file (cr_ac);
    file.open(QFile::Text|QFile::WriteOnly);
    if(!file.isOpen())
    {
        qout<<"cant write into file" cr_ac<<endl;
        throw "cant write into file" cr_ac;
    }
    QTextStream fst(&file);
    for(a_create_account_table::iterator itr=begin(); itr!=end(); itr++)
    {
        fst<<itr.key()<<","
          <<itr.value()<<endl;
    }
    file.close();
}

bool a_create_account_table::add_account()
{
    QString username;
    QString password;

    qout<<"enter username:"<<endl;
    qin>>username;
    if(this->find(username)!=this->end())
    {
        qout<<"this username has already been used!"<<endl;
        return false;
    }
    qout<<"enter password:"<<endl;
    qin>>password;
    qout<<"you are already logged in"<<endl;
    (*this)[username]=password;
    return true;
}

bool a_create_account_table::login()
{
    QString username;
    QString password;
    qout<<"enter username:"<<endl;
    qin>>username;
    for(a_create_account_table::iterator itr=begin();itr!=end();++itr)
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
                qout<<"password is incorrect!"<<endl;
                return false;
            }
        }
    }
    qout<<"this username is not available!"<<endl;
    return false;
}

a_create_account_table::~a_create_account_table()
{
    save();
}
