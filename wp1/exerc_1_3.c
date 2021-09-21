#include <stdio.h>
#include <ctype.h>
#define MAX 100
#define ROT 13
 
int main()
{
    char M[MAX];
    char C[MAX];
    int K=ROT;
		int i;
		
    printf("Please enter a word: \n");
    gets(M);
	
		//fgets(M, (sizeof M / sizeof M [0]), stdin);
    for(i=0; M[i]!='\0'; i++)
    {
       if(M[i]>='A' && M[i]<='Z')  {
        C[i]=(M[i]-'A'+K)%26+'A'; } // works for uppercase
     else if (M[i]>='a' && M[i]<='z')
		 { C[i]=(M[i]-'a'+K)%26+'a';} // works for lowercase 
		}
    C[i]='\0';
    printf("The word after rotation is:\n%s\n",C);
    return 0;
		}

