//linkedListLib.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"

void addListElem(listElement *start){
    listElement *new;
    new = (listElement*)malloc(sizeof(listElement));
    if (new ==NULL){
        printf("cant reserve storage.\n");
        return;
    }
    
    //manage pointers   
    listElement *currElem = start;                                          //wir erstellen einen Zeiger, der auf unseren Datentyp llistElement zeigt. diesen setzten wir auf die Adresse des ersten Elementes
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;       //während der Pointer des Structs nicht auf null zeigt setzten wir unseren currElem poiter auf den nexten Struct
    currElem->nextElem = new; // add new to the end of list                                               //wenn das dann erfüllt ist setzten wir den pointer dieses (letzten) Elements auf unser neues element
    new->nextElem = NULL;                                                   //und setzten den Pointer des neuen Elements auf NULL

    //enter data
    printf("please enter last Name? ");
    scanf("%s", &(new->lastName[0]));      //das ist das selbe wie unten
    printf("please enter first Name? ");
    scanf("%s", new->firstName);        //scan s erwartet eine Adresse wo er hinspeichern kann, da ein String eine Adresse speichert, die der beginn des strings ist
    printf("please enter age? ");
    scanf("%d", &(new->age));             //scan d erwartet einen Wert. daher &
}

void printList(listElement *start){

    if (start->nextElem == NULL) printf("\nlist is empty.\n");
    else{
        int i=1;
        listElement *currElem = start; 
        printf("\ncurrent list:\n\n");
        do {
            currElem = currElem->nextElem;
            printf("%d. Element",i); i++;
            printf ("\tlast Name: %s\n", currElem->lastName);
            printf ("\t\tfirst Name: %s\n", currElem->firstName);
            printf ("\t\tage: %d\n\n", currElem->age);           //auch möglich '*currElem->age'
        } while (currElem->nextElem != NULL);
        printf("\n");
    }
}

void delListElem(listElement *start){
    printf("\n>> delListElem fcn is tbd.\n\n");
}

void delList(listElement *start){
    printf("\n>> getLenOfList fcn is tbd.\n\n");
}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

void saveList(listElement *start){

	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
    fPtr = fopen(filename, "w");

    if (fPtr == NULL) {
        printf("couldn't create a file");
        return;
    }
    
    fprintf(fPtr, "%d\n", getLenOfList(start));

    int i=1;
        listElement *currElem = start; 
        do {
            currElem = currElem->nextElem;
            fprintf (fPtr, "%s %s %d\n", currElem->lastName, currElem->firstName, currElem->age);
        } while (currElem->nextElem != NULL);

    printf("your list has been saved as %s\n\n", filename);
    fclose(fPtr);
}

void loadList(listElement *start){
	
	char filename[50];
	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("ls /b *.txt"); //print availible *.txt files in current location       (dir /b *.txt for windows)
	printf("\nfilname without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");

    if (fPtr == NULL) {
        printf("couldn't open list");
        return;
    }

    int len = 0;
    fscanf(fPtr, "%d\n", &len); 
    listElement *currElem = start;
      for (int i=0; i<len; i++)
            {
            listElement *new;
            new = (listElement*)malloc(sizeof(listElement));
            if (new ==NULL){
                printf("cant reserve storage.\n");
                return;
            }
            while (currElem->nextElem != NULL) currElem = currElem->nextElem;
            currElem->nextElem = new;
            new->nextElem = NULL;  
            fscanf (fPtr, "%s %s %d\n", new->lastName, new->firstName, &new->age);
        } 	
    
	fclose(fPtr);
	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}
/*
JW-2020-05-27:
--------------
> well done (10/10) 
> how much time did you spend on this exercise? I think it was a litte to easy wasnt it?
*/
