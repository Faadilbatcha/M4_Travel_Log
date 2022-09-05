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

void create(){
    int i,n=0;
    FILE *fp;
    fp=fopen("logs.txt","a");
    if(fp==NULL){
        printf("can't create file");
        exit(1);
    }
    printf("How Many Logs You Want to Enter: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Log %d",i+1);
        printf("\nUser ID:= ");
        scanf("%d",&l.id);
        printf("From := ");
        scanf("%s",l.from);
        printf("To := ");
        scanf("%s",l.to);
        printf("Date(dd/mm/yy) := ");
        scanf("%s",l.date);
        printf("**********************************\n");
        fwrite(&l,sizeof(l),1,fp);
    }
    printf("Logs successfully created!\n");
    fclose(fp);
}
