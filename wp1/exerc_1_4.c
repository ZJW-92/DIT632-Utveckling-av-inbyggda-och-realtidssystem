#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess() 
{
	 int input = 0; 
   int tmp;
	 tmp = rand()%100+1; //to generate a number randomly
	 while(1)
	 {
		printf("Please guess a number between 1 to 100:");
		scanf("%d", &input);
        if (input==tmp)
		{
			printf("Congratulations! You guess right! \n");
			break;
		}
		else if (input>=tmp)
		{
      printf("The number is too big!\n");
		}
		else if (input<=tmp)
		{
      printf("The number is too small!\n");
		}
 
	 }
} 
int main () {
	int i =0 ;
	srand((unsigned int)time(NULL)); 
	guess(); 
}