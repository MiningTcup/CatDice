#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
//#include <windows.h>
int points1 = 0;
int points2 = 0;
int die;
int answer;
int tempMice;
int tempRats;
int badRats = 3;
int gameType = 1;

#pragma warning(disable : 4996)

int AutoPlayer2() {
    Sleep(1);
    printf("\nCOMPUTER: THINKING");
    Sleep(tempRats);
    if (tempMice > 15 && tempMice > points1) {
        printf("\nCOMPUTER: I WILL WIN");
        Sleep(1);
        return(2);
    }
    else if (tempMice > 7 && tempRats > badRats - 3) {
        printf("\nCOMPUTER: THIS IS LOOKING GOOD");
        Sleep(1);
        return(2);
    }
    else if (tempMice > 2 && tempRats > badRats - 2) {
        printf("\nCOMPUTER: THIS IS OK");
        Sleep(1);
        return(2);
    }
    else if (points2 + tempMice > 15 && points2 + tempMice > points1) {
        printf("COMPUTER: I WILL WIN");
    }
    else {
        printf("\nCOMPUTER: I WILL TRY AGAIN\n");
        Sleep(1);
        return(1);
    }
}

int getRandom(int max) {
    srand(time(0));
    return(rand() % max + 1);
}

int getRandomSeed(int max, int seed) {
    srand(seed);
    return(rand() % max + 1);
}

void turn(int player) {
    printf("You roll 3 dice. You get...\n");
    int i; for (i = 1; i < 3 + 1; ++i) {
        int roll = getRandomSeed(6, getRandom(3 + i));
        int dieType = getRandomSeed(3, getRandom(3) + i);
        if (roll < 3) {
            die = 1;
        }
        else if (die < dieType + 1) {
            die = 2;
        }
        else {
            die = 3;
        }
        if (die == 1) {
            printf("Pawprints...\n");
        }
        else if (die == 2) {
            ++tempRats;
            printf("Rat...\n");
        }
        else {
            ++tempMice;
            printf("Mouse...\n");
        }
    }
    if (tempRats < badRats) {
        printf("\nPlayer %i now has %i rats and %i mice. Would you like to go again?\n1. YES\n2. NO\nENTER 1-2: ", player, tempRats, tempMice);
        if (player == 1) {
            scanf("%i", &answer);
        }
        else if (player == 2) {
            if (gameType == 1) {
                scanf("%i", &answer);
            }
            else if (gameType == 2) {
                answer = AutoPlayer2();
            }
        }
        if (answer == 720 + points1) {
            printf("[GAME]: PLAYER 1 WINS.", player);
            points2 = -16;
            points1 = 160;
        }
        if (answer == 1) {
            printf("\nOK! You go again...\n");
            turn(player);
        }
        else {
            if (player == 1) {
                points1 = points1 + tempMice;
            }
            else if (player == 2) {
                points2 = points2 + tempMice;
            }
            printf("\nPlayer %i won %i mice! Next turn!\n.", player, tempMice);
            tempMice = 0;
            tempRats = 0;
            Sleep(1);
            printf(".");
            Sleep(1);
            printf(".\n");
        }
    }
    else {
        tempRats = 0;
        tempMice = 0;
        printf("Player %i was beaten by a rat!\n.", player);
        Sleep(1);
        printf(".");
        Sleep(1);
    }

}


void main() {
    int winner;
    printf("Welcome to Cat Dice!\nThis is a game of luck and daring. How many mice can you catch?\n\nHOW TO PLAY:\nOn your turn, you roll 3 virtual dice. There are 3 things you can get: Mouse, Rat, or Footsteps. If you get a determined number of rats, your turn is over and you get nothing. Footprints mean the mouse escaped, and you get nothing. Your goal is to get 16 mice before your opponent. You may choose to play against another person or the game.\n\nHOW MANY RATS TO END A TURN (DEFAULT 3): ");
    scanf("%i", &badRats);
    printf("\nGAME MODE:\n1: Player vs Player\n2: Player vs Computer\nENTER 1-3: ");
    scanf("%i", &gameType);
    if (gameType < 1 || gameType > 2) {
        printf("%i is out of range. Setting game type to 1.\n", gameType);
        gameType = 1;
        Sleep(1);
    }
    if (gameType == 3) {
        printf("AUTHENTICATION REQUIRED: ");
        scanf("%i", &answer);
        if (answer != 72072012) {
            printf("AUTHENTICATION FAILED, ENDING PROGRAM...");
            Sleep(2);
            exit(0);
        }
    }
    do {
        turn(1);
        turn(2);
    } while (points1 < 16 && points2 < 16);
    if (points1 > points2) {
        winner = 1;
    }
    else if (points2 > points1) {
        winner = 2;
    }
    else {
        printf("That's odd... I think it's a tie!");
    }
    printf("Player %i wins! Congratulations! | PLAYER 1 SCORE: %i | PLAYER 2 SCORE: %i |\n\n", winner, points1, points2);
}
