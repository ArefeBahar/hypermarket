#include "a_item.h"

a_item_table::a_item_table()
{

}

void a_item_table::load()
{
    QFile file (it_li);
    file.open(QFile::Text|QFile::ReadOnly);
    if(!file.isOpen())
        return;
    QTextStream fst(&file);
    while (!fst.atEnd())
    {
        QString line=fst.readLine();
        QStringList c=line.split(',');
        if(c.size()!=4)
            continue;
        (*this)[c[0]] = a_item { c[1] , c[2].toInt() , c[3].toDouble () } ;
}

}

void a_item_table::save()
{
    QFile file (it_li);
    file.open(QFile::Text|QFile::WriteOnly);
    if(!file.isOpen())
    {
        qout<<"cant write into file" it_li<<endl;
        throw "cant write into file" it_li;
    }
    QTextStream fst (&file);
    for(a_item_table::iterator itr=begin();itr!=end();++itr)
    {
        fst<<itr.key()<<","
          <<itr.value().name<<","
         <<itr.value().number<<","
        <<itr.value().price<<endl;
    }
    file.close();

}

void a_item_table::show_item()
{
    for(a_item_table::iterator itr=begin();itr!=end();++itr)
    {
        qout<<"________________________"<<endl;
        qout<<"id:"<<itr.key()<<endl;
        qout<<"name:"<<itr.value().name<<endl;
        qout<<"number:"<<itr.value().number<<endl;
        qout<<"price:"<<itr.value().price<<endl;
        qout<<"________________________"<<endl;

    }

}

bool a_item_table::delete_item()
{
    QString id ;
    qout << " enter id: " << endl ;
    qin >> id ;
    for(a_item_table::iterator itr=begin();itr!=end();++itr)
    {
        if (itr.key()==id)
        {
            erase(itr);
            qout<<id<<" "<<"delete."<<endl;
            return true;
        }
        else
        {
            qout << "cant delete!" << endl;
            return false;
        }

    }
}

bool a_item_table::add_item()
{
    QString id ;
    a_item t ;
    qout << " enter id: " << endl ;
    qin >> id ;

    if (this->find(id) != this->end () )
    {
        qout << " this id is registered before " << endl;
        return false ;
    }
    qout << " enter name: " << flush ;
    qin >> t.name ;
    qout << " enter number: " << flush ;
    qin >> t.number ;
    qout << " enter price: " << flush  ;
    qin >> t.price ;
    (*this)[id] = t ;
    return true ;
}

bool a_item_table::edit_item()
{
    QString id;
    a_item t;
    qout<<"enter id:"<<endl;
    qin>>id;
    for(a_item_table::iterator itr=begin();itr!=end();++itr)
    {
        if(itr.key()==id)
        {
            erase(itr);
            qout<<"enter new information:"<<endl;
            qout << " enter name: " << flush ;
            qin >> t.name ;
            qout << " enter number: " << flush ;
            qin >> t.number ;
            qout << " enter price: " << flush  ;
            qin >> t.price ;
            (*this)[id] = t ;
            return true ;
        }
        else
        {
            qout<<"this id not found!"<<endl;
            return false;
        }
    }
}

void a_item_table::search()
{
    QString x;
    qout<<"start..."<<endl;
    qin>>x;
    for(a_item_table::iterator itr=begin();itr!=end();++itr)
    {
        if(QString(itr.value().name).toLower().startsWith(x.toLower()))
        {
            qout<<"id:"<<itr.key()<<endl;
            qout<<"name:"<<itr.value().name<<endl;
            qout<<"number:"<<itr.value().number<<endl;
            qout<<"price:"<<itr.value().price<<endl;
        }
    }
    qout<<"finish!"<<endl;
}

void a_item_table::order()
{
    QString oid;
    QString ans;
    show_item();
    do{
        qout<<"enter id:"<<endl;
        qin>>oid;
        for(a_item_table::iterator itr=begin();itr!=end();++itr)
        {
            if(itr.key()==oid)
            {
                qout<<"your order has been placed."<<endl;
                (itr.value().number)--;
            }
        }
        qout<<"do you want to order another item ? (yes/no)"<<endl;
        qin>>ans;
    }while(QString("yes").toLower().startsWith(ans.toLower()));
}

a_item_table::~a_item_table()
{
    save();
}
