#include<stdio.h>
int num;
int main()
{  
	for( num=1; num<7; num++) {
	printf("enter a number between 1 to 5: ");
  scanf("%d",&num);
	
	switch(num) {
		case 1: printf("the number you input is %d \n",num);
		break;
		case 2: printf("the number you input is %d \n",num);
		break;
		case 3: printf("the number you input is %d \n",num);
		break;
		case 4: printf("the number you input is %d \n",num);
		break;
		case 5: printf("the number you input is %d \n",num);
		break; 
		default: printf("Wrong \n");	
	}
  } 
}