/**
* NAME: komplex (main) 
* AUTHOR: Elias Abt
* DATE: 2020-05-19
* DESCRIPTION:  calculation of complex numbers
* DEPENDENCIES: 
*   >> komfnc.c
*   >> komfnc.h
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "komfnc.h"

int main (){
char number1[64], number2[64], aop;
char delimiter[] = "+i";                        //die stelle, an welcher der string geteilt wird
char *real1, *real2, *imag1, *imag2;
double rea1, rea2, ima1, ima2;

printf("----------------------------\nThis program calculates complex numbers.\n\n");
printf("Please insert first complex number (i.e. '23+73i'): ");
scanf("%s", &number1); //int -> %d; float -> %f; char -> %c
printf("Please insert second complex number (i.e. '23+73i'): ");
scanf("%s", &number2);

real1 = strtok(number1, delimiter);             //strok teilt den String an der Stelle: delimiter
imag1 = strtok(NULL, delimiter);
real2 = strtok(number2, delimiter);
imag2 = strtok(NULL, delimiter);

number num1= {rea1=atof(real1), ima1=atof(imag1)};          //nummer 1 wird jeweils der als double gecastete (atof) string erstellt
number num2= {rea2=atof(real2), ima2=atof(imag2)};          //mit real und imaginärteil (siehe h datei)
number res= {0, 0};

printf("which arithmetic operations do you want to perform?\ni.e. + - * / \n");
scanf("%s", &aop);      //aop=arithmetic operations

switch(aop) {
	case '+': res = add(num1, num2); break;
	case '-': res = sub(num1, num2); break;
	case '*': res = mul(num1, num2); break;
    case '/': res = divi(num1, num2); break;
	default: printf("please insert valid arithmetic operations\n"); break;
    }
printf("the result is %.2f+%.2fi", res.rea, res.ima);

    return 0;
}
