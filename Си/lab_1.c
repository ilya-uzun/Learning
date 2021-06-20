#include <stdio.h> 
#include <stdlib.h>

int enterIntControl(void);
sum (int *n, int *m, int *s);

int main(){
    int n = 0, m = 0, s = 0 ;
    printf("Enter n and m \n");
    n = enterIntControl(); 
    m = enterIntControl();                        
    sum(&n, &m, &s);
    printf("summa %d \n", s);
    return 0;
}

sum (int *n, int *m, int *s){
   // первый интервал
   for (int i = 0; i < *n; i++) (*s)++;
   // второй интервал
   if (*n = *s) for (int j=0; j < *m; j++) (*s)++;
}

int enterIntControl(void)
{
    int input;
    while (scanf("%d",&input)==0)
    {
          printf("Enter the number \n");
          while (getchar()!='\n')
          continue;
    }
return input;
}
