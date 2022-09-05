#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logs.h"

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
            case 2:write();break;
            case 3:printf("Thank you for visiting your logs!!!\n");exit(1);
            default:printf("\n\tOption not Available\n");break;
        }
    }
}
