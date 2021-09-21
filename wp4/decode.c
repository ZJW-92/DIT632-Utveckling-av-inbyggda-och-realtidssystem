/* =======================================
File name: exerc_4_2.c (or cpp)
Date: 2021-02-19
Group nr 31
Members that contributeto the solutions
Zhijie Wei
Member not present at demonstration time:
Karim Abdeldayem
Demonstration code: 7EY6-WN2Y-52AQ-8AYX
==========================================*/
//include section
#include <stdio.h>
//declare a function
unsigned int hexaToInteger(const char*p);
//main program section
int main(int argc, char *argv[]) {
//*argc[0]is file path name, so total argc is two
    if(argc!=2){
        printf("There is an error, it is an invalid input!\n");
    }else{
        const char *value = argv[1]; //store 1 argument in pointer array
       //get the integer value from hexademcial to decimal 
        int intVal = hexaToInteger(value); 
        unsigned char a;  // declare a variable
        a = (1<<1)-1;   // ??????
        int engine_on = (intVal>>7)&a;  // right shift intVal 7 bits
        a=(1<<3)-1;  //????
        int gear_pos = (intVal>>4)&a; // right shift intVal 4 bits
        a=(1<<2)-1; // ????
        int key_pos = (intVal>>2)&a; // right shift intVal 2 bits
        a=(1<<1)-1; // ????
        int brake1 = (intVal>>1)&a; // right shift intVal 1 bit
        a=(1<<1)-1; // ???
        int brake2 = (intVal>>1)&a; //right shift intVal 1 bit

  // here is to deal with some error messages
        if (engine_on > 1 || engine_on < 0)
        {
            printf("Error! Engine value is out of range.\n");
            return 1;  // range of engine_on is 1 or 0
        }
        else if (gear_pos > 3 || gear_pos < 0)
        {
            printf("Error!Gear value is out of range.\n");
            return 1; // range of gear_pos is 0,1,2,3 
        }
        else if (key_pos > 2 || key_pos < 0)
        {
            printf("Error! Key value is out of range.\n");
            return 1; //range of key_pos is 0,1,2
        }
        else if (brake1 > 1 || brake1 < 0)
        {
            printf("Error! Break1 value is out of range.\n");
            return 1; //range of brake1 is 1 or 0
        }
        else if (brake2 > 1 || brake2 < 0)
        {
            printf("Error!Break2 value is out of range.\n");
            return 1; //range of brake1 is 1 or 0
        }
        else
        {  
            printf("Name        Value\n");  //print out the result
            printf("--------------------\n");
            printf("engine_on   %d\n", engine_on);
            printf("gear_pos    %d\n", gear_pos);
            printf("key_pos     %d\n", key_pos);
            printf("brake1      %d\n", brake1);
            printf("brake2      %d\n", brake2);
        }
        return 0;
    }
}

//define the function 
unsigned int hexaToInteger(const char *p){
    char hexaVal = *p; //initialize pointer variable in hexadecimal
    unsigned int val= 0;   //initialize integer in decimal 
    while (hexaVal == ' ' || hexaVal == '\t')
    {
        hexaVal = *(++p);   // pointer self plus one
    }
    while(1){
        if(hexaVal>='0'&& hexaVal<='9'){
            val = (val << 4)+(hexaVal-'0'); //change 0-9 in hexadecimal to decimal
        }else if(hexaVal>='A'&& hexaVal<='F'){
            val = (val << 4) + (hexaVal - 'A' + 10); //change A-F to 10-15 
        }else if(hexaVal>='a'&& hexaVal<='f'){
            val = (val << 4) + (hexaVal - 'a' + 10); //change a-f to 10-15
        }else{
                return val;  //get value in decimal 
        }
        hexaVal = *(++p);
    }
}
