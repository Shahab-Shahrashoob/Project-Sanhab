#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void bold_blue()
{
    printf("\033[1;34m");
}

void bold_green()
{
    printf("\033[1;32m");
}

void bold_red()
{
    printf("\033[1;31m");
}

void bold_yellow()
{
    printf("\033[1;33m");
}

void bold_magenta()
{
    printf("\033[1;35m");
}

void bold_cyan()
{
    printf("\e[1;36m");
}

void reset()
{
    printf("\033[0;m");
}

void clrscr()
{
    printf("\e[1;1H\e[2J");
}

void welcome()
{
    printf("\n\n\nWelcome");
    Sleep(1500);
    clrscr();
    printf("\n\n\nto project $anhab");
    Sleep(1500);
    clrscr();
    printf("\n\n\nEnjoy the game....!");
    Sleep(1500);
    clrscr();
}

void credits()
{
    Sleep(5000);
    clrscr();
    printf("\n\n\nCredits\n\n");
    Sleep(3000);
    printf("Developed and created by \n\n");
    Sleep(3000);
    bold_yellow();
    printf("Sania Dolat Abadi\n\n");
    reset();
    Sleep(2500);
    bold_cyan();
    printf("Shahab Shahrashoob\n\n\n");
    reset();
    Sleep(2500);
    printf("Special thanks to \n\n");
    Sleep(2500);
    printf("Our best professor\n ");
    Sleep(2500);
    bold_green();
    printf("Saeed Abrishami\n\n");
    reset();
    Sleep(2500);
    printf("And our kind mentor\n ");
    Sleep(2500);
    bold_red();
    printf("Tahoora Saeedi");
    reset();
    Sleep(4000);
    clrscr();
    printf("\n\n\nThanks for playing");
    Sleep(3000);
    clrscr();
    exit(EXIT_SUCCESS);
}

int easter(char name1[], char name2[])
{
    int i, j;
    i = j = 0;
    if (strcmp(name1, "$ania") == 0 || strcmp(name2, "$ania") == 0)
        i = 1;
    if (strcmp(name1, "ShahabDeKiller") == 0 || strcmp(name2, "ShahabDeKiller") == 0)
        j = 1;
    if (i == 1 && j == 1)
    {
        printf("\n\n\n\nDear Players...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nYou should know something...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nabout shahab and sania...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nThey are allies...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nyou can't put allies against each other...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nso...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\ndon't mess around with Miss.DEATH and Mr.DeKiller ");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nEnding #1 : Allies 4 ever\n\n\n");
        return 1;
    }
    return 0;
}

void battleship()
{
    int i;
    bold_cyan();
    printf("\n\n\n");
    for (i = 0; i < 15; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 8; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 7; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    printf("\n");
    for (i = 0; i < 15; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 1; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 8; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    printf("\n");
    for (i = 0; i < 15; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 5; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 3; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 7; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    printf("\n");
    for (i = 0; i < 15; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 5; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 7; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 6; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    printf("\n");
    for (i = 0; i < 15; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 3; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 7; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 5; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 10; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    printf("\n");
    for (i = 0; i < 15; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 9; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 10; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    printf("\n");
    for (i = 0; i < 15; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 11; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 3; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 6; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 4; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 5; i++)
    {
        printf("O");
    }
    for (i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (i = 0; i < 1; i++)
    {
        printf("O");
    }
    reset();
}

int menu()
{
    int i, choice;
    printf("\n\n\n");
    for (i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("⒈ 🤖 SinglePlayer 👤");
    printf("\n\n");
    for (i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("⒉ 👥 MuliPlayer 👥");
    printf("\n\n");
    for (i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("3. ▶️  Replay ⏸");
    printf("\n\n");
    for (i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("Please Enter Your Choice: ");
    scanf("%d", &choice);
    return choice;
}

int menucheck(int choice)
{
    char type[10];
    int mode, i;
    clrscr();
    printf("\n\n\n");
    getchar();
    if (choice == 1)
    {
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("1.Continue The Last Game ️💾\n\n");
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("Or\n\n");
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("2.New Game 🎮\n\n");
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("Please Enter Your Choice: ");
        scanf("%d", &mode);
        if (mode == 1)
            return 1;
        else if (mode == 2)
            return 2;
            clrscr();
    }
    else if (choice == 2)
    {
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("1.Continue The Last Game ️💾\n\n");
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("Or\n\n");
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("2.New Game 🎮\n\n");
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("Please Enter Your Choice: ");
        scanf("%d", &mode);
        if (mode == 1)
            return 3;
        else if (mode == 2)
        {
            printf("\n\n");
            for(i=0;i<40;i++)
            {
                printf(" ");
            }
            printf("Do You Want To Enter Your INFO In Terminal or File:");
            scanf("%s", type);
            clrscr();
            if (strcmp(type, "Terminal") == 0)
            {
                return 4;
            }
            else if (strcmp(type, "File") == 0)
            {
                return 5;
            }
        }
    }
}