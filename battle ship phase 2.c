#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int placement_check(char a[],char board[][30],int n){
    if(a[4]=='h'){
        if (board[a[0]][a[2]]!='*'||board[a[0]][a[2]+1]!='*'||board[a[0]][a[2]+2]!='*'||a[0]<n-2||a[2]<n-2)return 0;
        else return 1;
    }
    else if(a[4]=='v'){
        if (board[a[0]][a[2]]!='*'||board[a[0]+1][a[2]]!='*'||board[a[0]+2][a[2]]!='*'||a[0]<n-2||a[2]<n-2)return 0;
        else return 1;
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

int main()
{
    int i, j, k, x, y, n, len1, len2, delta, ships;
    scanf("%d\n%d", &n, &ships);
    char bin[4];
    char ship1[ships][7];
    char ship2[ships][7];
    char name1[10];
    char name2[10];
    char FOCP1[n + 1][n + 1];
    char FOCP2[n + 1][n + 1];
    //---------------------------------------------------------------------------------//
    getchar(); /*Scaning the coordinates*/
    gets(name1);
    for (i = 0; i < ships; i++)
    {
        fgets(ship1[i], 7, stdin);
        if(placement_check(ship1[i],FOCP1,n)==0){
        x = ship1[i][0] - '0';
        y = ship1[i][2] - '0';
        if (ship1[i][4] == 'h')
            for (k = 0; k < 3; k++)
                FOCP1[x][y + k] = '*';
        else if (ship1[i][4] == 'v')
            for (k = 0; k < 3; k++)
                FOCP1[x + k][y] = '*';
        }
        else if(placement_check(ship1[i],FOCP1,n)==-1){
            printf("There is something blocking your ship . Please try again :\n");
            i--;
        }
    }
    printf("\n");
    scanf("%s", bin);
    printf("\n");
    getchar();
    gets(name2);
    for (i = 0; i < ships; i++)
    {
        fgets(ship2[i], 7, stdin);
        if(placement_check(ship2[i],FOCP2,n)==0){
        x = ship2[i][0] - '0';
        y = ship2[i][2] - '0';
        if (ship2[i][4] == 'h')
            for (k = 0; k < 3; k++)
                FOCP2[x][y + k] = '*';
        else if (ship2[i][4] == 'v')
            for (k = 0; k < 3; k++)
                FOCP2[x + k][y] = '*';
        }
        else if(placement_check(ship2[i],FOCP2,n)==1){
            printf("There is something blocking your ship . Please try again :\n");
            i--;
        }
    }
    printf("\n");
    //---------------------------------------------------------------------------------//
    for (i = 0; i < n + 1; i++) /*Grid for player 1 board*/
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
    for (i = 0; i < n + 1; i++) /*Grid for player 2 board*/
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
    for (i = 0; i < len1; i++)
        printf("%c", name1[i]);
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
    for (i = 0; i < len2; i++)
        printf("%c", name2[i]);
    printf("\nremaing ships:%d", ships);
    for (i = 0; i <= 2 * n - 7; i++)
        printf(" ");
    printf("remaing ships:%d\n\n", ships);
    //--------------------------------------------------------------------------------//
    for (i = 0; i < n + 1; i++) /*Printing the boards*/
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
                    bold_green();
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
                    bold_green();
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
