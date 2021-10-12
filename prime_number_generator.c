#include <stdio.h>
#include <unistd.h>
#include <string.h>
static volatile int keepRunning = 1;

int main ()
{
    /* local variable definition */
    int num = 2;
    int factor = 2;
    char cwd[256];
    FILE *fp;
    getcwd(cwd, sizeof(cwd));
    fp = fopen(strcat(cwd , "/primes.txt"), "w+");

    while(keepRunning) {
        for(factor=2; factor <= (num/factor); factor++){
            if(!(num%factor)){
                break;
            }
        }
        if(factor > (num/factor)){
            fprintf(fp, "%d\n",num);
        }
        num++;
    }
    getchar();
}