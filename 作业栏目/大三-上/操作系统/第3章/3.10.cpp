#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/wait.h>
#define SIZE 5


int nums[SIZE] = {0, 1, 2, 3, 4};

int main(int argc,char **argv)
{
    int i;
    pid_t pid;

    pid = fork();
    if(pid == 0)
    {
        for(i = 0; i < SIZE; i++)
        {
            nums[i] *= -i;
            printf("CHILD: %d", nums[i]);/*LINE X*/
        }
    }
    else if(pid > 0)
    {
        wait(NULL);
        for(i = 0; i < SIZE; i++) 
            printf("PARENT: %d", nums[i]);/*LINE Y*/
    }
}
