#include <stdio.h>

void horizonal(int x,int y,char a[][30],int m){
    int i;
    for(i=0;i<m;i++){
        a[x+i][y]='*';
    }
}

void vertical(int x,int y,char a[][30],int m){
    int i;
    for(i=0;i<m;i++){
        a[x][y+i]='*';
    }
}

int main()
{
    int i,j,n,ship,x,y,m;
    scanf("%d",&n);
    scanf("%d",&ship);
    char pos1[ship][3];
    char pos2[ship][3];
    char FOCP1[n+1][n+1];
    char FOCP2[n+1][n+1];
    char name1[20];
    char name2[20];
    char bin;
    m=3;
    scanf("%s",name1);
    for(j=0;j<ship;j++){
        scanf("%c %c %c",pos1[j][0],pos1[j][1],pos1[j][2]);
    }
    for(i=0;i<3;i++)scanf("%c",bin);
    scanf("%s",name2);
    for(j=0;j<ship;j++){
        scanf("%c %c %c",pos2[j][0],pos2[j][1],pos2[j][2]);
    }
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
    for(i=0;i<ship;i++){
        x=pos1[i][0];
        y=pos1[i][1];
        if(pos1[i][2]=='h')horizonal(x,y,FOCP1,m);
        if(pos1[i][2]=='v')vertical(x,y,FOCP1,m);
    }
    //--------------------------------------------------------------------------------//
    for(i=0;i<ship;i++){
        x=pos2[i][0];
        y=pos2[i][1];
        if(pos2[i][2]=='h')horizonal(x,y,FOCP2,m);
        if(pos2[i][2]=='v')vertical(x,y,FOCP2,m);
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
                else if(FOCP1[i][j]=='*')printf("♆ ",FOCP1[i][j]);
                else if(FOCP1[i][j]=='0') printf("  ",FOCP1[i][j]);
                    else printf("%c ",FOCP1[i][j]);
                printf("\033[0m");
            }
            printf("       ");
            for(j=0;j<n+1;j++)
            {
                if(i>0&&j>0)printf("\033\e[0;34m");
                if(FOCP2[i][j]=='~')printf("≋ ",FOCP2[i][j]);
                else if(FOCP2[i][j]=='*')printf("♆ ",FOCP2[i][j]);
                else if(FOCP2[i][j]=='0') printf("  ",FOCP2[i][j]);
                    else printf("%c ",FOCP2[i][j]);
                printf("\033[0m");
            }
            printf("\n");
        }
    }
    return 0;
}