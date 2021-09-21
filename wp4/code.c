/* =========================================
File name: exerc_4_1.c (or cpp)
Date: 2021-02-19
Group nr 31
Members that contributeto the solutions
Zhijie Wei
Member not present at demonstration time:
Karim Abdeldayem
Demonstration code:  7EY6-WN2Y-52AQ-8AYX
=========================================== */
//incluede section
#include <stdio.h>
#include <stdlib.h>
//main program section
int main(int argc, char *argv[]) {
// variable declarations
    unsigned char a =0;
    char engine_on; //declare 5 arguments
    char gear_pos;
    char key_pos;
    char brake1;
    char brake2;
//*argc[0]is file path name, so total argc is from 0-5 that is 6 
    if(argc!=6){
        printf("There is an error, it is an invalid input!\n");
    }else{
//store 5 arguments in the pointer array
        engine_on=*argv[1];
        gear_pos=*argv[2];
        key_pos=*argv[3];
        brake1=*argv[4];
        brake2=*argv[5];
   //here is to deal with some error messages
        if(engine_on != '1' && engine_on != '0')
        {
            printf("There is an incorrect value in engine_on.\n");
            return(0); // range of engine_on is 1 or 0
        }
        else if(gear_pos < '0' || gear_pos > '4')
        {
            printf("There is an incorrect value in gear_pos.\n");
            return(0); // range of gear_pos is 0,1,2,3,4
        }
        else if(key_pos < '0' || key_pos > '2')
        {
            printf("There is an incorrect value in key_pos.\n");
            return(0); //range of key_pos is 0,1,2
        }
        else if(brake1 != '1' && brake1!= '0')
        {
            printf("There is an incorrect value in brake1.\n");
            return(0); //range of brake1 is 1 or 0
        }
        else if(brake2 != '1' && brake2 != '0')
        {
            printf("There is an incorrect value in brake2.\n");
            return(0); //range of brake2 is same with brake1
        }
  
        a += engine_on-'0';  //get numeric value of engine_on
        a = a << 3;   // left shift three bits for gear_pos
        a += gear_pos-'0';  // get numeric value of gear_pos
        a = a << 2;  // left shift two bits for key_pos
        a += key_pos-'0';  // get numeric value of key_pos
        a = a << 1;   //left shift one bit for brake1
        a += brake1-'0'; //get numeric value of brake1
        a = a << 1;  //left shift one bit for brake2
        a += brake2 -'0'; //get numeric value of brake2
        printf("%X\n",a); //print unsigned char a in hexadecimal form
    }
}

