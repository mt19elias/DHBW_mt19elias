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
    if(start->nextElem == NULL) printf("list is empty\n");
    else{
        int ElemToDel = 0;
        printList(start);
        printf("\nplease enter index of list elemment to delete...\n");
        scanf("%d", &ElemToDel);
        if(getLenOfList(start) < ElemToDel){
            printf("\ninvalid index. list index ends at %d\n", getLenOfList(start));
            return;
            }
        listElement *currElem = start;
        for (int i=1; i<ElemToDel; i++){
            currElem = currElem->nextElem;
        }
        listElement *delElem = currElem->nextElem;
        currElem->nextElem = (currElem->nextElem)->nextElem; //alternativ: currElem->nextElem = delElem->nextElem;
        free(delElem);
        printf("Element has been deleted\n");
    }
}

void delList(listElement *start){
    int del = 0;
    printf("do you want to delete the list?\n");
    printf("[0] ... no\n");
    printf("[1] ... yes\n");
    scanf("%d", &del);
    if (del == 0) return;
    if(start->nextElem == NULL) printf("list is empty\n");
    else{
        listElement *currElem = start;
        listElement *delElem;
        while(currElem->nextElem != NULL){
            delElem = currElem->nextElem; // extra pointer auf element to del --> free()
            currElem->nextElem = (currElem->nextElem)->nextElem;
            free(delElem);
        }
        printf("list has been deleted\n");
    }
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
	system("dir /b *.txt"); //print availible *.txt files in current location       (dir /b *.txt for windows)
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

  int saveFlagg = 0;
  printf("do you want to save the current list?\n");
  printf("[0] ... no\n");
  printf("[1] ... yes\n");
  scanf("%d", &saveFlagg);

  if (saveFlagg == 1) saveList(start);
  system("cls");
}

void sortList(listElement *start){
	
	int i, lenOfList, userFLAGG, swapFLAGG, SWAPPING = 0; // some locals
    listElement * currElem, * prevElem;
    char temp1[50];
    char temp2[50];

	printf("sort current list according to ...\n");
	printf(" [1] ... last name\n [2] ... first name\n [3] ... age\n [0] ... exit\n");
	scanf("%d",&userFLAGG);
    printf("\n\n");

    // sort useres choice and get flagg if char or int
	if (userFLAGG != 0 && userFLAGG != 1 && userFLAGG != 2 && userFLAGG != 3){
        system("cls");
        printf("invalid choice. will exit function\n\n");
        return; 
    }
    else if (userFLAGG == 0){
        system("cls");
        return;
        }
    else{ // do the sorting

        lenOfList = getLenOfList(start);

        do{

            currElem = start->nextElem;
            prevElem = start;

            SWAPPING = 0; 
            for (i = 0; i < lenOfList - 1; i++){

                    swapFLAGG = 0;
                    switch (userFLAGG){
                    case 1: // last name 
                    strcpy(temp1, currElem->lastName);
                    stringToLower(temp1);
                    strcpy(temp2, currElem->nextElem->lastName);
                    stringToLower(temp2);

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;  //mit strcmp werden beide Strings verglichen (=0 Strings gleich; >0  erste ungleiche Zeichen in str1 größer als in str2;  <0 erste ungleiche Zeichen in str1 kleiner als in str2

                        break;
                    case 2: // first name   
                    strcpy(temp1, currElem->firstName);
                    stringToLower(temp1);
                    strcpy(temp2, currElem->nextElem->firstName);
                    stringToLower(temp2);

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;
                        break;
                    case 3: // age
                    if (currElem->age > currElem->nextElem->age) swapFLAGG=1;                   
                        break;    
                    
                    default:
                        break;
                    }

                if (swapFLAGG){ 
                    prevElem->nextElem = currElem->nextElem;
                    currElem->nextElem = currElem->nextElem->nextElem;
                    prevElem->nextElem->nextElem = currElem;

                    prevElem = prevElem->nextElem;

                    SWAPPING = 1;
                } else{ // increament both
                    currElem = currElem->nextElem;
                    prevElem = prevElem->nextElem;
                }

            }

            lenOfList--;
        
        }while(SWAPPING);
        
    }
	printList(start); // print sorted list.
}



void stringToLower(char *string) {
	int i;
	int len = strlen(string); //is part of string.h
	for(i=0; i<len; i++) {
		if(string[i] >= 'A' && string[i] <= 'Z') { //wenn größer als A und kleiner Z // || string[i] == 'Ä' || string[i] == 'Ö' || string[i] == 'Ü'
			string[i] += 32;                        // dann wird 32 addiert -> siehe ASCII
		}
	}
}
/*
JW-2020-05-27:
--------------
> well done (10/10) 
> how much time did you spend on this exercise? I think it was a litte to easy wasnt it?
*/
/*
JW-2020-06-05:
--------------
> well done (10/10) 
*/
