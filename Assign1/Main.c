#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include <time.h>
#include <pthread.h>
int pthread_join(pthread_t thread, void **value_ptr);
int pid;
char compath[100];
char entpath[100]={"/home/"};
char *user;
int valid(char com[]){
    char commands1[9][100]={"cd","echo","pwd","ls","mkdir","rm","date","cat","exit"};
    char commands2[8][100]={"cd&t","echo&t","pwd&t","ls&t","mkdir&t","rm&t","date&t","cat&t"};
    for(int i=0;i<9;i++){
        if(!strcmp(com,commands1[i])){
            return 1;
        }
    for(int i=0;i<8;i++){
        if(!strcmp(com,commands2[i])){
            return 1;
        }
    }
    }
    return 0;
}
void fn_mkdir(char *cmd){
    char *argv[10];
    int idx=1;
    char path[100];
    strcpy(path,compath);
    strcat(path,"/mkdir");
    for(int i=0;i<10;i++){
        argv[i]=(char*)malloc(100*sizeof(char));
    }
    strcpy(argv[0],path);
    while(cmd!=0){
        if(!strcmp(cmd,"mkdir")){
            cmd=strtok(0," ");
            continue;
        }
        strcpy(argv[idx],cmd);
        idx++;
        cmd=strtok(0," ");
    }
    argv[idx]=NULL;
    idx++;
    pid=fork();
    if(pid<0){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    else if(pid==0){
            execl(path,path,argv[1],argv[2],NULL);
            return;
    }else{
        wait(NULL);
        return;
    }
}
void *fn_mkdirst(char *cmd){
    char *path;
    path=(char*)malloc(100*sizeof(char));
    strcpy(path,compath);
    strcat(path,"/mkdir ");
    while(cmd!=0){
        if(!strcmp(cmd,"mkdir&t")){
            cmd=strtok(0," ");
            continue;
        }
        strcat(path,cmd);
        strcat(path," ");
        cmd=strtok(0," ");
    }
    int res=system(path);
    if(res==-1){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    return NULL;
}
void fn_rm(char *cmd){
    char *argv[10];
    int idx=1;
    char path[100];
    strcpy(path,compath);
    strcat(path,"/rm");
    for(int i=0;i<10;i++){
        argv[i]=(char*)malloc(100*sizeof(char));
    }
    strcpy(argv[0],path);
    while(cmd!=0){
        if(!strcmp(cmd,"rm")){
            cmd=strtok(0," ");
            continue;
        }
        strcpy(argv[idx],cmd);
        idx++;
        cmd=strtok(0," ");
    }
    argv[idx]=NULL;
    idx++;
    pid=fork();
    if(pid<0){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    else if(pid==0){
            execl(path,path,argv[1],argv[2],NULL);
            return;
    }else{
        wait(NULL);
        return;
    }
}
void *fn_rmst(char *cmd){
    int idx=0;
    char *path;
    path=(char*)malloc(100*sizeof(char));
    strcpy(path,compath);
    strcat(path,"/rm ");
    while(cmd!=0){
        if(!strcmp(cmd,"rm&t")){
            cmd=strtok(0," ");
            continue;
        }
        strcat(path,cmd);
        strcat(path," ");
        cmd=strtok(0," ");
    }
    int res=system(path);
    if(res==-1){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    return NULL;
}
void fn_pwd(){
    char temp_path[100];
    getcwd(temp_path,sizeof(temp_path));
    puts(temp_path);
}
void fn_cat(char *cmd){
    char *argv[10];
    int idx=1;
    char path[100];
    strcpy(path,compath);
    strcat(path,"/cat");
    for(int i=0;i<10;i++){
        argv[i]=(char*)malloc(100*sizeof(char));
    }
    strcpy(argv[0],path);
    while(cmd!=0){
        if(!strcmp(cmd,"cat")){
            cmd=strtok(0," ");
            continue;
        }
        strcpy(argv[idx],cmd);
        idx++;
        cmd=strtok(0," ");
    }
    argv[idx]=NULL;
    idx++;
    pid=fork();
    if(pid<0){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    else if(pid==0){
            execl(path,path,argv[1],argv[2],NULL);
            return;
    }else{
        wait(NULL);
        return;
    }
}
void *fn_catst(char *cmd){
    int idx=0;
    char *path;
    path=(char*)malloc(100*sizeof(char));
    strcpy(path,compath);
    strcat(path,"/cat ");
    while(cmd!=0){
        if(!strcmp(cmd,"cat&t")){
            cmd=strtok(0," ");
            continue;
        }
        strcat(path,cmd);
        strcat(path," ");
        cmd=strtok(0," ");
    }
    int res=system(path);
    if(res==-1){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    return NULL;
}
void fn_date(char *cmd){
    int flag1=0;
    int flag2=0;
    char *path;
    path=(char*)malloc(100*sizeof(char));
    strcpy(path,compath);
    strcat(path,"/date");
    while(cmd!=0){
        if(!strcmp(cmd,"-u")){
            flag1=1;
        }
        else if(!strcmp(cmd,"-R")){
            flag2=1;
        }
        cmd=strtok(0," ");
    }
    if(flag1 && flag2){
        printf("Error! You cannot use 2 options at the same time!\n");
        return;
    }
    if(!(flag1 || flag2)){
        pid=fork();
        if(pid<0){
            printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
        }
        else if(pid==0){
            execl(path,path,NULL);
        }
        else{
            wait(NULL);
            return;
        }
    }
    if (flag1){
        pid=fork();
        if(pid<0){
            printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
        }
        else if(pid==0){
            execl(path,path,"-u",NULL);
            return;
        }
        else{
            wait(NULL);
            return;
        }
    }
    if (flag2){
        pid=fork();
        if(pid<0){
            printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
        }
        else if(pid==0){
            execl(path,path,"-R",NULL);
            return;
        }
        else{
            wait(NULL);
            return;
        }
    }
}
void *fn_datest(char *cmd){
    char *path;
    path=(char*)malloc(100*sizeof(char));
    strcpy(path,compath);
    strcat(path,"/date ");
    while(cmd!=0){
        if(!strcmp(cmd,"date&t")){
            cmd=strtok(0," ");
            continue;
        }
        strcat(path,cmd);
        strcat(path," ");
        cmd=strtok(0," ");
    }
    int res=system(path);
    if(res==-1){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    return NULL;
}
void fn_ls(char *cmd){
    int flag1=0;
    int flag2=0;
    int i=0;
    char *path;
    char des[100];
    path=(char*)malloc(100*sizeof(char));
    strcpy(path,compath);
    strcat(path,"/ls");
    while(cmd!=0){
        if(!strcmp(cmd,"-a")){
            flag1=1;
        }
        else if(!strcmp(cmd,"-m")){
            flag2=1;
        }
        if(i==1){
            strcpy(des,cmd);
        }else{
            strcpy(des,"a");
        }
        cmd=strtok(0," ");
        i++;
    }
    if(flag1 && flag2){
        printf("Error! You cannot use 2 options at the same time!\n");
        return;
    }
    if((!(flag1 || flag2)) && !(strcmp(des,"a"))){
        pid=fork();
        if(pid<0){
            printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
        }
        else if(pid==0){
            execl(path,path,NULL);
            return;
        }
        else{
            wait(NULL);
            return;
        }
    }
    if (flag1){
        pid=fork();
        if(pid<0){
            printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
        }
        else if(pid==0){
            execl(path,path,"-a",NULL);
            return;
        }
        else{
            wait(NULL);
            return;
        }
    }
    if (flag2){
        pid=fork();
        if(pid<0){
            printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
        }
        else if(pid==0){
            execl(path,path,des,NULL);
            return;
        }
        else{
            wait(NULL);
            return;
        }
    }else{
        pid=fork();
        if(pid<0){
            printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
        }
        else if(pid==0){
            execl(path,path,des,NULL);
            return;
        }
        else{
            wait(NULL);
            return;
        }
    }
    return;
}
void *fn_lsst(char *cmd){
    char *path;
    path=(char*)malloc(100*sizeof(char));
    strcpy(path,compath);
    strcat(path,"/ls ");
    while(cmd!=0){
        if(!strcmp(cmd,"ls&t")){
            cmd=strtok(0," ");
            continue;
        }
        strcat(path,cmd);
        strcat(path," ");
        cmd=strtok(0," ");
    }
    int res=system(path);
    if(res==-1){
        printf("Command Not Executed Properly. Kindly retype the previous Command!\n");
    }
    return NULL;
}
void fn_cd(char *cmd){
    char temp_path[10][100];
    int idx=0;
    int flag=0;
    while(cmd!=NULL){
        if(strcmp(cmd,"/")==0){
            flag=1;
            cmd=strtok(NULL," ");
            continue;
        }
        strcpy(temp_path[idx],cmd);
        idx++;
        cmd=strtok(NULL," ");
    }
    if(flag==1){
        int res=chdir("/home/");
    }
    int res=chdir(temp_path[1]);
    if(res<0 && flag!=1){
        printf("No such File or directory exists.\n");
    }
}
void fn_echo(char *cmd){
    int flag1=0;
    int flag2=0;
    char inp[1000][1000];
    int idx=0;
    while(cmd!=NULL){
        if(!strcmp(cmd,"-n")){
            flag1=1;
        }
        else if(!strcmp(cmd,"*")){
            flag2=1;
        }
        strcpy(inp[idx],cmd);
        idx++;
        cmd=strtok(NULL," ");
    }
    if(flag1 && flag2){
        printf("Error! You cannot use 2 options at the same time!\n");
        return;
    }
    if(!strcmp(inp[1],"*")){
        char path[100];
        getcwd(path,sizeof(path));
        struct dirent *d;
        DIR *dir =opendir(path);
            while((d=readdir(dir))!=NULL){
                if(d->d_name[0]!='.'){
                    printf("%s ",d->d_name);
                }
            }
        printf("\n");
        closedir(dir);
    }
    else if(!strcmp(inp[1],"-n")){
        for(int i=2;i<idx;i++){
            if(i!=idx-1){
                printf("%s ",inp[i]);
            }else{
                printf("%s",inp[i]);
            }
        }
        return;
    }else{
        for(int i=1;i<idx;i++){
            printf("%s ",inp[i]);
        }
        printf("\n");
        return;
    }
}
int main(){
    char cmdin[100];
    user=getenv("USER");
    getcwd(compath,sizeof(compath));
    strcat(entpath,user);
    strcat(entpath,"/.bash_history");
    while("true"){
        char temp_path[100];
        printf("%s@Devansh's_OS%s: ~ ",user,getcwd(temp_path,sizeof(temp_path)));
        fgets(cmdin,100,stdin);
        // FILE *f;
        // f=fopen(entpath,"a+");
        // fputs(compath,f);
        // fputs("\n",f);
        // fclose(f);
        char *Error_cmd=strtok(cmdin,"\n");
        char *cmd_split=strtok(cmdin," ");
        if(!valid(cmd_split)){
            printf("Error! '%s' command not Supported!\n",Error_cmd);
        }else{
            if(!strcmp(cmd_split,"mkdir")){
                fn_mkdir(cmd_split);
            }
            else if(!strcmp(cmd_split,"rm")){
                fn_rm(cmd_split);
            }
            else if(!strcmp(cmd_split,"cat")){
                fn_cat(cmd_split);
            }
            else if(!strcmp(cmd_split,"date")){
                fn_date(cmd_split);
            }
            else if(!strcmp(cmd_split,"ls")){
                fn_ls(cmd_split);
            }
            else if(!strcmp(cmd_split,"pwd")){
                fn_pwd();
            }
            else if(!strcmp(cmd_split,"cd")){
                fn_cd(cmd_split);
            }
            else if(!strcmp(cmd_split,"echo")){
                fn_echo(cmd_split);
            }
            else if(!strcmp(cmd_split,"pwd&t")){
                fn_pwd();
            }
            else if(!strcmp(cmd_split,"mkdir&t")){
                pthread_t p;
                int pid=pthread_create(&p,NULL,(void*)fn_mkdirst,cmd_split);
                pthread_join(p, NULL);
            }
            else if(!strcmp(cmd_split,"rm&t")){
                pthread_t p;
                int pid=pthread_create(&p,NULL,(void*)fn_rmst,cmd_split);
                pthread_join(p, NULL);
            }
            else if(!strcmp(cmd_split,"ls&t")){
                pthread_t p;
                int pid=pthread_create(&p,NULL,(void*)fn_lsst,cmd_split);
                pthread_join(p, NULL);
            }
            else if(!strcmp(cmd_split,"date&t")){
                pthread_t p;
                int pid=pthread_create(&p,NULL,(void*)fn_datest,cmd_split);
                pthread_join(p, NULL);
            }
            else if(!strcmp(cmd_split,"cat&t")){
                pthread_t p;
                int pid=pthread_create(&p,NULL,(void*)fn_catst,cmd_split);
                pthread_join(p, NULL);
            }else if(!strcmp(cmd_split,"exit")){
                break;
            }
        }
    }
    printf("Thanks for using my Shell!.\n");
    return 0;
}