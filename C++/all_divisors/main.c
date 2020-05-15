#include <stdio.h> 
int main ()
{
    int num;
    printf("\nEnter number");
    scanf(num);
    int half = num/2;
    int div = 2;
    while (div < half)
    {/* condition */
        if (!(num % div)) printf("\n div");
        div++;
    }
return 0;
}