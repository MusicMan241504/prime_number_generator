#include <stdio.h>
#include <unistd.h>
#include <string.h>
static volatile int keepRunning = 1;

int main ()
{
    /* local variable definition */
    unsigned long long int num = 2;
    unsigned long long int factor = 2;
    printf("Enter starting number: \n # ");
    scanf("%llu", &num);
    printf("Starting number: %llu\n",num);
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
            fprintf(fp, "%llu\n",num);
        }
        num++;
    }
    getchar();
}