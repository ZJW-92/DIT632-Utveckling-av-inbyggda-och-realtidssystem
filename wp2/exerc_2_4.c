/*==========================================
File name:exerc_2_4.c
Date: 2020-02-04
Group nr 31
Members that contribute to the solutions
Syeda Elham Shahed  
Zhijie Wei
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> CD4Y-8YYA-N5XM-FR3H]   
=============================================*/

#include <stdio.h>
#include <string.h>
#define MAX 100

void main(){
    char s[MAX];   
    int i, j, n; 
    printf("Please enter a string：");
		gets(s);
    n=strlen(s); // calculate actual length of the array
		// to campare if the first character equal with the last, then compare the second with the seconde last etc. 
    for(i=0,j=n-1;i<j;i++,j--)
        if(s[i]!=s[j]) break; //the first doesn't equal to the last
        if(i>=j)
            printf("The string is palindrome. \n");
        else
            printf("The string is not palindrome. \n");
}