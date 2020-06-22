#include <stdio.h> 
int main ()
{
    int num;
    printf("\nEnter number");
    scanf("%d", &num);
    int half = num/2;
    int div = 2;
    while (div < half)
    {
        if (!(num % div)) printf("\ndiv=%d", div);
        div++;
    }
return 0;
}