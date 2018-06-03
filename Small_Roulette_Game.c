/* 
Written By D-VR
Copyright 2018 GPL-2.0 license
dvr@paperboxfilm.net

Sources for ASCII Art:
http://roulette.ascii.uk/
http://chris.com/ascii/index.php

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 400
char revolver[] = "       _  __________=__      \n        \\@([____]_____(====|=====|=O\n       _/\\|-[____]	   |BANG!|\n      /     /(( )          |_____|\n     /____|'----'\n     \\____/    \n";
char revolverwait[] = "            *CLICK*\n       _  __________=__      \n        \\@([____]_____()\n       _/\\|-[____]			\n      /     /(( )           \n     /____|'----'\n     \\____/    ";char revolverwin[] = "\n       _  __________=__      \n        \\@([____]_____()\n       _/\\|-[____]			\n      /     /(( )           \n     /____|'----'\n     \\____/    ";
char roulette[] = "                 _      _   _       \n                | |    | | | |      \n _ __ ___  _   _| | ___| |_| |_ ___ \n| '__/ _ \\| | | | |/ _ \\ __| __/ _ \\\n| | | (_) | |_| | |  __/ |_| ||  __/\n|_|  \\___/ \\__,_|_|\\___|\\__|\\__\\___|";
int getuserinput(int, int, char[]);
char newFrame[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

int main()
{
	int input = 0;
	int rndint = 0;
	char yes = 'n';
	int i = 7;
	char errormsg[MAX];
	for(;;){
	input = 0;
	i = 7;
	//since the number should be ABOVE 1
	rndint = rand() % 100;
	if(rndint == 0){
		rndint = 100;
	}

	printf("%s", newFrame);
	printf("%s\n%s\nWELCOME TO THE DVR ROULETTE GAME!\nYou have 7 Tries to guess a number \nbetween 1 and 100 before YOU LOSE! Good luck!\n\n",revolverwin, roulette);
	
	for(;i != 0;i--){
		input = getuserinput(input, i, errormsg);
		printf("%s", newFrame);
		if (input == rndint)
		{

		printf("%s\n\n\n\n\nHooray, you have WON!\n", revolverwin);
			break;
		}
		if(input < rndint){
			char error[] = ", was SMALLER than mine!\n";
			strcpy(errormsg, error);
		}
		if(input > rndint){
			char error[] = ", was BIGGER than mine!\n";
			strcpy(errormsg, error);
		}

	}
	if(i == 0){
		printf("%s\n\n\n\n\nSorry, you LOSE\n",revolver);
	}
	printf("My number was %d!\n\n", rndint);
	printf("Do you want to play again? Y/N\n");
	fseek(stdin,0,SEEK_END);
	yes = getchar();
	if(yes == 'Y' || yes == 'y'){
		continue;
	}
	else {
	break;
	}
	}

	printf("%sThanks for Playing!\n\n\n\n", newFrame);

	return 0;
}

int getuserinput(int lastinput, int tries, char errormsg[])
{
	int num1 = 0;
	
	for(;;){
		if(lastinput != 0){
		printf("%s\n\n\n\nWRONG Number, Try again..\nYour Number of %d%s\n",revolverwait, lastinput, errormsg);
		}
		printf("Enter a number between 1 and 100!\nExample: 42\n");
		if(tries == 1){
			printf("You have %d Try left to win! Make it Count!\n", tries);
			}	
		else printf("You have %d Tries left to win!\n", tries);

		scanf("%d", &num1);
		if(num1 > 0 && num1 <= 100){
			break;
		}
		printf("%sInvalid number! Try again.\n\n", newFrame);
		//this might not work depending on system. Works on MacOS. Is to prevent breaking of program if a char is entered.
		fseek(stdin,0,SEEK_END);
	}
	return num1;
}