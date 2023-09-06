#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
static volatile int keepRunning = 1;

int main ()
{
    /* local variable definition */
    unsigned long long int num = 2;
    unsigned long long int factor = 2;
    double decimal_number= 2;
    const int power;

    const int standard_form;
    printf("Do you want to enter starting number in standard form: (1,0)\n # ");
    scanf("%d", &standard_form);
    if(standard_form == 1){
        printf("Enter decimal: \n # ");
        scanf("%lf", &decimal_number);
        printf("Enter power: \n # ");
        scanf("%d", &power);
        num = pow(10.0,power)*decimal_number;
    }else{
        printf("Enter starting number: \n # ");
        scanf("%llu", &num);
    }
    printf("Starting number: %llu\n",num);

    const int print;
    printf("Do you want to print each each number(2) each prime number(1) or nothing(0): (2/1/0)\n # ");
    scanf("%d", &print);

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
            if(print == 1 || print == 2){
                printf("    Prime:  %llu\n",num);
            }
        }else{
            if(print == 2){
                printf("%llu\n",num);
            }
        }
        num++;
    }
    getchar();
}