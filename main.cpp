#include <iostream>
#include "expression.h"

using std::cout;
int main(int argc, char *argv[])
{

    // сначала создаём объекты для подвыражения 4.5 * 5
    //SharedPtr sube(new BinaryOperation(new Number(4.5), '*', new Number(5)));
    // потом используем его в выражении для +
   // SharedPtr expr(new BinaryOperation(new Number(3), '+',new Number(5)));
    SharedPtr p1 (new Number(5));

    {
        SharedPtr p2 = p1;

    }
    p1.reset(new Number(7));


    return 0;
}
