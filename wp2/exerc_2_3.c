/* ====================================
File name: exerc_2_3.c (or cpp)
Date: 2021-02-04
Group nr 031
Members that contribute to the solutions
Syeda Elham Shahed
Zhijie Wei 
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> CD4Y-8YYA-N5XM-FR3H] 
====================================== */
#include<stdio.h>
#include<string.h>
// ------ Function declaration ----------
int stringcompare( const char* str1, const char* str2);
int main(int argc, char **argv){
    if (argc < 2) // no arguments were passed
    {
        printf("\n no text enterred");
    }else if (argc == 3) { // exactly two string was passed

        // checks two strings are same or not   
        if (strcmp(argv[2], argv[1]) == 0)  
        {
            printf("\n (using strcmp) exactly two identical word enterred");
        }
        else
        {
            printf("\n (using strcmp) two words are not identical");
        }
				
        // checks two strings are same or not
        if (stringcompare(argv[2], argv[1]) == 1) 
        {
            printf("\n (using strcompare) exactly two identical word enterred");
        }
        else
        {
            printf("\n (using strcompare) two words are not identical");
        }
        
    }else{ // more then two string or only one string was passed
        printf("\n more then two words enterred");
    }
}

int stringcompare( const char* str1, const char* str2){
    // Returns 1 if enterred strings are equal, else 0
    while(( *str1 == *str2 ) && *str1 !='\0'){ // checking if input strings are same
        str1++;
        str2++;
    }
    if(*str1 == *str2){ 
        return(1) ;
    } else
        return(0);
}