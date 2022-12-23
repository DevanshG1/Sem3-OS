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
float denom=1e9;
void randstrgenerator(char randstr[][6]){
   srand(time(NULL));
    for(int i=0;i<50;i++){
        for(int j=0;j<5;j++){
            randstr[i][j]=rand()%26 +65;
        }
        randstr[i][5]='\0';
    }
}
void strprinter(char st[]){
    for(int i=0;i<5;i++){
        printf("%c",st[i]);
    }
    printf("\n");
}
int main(){
    struct timespec start,finish;
    clock_gettime(CLOCK_REALTIME,&start);
    char *shm;
    int shm_id;
    char randstr[51][6];
    shm_id=shmget((key_t)2345,1024,0666|IPC_CREAT);
    shm=(char*)shmat(shm_id,NULL,0);
    randstrgenerator(randstr);
    for(int i=0;i<50;i++){
            strprinter(randstr[i]);
    }
    printf("The Above Strings have been Randomly Generated!\n");
    for(int i=0;i<50;){
        for(int j=0;j<5;j++){
            strcpy(shm,randstr[i+j]);
            while(*shm!=-1);
        }
        printf("Max ID sent by Process 2: %d\n",i+5);
        i+=5;
    }
    clock_gettime(CLOCK_REALTIME,&finish);
    float timetaken= (finish.tv_sec - start.tv_sec)+((finish.tv_nsec - start.tv_nsec)/denom);
    printf("TIme taken by Shared Memory to accomplish the task is: %f\n",timetaken);
    return 0;
}