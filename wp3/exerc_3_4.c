/*==========================================
File name: exerc_3_4.c
Date: 2021-02-11
Group nr 31
Members that contribute to the solutions 
Zhijie Wei
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> CHUY-ACRU-JTXS-ZLDM]    
===========================================*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define FILENAME "database.bin"

// -----Typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
}PERSON;

// Function declaration 
PERSON input_record(void); // Read in a person's record.
void write_new_file(PERSON *inrecord); //Creats a file and write a first record 
void printfile(void); // print out all persons in the file
void search_by_firstname(char *name);// print out person if it is in list
void append_file(PERSON *inrecord);// appends a new person to the file
void clearstdin(void);
int printMenu();
void run(int option);
void write_dummy_record();
void printFile();
void search_by_famname(char *name);

int main( void){
    PERSON ppost;
    int option = printMenu();
    run(option);
}

PERSON input_record( void){
    PERSON *person =  malloc(sizeof(PERSON)); //allocate memory dynamically
    char firstName[20];
    char lastName[20];
    char pNum[13];  //personal number string
    printf("Please enter firstname: \n");
    scanf("%s", firstName);
    strcpy(person->firstname, firstName); //use pointer person to firstname  and copy it
    printf("Your firstname is %s \n", person->firstname); 
    printf("Please enter lastname: \n");
    scanf("%s", lastName);
    strcpy(person->famname, lastName); //use pointer person to lastname and copy
    printf("Your lastname is %s \n", person->famname);
    printf("Please enter personal number: \n");
    scanf("%s", pNum);
    strcpy(person->pers_number, pNum);//use pointer person to personal number
    printf("Your person number is %s \n", person->pers_number);
    append_file(person);
    return *person;
} // Read in a person record.

void write_new_file( PERSON *inrecord){
    FILE *myFile = fopen(FILENAME, "wb"); // create file in binary mode 
    fwrite(inrecord,sizeof(PERSON),1,myFile); //write data in binary mode
    fclose(myFile);
} 

void search_by_firstname(char *name){
    FILE *myFile;
    PERSON *result = malloc(sizeof(PERSON)); // allocate memory
    myFile = fopen(FILENAME,"rb");  //open file in binary mode 
    int check=0;
    while(fread(result, sizeof(PERSON), 1, myFile)) {
        if (strcmp(name, result->firstname)==0){
            printf("First Name is: %s\nLast Name is: %s\nPersonal Number is: %s\n ", result->firstname, result->famname,
                   result->pers_number);
            check=1; //compare if the person record exists in list
        }
    }
    if(check==0){
        printf("This person does not exist.\n");
    }
}// print out person record if it is in list

// same way as searching by firstname
void search_by_famname(char *name){
    FILE *myFile;
    PERSON *result = malloc(sizeof(PERSON));
    myFile = fopen(FILENAME,"rb");
    int check=0;
    while(fread(result, sizeof(PERSON), 1, myFile)) {
        if (strcmp(name, result->famname)==0){
            printf("First Name is: %s\nLast Name is: %s\nPersonal Number is: %s\n ", result->firstname, result->famname,
                   result->pers_number);
            check=1;
        }
    }
    if(check==0){
        printf("This person does not exist.\n");
    }
} 

void append_file(PERSON *inrecord){
    FILE *myFile = fopen(FILENAME,"ab"); // append a new person record to the file
    fwrite(inrecord, sizeof(PERSON),1,myFile);
    fclose(myFile);
}
int printMenu(){
    int option;
    do{printf("Please give an option:\n"
              "1 Create a new and delete the old file.\n"
              "2 Add a new person to the file.\n"
              "3 Search for a person in the file .\n"
              "4 Print out all in the file.\n"
              "5 Exit the program.\n");
    fflush((stdin));  //clear file cache
    scanf("%d",&option); // read user option
    }while(option != 1 && option != 2 && option != 3 && option != 4 && option != 5); 
    return option;
}
void clearstdin(){
    while(getchar() != '\n' && getchar() != EOF){
        ;
    }
}
//write a dummy record
void write_dummy_record(){
    PERSON *inrecord = malloc(sizeof(PERSON));
    strncpy(inrecord->firstname,"Zhijie", sizeof(inrecord->firstname));
    strncpy(inrecord->famname,"Wei", sizeof(inrecord->famname));
    strncpy(inrecord->pers_number,"199202014438", sizeof(inrecord->pers_number));
    write_new_file(inrecord);  
}

void printFile(){
    FILE *myFile = fopen(FILENAME, "r"); //open file
    PERSON person;
    while(fread(&person, sizeof(PERSON), 1, myFile))
        printf ("%s %s %s\n", person.firstname, person.famname,person.pers_number);
    fclose (myFile);
}

 void run(int option){
    int choice;
     switch (option){
         case 1:
             write_dummy_record();
             printf("A new Database has created.\n");
             choice=printMenu();
             clearstdin();
             run(choice);
         case 2:
             input_record();
             choice=printMenu();
             clearstdin();
             run(choice);
         case 3:
             printf("Do you want to search by 1.first name or 2.family name?: \n");
             int searchChoice;
             scanf("%d", &searchChoice);
             if (searchChoice == 1){
                 printf("Please enter a first name to search: \n");
                 char name[20];
                 scanf("%s", name);
                 search_by_firstname(name);
             } else if (searchChoice == 2){
                 printf("Please enter a family name to search: \n");
                 char name[20];
                 scanf("%s", name);
                 search_by_famname(name);
             } else{
                 printf("This person does not exist! Please enter a new name!\n");
             }
             choice=printMenu();
             clearstdin();
             run(choice);
         case 4:
             printFile();
             choice=printMenu();
             clearstdin();
             run(choice);
         case 5:
             exit(0);
         default:
             break;
     }
 }
