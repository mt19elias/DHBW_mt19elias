//dieses Programm reserviert zusammenhängender Speicherplatz
//gibt dann die Werte aus
//und die jeweilige Addresse in hex und dezimal

#include <stdio.h>
#include <stdlib.h>

int main(){

	double* pointer = malloc(sizeof(double)*5);   //je nachdem was für ein dastentyp man reserviert, wird speicherplatz reserviert (bspw. int 4 Bytes)

printf("Values of vec:\n");
for (int i = 0; i < 5; i++){
	printf("value %d = %d \n",i, pointer[i]);
	}
printf("Adress of vec in hex:\n");
for (int i = 0; i < 5; i++){
	printf("Adress %d = %p \n",i, &pointer[i]);
	}
printf("Adress of vec in dec:\n");
for (int i = 0; i < 5; i++){
	printf("Adress %d = %d \n",i, &pointer[i]);
	}
	return 0;

}
