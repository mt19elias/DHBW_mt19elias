#ifndef KOMFCN_H_       //wenn diese Header noch nicht definiert ist, dann:
#define KOMFCN_H_	    //...gilt das hier

typedef struct {          //hier wird eine neue Sturktur erstellt und zwar zahlen
double rea;
double ima;
}number;                   //hier steht der name des Objekts der Struktur. es könne auch mehrere Objekte angelegt werden

number add(number, number);   //wir schreiben nur was es ist (also der Rückgabewert)(number),
number sub(number, number);     // wie die Funktion heißt (sub),
number mul(number, number);        //und welchen wert sie erwartet (2 number)
number divi(number, number); 

#endif					//und hier endet es dann
