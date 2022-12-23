#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc,char *argv[],char *envp[]){
    int flag1=0;
    int flag2=0;
    if(!strcmp(argv[1],"-p"))
            flag1=1;
    if(!strcmp(argv[1],"-v"))
            flag2=1;
    if(argv[2]!=NULL){
        if(!strcmp(argv[2],"-p"))
            flag1=1;
    if(!strcmp(argv[2],"-v"))
            flag2=1;
    }
    if(flag1 && flag2){
        printf("Error! You cannot use 2 options at the same time!\n");
        return 0;
    }
    if(!(flag1 || flag2)){
        int res=mkdir(argv[1],0777);
        if(res){
            printf("Directory %s already exists! Cannot Create Directory Copies.\n",argv[1]);
        }
        
    }
    if(flag1){
        puts(argv[2]);
        char *temp=strtok(argv[2],"/");
        puts(temp);
        char path[100];
        getcwd(path,sizeof(path));
        strcat(path,"/");
        puts(path);
        while(temp!=0){
            if(temp[strlen(temp)-1]=='\n')
            temp[strlen(temp)-1]='\0';
            chdir(path);
            int res=mkdir(temp,0777);
            strcat(path,"/");
            strcat(path,temp);
            temp=strtok(0,"/");
        }
    }
    if(flag2){
        int res=mkdir(argv[2],0777);
        if(res){
            printf("Directory %s already exists! Cannot Create Directory Copies.\n",argv[2]);
        }else{
            printf("New Directory Created: %s\n",argv[2]);
        }
    }
    return 0;
}