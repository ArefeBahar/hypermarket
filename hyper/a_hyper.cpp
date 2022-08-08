#include "a_hyper.h"
#include<QTextStream>
#include<QString>

extern QTextStream qout;
extern QTextStream qin;



a_hyper::a_hyper()
{
    menu();
    crt.load();
    lat.load();
    it.load();
    gt.load();
}

void a_hyper::menu()
{
    qout<<"__________________________________________________________"<<endl;
    qout<<"Help                     for helping"<<endl;
    qout<<"CreateAccount            for creating account"<<endl;
    qout<<"Login                    for logining as user"<<endl;
    qout<<"ALogin                   for logining as admin"<<endl;
    qout<<"Quit                     for quiting"<<endl;
    qout<<"___________________________________________________________"<<endl;


}

void a_hyper::run()
{
    QString cmd;
    forever
    {
        qout<<"enter a command:"<<flush;
        qin>>cmd;
        if(QString("Help").toLower().startsWith(cmd.toLower()))
            menu();

        else if(QString("Quit").toLower().startsWith(cmd.toLower()))
            break;

        else if (QString("CreateAccount").toLower().startsWith(cmd.toLower()) && is_logged==false )
        {
            bool result = crt.add_account();
            if(result==true)
                menu2();
        }

        else if (QString("Login").toLower().startsWith(cmd.toLower()) && is_logged==false )
        {
            bool result2=crt.login();
            if(result2==true)
                menu2();
        }

        else if (QString("ALogin").toLower().startsWith(cmd.toLower()) && is_adminlogged==false )
        {
            bool result3=lat.admin_login();
            if(result3==true)
                menu3();
        }

        else if(QString("CHelp").toLower().startsWith(cmd.toLower()))
            menu2();

        else if(QString("AHelp").toLower().startsWith(cmd.toLower()))
            menu3();

        else if(QString("AddItem").toLower().startsWith(cmd.toLower()))
            it.add_item();

        else if(QString("DeleteItem").toLower().startsWith(cmd.toLower()))
            it.delete_item();

        else if(QString("EditItem").toLower().startsWith(cmd.toLower()))
            it.edit_item();

        else if(QString("ShowItem").toLower().startsWith(cmd.toLower()))
            it.show_item();

        else if(QString("Search").toLower().startsWith(cmd.toLower()))
            it.search();

        else if(QString("Order").toLower().startsWith(cmd.toLower()))
            it.order();

        else if(QString("GAdd").toLower().startsWith(cmd.toLower()))
            gt.add_group();

        else if(QString("GShow").toLower().startsWith(cmd.toLower()))
            gt.show_group();

        else if(QString("AItem").toLower().startsWith(cmd.toLower()))
            gt.add_gitem();

        else if(QString("DItem").toLower().startsWith(cmd.toLower()))
            gt.delete_gitem();

        else if(QString("GSearch").toLower().startsWith(cmd.toLower()))
            gt.gsearch();


        else if(QString("SignOut").toLower().startsWith(cmd.toLower()))
            sign_out();

        else
        {
            qout<<"no such command (" <<cmd<< ") "<<endl;
            menu();
        }
    }
}

void a_hyper::menu2()
{
    qout<<"__________________________________________________________"<<endl;
    qout<<"CHelp                              for Helping customers"<<endl;
    qout<<"ShowItem                           for showing item"<<endl;
    qout<<"Search                             for searching"<<endl;
    qout<<"GShow                              for showing group"<<endl;
    qout<<"GSearch                            for searching"<<endl;
    qout<<"Order                              for ordering"<<endl;
    qout<<"SignOut                            for signing out"<<endl;
    qout<<"Quit                               for quit"<<endl;
    qout<<"__________________________________________________________"<<endl;

}

void a_hyper::menu3()
{
    qout<<"__________________________________________________________"<<endl;
    qout<<"AHelp                          for Helping admin"<<endl;
    qout<<"AddItem                        for adding item"<<endl;
    qout<<"EditItem                       for editing item"<<endl;
    qout<<"ShowItem                       for showing item"<<endl;
    qout<<"Search                         for searching"<<endl;
    qout<<"DeleteItem                     for deleting item"<<endl;
    qout<<"GAdd                           for adding group"<<endl;
    qout<<"GShow                          for showing group"<<endl;
    qout<<"GSearch                        for searching group"<<endl;
    qout<<"AItem                          for adding item to group"<<endl;
    qout<<"Ditem                          for deleting item from group"<<endl;
    qout<<"SignOut                        for signing out"<<endl;
    qout<<"Quit                           for quit"<<endl;
    qout<<"__________________________________________________________"<<endl;
}

void a_hyper::sign_out()
{
    menu();
}
