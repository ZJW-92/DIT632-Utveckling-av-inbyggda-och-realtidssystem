/* ====================================
File name: exerc_2_6.c (or cpp)
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
#define MAX 5
// ------ Function declaration ----------
void initQue (int list [], int max );
int input (int list [] , int number, int max);
int output( int list[], int max);
void printArray(int list[], int max);
 
int main()
{
    int que [ MAX ] ;
    int input_value, input_is, output_value, input_number, output_number ;

    initQue(que, MAX);
    
    // -------------for input-----------------
    
    printf("\n enter a positive number to put in the queue ");
    scanf("%d", &input_number); // your intended input value is read

    input_is = input(que, input_number, MAX); // enter in queue

    // find out if the input was successful or not
    if(input_is == 0){
        printf("\n the queue is full");
    }else if (input_is == 1){
        printf("\n the number enterred successfully into the queue");
    }        
    // print the current array
    printf("\n the array is ----------\n");
    printArray(que, MAX);
   
    //------------- for output----------------
   
    output_number = output(que, MAX); // fetch from the queue
    
    // check if there was any number to take out, and what was it
    if(output_number == 0){
        printf("\n the queue is empty");
    }else {
        printf("\n output_number is %d \n",output_number );
    } 
    
    // print the current array
    printf("\n the array is ----------\n");
    printArray(que, MAX);
    
}

//initializes a list to initially containing max nr of vacant positions (-1).
void initQue (int list [], int max ){
    for (int i = 0; i < MAX; i++){
        list[i] = -1;
    }
}

//adds a number in the queue according to the rules , and
// return 1 if the number could be entered and 0 if the queue is full 
int input (int list [] , int number, int max){
    int i;
    if(list [max-1] != -1){ // if the array is full return 0
        return 0;
    }else{
        for ( i = max-1; i > 0; i--){
            if(list[i] == -1 && list[i-1] != -1){ // find out the first empty space
                list[i] = number;
                return 1;
            }            
        }
        list[i] = number; // if the array is all -1 (empty) this line executes
        return 1;
    }    
}

//returns the value if any to fetch or 0 if que is empty
int output( int list[], int max){
    int i;
    int output_number;
    if(list [0] == -1){ // if the array is empty return 0
        return 0;
    }else{  
        output_number = list [0]; // the first value is to be taken out
        // move all element of the array one place forward
        for ( i = 0; i < MAX-1; i++){
            list[i] = list[i+1];
        }
        list[i] = -1 ; // assign -1 at last position of the queue, after a value is taken out 
        return output_number;
    }    
}

// prints array
void printArray(int list[], int max){
     for (int i = 0; i < MAX; i++){
        printf(" %2d ", list[i]);
    }
}    