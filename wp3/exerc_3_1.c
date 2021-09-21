/*===========================================
File name: exerc_3_1.c
Date: 2021-02-11
Group nr 31
Members that contribute to the solutions 
Zhijie Wei
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8>CHUY-ACRU-JTXS-ZLDM]    
===========================================*/

#include <stdio.h>
#include <string.h>
#define MAX 10
#define BOUNDARY_MAX 99
#define BOUNDARY_MIN 0
enum DIRECTION {N,O,S,W};

typedef struct{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

//declare functions 
void move(int *curretXpos,int *currentYpos, enum DIRECTION *direction);
void turn(enum DIRECTION *direction);
void printRobot(ROBOT robot);

int main(){
    char startAgain; 
    do{
        ROBOT robot;
        robot.dir = N;  // inital direction north
        char instructions[MAX];
        printf("Please enter a starting x,y position: \n");
        scanf("%d %d", &robot.xpos, &robot.ypos);  // read xpos and ypos position
        if(robot.xpos>BOUNDARY_MAX||robot.xpos<BOUNDARY_MIN||
        robot.ypos>BOUNDARY_MAX||robot.ypos<BOUNDARY_MIN){
            printf("out of boundary.");   //range from 0- 99
            break;
        } 
        printf("Please give instructions to the robot: \n");
        scanf("%s", instructions); // read either m or t 
        for(int i = 0; i < strlen(instructions);i++){
            if(instructions[i]=='m'||instructions[i]=='M'){
                move(&robot.xpos, &robot.ypos, &robot.dir);
            } //calculate the number of m and t, once read m/M,robot will move one step,
            if(instructions[i]=='t'||instructions[i]=='T'){
                turn(&robot.dir);
            } // once read t/T,robot will turn clockwise
            if(robot.xpos>BOUNDARY_MAX||robot.xpos<BOUNDARY_MIN||
               robot.ypos>BOUNDARY_MAX||robot.ypos<BOUNDARY_MIN){
                printf("Out of boundary.\n");
                break;
            }else{
                printRobot(robot);
            }
        }
        printf("Do you want to start again?\n");
        scanf("%s", &startAgain);

    }while(startAgain!='q');  //enter q to exit 

}
//move function 
void move(int *currentXpos,int *currentYpos, enum DIRECTION *direction){
    if(*direction == N){
    *currentYpos = *currentYpos + 1; //if robot faces north, y plus 1 when moving
    }
    if(*direction == O){
        *currentXpos = *currentXpos + 1; //if facing east, x plus 1 when moving
    }
    if(*direction == S){
      *currentYpos = *currentYpos - 1; // if facing south, y minus 1 when moving
    }
    if(*direction == W){
        *currentXpos = *currentXpos - 1;//if facing west, x minus 1 when moving
    }
}
//turn robot direction function follow N->O->S->W
void turn(enum DIRECTION *direction){
    if(*direction == N){
        *direction = O;  
    }else if(*direction == O){
        *direction = S;
    }else if(*direction == S){
        *direction = W;
    }else{
        *direction = N;
    }
}

void printRobot(ROBOT robot){
    printf("xPos: %d and yPos: %d\n", robot.xpos, robot.ypos);
    if(robot.dir == N){
        printf("Direction: North\n");
    }else if(robot.dir == O){
        printf("Direction: East\n");
    }else if(robot.dir == S){
        printf("Direction: South\n");
    }else{
        printf("Direction: West\n");
    }
}