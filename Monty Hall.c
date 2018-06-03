/* 
Written By D-VR
Copyright 2018 GPL-2.0 license
dvr@paperboxfilm.net

Info About the Monty Hall Problem:
https://en.wikipedia.org/wiki/Monty_Hall_problem

Become a Guest at a Tv Show and try to win your dream prize..
Oh and test the Monty Hall Problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char validInput[] = "?y2n3r1q";
char getUserInput();
int opselect = 1;
int door = 0;
int choice123;
int wincount = 0;
int gamecount = 0;
float percentage = 0;



char newFrame[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";


int main(int argc, char const *argv[])
{

    srand(time(NULL));
    for (;;)
    {
        int windoor;
        int restart = 0;
        char input = '0';
        int rndint = 0;
        choice123 = 1;
        door = 0;
        gamecount+=1;
        int userdoor;
        int HostDoor;
        int choicedoor;
        char gamemessage[] = "\n\nChoose a door!\n(Enter 1, 2 or 3)\n";
        char winmessage[60];


        rndint = rand() % 3;
        windoor = rndint+1;

        printf("%sWelcome to the Monty Hall Problem!\nYou are a Guest in a Tv Show\nYour task is it to Choose a door of three, behind which lies a prize\nThe Host then Opens a door\nYou are given the Option to switch", newFrame);
        
        for (;;)
        {
            if(door == 1){
                opselect = 3;
            }
            else
            {
            printf("%s", gamemessage);
            input = getUserInput();
            }
            switch  (opselect)
            {
                case 1:
                    printf("%sInput what is asked\nq to quit\nr to restart\n? for help\n", newFrame);
                    break;
                case 2:
                    printf("quitting, thanks for playing\n");
                    return 0;
                    break;
                case 3:
                    printf("%sYou Chose Door Nr. %d\n", newFrame, userdoor);
                    if((userdoor + windoor) == 4 && (userdoor != windoor)){
                        HostDoor = 2;
                    }
                    else
                        if((userdoor + windoor) == 5){
                        HostDoor = 1;
                    }
                    else
                        if((userdoor + windoor) == 3){
                        HostDoor = 3;
                    }
                    else
                        for(;;){
                        rndint = rand() % 3;
                        rndint+=1;
                        if(rndint != windoor){
                            HostDoor = rndint;
                            break;
                        }
                        }
                    printf("I have opened Door Nr. %d for you.. it was empty\n", HostDoor);
                    printf("Do you want to switch your Door? y/n\n");
                    char doorchoice = 'y';
                    doorchoice = getUserInput();
                    if(doorchoice == 'y'){
                        choicedoor = 6 - HostDoor - userdoor;

                        printf("%sYour door: %d, Winning Door: %d\n", newFrame, choicedoor, windoor);
                        if(choicedoor == windoor){
                            strcpy(winmessage, "Congrats you won");
                            wincount+=1;

                        }
                        else
                            strcpy(winmessage, "You have lost");
                    }
                    else
                        if(userdoor == windoor){
                            strcpy(winmessage, "Congrats you won");
                            wincount+=1;
                        }
                        else
                            strcpy(winmessage, "You have lost");
                    percentage = wincount / gamecount;
                    percentage*=100;
                    printf("Total Games: %d\n Total Wins: %d\nWin percentage: %.2f\n", gamecount, wincount, percentage);
                    printf("Do you want to play again? y/n\n\n");
                    doorchoice = getUserInput();
                    if(doorchoice == 'y'){
                        restart = 1;
                    }
                    else
                        return 0;

                    break;
                case 4:
                    restart = 1;
                    break;
                case 5:
                    door = 1;
                    choice123 = 0;
                    userdoor = input - '0';
                    break;
            }
            if(restart == 1){
                break;
            printf("%s", newFrame);
            }


        }
    }


    return 0;
}

char getUserInput()
{
    for (;;)
    {
        char Input;
        char line[256];

        if (fgets(line, sizeof line, stdin) == NULL) {
            printf("Input error.\n");
            exit(1);
        }

        Input = line[0];
        for (int i = -1; i < 8; ++i)
        {
            if (Input == validInput[i])
            {
                if(Input == '?'){
                    opselect = 1;
                    break;
                }
                else
                if(Input == 'q'){
                    opselect = 2;
                    break;
                }
                else
                if((Input == 'n' || Input == 'y') && (door == 1)){
                    opselect = 3;
                    return Input;

                }else

                if(Input == 'r'){
                    opselect = 4;
                    break;
                }else
                if((Input == '1' || Input == '2' || Input == '3') && choice123 == 1){
                    opselect = 5;
                    return Input;
                }


            }
            else 
                if(i == 7){

                printf("%sInvalid Input, do '?' for help.\n\n\n", newFrame);

                }
        }


    }
}