/* ====================================
File name: exerc_2_8.c (or cpp)
Date: 2021-02-04
Group nr 031
Members that contribute to the solutions
Syeda Elham Shahed
Karim Abdeldayem
Member not present at demonstration time:
All present
Demonstration code: [<Ass code 1-8> CD4Y-8YYA-N5XM-FR3H] 
====================================== */

/* *  File    : nim.c  
*  Program : Nim game 
*  Author  : Karim Abdeldayem
*  Code    : CD4Y-8YYA-N5XM-FR3Hs 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_COINS 13
const int HUMAN = 0;
const int COMPUTER = 1;
/* ------------- IO --------------- */
/* * human_choice * Get human choce as an int from stdin. 
* Clears stdin. * in: pile * out: int-value in range 1-3 (and also less than pile) */
int human_choice(int pile);
/* * write_winner * Write winner as a string on stdout. * in: Values HUMAN or COMPUTER. * out: */
void write_winner(int player);
/* * play_again * Ask human if he/she wants to play * another round. 
If 'n' or 'N' selected * (single char) return false else true. 
* Clears stdin. * in:  * out: true or false */
int play_again();
/* ---------------- Logic ----------------*/
/* * computer_choice  * Get computers choice (including some AI, * if 4 coins or less left, 
function makes a  * smart choice else random). 
* in: pile * out: int-value in range 1-3 (and also less than pile) */
int computer_choice(int pile);
/* * toggle * Switches player, if HUMAN in COMPUTER out * etc. 
* in:  actual player * out: next player */
int toggle(int player);
/* --------------------- Utilities -------------*/
void clear_stdin();
/***************** * *    MAIN * *****************/
int main()
{
    int pile,       /* This is how many coins we have */
        player,     /* Who is playing? */
        n_coins;    /* Number of coins taken */
    srand(time(0)); /* Setup random */
    printf("Valkommen till NIM by ...");
    pile = MAX_COINS; /* Set start values (= init) */
    player = HUMAN;
​
    /*    *  Program main loop    */
    while (true)
    {
​
        printf("Det ligger %d  mynt i hogen \n ", pile);
        printf("------------------------------------- \n");
        if (player == HUMAN)
        {
            n_coins = human_choice(pile);
            if (n_coins==0)
            {
                continue;
            }
            pile -= n_coins; // The pile is deducted with every choice the player makes
​
            if(pile <= 1){ // if the pile is equal to 1 the and it's the players turn that automatically means he lost
                //write_winner(COMPUTER);
                printf("You Won! \n");
                break;
            }
        }
        else
        {
            n_coins = computer_choice(pile);
            printf("- Jag tog %d\n", n_coins);
            printf("------------------------------------- \n");
            pile -= n_coins;
​
            if(pile <= 1){ // if the pile is equal to 1 the and it's the computer's turn that automatically means he lost
                //write_winner(HUMAN);
                printf("You Lost! \n");
                break;
            }
        }
        player = toggle(player);
    } /*   * end main loop   */
​
    //write_winner(player);
    printf("Avslutat\n");
    int restart = play_again();
    
    if (restart)
    {
        return main();
    }
    
    return 0;
} /****************** * *  DEFINITIONS *  ******************/
void clear_stdin()
{
    while (getchar() != '\n')
    {
        ;
    }
}
int human_choice(int pile)
{
    int coins = 0;
​
    printf("---------------------------------------------\n");
    printf("%d coins left in the stack. Take some coins\n", pile);
    scanf("%d", &coins); // Scans what the user inputs.
    printf("----------------------------------------------\n");
    clear_stdin();
​
    if (coins >= 4 || coins < 1 || coins > pile) //An if statement that limits what the user inputs, it couldn't be over 3 or under 1.
    {
         printf("%d coins are not valid, please try again\n ", coins); // Prints what happens if you input a wrong number.
         coins = 0; 
    }
    
​
    return coins; // returns the coins taken after the user choises the number of coins he wants to pick up.
}
int computer_choice(int pile)
{
    srand(time(NULL));
    int randomNumber = rand() % 3 + 1; // createss a random number
    int coins = 0;
​
​
    if (pile == 4) // A way to determine what the computer will pick based on how many coines are left
    {
        coins = 3;
    }else if (pile == 3)
    {
        coins = 2;
    }else if (pile == 2)
    {
        coins = 1;
    }else if (pile == 1)
    {
        coins = 1;
    }else
    {
        coins = randomNumber; // The computer will pick a random number if neither of the numbers above is available 
    }
​
    return coins;
    
}
/*void write_winner(int player) {
    //Couldn't figure out how to do this yet
    if (player == 0){
        printf("YOU WON! \n");
    }else if(player == 1){
        printf("You Lost! \n");
    }
}*/
int play_again() {
     char playAgain;
     int anotherGame; //An int here that works as a boolean if 1 it's true if 0 it's false
   
    printf("Press anything to continue playing or N to quit. \n");
    scanf("%c", &playAgain);
    if (playAgain =='n' || playAgain =='N')
    {  //If it's n or N the game will stop
     anotherGame = 0;   
    }else
    {
        anotherGame=1;
    }
    
    clear_stdin();
    return anotherGame;
}
int toggle(int player) {
    return !player;
}