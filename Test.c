 #include <stdio.h>

 
 int main()
 {
    int i, j, n, len1, len2, delta, ships;
    scanf("%d\n%d", &n, &ships);
    char bin[4];
    char ship1[ships][7];
    char ship2[ships][7];
    char name1[10];
    char name2[10];
    char FOCP1[n + 1][n + 1];
    char FOCP2[n + 1][n + 1];
    getchar();                                              
    gets(name1);
    for (i = 0; i <ships; i++)
    {
        fgets(ship1[i],7,stdin);
    }
    printf("\n");
    scanf("%s", bin);
    printf("\n");
    getchar();
    gets(name2);
    for (i = 0; i < ships; i++)
    {
        fgets(ship2[i],7,stdin);
    }
    printf("\n");
    for (i=0;i<ships;i++) printf("%c\n",ship2[i][0]);
 }