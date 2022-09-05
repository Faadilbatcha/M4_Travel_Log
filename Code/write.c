#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logs.h"

struct logs{
    int id;
    char from[30];
    char to[30];
    char date[15];
}l;

void write(){
    FILE *fp;
    fp=fopen("logs.txt","r");
    if(fp==NULL){
        printf("can't read file");
        exit(1);
    }
    printf("\n\t\t\t\tLOG History\n\n");
    printf("\tUser ID\t\t|From\t\t|To\t\t|Date\n");
    while(fread(&l,sizeof(l),1,fp)==1){
        printf("\n\t%d    \t\t|%s    \t|%s    \t|%s",l.id,l.from,l.to,l.date);
    }
    printf("\n");
    fclose(fp);
}
