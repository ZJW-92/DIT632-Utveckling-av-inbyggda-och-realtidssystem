/* ===================================
File name: exerc_2_5.c (or cpp)
Date: 2021-02-04
Group nr 031
Members that contribute to the solutions
Syeda Elham Shahed
Karim Abdeldayem
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> CD4Y-8YYA-N5XM-FR3H] 
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MAXNUMBER 20

// ------ Function declaration ----------
void create_random( int *tab ); // Use pointer to fill the table
void count_frequency(int *tab, int *freq ); // Use pointer
void draw_histogram(int *freq ); // Use pointer

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main ( void){
    int table[MAX], n ;
    int frequency[MAXNUMBER];
    create_random(table); // to create a random array
    qsort(table, MAX, sizeof(int), cmpfunc); // sorting the array 
    
    count_frequency(table, frequency); // populating frequency array by counting frequencies by which 
                                       //each number appeared in array table 
   
    draw_histogram(frequency); 
}

//create a random array
void create_random( int *tab ){
    srand(time(0));
    for (int i = 0 ; i< MAX; i++){
        *tab = rand() % MAXNUMBER;
        tab++;
    }
}

// populating frequency array by counting frequencies by which each number appeared in array table 
void count_frequency(int *tab, int *freq ){
    int count = 0;
    int i = 0;
    for (int j = 0 ; j < MAXNUMBER; j++){ // loop for counting frequencies using j value
        for (; i< MAX; i++){ // loop for array tab

            // check how many times each value of tab occurred  
            if(*tab == j){
                count++;
            }            
            else{                
                break;
            }             
            tab++;         
        }
        *freq = count; // populating freq with how many times  each number, that is equal to j, occurred 
        freq++;                
        count = 0; // initializing count for counting frequecy for the next item in tab 
    }

}

// draw histogram
void draw_histogram(int *freq ){

    for (int i = 0 ; i< MAXNUMBER; i++){
            //check if a number between 1 to MAXNUMBER occurred at all, if not, then o histogram is printed 
            if(*freq != 0){ 
                 printf("\n the array using pointer : %-3d",  i);

                // loop for drawing histogram 
                for(int j = 0; j < *freq ; j++ ){
                    printf("x");
            }    
        }
        freq++;
    }

}