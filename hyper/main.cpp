#include "a_hyper.h"
#include <QTextStream>

QTextStream qout (stdout);
QTextStream qin (stdin);

int main(void)
{
    a_hyper hyp;
    hyp.run();
}
