#ifndef A_ITEM_H
#define A_ITEM_H
#include <QTextStream>
#include <QString>
#include <QFile>
#include <QMap>
#include <QStringList>

#define it_li "item.txt"

extern QTextStream qout;
extern QTextStream qin;

class a_item
{
public:
    QString name;
    int number;
    double price;
};

class a_item_table:public QMap<QString,a_item>
{
public:
  a_item_table();
  void load();
  void save();
  void show_item();
  bool delete_item();
  bool add_item();
  bool edit_item();
  void search();
  void order();
  ~a_item_table();

};

#endif // A_ITEM_H
