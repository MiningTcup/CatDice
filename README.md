# CatDice
Just a fun little game I made. I Know it's pretty inefficient, I made it a while ago. Inspired by [Zombie Dice](https://www.amazon.com/Steve-Jackson-Games-SJG-131313/dp/B003IKMR0U).
***
You're a cat. You try to catch 16 mice before your opponent. You can play against either another person at your computer, or against the bot I programmed.

Each turn, you will catch 3 things, each with the possibility of being a mouse, rat, or footsteps. A mouse is good, you need 16 to win. A rat is bad, if you get 3 on any given round, your turn ends immediatly. Footsteps are neutral, they mean the mouse escaped.
***
libraries: 
```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
```

<details>
  <summary>Bot Code</summary>
  This is the code for the bot. Please only read this if you have already beaten the it.
  
  ```c
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
  ```
  
</details>
