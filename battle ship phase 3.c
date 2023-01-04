#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

char FOCP1[21][21];
char FOCP2[21][21];
char name1[20];
char name2[20];

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

void intro()
{
    printf("\n\n\nWelcome");
    Sleep(1500);
    clrscr();
    printf("\n\n\nto project $anhab");
    Sleep(1500);
    clrscr();
    printf("\n\n\nEnjoy the game");
    Sleep(1500);
    clrscr();
}

int easter()
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
        printf("\n\n\n\nEnding #1 : Allies 4ever\n\n\n");
        return 1;
    }
    return 0;
}

int placement_check1(char a, char b, char c, int n)
{
    if (c == 'h')
    {
        if (FOCP1[a - 48][b - 48] == '^' || FOCP1[a - 48][b - 47] == '^' || FOCP1[a - 48][b - 46] == '^' || a - 48 > n || b - 48 > n - 2)
            return 1;
        else
            return 0;
    }
    if (c == 'v')
    {
        if (FOCP1[a - 48][b - 48] == '^' || FOCP1[a - 47][b - 48] == '^' || FOCP1[a - 46][b - 48] == '^' || a - 48 > n - 2 || b - 48 > n)
            return 1;
        else
            return 0;
    }
}

int placement_check2(char a, char b, char c, int n)
{
    if (c == 'h')
    {
        if (FOCP2[a - 48][b - 48] == '^' || FOCP2[a - 48][b - 47] == '^' || FOCP2[a - 48][b - 46] == '^' || a - 48 > n - 2 || b - 48 > n - 2)
            return 1;
        else
            return 0;
    }
    if (c == 'v')
    {
        if (FOCP2[a - 48][b - 48] == '^' || FOCP2[a - 47][b - 48] == '^' || FOCP2[a - 46][b - 48] == '^' || a - 48 > n - 2 || b - 48 > n - 2)
            return 1;
        else
            return 0;
    }
}

void board1(int n)
{
    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i > 0 && j > 0)
            {
                if (FOCP1[i][j] == '~')
                {
                    bold_blue();
                    printf("≋ ", FOCP1[i][j]);
                    reset();
                }
                else if (FOCP1[i][j] == '^')
                {
                    bold_blue();
                    printf("≋ ", FOCP2[i][j]);
                    reset();
                }
                else if (FOCP1[i][j] == 'o')
                {
                    bold_green();
                    printf("o ", FOCP1[i][j]);
                    FOCP1[i][j] = '~';
                    reset();
                }
                else if (FOCP1[i][j] == '*')
                {
                    bold_red();
                    printf("☼ ", FOCP1[i][j]);
                    reset();
                }
            }
            if (FOCP1[i][j] == '0')
                printf("  ", FOCP1[i][j]);
            else if (i == 0 || j == 0)
            {
                if (i == 0)
                    printf("%d ", j);
                if (j == 0)
                    printf("%d ", i);
            }
        }
        printf("\n");
    }
}

void board2(int n)
{
    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i > 0 && j > 0)
            {
                if (FOCP2[i][j] == '~')
                {
                    bold_blue();
                    printf("≋ ", FOCP2[i][j]);
                    reset();
                }
                else if (FOCP2[i][j] == '^')
                {
                    bold_blue();
                    printf("≋ ", FOCP2[i][j]);
                    reset();
                }
                else if (FOCP2[i][j] == 'o')
                {
                    bold_green();
                    printf("o ", FOCP2[i][j]);
                    FOCP2[i][j] = '~';
                    reset();
                }
                else if (FOCP2[i][j] == '*')
                {
                    bold_red();
                    printf("☼ ", FOCP2[i][j]);
                    reset();
                }
            }
            if (FOCP2[i][j] == '0')
                printf("  ", FOCP2[i][j]);
            else if (i == 0 || j == 0)
            {
                if (i == 0)
                    printf("%d ", j);
                if (j == 0)
                    printf("%d ", i);
            }
        }
        printf("\n");
    }
}

void put1(int x, int y, int n)
{
    if (FOCP1[x][y] == '~')
    {
        FOCP1[x][y] = 'o';
    }
    else if (FOCP1[x][y] == '^')
    {
        FOCP1[x][y] = '*';
    }
}

void put2(int x, int y, int n)
{
    if (FOCP2[x][y] == '~')
    {
        FOCP2[x][y] = 'o';
    }
    else if (FOCP2[x][y] == '^')
    {
        FOCP2[x][y] = '*';
    }
}

int main()
{
    clrscr();
    intro();
    int i, j, k, sw, x, y, n, len1, len2, delta, ships, acount, bcount;
    printf("Board size : ");
    scanf("%d", &n);
    printf("Number of ships : ");
    scanf("%d", &ships);
    char bin[4];
    char ship1[ships][7];
    char ship2[ships][7];
    //---------------------------------------------------------------------------------//
    clrscr();
    getchar(); /*Scaning the coordinates*/
    printf("\nPlayer 1's name :\n\n");
    gets(name1);
    printf("\nPlease enter your ships coordinates commander %s :\n\n", name1);
    for (i = 0; i < ships; i++)
    {
        fgets(ship1[i], 7, stdin);
        j = placement_check1(ship1[i][0], ship1[i][2], ship1[i][4], n);
        if (j == 0)
        {
            x = ship1[i][0] - '0';
            y = ship1[i][2] - '0';
            if (ship1[i][4] == 'h')
                for (k = 0; k < 3; k++)
                    FOCP1[x][y + k] = '^';
            else if (ship1[i][4] == 'v')
                for (k = 0; k < 3; k++)
                    FOCP1[x + k][y] = '^';
        }
        else if (j == 1)
        {
            Beep(1000, 500);
            printf("\nThere is something blocking your ship commander\a . Please try another coordinates :\n");
            i--;
        }
    }
    printf("\nPlayer 2's name :\n\n");
    gets(name2);
    printf("\nPlease enter your ships coordinates commander %s :\n\n", name2);
    for (i = 0; i < ships; i++)
    {
        fgets(ship2[i], 7, stdin);
        j = placement_check2(ship2[i][0], ship2[i][2], ship2[i][4], n);
        if (j == 0)
        {
            x = ship2[i][0] - '0';
            y = ship2[i][2] - '0';
            if (ship2[i][4] == 'h')
                for (k = 0; k < 3; k++)
                    FOCP2[x][y + k] = '^';
            else if (ship2[i][4] == 'v')
                for (k = 0; k < 3; k++)
                    FOCP2[x + k][y] = '^';
        }
        else if (j == 1)
        {
            Beep(1000, 500);
            printf("\nThere is something blocking your ship commander\a . Please try another coordinates :\n");
            i--;
        }
    }
    printf("\n");
    clrscr();
    //---------------------------------------------------------------------------------//
    for (i = 0; i < n + 1; i++) /*Grid for player 1*/
    {
        FOCP1[0][i] = i + 48;
        FOCP1[i][0] = i + 48;
    }
    //--------------------------------------------------------------------------------//
    for (i = 1; i < n + 1; i++) /*Filling the sea of player 1*/
    {
        for (j = 1; j < n + 1; j++)
        {
            if (FOCP1[i][j] != '^')
                FOCP1[i][j] = '~';
        }
    }
    //--------------------------------------------------------------------------------//
    for (i = 0; i < n + 1; i++) /*Grid for player 2*/
    {
        FOCP2[0][i] = i + 48;
        FOCP2[i][0] = i + 48;
    }
    //--------------------------------------------------------------------------------//
    for (i = 1; i < n + 1; i++) /*Filling the sea of player 2*/
    {
        for (j = 1; j < n + 1; j++)
        {
            if (FOCP2[i][j] != '^')
                FOCP2[i][j] = '~';
        }
    }
    //-------------------------------------------------------------------------------//
    acount = bcount = ships * 3; /*Attack*/
    for (; acount != 0 && bcount != 0;)
    {
        board2(n);
        printf("\ncommander %s's attack\n\n", name1);
        scanf("%d %d", &x, &y);
        if (x > n || y > n)
        {
            Beep(1000, 500);
            printf("\nOut of bounds . Please try again :\n");
            scanf("%d %d", &x, &y);
        }
        put2(x, y, n);
        clrscr();
        board2(n);
        if (FOCP2[x][y] == '*')
            bcount--;
        if (bcount == 0)
            break;
        Sleep(2500);
        clrscr();
        board1(n);
        printf("\ncommander %s's attack\n\n", name2);
        scanf("%d %d", &x, &y);
        if (x > n || y > n)
        {
            Beep(1000, 500);
            printf("\nOut of bounds . Please try again :\n");
        }
        put1(x, y, n);
        clrscr();
        board1(n);
        if (FOCP1[x][y] == '*')
            acount--;
        if (acount == 0)
            break;
        Sleep(2500);
        clrscr();
    }
    clrscr();
    if (acount == 0)
        printf("commander %s won", name2);
    else if (bcount == 0)
        printf("commander %s won", name1);
}
