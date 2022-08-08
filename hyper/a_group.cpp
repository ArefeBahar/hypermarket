#include "a_group.h"


a_group_table::a_group_table()
{

}

void a_group_table::load()
{
    QFile file(gr_li);
    file.open(QFile::Text|QFile::ReadOnly);
    if(!file.isOpen())
        return;
    QTextStream fst(&file);
    while(!fst.atEnd())
    {
        QString line=fst.readLine();
        QStringList d=line.split(',');
        if(d.size()!=4)
            continue;
        QString gname=d[0];
        a_item t;
        (*this)[gname].push_back(t);
    }
}

void a_group_table::save()
{
    a_item t;

    QFile file (gr_li);
    file.open(QFile::Text|QFile::WriteOnly);
    if(!file.isOpen())
    {
        qout<<"cant write into file" gr_li<<endl;
        throw "cant write into file" gr_li;
    }
    QTextStream fst(&file);
    for(a_group_table::iterator itr=begin(); itr!=end(); itr++)
    {
        fst<<itr.key()<<",";
        for(int i=0;i<itr.value().size();i++)
        {
            fst<<itr.value().at(i).name<<","
              <<itr.value().at(i).number<<","
             <<itr.value().at(i).price<<endl;
        }
    }
    file.close();
}

bool a_group_table::add_group()
{
    QString gname ;
    QString gans;
    a_item t ;
    qout << " enter group name: " << endl ;
    qin >> gname ;
    if(this->find(gname)!=this->end())
    {
        qout << " this name is registered before!" << endl;
        return false ;
    }
    else
    {
        qout<<"group stablished successfully!"<<endl;
    }
    (*this)[gname];
    return true ;
}

bool a_group_table::add_gitem()
{
    QString gname;
    a_item t;
    qout<<"enter group name:"<<endl;
    qin>>gname;
    if(this->find(gname)!=this->end())
    {
        qout<<"enter name:"<<endl;
        qin>>t.name;
        qout<<"enter number:"<<endl;
        qin>>t.number;
        qout<<"enter price:"<<endl;
        qin>>t.price;
    }
    else
    {
        qout<<"not found!"<<endl;
        return false;
    }
    (*this)[gname].push_back(t);
    return true ;
}

bool a_group_table::delete_gitem()
{
    QString gname;
    QString z;
    qout<<"enter group name:"<<endl;
    qin>>gname;
    for(a_group_table::iterator itr=begin();itr!=end();++itr)
    {
        if(itr.key()==gname)
        {
            for(int i=0;i<itr.value().size();i++)
            {
                qout<<"item:"<<endl;
                qout<<itr.value().at(i).name<<endl;
                qout<<itr.value().at(i).number<<endl;
                qout<<itr.value().at(i).price<<endl;
            }
            qout<<"enter name:"<<endl;
            qin>>z;
            for(auto q=itr.value().begin();q!=itr.value().end();q++)
            {
                if(q->name==z)
                {
                    itr.value().erase(q);
                    qout<<"delete!"<<endl;
                    return true;
                }
            }
        }
    }
    qout<<"cant delete!"<<endl;
    return false;
}

void a_group_table::show_group()
{
    for(a_group_table::iterator itr=begin();itr!=end();++itr)
    {
        qout<<"________________________"<<endl;
        qout<<"group name:"<<itr.key()<<endl;
        qout<<"item:"<<endl;
        for(int i=0;i<itr.value().size();i++)
        {
            qout<<itr.value().at(i).name<<endl;
            qout<<itr.value().at(i).number<<endl;
            qout<<itr.value().at(i).price<<endl;
            qout<<"________________________"<<endl;
        }
        qout<<"________________________"<<endl;
    }
}

void a_group_table::gsearch()
{
    QString x;
    qout<<"start"<<endl;
    qin>>x;
    for(a_group_table::iterator itr=begin();itr!=end();++itr)
    {
        if(QString(itr.key()).toLower().startsWith(x.toLower()))
        {
            qout<<"++"<<endl;
            qout<<itr.key()<<endl;
            for(int i=0;i<itr.value().size();i++)
            {
                qout<<itr.value().at(i).name<<endl;
                qout<<itr.value().at(i).number<<endl;
                qout<<itr.value().at(i).price<<endl;
            }
            qout<<"++"<<endl;
        }
    }
    qout<<"finish!"<<endl;
}

a_group_table::~a_group_table()
{
    save();
}
