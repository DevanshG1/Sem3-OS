#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char *argv[], char *envp[]){
    char path[100];
    getcwd(path,sizeof(path));
    struct dirent *d;
    DIR *dir =opendir(path);
    if(argv[1]==NULL){
        while((d=readdir(dir))!=NULL){
            if(d->d_name[0]!='.'){
                printf("%s\t",d->d_name);
            }
        }
        printf("\n");
    }
    else if(!strcmp(argv[1],"-a")){
        while((d=readdir(dir))!=NULL){
            printf("%s\t",d->d_name);
            
        }
        printf("\n");
    }
    else if(!strcmp(argv[1],"-m")){
        while((d=readdir(dir))!=NULL){
            if(d->d_name[0]!='.'){
                printf("%s, \t",d->d_name);
            }
        }
        printf("\n");
    }
    else{
        strcat(path,"/");
        strcat(path,argv[1]);
        dir=opendir(path);
        while((d=readdir(dir))!=NULL){
            if(d->d_name[0]!='.'){
                printf("%s\t",d->d_name);
            }
        }
        printf("\n");
    }
    closedir(dir);
    return 0;
}