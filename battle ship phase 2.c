#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

char FOCP1[20][20];
char FOCP2[20][20];

int placement_check1(char a,char b,char c,int n){
    if(c=='h'){
        if (FOCP1[a-48][b-48]=='*'||FOCP1[a-48][b-47]=='*'||FOCP1[a-48][b-46]=='*'||a-48>n||b-48>n-2)return 1;
        else return 0;
    }
    if(c=='v'){
        if (FOCP1[a-48][b-48]=='*'||FOCP1[a-47][b-48]=='*'||FOCP1[a-46][b-48]=='*'||a-48>n-2||b-48>n)return 1;
        else return 0;
    }
}

int placement_check2(char a,char b,char c,int n){
    if(c=='h'){
        if (FOCP2[a-48][b-48]=='*'||FOCP2[a-48][b-47]=='*'||FOCP2[a-48][b-46]=='*'||a-48>n-2||b-48>n-2)return 1;
        else return 0;
    }
    if(c=='v'){
        if (FOCP2[a-48][b-48]=='*'||FOCP2[a-47][b-48]=='*'||FOCP2[a-46][b-48]=='*'||a-48>n-2||b-48>n-2)return 1;
        else return 0;
    }
}

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
    printf("\033[1;36m");
}


void reset()
{
    printf("\033[0;m");
}


void clrscr()
{
    printf("\e[1;1H\e[2J");
}

int main()
{
    int i, j, k, sw, x, y, n, len1, len2, delta, ships;
    printf("Board size : ");
    scanf("%d", &n);
    printf("Number of ships : ");
    scanf("%d",&ships);
    char bin[4];
    char ship1[ships][7];
    char ship2[ships][7];
    char name1[20];
    char name2[20];
    //---------------------------------------------------------------------------------//
    getchar(); /*Scaning the coordinates*/
    printf("Player 1's name :\n\n");
    gets(name1);
    printf("\nPlease enter your ships coordinates commander %s :\n\n",name1);
    for (i = 0; i < ships; i++)
    {
        fgets(ship1[i], 7, stdin);
        j=placement_check1(ship1[i][0],ship1[i][2],ship1[i][4],n);
        if(j==0){
        x = ship1[i][0] - '0';
        y = ship1[i][2] - '0';
        if (ship1[i][4] == 'h')
            for (k = 0; k < 3; k++)
                FOCP1[x][y + k] = '*';
        else if (ship1[i][4] == 'v')
            for (k = 0; k < 3; k++)
                FOCP1[x + k][y] = '*';
        }
        else if(j==1){
            printf("\nThere is something blocking your ship commander\a . Please try another coordinates :\n");
            i--;
        }
    }
    printf("\n");
    scanf("%s", bin);
    printf("\nPlayer 2's name :\n\n");
    getchar();
    gets(name2);
    printf("\nPlease enter your ships coordinates commander %s :\n\n",name2);
    for (i = 0; i < ships; i++)
    {
        fgets(ship2[i], 7, stdin);
        j=placement_check2(ship2[i][0],ship2[i][2],ship2[i][4],n);
        if(j==0){
        x = ship2[i][0] - '0';
        y = ship2[i][2] - '0';
        if (ship2[i][4] == 'h')
            for (k = 0; k < 3; k++)
                FOCP2[x][y + k] = '*';
        else if (ship2[i][4] == 'v')
            for (k = 0; k < 3; k++)
                FOCP2[x + k][y] = '*';
        }
        else if(j==1){
            printf("\nThere is something blocking your ship commander\a . Please try another coordinates :\n");
            i--;
        }
    }
    printf("\n");
    clrscr();
    //---------------------------------------------------------------------------------//
    for (i = 0; i < n + 1; i++) /*Grid for player 1 FOCP*/
    {
        FOCP1[0][i] = i + 48;
        FOCP1[i][0] = i + 48;
    }
    //--------------------------------------------------------------------------------//
    for (i = 1; i < n + 1; i++) /*Filling the sea of player 1*/
    {
        for (j = 1; j < n + 1; j++)
        {
            if(FOCP1[i][j]!='*')FOCP1[i][j] = '~';
        }
    }
    //--------------------------------------------------------------------------------//
    for (i = 0; i < n + 1; i++) /*Grid for player 2 FOCP*/
    {
        FOCP2[0][i] = i + 48;
        FOCP2[i][0] = i + 48;
    }
    //--------------------------------------------------------------------------------//
    for (i = 1; i < n + 1; i++) /*Filling the sea of player 2*/
    {
        for (j = 1; j < n + 1; j++)
        {
            if(FOCP2[i][j]!='*')FOCP2[i][j] = '~';
        }
    }
    //--------------------------------------------------------------------------------//
    len1 = strlen(name1); /*printing players'names*/
    len2 = strlen(name2);
    delta = len1 - len2;
    printf("%s",name1);
    if (delta >= 0)
    {
        for (i = 0; i < (2 * n + 4) - delta; i++)
            printf(" ");
    }
    else if (delta < 0)
    {
        for (i = 0; i < 2 * n + 4; i++)
            printf(" ");
    }
    printf("%s",name2);
    printf("\nremaing ships:%d", ships);
    for (i = 0; i <= 2 * n - 7; i++)
        printf(" ");
    printf("remaing ships:%d\n\n", ships);
    //--------------------------------------------------------------------------------//
    for (i = 0; i < n + 1; i++) /*Printing the FOCPs*/
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
                else if (FOCP1[i][j] == '*')
                {
                    bold_yellow();
                    printf("♆ ", FOCP1[i][j]);
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
        printf("       ");
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
                else if (FOCP2[i][j] == '*')
                {
                    bold_red();
                    printf("♆ ", FOCP2[i][j]);
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
    return 0;
}