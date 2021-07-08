#include <stdio.h>
#include <signal.h>
static volatile int keepRunning = 1;

void intHandler(int dummy) {
    keepRunning = 0;
}
int main ()
{
    /* local variable definition */
    int num = 2;
    int factor = 2;
    FILE *fp;
    fp = fopen("C:/Users/Isaac/Documents/Coding/c/prime_number_generator/primes.txt", "w+");

    signal(SIGINT, intHandler);
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