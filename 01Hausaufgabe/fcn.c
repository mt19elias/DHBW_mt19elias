/*hier werden die funktionswerte berechnet und zurückgegeben.*/
#include <stdio.h>
#include <math.h>

double fcn(double x){     //das hier ist unsere Funktion
double y=0;
y=pow((x-3),2);
return y;
}

double der(double x){   //das hier ist unsere Ableitung (der=derivation)
double y=0;
y=2*(x-3);
return y;
}

double nfc(double x, double f1, double f2){   //das hier ist unsere berechnung des neuen x-Wertes
double y=0;
y=x-(f1/f2);
return y;
}