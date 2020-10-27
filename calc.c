//
// Created by phungsy on 14/10/2020.
//

#include "stdio.h"
#include "stdbool.h"
#include "limits.h"
#include "lib/calc.h"

int main() {
    int a = 5;
    int b = 11;
    float result = b/a;
//    must include stdbool.h to use
    bool check = true;
//    declare two var with the same type in one line
    float num1 = 4.66, num2 = 7.4;
//    declare character must use  ''
    char x = 'm';
//    =======> data build-in is int , char , float , double

    /*shift-ctrl-/ to block comment */
/* printf("message %type" , var) to printf out screen
 * var can be primative data or result of operator like b-a , b+a , add(a,b),...
 * %c is present for character , %d for interger , %f for float , double
 *  use "" in printf not use ''
 *  use \n to break line
 * */
    printf("ki tu x la %c \n",x);
    printf("b/a %f",result);
    return 0;
}