#ifndef A_HYPER_H
#define A_HYPER_H
#include "a_create_account_table.h"
#include "a_login_admin_table.h"
#include "a_item.h"
#include "a_group.h"

class a_hyper
{
public:
    a_create_account_table crt;
    a_login_admin_table lat;
    a_item_table it;
    a_group_table gt;
    bool is_logged=false;
    bool is_adminlogged=false;
    a_hyper();
    void menu();
    void run();
    void menu2();
    void menu3();
    void sign_out();

};

#endif // A_HYPER_H
