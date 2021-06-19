#include <stdio.h> 

sum (int *n, int *m, int *s){
   // первый интервал
   for (int i = 0; i < *n; i++) (*s)++;
   // второй интервал
   if (*n = *s) for (int j=0; j < *m; j++) (*s)++;
}

int main(){
    int n = 0, m = 0, s = 0 ;
    printf("Enter n and m \n");
    scanf("%d", &n);
    scanf("%d", &m);
    sum(&n, &m, &s);
    printf("summa %d \n", s);
    return 0;
}

