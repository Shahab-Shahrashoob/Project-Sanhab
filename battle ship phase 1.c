#include <stdio.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    char player1[n+1][n+1];
    char player2[n+1][n+1];
    //---------------------------------------------------------------------------------//
    for(i=0;i<n+1;i++)                                       /*Grid for player 1 board*/
    {
        player1[0][i]=i+48;                                      
        player1[i][0]=i+48;
    }
    //--------------------------------------------------------------------------------//
    for(i=1;i<n+1;i++)                                  /*Filling the sea of player 1*/
    {
        for(j=1;j<n+1;j++) {player1[i][j]='~';}                 
    }
    //--------------------------------------------------------------------------------//
    for(i=0;i<n+1;i++)                                      /*Grid for player 2 board*/
    {                                                       
        player2[0][i]=i+48;                                  
        player2[i][0]=i+48;
    }
    //--------------------------------------------------------------------------------//
    for(i=1;i<n+1;i++)                                  /*Filling the sea of player 2*/ 
    {
        for(j=1;j<n+1;j++) {player2[i][j]='~';}                
    }
    //--------------------------------------------------------------------------------//
    for(i=0;i<n+1;i++)                                          /*Printing the boards*/
    {
        for(j=0;j<n+1;j++)printf("%c ",player1[i][j]);
        printf("  |  ");                                     
        for(j=0;j<n+1;j++)printf("%c ",player2[i][j]);
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
            if(i>0&&j>0)printf("\033\e[0;34m");
            printf("%c ",player1[i][j]);
            printf("\033[0m");
        }
        printf("  |   ");                                     /*Printing the boards*/
        for(j=0;j<n+1;j++){
            if(i>0&&j>0)printf("\033\e[0;34m");
            printf("%c ",player2[i][j]);
            printf("\033[0m");
        }

        printf("\n");
    }
    return 0;
    }
}
