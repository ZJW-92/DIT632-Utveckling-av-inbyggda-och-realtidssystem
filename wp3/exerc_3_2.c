/*===========================================
File name: exerc_3_2.c
Date: 2021-02-11
Group nr 31
Members that contribute to the solutions 
Zhijie Wei
Karim Abdeldayem
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> ]    
===========================================*/
#include <stdio.h>
#include <string.h>

int search_number(int number, int tab[], int size);
void sort(int number, int tab[]);
void print(int tab[],int size);

int main(){
    int test[] = {1,2,34,5,67,3,23,12,13,10};
		int findNum;
		printf("enter a integer: ");
		scanf("%d", &findNum);
    // int findNum = 2; // given integer for example 2
    int size = sizeof(test)/ sizeof(test[0]);
   // print(test,size); // before sorted
    int position = search_number(findNum, test, size);
    printf("The given integer is in position:%d \n",position);
    sort(size, test);
    print(test,size); //after sorted
}

int search_number(int number, int tab[], int size){
    int position= -1;  //assume integer does not exist
    for(int i=0;i< size ;i++){
        if(tab[i]==number){
            position = i+1; // give index i to position if they are equal    
            break;
        }
    }
    return position;
}

// swap two integers function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int number, int tab[]){
    int i, j;  //declare two variables
    for (i = 0; i < number-1; i++){  // find minimum value in first loop
        for (j = 0; j < number-i-1; j++){
            if (tab[j] > tab[j+1])   //compare adjacent two values inside loop
                swap(&tab[j], &tab[j+1]); //swap these two if the first is bigger
        }
    }
}
void print(int tab[],int size){
    printf("After sorted:");
	  for (int i = 0; i < size ; i++)
        printf("%d ", tab[i]);
        printf("\n");
}