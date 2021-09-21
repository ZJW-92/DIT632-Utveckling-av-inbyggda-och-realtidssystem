/* ====================================
File name: exerc_6_3.c (or cpp)
Date: 2021-03-09
Group nr 031
Members that contribute to the solutions
Syeda Elham Shahed
Zhijie Wei 
Member not present at demonstration time:
Karim Abdeldayem
Demonstration code: MAS7-HD6U-HSQN-CTWS
====================================== */

// Include section
#include <stdio.h>
#include <errno.h>      // library containing error codes
#include <stdlib.h>
#include <string.h>
#include <process.h>        // this library is important as it containts threads and process handling
#include <windows.h>        // library that provides access to Win32 API, important for the threads management


/*
#define PORTA 0x0400 // IN port
#define PORTB 0x0402 // OUT port
*/
#define ML13_Status 0x0B10
#define ML13_Control 0x0B00

//unsigned char in, out ; // usually unsigned type when IO values
//unsigned char sensorValue, controlValue;  // to read the status of the door

// initialize ponters to hold the pointer to inportA-IN port address and outportB- OUT port address variable
unsigned char *inportA = NULL;  
unsigned char *outportB = NULL; 


// ----------------------------------------The main Function----------------------------------
void main () {

    *outportB = *outportB|00000010;// initially the door is closed the 0 bit is 1 that is why

    // this loop will ensure contiuous reading of the status of the door
    while (1){
        
        inportA = ML13_Status;// Pointer to the IN port address
        outportB = ML13_Control;// Pointer to the OUT port address
        HANDLE  hThread1,
            hThread2; 
        
        // If someone at the door and the door is closed need to open the door
        if(someoneAtDoor(*inportA) && close(*inportA)){ 
            // open the door
           openDoor();
           
        }

        //If the door is openning already this if statement will be true  we wait and do nothing
        if(openning(*inportA)){
            //do nothing until the door is open
            while (!open(*inportA)){ 
            }
            
        }
        // if the door is open this if statement will be true 
        if(open(*inportA)){
            // if the door is open make delay for 10 sec
            delay();
           
            // close the door after delay
            closeDoor();
        }
        ////If the door is closing already this if statement will be true
        if(closing(*inportA)){
            // when we are closing we have to keep on checking with a while loop if someone at the door
            // and if no one is at the door loop is not executed and we get out of this if doing nothing 
            while (someoneAtDoor(*inportA)){ 
                // open the door 
                openDoor();
                //do nothing until the door is open
                while (!open(*inportA)){ 
                }
            }           
        }

    }
}

// this function reads the In portA and return 1 if the door state is open
unsigned char open(unsigned char status) {

    return (status>>4) & 1;
}

// this function reads the In portA and return 1 if the door state is close
unsigned char close(unsigned char status) {

    return (status>>5) & 1;
}
// this function reads the In portA and return 1 if the door state is openning
unsigned char openning(unsigned char status) {

    return (status>>6) & 1;
}

// this function reads the In portA and return 1 if the door state is closing
unsigned char closing(unsigned char status) {

    return (status>>7) & 1;
}

// this function reads the In portA and return 1 if the door state is some one at the door
unsigned char someoneAtDoor(unsigned char status) {

    return (status>>3) & 1;
}

// This function set the outport portB to make the door open 

void openDoor(){
// check is already open or openning and than
// change vlaue for open door
    if(!openning(*inportA) && !open(*inportA)){
        *outportB = *outportB|00000001;  // write in outport  PORTB  bit 0 with value 1.
        *outportB = *outportB|00000000; //clear bit
    }
    
}

//  close the door
void closeDoor(){
    // check is already closed and than
    // change vlaue for close door
    if(!close(*inportA)){
        *outportB = *outportB|00000010; // write in outport  in bit 1 with value 1.
        *outportB = *outportB|00000000; //clear bit
    }

}

//delay(TIME)
void delay(){
    // simple for loop that has 10000 iteration which will make a delay of 10 seconds == 10000 miliseconds
    for (int i = 0; i < 10000; i++)
    {
        //if sensor is activated that is someone at the door, restart delay by setting the iteration initial value to 0
        if (someoneAtDoor(*inportA))
        {
            i = 0; 
        }
    }
}    