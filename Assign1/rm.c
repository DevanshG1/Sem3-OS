#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envo[]){
    int flag1=0;
    int flag2=0;
    if((!strcmp(argv[1],"-i")))
            flag1=1;
    else if((!strcmp(argv[1],"-d")))
            flag2=1;
    if(argv[2]!=NULL){
        if((!strcmp(argv[2],"-i")))
            flag1=1;
    else if((!strcmp(argv[2],"-d")))
            flag2=1;
    }      
    if(flag1 && flag2){
        printf("Error! You cannot use 2 options at the same time!\n");
        return 0;
    }
    if(!(flag1 || flag2)){
        int res=remove(argv[1]);
        if(res){
            printf("Cannot remove %s ! %s is a directory.\n",argv[1],argv[1]);
        }
        
    }
    if(flag1){
        char flag;
        printf("Do you want to delete the file (y/n): ");
        scanf("%s",&flag);
        if(flag=='y'){
            int res=remove(argv[2]);
        if(res){
            printf("Cannot remove %s ! %s is a directory.\n",argv[2],argv[2]);
        }
        }
    }
    if(flag2){
        int res=remove(argv[2]);
        if(res){
            printf("Failed to remove! Directory is not empty\n");
        }
    }
    return 0;
}