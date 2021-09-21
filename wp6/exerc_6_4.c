/* ====================================
File name: exerc_6_4.c (or cpp)
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
#include <stdlib.h>
#include <process.h>        // this library is important as it containts threads and process handling
#include <windows.h>        // library that provides access to Win32 API, important for the threads management
#include <sys/time.h>       // library that take care of the time functions


// ------ Function declaration ----------
double get_time_ms();

// global variable declarations
int program_time = 0; // The global time, start value 0

// ----------------------- Thread functions --------------------------------------------

// the following thread is responsible for increasing program_time every second
void *time_count() {

    // Check system-time ( get_time_ms())   
    // start_time is initialized with  the starting time  of the execution of the thread
    double start_time = get_time_ms();
    while (program_time < 50) { // program time has to be less than 50
        
        double current_time = get_time_ms(); // current_time is initialized with a the current time that 
                                            //is supposed to differ from start time at this line excution
        // Increase program_time by one every second. 
        if((current_time - start_time) >= 1000){ // check if 1 second has passed 
                                                //(1000 ms = 1 second). since the get_time_ms returns time in milisecond 
            
            program_time += 1 ; // Increase program_time by one every second. 
            start_time = get_time_ms(); // start time is reinitialized with a new start time for the next second
        }
     
    }
    // exit thread;
    _endthread();
} 
//End------------------------------------

// the following thread reads inport every 5 second

void *read_inport(){
    double sec =  5; // initializing variable sec with 5 which will be used to keep track of every 5 second count
    while (program_time < 50){ // program time has to be less than 50
    // Read Inport every 5 second.    ( Simulated this just by print out a text : Reading Inport now)

        if(program_time > sec ){ 

            printf(" Reading Inport now\n");
            sec += 5; // to make sure the print is only executed every 5 sec
        }
       
    }
    // exit thread;
    _endthread();
} //End------------------------------------

// -------------------------the main function--------------------
int main(){

    printf("%s", "Starting main... \n");
 
    // two threads, two handles
    HANDLE  hThread1,
        hThread2;
    // Start up the thread time_count.
    // Start up the thread read_inport.
    // since we are working with global variable we don't need to pass any argument to these thread.
    hThread1 = _beginthread(time_count, 0, NULL); 
    hThread2 = _beginthread(read_inport, 0, NULL);

    // start_time is initialized with a the starting time 
    double start_time = get_time_ms();
    while ( program_time < 50) { // program time has to be less than 50
    //Print out system time every second.
     double current_time = get_time_ms(); // current_time is initialized with a the current time that 
                                            //is supposed to differ from start time at this line excution
        
        if(current_time - start_time >= 1000){   // check if 1 second has passed
                                                //(1000 ms = 1 second). since the get_time_ms returns time in milisecond 
            // print the time 
            // to get the next 5 times in one row two printf statement is used
            if (program_time % 5 == 1){
                printf("Time is ");
            }
            printf("  %d,  ", program_time);
            if (program_time % 5 == 0){
                printf("\n ");
            }
            
            start_time = get_time_ms();  // start time is reinitialized with a new start time for the next second
        }
        
    }
    // finally end the program by returning 0
    return(0);
}
// --- End of main thread ------



// -------- Function get_time_ms --------------------
// this function returns the current time in milisecond
double get_time_ms(){
    struct timeval t;

    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
} // ------------ End -------------------