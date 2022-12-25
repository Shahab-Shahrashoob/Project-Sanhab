#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <time.h>

char FOCP1[21][21];
char FOCP2[21][21];
char name1[51];
char name2[51];

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

void RESET()
{
    printf("\033[0;m");
}

void clrscr()
{
    printf("\e[1;1H\e[2J");
}

int placement_check1(char a, char b, char c, int n)
{
    if (c == 'h')
    {
        if (FOCP1[a - 48][b - 48] == '*' || FOCP1[a - 48][b - 47] == '*' || FOCP1[a - 48][b - 46] == '*' || a - 48 > n || b - 48 > n - 2)
            return 1;
        else
            return 0;
    }
    if (c == 'v')
    {
        if (FOCP1[a - 48][b - 48] == '*' || FOCP1[a - 47][b - 48] == '*' || FOCP1[a - 46][b - 48] == '*' || a - 48 > n - 2 || b - 48 > n)
            return 1;
        else
            return 0;
    }
}

int ending2(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (FOCP1[i][j] == '*')
                return 0;
    }
    return 2;
}

int ending1(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (FOCP2[i][j] == '*')
                return 0;
    }
    return 1;
}

int placement_check2(char a, char b, char c, int n)
{
    if (c == 'h')
    {
        if (FOCP2[a - 48][b - 48] == '*' || FOCP2[a - 48][b - 47] == '*' || FOCP2[a - 48][b - 46] == '*' || a - 48 > n - 2 || b - 48 > n - 2)
            return 1;
        else
            return 0;
    }
    if (c == 'v')
    {
        if (FOCP2[a - 48][b - 48] == '*' || FOCP2[a - 47][b - 48] == '*' || FOCP2[a - 46][b - 48] == '*' || a - 48 > n - 2 || b - 48 > n - 2)
            return 1;
        else
            return 0;
    }
}

int attack_check(int x, int y, int n)
{
    if (x > n || y > n)
    {
        Beep(1000, 500);
        printf("\nOut of bounds . Please try again :\n");
        return 0;
    }
    else
        return 1;
}

void attack1(char a[], int n)
{
    int i, x, y, sw;
    sw = 0;
    printf("\nCommander %s's turn :\n\n", a);
    while (sw == 0)
    {
        scanf("%d %d", &x, &y);
        sw = attack_check(x, y, n);
    }
    if (FOCP2[x][y] == '*')
        FOCP2[x][y] = 'X';
    else
        FOCP2[x][y] = 'O';
}

void attack2(char a[], int n)
{
    int i, x, y, sw;
    sw = 0;
    printf("\nCommander %s's turn :\n\n", a);
    while (sw == 0)
    {
        scanf("%d %d", &x, &y);
        sw = attack_check(x, y, n);
    }
    if (FOCP1[x][y] == '*')
        FOCP1[x][y] = 'X';
    else
        FOCP1[x][y] = 'O';
}

void credits(){
    printf("\n\nPresented to you by\n\n");
    Sleep(2500);
    printf("$ania Dolat\n\n");
    Sleep(2500);
    printf("Shahab Shahrashoob\n\n");
}

int easter(){
    int i,j;
    i=j=0;
    if(strcmp(name1,"sania")==0||strcmp(name2,"sania")==0||strcmp(name1,"Sania")==0||strcmp(name2,"Sania")==0||strcmp(name1,"$ania")==0||strcmp(name2,"$ania")==0)i=1;
    if(strcmp(name1,"shahab")==0||strcmp(name2,"shahab")==0||strcmp(name1,"Shahab")==0||strcmp(name2,"Shahab")==0||strcmp(name1,"ShahabDeKiller")==0||strcmp(name2,"ShahabDeKiller")==0)j=1;
    if(i==1&&j==1){
        printf("\n\n\n\nDear Players...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nWho do you think you are...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nthat you are trying to put shahab and sania...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nagainst each other...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nThey are allies...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nand always will be...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nNothing can put them against each other...");
        Sleep(2500);
        clrscr();
        printf("\n\n\n\nEven this game...");
        Sleep(2500);
        clrscr();
        printf("\n\nEnding : Allies 4ever\n\n");
        return 1;
    }
    return 0;
}

void printing1(int n)
{
    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i > 0 && j > 0)
            {
                if (FOCP2[i][j] == '~' || FOCP2[i][j] == '*')
                {
                    bold_blue();
                    printf("≋ ", FOCP2[i][j]);
                    RESET();
                }
                else if (FOCP2[i][j] == 'X')
                {
                    bold_red();
                    printf("☼ ", FOCP2[i][j]);
                    RESET();
                }
                else if (FOCP2[i][j] == 'O')
                {
                    bold_green();
                    printf("O ", FOCP1[i][j]);
                    RESET();
                    FOCP2[i][j] = '~';
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

void printing2(int n)
{
    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i > 0 && j > 0)
            {
                if (FOCP1[i][j] == '~' || FOCP1[i][j] == '*')
                {
                    bold_blue();
                    printf("≋ ", FOCP2[i][j]);
                    RESET();
                }
                else if (FOCP1[i][j] == 'X')
                {
                    bold_red();
                    printf("☼ ", FOCP1[i][j]);
                    RESET();
                }
                else if (FOCP1[i][j] == 'O')
                {
                    bold_green();
                    printf("O ", FOCP1[i][j]);
                    RESET();
                    FOCP1[i][j] = '~';
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

int main()
{
    clrscr();
    int i, j, k, sw, x, y, n, len1, len2, delta, ships;
    printf("Board size : ");
    scanf("%d", &n);
    printf("Number of ships : ");
    scanf("%d", &ships);
    char bin[4];
    char ship1[ships][7];
    char ship2[ships][7];
    //---------------------------------------------------------------------------------//
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
                    FOCP1[x][y + k] = '*';
            else if (ship1[i][4] == 'v')
                for (k = 0; k < 3; k++)
                    FOCP1[x + k][y] = '*';
        }
        else if (j == 1)
        {
            Beep(1000, 500);
            printf("\nThere is something blocking your ship commander\a . Please try another coordinates :\n");
            i--;
        }
    }
    clrscr();
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
                    FOCP2[x][y + k] = '*';
            else if (ship2[i][4] == 'v')
                for (k = 0; k < 3; k++)
                    FOCP2[x + k][y] = '*';
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
    if(easter()==1)return 0;
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
            if (FOCP1[i][j] != '*')
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
            if (FOCP2[i][j] != '*')
                FOCP2[i][j] = '~';
        }
    }
    //--------------------------------------------------------------------------------//
    sw = 0;
    while (sw == 0)
    {
        clrscr();
        printf("%s\n",name1);
        printing1(n);
        attack1(name1, n);
        sw = ending1(n);
        clrscr();
        printf("%s\n",name1);
        printing1(n);
        Sleep(2500);
        if (sw == 1)
            break;
        clrscr();
        printf("%s\n",name2);
        printing2(n);
        attack2(name2, n);
        sw = ending2(n);
        clrscr();
        printf("%s\n",name2);
        printing2(n);
        Sleep(2500);
        if (sw == 2)
            break;
    }
    if (sw == 1)
        printf("\nCommander %s Won\n\n\n", name1);
    if (sw == 2)
        printf("\nCommander %s Won\n\n\n", name2);
    Sleep(2500);
    clrscr();
    credits();
    return 0;
}