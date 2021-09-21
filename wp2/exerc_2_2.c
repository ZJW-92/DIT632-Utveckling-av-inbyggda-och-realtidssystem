/*=============================
File name: exerc_2_2.c
Date: 2020-02-04
Group nr 31
Members that contribute to the solutions
Syeda Elham Shahed  
Zhijie Wei
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> CD4Y-8YYA-N5XM-FR3H]      
================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 99

int main ()
{ 
int arr[MAX], num;
srand((unsigned)time(NULL)); // initialize a random number
for(int i= 0; i<MAX;i++) {
	num = rand()%100;  //generate random integer 1-99
	arr[i]= num; 
}
printf("The value of the label array (address) is: %p\n", &arr);
printf("First integer in the array is (array[0]): %d\n",arr[0]);
printf("The size of an integer (number of bytes) is:%d\n",sizeof arr[0]);
printf("The size of the whole array is:%d\n",sizeof(arr)/sizeof(arr[0]));
//print out each integer using pointer 
int *p = arr;
for(int i=0; i<MAX; i++) {
	printf("arr[%d]=%d\n",i,*(p+i));
	// convert integer to double value 
	printf("arr[%d]=%f\n",i,(double)*(p+i));
}
return 0;
}