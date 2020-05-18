/*
Newton-Ramphson-Verfahren
Elias Abt
13.05.2020
*/
#include <stdio.h>
#include "fcn.h"

int main(){
double i=8, j=1, k=0;  //i ist der x-Wert. Also 8 als Startwert (der erste x_wert mit dem man rechnet). j ist f(x) und k ist f'(x)

FILE *fp = fopen ("data.txt", "w"); //hier wird eine .txt datei erzeugt, wenn es sie noch nicht gibt. Und überschrieben. 
                                    //"w"-> write (Überschreiben); "a"-> append (anhängen); "r"-> read (lesen)

while (j>0.0000000001){
printf("%lf ", j=fcn(i));
printf("%lf ", k=der(i));
printf("%lf\n", i=nfc(i,j,k));
fprintf(fp, "%lf   %lf\n", j, k);
}
fclose(fp);
    return 0;
}

/*
JW-2020-06-14:
--------------
> nice implementation! (9/10) 
> missing abort criteria max iterations: -1Pkt
*/