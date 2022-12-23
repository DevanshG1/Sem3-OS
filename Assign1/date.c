#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
char *month(int n){
    if(n==0){
        return "Jan";
    }
    else if(n==1){
        return "Feb";
    }
    else if(n==2){
        return "Mar";
    }
    else if(n==3){
        return "Apr";
    }
    else if(n==4){
        return "May";
    }
    else if(n==5){
        return "Jun";
    }
    else if(n==6){
        return "Jul";
    }
    else if(n==7){
        return "Aug";
    }
    else if(n==8){
        return "Sep";
    }
    else if(n==9){
        return "Oct";
    }
    else if(n==10){
        return "Nov";
    }
    else if(n==11){
        return "Dec";
    }
    return "a";
}
char *day(int n){
    if(n==0){
        return "Sun";
    }
    else if(n==1){
        return "Mon";
    }
    else if(n==2){
        return "Tue";
    }
    else if(n==3){
        return "Wed";
    }
    else if(n==4){
        return "Thu";
    }
    else if(n==5){
        return "Fri";
    }
    else if(n==6){
        return "Sat";
    }
    return "b";
}
int main(int argc,char *argv[], char *envp[]){
    time_t time1;
    time1=time(NULL);
    struct tm *rn=localtime(&time1);
    if(argv[1]!=NULL){
        if(!strcmp(argv[1],"-R")){
        printf("%s, %s %d %02d:%02d:%02d IST %d +0530 \n",day(rn->tm_wday),month(rn->tm_mon),rn->tm_mday,rn->tm_hour,rn->tm_min,rn->tm_sec,1900+rn->tm_year);
        return 0;
    }
    if(!strcmp(argv[1],"-u")){
        rn=gmtime(&time1);
        printf("%s, %s %d %02d:%02d:%02d UTC %d\n",day(rn->tm_wday),month(rn->tm_mon),rn->tm_mday,rn->tm_hour,rn->tm_min,rn->tm_sec,1900+rn->tm_year);
        return 0;
    }
    }
    printf("%s, %s %d %02d:%02d:%02d IST %d\n",day(rn->tm_wday),month(rn->tm_mon),rn->tm_mday,rn->tm_hour,rn->tm_min,rn->tm_sec,1900+rn->tm_year);
    return 0;
}