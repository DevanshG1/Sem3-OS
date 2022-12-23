#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/un.h>
typedef long long int ll;
float denom=1e9;
struct timespec start,finish;
int Buff_len=100;
void randstrgenerator(char randstr[51][6]){
    srand(time(NULL));
    for(int k=1;k<51;k++){
        randstr[k][0]=k;
    }
    for(int i=1;i<51;i++){
        for(int j=1;j<6;j++){
            randstr[i][j]=rand()%26 +65;
        }
    }
}
void strprinter(char st[]){
    for(int i=1;i<6;i++){
        printf("%c",st[i]);
    }
    printf("\n");
}
void error_check(int status,int flag){
    if(status==-1){
        if(flag==0){
            printf("Error!! Couldn't Access THe First FIFO(FIFO1)\n");
        }
        else if(flag==1){
            printf("Error! Couldn't write to FIFO!\n");
        }else if(flag==2){
            printf("Error! Couldn't read from FIFO!\n");
        }
        exit(1);
    }
}
int main(){
        clock_gettime(CLOCK_REALTIME,&start);
        int p1,p2;
        char buffer[Buff_len];
        char *fifo1="FIFO1";
        char *fifo2="FIFO2";
        char randstr[51][6]={{-1}};
        int fin_idx=1;
        int status;
        int temp_idx;
        randstrgenerator(randstr);
        for(int i=1;i<51;i++){
            printf("%d ",randstr[i][0]);
            strprinter(randstr[i]);
        }
        printf("The Strings printed above have been randomly generated!\n");
        mkfifo(fifo1,0666);
        mkfifo(fifo2,0666);
        while(100){
            error_check(p1,0);
            printf("Connection with FIFO1 has been established.Sending Strings from %d to %d to Process P2;\n",fin_idx,fin_idx+4);
            for(int i=fin_idx;i<fin_idx+5;i++){
                p1=open(fifo1,O_WRONLY);
                status=write(p1,randstr[i],sizeof(randstr[i])+1);
                error_check(status,1);
                sleep(1);
                close(p1);
            }
            p2=open(fifo2,O_RDONLY);
            status=read(p2,buffer,sizeof(buffer));
            close(p2);
            error_check(status,2);
            temp_idx=atoi(buffer);
            printf("Max ID sent by Process 2: %d!\n",temp_idx);
            fin_idx=temp_idx+1;
            if(fin_idx>49){
                break;
            }
        }
        clock_gettime(CLOCK_REALTIME,&finish);
        float timetaken= (finish.tv_sec - start.tv_sec)+((finish.tv_nsec - start.tv_nsec)/denom);
        printf("TIme taken by FIFO to accomplish the task is: %f\n",timetaken);
        return 0;
}