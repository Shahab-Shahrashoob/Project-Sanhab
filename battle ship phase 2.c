#include <stdio.h>

int main()
{
    int i,j,n,ship;
    scanf("%d",&n);
    scanf("%d",&ship);
    char FOCP1[n+1][n+1];
    char FOCP2[n+1][n+1];
    //---------------------------------------------------------------------------------//
    for(i=0;i<n+1;i++)                                       /*Grid for player 1 board*/
    {
        FOCP1[0][i]=i+48;                                      
        FOCP1[i][0]=i+48;
    }
    //--------------------------------------------------------------------------------//
    for(i=1;i<n+1;i++)                                  /*Filling the sea of player 1*/
    {
        for(j=1;j<n+1;j++) {FOCP1[i][j]='~';}                 
    }
    //--------------------------------------------------------------------------------//
    for(i=0;i<n+1;i++)                                      /*Grid for player 2 board*/
    {                                                       
        FOCP2[0][i]=i+48;                                  
        FOCP2[i][0]=i+48;
    }
    //--------------------------------------------------------------------------------//
    for(i=1;i<n+1;i++)                                  /*Filling the sea of player 2*/ 
    {
        for(j=1;j<n+1;j++) {FOCP2[i][j]='~';}                
    }
    //--------------------------------------------------------------------------------//
    for(i=0;i<n+1;i++)                                          /*Printing the boards*/
    {
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i>0&&j>0)printf("\033\e[0;34m");
                if(FOCP1[i][j]=='~')printf("≋ ",FOCP1[i][j]);
                else if(FOCP1[i][j]=='0') printf("  ",FOCP1[i][j]);
                    else printf("%c ",FOCP1[i][j]);
                printf("\033[0m");
            }
            printf("       ");
            for(j=0;j<n+1;j++)
            {
                if(i>0&&j>0)printf("\033\e[0;34m");
                if(FOCP1[i][j]=='~')printf("≋ ",FOCP2[i][j]);
                else if(FOCP2[i][j]=='0') printf("  ",FOCP2[i][j]);
                    else printf("%c ",FOCP2[i][j]);
                printf("\033[0m");
            }
            printf("\n");
        }
    }
    return 0;
}