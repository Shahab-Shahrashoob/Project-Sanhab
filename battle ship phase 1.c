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

int main()
{
    int i, j, n, len1, len2, delta, ship;
    scanf("%d", &n);
    scanf("%d", &ship);
    int hit1[3][2];
    for (i = 0; i < 3; i++)
    {
        scanf("%d %d", &hit1[i][0], &hit1[i][1]);
    }
    int hit2[3][2];
    for (i = 0; i < 3; i++)
    {
        scanf("%d %d", &hit2[i][0], &hit2[i][1]);
    }
    char FOCP1[n + 1][n + 1];
    char FOCP2[n + 1][n + 1];
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
    for (i = 0; i < 3; i++) /*damged ships of player 1 */
    {
        FOCP1[hit1[i][0]][hit1[i][1]] = '*';
    }
    //--------------------------------------------------------------------------------//
    for (i = 0; i < 3; i++) /*damaged ships of player 2*/
    {
        FOCP2[hit2[i][0]][hit2[i][1]] = '*';
    }
    //--------------------------------------------------------------------------------//
    printf("\n\nFOCP1"); /*printing players' names*/
    for (i = 0; i <= 2 * n + 3; i++)
        printf(" ");
    printf("FOCP2");
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
