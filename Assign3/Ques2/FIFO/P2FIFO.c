#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/un.h>
int buff_len=100;
void strprinter(char st[]){
    for(int i=1;i<6;i++){
        printf("%c",st[i]);
    }
    printf("\n");
}
int main(){
    int p1,p2;
    char buffer[buff_len];
    int midx=0;
    int cidx=0;
    int status;
    char *fifo1="FIFO1";
    char *fifo2="FIFO2";
    mkfifo(fifo1,0666);
    mkfifo(fifo2,0666);
    while(100){
        while(cidx<midx+5){
            sleep(2);
            p1=open(fifo1,O_RDONLY);
            status=read(p1,buffer,sizeof(buffer));
            close(p1);
            if(status==-1){
                printf("Error FIFO! for Process 2 Couldn't read\n");
                return 0;
            }
            cidx=buffer[0];
            strprinter(buffer);
            sprintf(buffer,"%d",cidx);
            printf("ID that has been currently received by Process 2: %d\n",cidx);
        }
        midx=cidx;
        p2=open(fifo2,O_WRONLY);
        printf("Sent\n");
        status=write(p2,buffer,sizeof(buffer));
        close(p2);
        if(midx>49){
            return 0;
        }
    }
    return 0;
}