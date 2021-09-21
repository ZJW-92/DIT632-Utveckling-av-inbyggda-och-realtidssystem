/*===========================================
File name: exerc_2_1.c
Date: 2020-02-04
Group nr 31
Members that contribute to the solutions
Syeda Elham Shahed  
Zhijie Wei
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> CD4Y-8YYA-N5XM-FR3H]    
===================================================*/

#include <stdio.h>
#include <string.h>
#define MAX 20

 // declare copyString method with two arguments 
void copyString(char *str, char *str_copy) { 
 int i = 0;
 for( i =0; str[i]!=0;i ++) {
	 str_copy[i] = str[i];    
 }
 str_copy[i] = '\0' ;    // end array with \0
 printf("this is without using strcpy:%s\n",str_copy);
}

int main ()
{ 
	char str[MAX], str1[MAX],str_copy[MAX],str2[MAX]; //declare arrays 
	printf("Please enter no more than 20 characters: ");
	fgets(str,MAX,stdin); //get string
  strcpy (str1,str); // copy string using strcpy
  printf ("this is what copied characters by using strcpy:%s\n",str1);
	copyString(str, str_copy); //use copy string method
	FILE *fpRead=fopen("myfile.txt","r"); // point to myfile.txt
	fgets(str2, MAX, fpRead);  //retrieve first 20 char
	printf("this is what writes in the text file: %s\n",str2);
	return 0;
}