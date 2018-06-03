/* 
Written By D-VR
Copyright 2018 GPL-2.0 license
dvr@paperboxfilm.net

Info About the Monty Hall Problem:
https://en.wikipedia.org/wiki/Monty_Hall_problem

Simulates Monty Halls Problem and always picks the option to 'Switch'
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int rndint, windoor, userdoor, HostDoor, choicedoor;
    float gamecount = 0;
    float wincount = 0;
    float percantager = 0;
    char newFrame[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        srand(time(NULL));

    for (;;)

    {
        gamecount+=1;

    rndint = rand() % 3;
    windoor = rndint+1;

    userdoor = rand() % 3;
    userdoor+=1;

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
    choicedoor = 6 - HostDoor - userdoor;
    if(choicedoor == windoor){
        wincount+=1;
    }
    percantager = wincount / gamecount;
    percantager*=100;
    printf("%sMonty Hall - Always Switch\n\nCurrent Game: %.2f\nCurrent Amount of Wins: %.2f\nWin percentage: %.2f\n", newFrame, gamecount, wincount, percantager);
    usleep(5000);
    }


    

    return 0;
}
