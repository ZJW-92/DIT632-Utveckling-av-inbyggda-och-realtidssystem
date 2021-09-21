/* ====================================
File name: exerc_2_7.c (or cpp)
Date: 2021-02-04
Group nr 031
Members that contribute to the solutions
Syeda Elham Shahed
Member not present at demonstration time:
All present
reference used in this code : https://en.wikipedia.org/wiki/Personal_identity_number_(Sweden)
Demonstration code: [<Ass code 1-8> CD4Y-8YYA-N5XM-FR3H] 
====================================== */

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 10

// ------ Function declaration ----------
void clearstdin(void);

void main()  
{ 
    char c, *ptr;
    int n = 0 , calc , year, month, day, number, last_digit;
    int year_modulo, month_modulo, day_modulo, number_modulo;
    int temp_sum, sum = 0, temp_digit1, temp_digit2;
    long long person_number;
    char personNumber[MAX];

    while ( c != 'q'  ){ // untill q is pressed the programm should take input
        printf("\n enter  a person number ");
        fgets( personNumber, MAX+1,stdin); // read the person number
       
        c = personNumber[0]; // to keep track if q is pressed

        // if q is pressed need to quit the program
        if(c == 'q'){
            break;
        }        
        person_number = atoll(personNumber); // convert string person number to integer 

        // calculate year
        year = person_number/pow(10, 8);  // first two digit 
        year_modulo = person_number % (int) pow(10, 8); // to get last 8 digit

        // calculate month
        month = year_modulo /pow(10, 6);  // 3rd and 4th digit
        month_modulo =   year_modulo % (int) pow(10, 6); // to get last 6 digit

        // calculate day
        day = month_modulo/pow(10,4);  //5th and 6th digit
        day_modulo = month_modulo % (int) pow(10, 4);  // to get last 4 digit

        // calculate  number
        number = day_modulo/pow(10, 1);  //7,8,9 th digit

        // calculate last digit 
        last_digit = day_modulo % (int) pow(10, 1); // to get last  digit

        // check if month , day in correct range 
        if((month > 12 || month < 1) || (day > 31 || day < 1) ){
            printf("wrong month/ day in the person number");
        }else{  

             //check last digit (control digit)
            for (int j = 0 ; j < MAX-1 ; j++){

                calc =  personNumber[j] - '0'; // to convert char to integer

                if(j%2 == 0){ // this if statement tests if the array item is in even position so that,
                              // it could be multiplied by 2
                    temp_sum = calc*2;
                    // if the temp_sum is a two digit number we need to add the two digit
                    if (temp_sum > 9){ 
                        temp_digit1 = temp_sum/10;
                        temp_digit2 = temp_sum%10;
                        temp_sum = temp_digit1 + temp_digit2;
                    }          
                    
                }else { 
                    temp_sum = calc;
                }

                sum = sum + temp_sum; // adding first 9 digits (after multiplying each by 212121-212 respectivly) of person number
            }

            // subtracting the last digit of the sum 
            // from 10 to compare with last digit of person number,
            //if doesn't match then the person number is wrong
            if(last_digit != (10 - (sum%10))){  
                printf("\n wrong person number");
            }else{
                printf("\n correct person number");
            }
        }    
        clearstdin();
    }
    
}    

// -------Clear buffer------
void clearstdin(void){
    char temp;
    while((temp=getchar()) !='\n');
}
//----------------------------------
