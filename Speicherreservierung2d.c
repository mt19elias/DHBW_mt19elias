//dieses Programm reserviert zusammenhängender Speicherplatz
//gibt dann die Werte aus


#include <stdio.h>
#include <stdlib.h>

int main(){

double **pointer = malloc(sizeof(double)*5);  

for(int i = 0; i<5; i++){
    pointer[i] = malloc(sizeof(double)*5);
    }

printf("Values of vec:\n");
for (int i = 0; i < 5; i++){
    for (int j=0; j<5; j++){
	printf("%d ", pointer[i][j]);
    }
    printf("\n");
}

	return 0;

}
