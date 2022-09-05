#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create();
void read();

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

void read(){
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

int main(){
    int ch;
    printf("\t\t\tTravel Log\t\t\t");
    while(1)
    {
        printf("\n1:Create Entry\n2:Log History\n3:Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();break;
            case 2:read();break;
            case 3:exit(1);
            default:printf("\n\tOption not Available\n");break;
        }
    }
}
