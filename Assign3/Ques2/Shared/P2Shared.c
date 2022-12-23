#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>  
#include <stdbool.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
void strprinter(char st[]){
    for(int i=0;i<5;i++){
        printf("%c",st[i]);
    }
    printf("\n");
}
int main(){
    char *shm;
    int shm_id;
    char buff[6];
    shm_id=shmget((key_t)2345,1024,0666|IPC_CREAT);
    shm=(char*)shmat(shm_id,NULL,0);
    for(int i=0;i<50;i+=5){
        for(int j=0;j<5;j++){
            while(*shm==-1)
            printf("ID sent by Process 1: %d\n",i+j);
            printf("String sent by Process 1: ");
            strprinter(shm);
            *shm=-1;
        }        
    }
    return 0;
}