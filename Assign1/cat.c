#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[], char *envp[]){
    int flag1=0;
    int flag2=0;
    char data[100];
    FILE *f;
    if(!strcmp(argv[1],"-n"))
            flag1=1;
    if(!strcmp(argv[1],"-E"))
            flag2=1;
    if(argv[2]!=NULL){
        if(!strcmp(argv[2],"-n"))
            flag1=1;
        if(!strcmp(argv[2],"-E"))
            flag2=1;
    }
    if(flag1 && flag2){
        printf("Error! You cannot use 2 options at the same time!\n");
        return 0;
    }
    if(!(flag1 || flag2)){
        f=fopen(argv[1],"r");
        while(fgets(data,100,f)!=NULL){
            printf("%s ",data);
        }
        fclose(f);
    }
    if(flag1){
        int i=1;
        f=fopen(argv[2],"r");
        while(fgets(data,100,f)!=NULL){
            printf("%d %s ",i,data);
            i++;
        }
        fclose(f);
    }
    if(flag2){
        int i=1;
        f=fopen(argv[2],"r");
        while(fgets(data,100,f)!=NULL){
            data[strlen(data)-1]='\0';
            printf("%s$\n",data);
            
        }
        fclose(f);
    }
    return 0;
}