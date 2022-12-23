#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define TWOD_COPY_SYSCALL 451

int main()
{
    float src_arr[4][4] = {{1, 2, 3, 41},{1, 2, 3, 42},{1, 2, 3, 43},{1, 2, 3, 44}};
    float dest_arr[4][4]; 
    long sys_call_status;

    sys_call_status = syscall(TWOD_COPY_SYSCALL, src_arr, dest_arr);

    if (sys_call_status != EFAULT){
        printf("Message : System Call 451 successfuly invoked \n");
        for (int i = 0; i < 4; i++){
            for(int j=0;j<4;j++){
                if(src_arr[i][j]!=dest_arr[i][j]){
                printf("%f %f lhs!=rhs at %d,%d",src_arr[i][j],dest_arr[i][j],i,j);
                return 0;
                }
            }
        }
    }
    printf("Message : Success LHS = RHS. The Destination Matrix/2D Array is as follows: \n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%f ",dest_arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
