/*From Scratch*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void bold_blue()
{
    printf("\033[1;34m");
}
void bold_red()
{
    printf("\033[0;31m");
}
void reset()
{
    printf("\033[0;m");
}

void horizonal(int x, int y, char a[][30], int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        a[x][y+i] = '+';
    }
}

void vertical(int x, int y, char a[][30], int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        a[x+i][y] = '+';
    }
}


int main()
{
    int i, j, n, len1, len2, delta, ship;
    scanf("%d", &n);
    scanf("%d", &ship);
    char bin[3];
    char ship1[ship][3];
    char ship2[ship][3];
    char name1[20];
    char name2[20];
    char FOCP1[n + 1][n + 1];
    char FOCP2[n + 1][n + 1];
    //---------------------------------------------------------------------------------//
    fgets(name1,20,stdin);                                     /*Scaning the coordinates*/
    for(i=0;i<ship;i++){
        scanf("%c %c %c",ship1[i][0],ship1[i][1],ship1[i][2]);
    }
    scanf("%s",bin);
    fgets(name2,20,stdin);
    for(i=0;i<ship;i++){
        scanf("%c %c %c",ship2[i][0],ship2[i][1],ship2[i][2]);
    }
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
            FOCP1[i][j] = '~';
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
            FOCP2[i][j] = '~';
        }
    }
    //--------------------------------------------------------------------------------//
    for(i=0;i<ship;i++)
    {
        if(ship1[i][2]=='h') horizonal(ship1[i][0],ship1[i][1],FOCP1,3);
        else if(ship1[i][2]=='v') vertical(ship1[i][0],ship1[i][1],FOCP1,3);
    }
    for(i=0;i<ship;i++)
    {
       if(ship2[i][2]=='h') horizonal(ship2[i][0],ship2[i][1],FOCP2,3);
        else if(ship2[i][2]=='v') vertical(ship2[i][0],ship2[i][1],FOCP2,3); 
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
    printf("\n");
    printf("\nremaing ships:%d", ship);
    for (i = 0; i <= 2 * n - 7; i++)
        printf(" ");
    printf("remaing ships:%d\n\n", ship);
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
                    printf("☼ ", FOCP2[i][j]);
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