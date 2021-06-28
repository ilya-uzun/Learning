#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j;
	int myArray[3][2];
	srand(time(NULL)); // time(null)- выводит время в секундах о 1970г. srand() - при перезапускает rand() если изменён аргумент

	for(i=0; i<3;i++){
		for(j=0; j<2; j++)
		{
			myArray[i][j]= rand()%10;
		}
	}
	// печать
	for(i=0; i<3;i++){
        printf("\n");
		for(j=0; j<2; j++)
		{
			printf("%d ",myArray[i][j]);
		}
	}
	printf("\n");
		
}
