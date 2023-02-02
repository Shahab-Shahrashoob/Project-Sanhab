#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <menu.h>
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define NOTHING 0

int ships, n, repair, xai, yai, arepair, brepair;
char FOCP1[21][21];
char FOCP2[21][21];
char name1[20];
char name2[20];
char bin[4];
char ship1[10][7];
char ship2[10][7];
FILE *save;
FILE *input;
FILE *replay;
typedef struct
{
    int x, y, no;
} Ship;

void savereplay()
{
    replay = fopen("replay.dat", "ab");
    fwrite(&n, sizeof(n), 1, replay);
    fwrite(&ships, sizeof(ships), 1, replay);
    fwrite(name1, sizeof(name1), 1, replay);
    fwrite(&arepair,sizeof(arepair), 1, replay);
    fwrite(FOCP1, sizeof(FOCP1), 1, replay);
    fwrite(name2, sizeof(name2), 1, replay);
    fwrite(&brepair,sizeof(brepair), 1, replay);
    fwrite(FOCP2, sizeof(FOCP2), 1, replay);
    fclose(replay);
}

void deletereplay()
{
    replay = fopen("replay.dat", "wb");
    fclose(replay);
}

void savegame()
{
    save = fopen("save.dat", "wb");
    if (!save)
    {
        bold_red();
        printf("Can't Open Save File");
        reset();
    }
    else
    {
        fwrite(&n, sizeof(n), 1, save);
        fwrite(&ships, sizeof(ships), 1, save);
        fwrite(name1, sizeof(name1), 1, save);
        fwrite(FOCP1, sizeof(FOCP1), 1, save);
        fwrite(name2, sizeof(name2), 1, save);
        fwrite(FOCP2, sizeof(FOCP2), 1, save);
    }
    fclose(save);
}

int continuegame()
{
    save = fopen("save.dat", "rb");
    if (save == NULL)
    {
        int i;
        bold_red();
        for (i = 0; i < 40; i++)
        {
            printf(" ");
        }
        printf("You Don't Have Any Saved Game");
        reset();
        Sleep(1500);
        clrscr();
        return 1;
    }
    else
    {
        fread(&n, sizeof(n), 1, save);
        fread(&ships, sizeof(ships), 1, save);
        fread(name1, sizeof(name1), 1, save);
        fread(FOCP1, sizeof(FOCP1), 1, save);
        fread(name2, sizeof(name2), 1, save);
        fread(FOCP2, sizeof(FOCP2), 1, save);
    }
    fclose(save);
    return 0;
}

void boardfiller()
{
    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        FOCP1[0][i] = i + 48;
        FOCP1[i][0] = i + 48;
    }
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
        {
            if (FOCP1[i][j] != '^')
                FOCP1[i][j] = '~';
        }
    }
    for (i = 0; i < n + 1; i++)
    {
        FOCP2[0][i] = i + 48;
        FOCP2[i][0] = i + 48;
    }
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
        {
            if (FOCP2[i][j] != '^')
                FOCP2[i][j] = '~';
        }
    }
}

void board1()
{
    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i > 0 && j > 0)
            {
                if (FOCP1[i][j] == '~' || FOCP1[i][j] == '+')
                {
                    bold_blue();
                    printf("≋ ", FOCP1[i][j]);
                    reset();
                }
                else if (FOCP1[i][j] == '^')
                {
                    bold_blue();
                    printf("s ", FOCP1[i][j]);
                    reset();
                }
                else if (FOCP1[i][j] == 'o')
                {
                    bold_green();
                    printf("o ", FOCP1[i][j]);
                    FOCP1[i][j] = '+';
                    reset();
                }
                else if (FOCP1[i][j] == '*' || FOCP1[i][j] == '=')
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

void board2()
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
                    printf("s ", FOCP2[i][j]);
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

int ship_check1()
{
    int acount = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (FOCP1[i][j] == '^')
                acount++;
        }
    }
    return acount;
}

int ship_check2()
{
    int bcount = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (FOCP2[i][j] == '^')
                bcount++;
        }
    }
    return bcount;
}

int bomb_check1()
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (FOCP1[i][j] == '*' || FOCP1[i][j] == '=')
                return 1;
        }
    }
    return 0;
}

int bomb_check2()
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (FOCP2[i][j] == '*' || FOCP2[i][j] == '=')
                return 1;
        }
    }
    return 0;
}

void replaing()
{
    clrscr();
    int i, j, k;
    replay = fopen("replay.dat", "rb");
    fread(name1, sizeof(name1), 1, replay);
    while (!feof(replay))
    {
        fread(name2, sizeof(name2), 1, replay);
        fread(&n, sizeof(n), 1, replay);
        fread(&ships, sizeof(ships), 1, replay);
        fread(FOCP1, sizeof(FOCP1), 1, replay);
        fread(FOCP2, sizeof(FOCP2), 1, replay);
        printf("%s\n", name1);
        board2();
        printf("\n\n_________________________________________________________\n\n");
        printf("%s\n", name2);
        board1();
        Sleep(3000);
        clrscr();
        fread(name1, sizeof(name1), 1, replay);
    }
    fclose(replay);
    clrscr();
    exit(EXIT_SUCCESS);
}

int area1(Ship a, int x, int y, char c)
{
    int i, j, k, sw = 1;
    if (c == 'h')
    {
        for (i = 0; i < a.x && sw == 1; i++)
        {
            for (j = 0; j < a.y && sw == 1; j++)
            {
                if (FOCP1[i + x][j + y] == '^' || i + x > n || i + x < 0 || j + y > n || j + y < 0)
                    sw = 0;
                else
                    (FOCP1[x + i][y + j] = '^');
            }
        }
        return sw;
    }
    if (c == 'v')
    {
        for (i = 0; i < a.y && sw == 1; i++)
        {
            for (j = 0; j < a.x && sw == 1; j++)
            {
                if (FOCP1[i + y][j + x] == '^' || i + y > n || i + y < 0 || j + x > n || j + x < 0)
                    sw = 0;
                else
                    (FOCP1[y + i][x + j] = '^');
            }
        }
        return sw;
    }
}

int area2(Ship a, int x, int y, char c)
{
    int i, j, k, sw = 1;
    if (c == 'h')
    {
        for (i = 0; i < a.x && sw == 1; i++)
        {
            for (j = 0; j < a.y && sw == 1; j++)
            {
                if (FOCP2[i + x][j + y] == '^' || i + x > n || i + x < 0 || j + y > n || j + y < 0)
                    sw = 0;
                else
                    (FOCP2[x + i][y + j] = '^');
            }
        }
        return sw;
    }
    if (c == 'v')
    {
        for (i = 0; i < a.y && sw == 1; i++)
        {
            for (j = 0; j < a.x && sw == 1; j++)
            {
                if (FOCP2[i + y][j + x] == '^' || i + y > n || i + y < 0 || j + x > n || j + x < 0)
                    sw = 0;
                else
                    (FOCP2[y + i][x + j] = '^');
            }
        }
        return sw;
    }
}

/*void singleplayerinsert()
{
    clrscr();
    int i, j, k, x, y;
    printf("Board size : ");
    scanf("%d", &n);
    printf("Number of ships : ");
    scanf("%d", &ships);
    clrscr();
    printf("\nPlayer 1's name :\n\n");
    getchar();
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
}

void AIinsert(int n, int ships)
{
    int x, y, i, ch, j, k;
    char vh;
    strcpy(name2,"AI");
    for (i = 0; i < ships; i++)
    {
        x = rand() % n + 1;
        y = rand() % n + 1;
        ch = rand() % 2 + 1;
        if (ch == 1)
            vh = 'h';
        if (ch == 2)
            vh = 'v';
        j = placement_check2(x + 48, y + 48, vh, n);
        if (j == 0)
        {
            if (vh == 'h')
                for (k = 0; k < 3; k++)
                    FOCP2[x][y + k] = '^';
            else if (vh == 'v')
                for (k = 0; k < 3; k++)
                    FOCP2[x + k][y] = '^';
        }
        else if (j == 1)
            i--;
    }
}*/

void put1(int x, int y)
{
    if (FOCP1[x][y] == '~' || FOCP1[x][y] == '+')
    {
        FOCP1[x][y] = 'o';
    }
    else if (FOCP1[x][y] == '^')
    {
        FOCP1[x][y] = '*';
    }
}

void put2(int x, int y)
{
    if (FOCP2[x][y] == '~' || FOCP1[x][y] == '+')
    {
        FOCP2[x][y] = 'o';
    }
    else if (FOCP2[x][y] == '^')
    {
        FOCP2[x][y] = '*';
    }
}

int AIAI()
{
    int i, j, sw = 0;
    for (i = 1; i < n + 1 && sw == 0; i++)
    {
        for (j = 1; j < n + 1 && sw == 0; j++)
        {
            if (FOCP1[i][j] == '*')
                sw = 1;
        }
    }
    if (sw == 0)
        return NOTHING;
    xai = i - 1;
    yai = j - 1;
    if (FOCP1[xai - 1][yai] == '~' || FOCP1[xai - 1][yai] == '^')
    {
        sw = UP;
    }
    else if (FOCP1[xai][yai + 1] == '~' || FOCP1[xai][yai + 1] == '^')
    {
        sw = RIGHT;
    }
    else if (FOCP1[xai + 1][yai] == '~' || FOCP1[xai + 1][yai] == '^')
    {
        sw = DOWN;
    }
    else if (FOCP1[xai][yai - 1] == '~' || FOCP1[xai][yai - 1] == '^')
    {
        sw = LEFT;
    }
    else
    {
        sw = NOTHING;
        FOCP1[xai][yai] = '=';
    }
    if ((FOCP1[xai][yai - 1] == '+' || FOCP1[xai][yai - 1] == '*') && (FOCP1[xai + 1][yai] == '+' || FOCP1[xai + 1][yai] == '*') && (FOCP1[xai][yai + 1] == '+' || FOCP1[xai][yai + 1] == '*') && (FOCP1[xai - 1][yai] == '+' || FOCP1[xai - 1][yai] == '*'))
        FOCP1[xai][yai] = '=';
    return sw;
}

int AIattack()
{
    int x, y, k;
    k = AIAI();
    if (k == NOTHING)
    {
        x = rand() % n + 1;
        y = rand() % n + 1;
        while (FOCP1[x][y] == '+' || FOCP1[x][y] == '*')
        {
            x = rand() % n + 1;
            y = rand() % n + 1;
        }
        put1(x, y);
        if (FOCP1[x][y] == '*')
            return 1;
        else
            return 0;
    }
    else if (k == UP)
    {
        put1(xai - 1, yai);
        if (FOCP1[xai - 1][yai] == '*')
            return 1;
        else
            return 0;
    }
    else if (k == LEFT)
    {
        put1(xai, yai - 1);
        if (FOCP1[xai][yai - 1] == '*')
            return 1;
        else
            return 0;
    }
    else if (k == DOWN)
    {
        put1(xai + 1, yai);
        if (FOCP1[xai + 1][yai] == '*')
            return 1;
        else
            return 0;
    }
    else if (k == RIGHT)
    {
        put1(xai, yai + 1);
        if (FOCP1[xai][yai + 1] == '*')
            return 1;
        else
            return 0;
    }
}

void singleplayergame()
{
    int acount, bcount, x, y, q;
    clrscr();
    printf("\n\nIf you want to exit the game , enter coordinates 0 and 0 .");
    Sleep(3000);
    clrscr();
    acount = bcount = ships * 3;
    for (; acount != 0 && bcount != 0;)
    {
        savereplay();
        printf("AI\n");
        board2();
        printf("\ncommander %s attack\n\n", name1);
        scanf("%d %d", &x, &y);
        if (x == 0 && y == 0)
            exit(EXIT_SUCCESS);
        while (x > n || y > n)
        {
            Beep(1000, 500);
            printf("\nOut of bounds . Please try again :\n");
            scanf("%d %d", &x, &y);
        }
        put2(x, y);
        clrscr();
        board2(n);
        if (FOCP2[x][y] == '*')
            bcount--;
        if (bcount == 0)
            break;
        Sleep(2500);
        clrscr();
        printf("%s\n", name1);
        board1();
        Sleep(2500);
        q = AIattack();
        clrscr();
        board1();
        if (q == 1)
            acount--;
        if (acount == 0)
            break;
        q = 0;
        Sleep(2500);
        clrscr();
        savegame();
    }
    if (acount == 0)
        printf("You Lost");
    else if (bcount == 0)
        printf("You won");
}

void multiplayerinsertT()
{
    clrscr();
    int i, j, k, x, y, mode, choice, count;
    Ship ship;
    printf("Board size : ");
    scanf("%d", &n);
    printf("Number of ships : ");
    scanf("%d", &ships);
    printf("Repairs : ");
    scanf("%d", &repair);
    clrscr();
    getchar();
    printf("\nPlayer 1's name :\n\n");
    gets(name1);
    count = ships;
    choice = 1;
    while (count > 0 && choice == 1)
    {
        printf("\nPlease enter your ship's info commander %s :\n\n", name1);
        scanf("%d %d %d", &ship.x, &ship.y, &ship.no);
        while (ship.x * ship.y * ship.no > count)
        {
            Beep(1000, 500);
            printf("\nPlease enter another correct INFO:\n");
            scanf("%d %d %d", &ship.x, &ship.y, &ship.no);
        }
        if (ship.x > ship.y)
        {
            i = ship.y;
            ship.y = ship.x;
            ship.x = i;
        }
        getchar();
        printf("\nPlease enter your ships coordinates commander %s :\n\n", name1);
        for (i = 0; i < ship.no; i++)
        {
            fgets(ship1[i], 7, stdin);
            j = area1(ship, ship1[i][0] - '0', ship1[i][2] - '0', ship1[i][4]);
            if (j == 0)
            {
                Beep(1000, 500);
                printf("\nThere is something blocking your ship commander\a . Please try another coordinates :\n");
                i--;
            }
        }
        count -= (ship.x * ship.y * ship.no);
        if (count == 0)
            break;
        clrscr();
        printf("You have %d ship left . Do you want to continue ?\n\n1.Yes !\n2.No\n\n Your answer : ", count);
        scanf("%d", &choice);
        clrscr();
    }
    getchar();
    printf("\nPlayer 2's name :\n\n");
    gets(name2);
    count = ships;
    choice = 1;
    while (count > 0 && choice == 1)
    {
        printf("\nPlease enter your ship's info commander %s :\n\n", name2);
        scanf("%d %d %d", &ship.x, &ship.y, &ship.no);
        while (ship.x * ship.y * ship.no > ships)
        {
            Beep(1000, 500);
            printf("\nPlease enter another correct INFO:\n");
            scanf("%d %d %d", &ship.x, &ship.y, &ship.no);
        }
        if (ship.y > ship.x)
        {
            i = ship.y;
            ship.y = ship.x;
            ship.x = i;
        }
        getchar();
        printf("\nPlease enter your ships coordinates commander %s :\n\n", name2);
        for (i = 0; i < ship.no; i++)
        {
            fgets(ship2[i], 7, stdin);
            j = area2(ship, ship2[i][0] - '0', ship2[i][2] - '0', ship2[i][4]);
            if (j == 0)
            {
                Beep(1000, 500);
                printf("\nThere is something blocking your ship commander\a . Please try another coordinates :\n");
                i--;
            }
        }
        count -= ship.x * ship.y * ship.no;
        if (count == 0)
            break;
        clrscr();
        printf("You have %d ship left . Do you want to continue ?\n\n1.Yes !\n2.No\n\n Your answer : ", count);
        scanf("%d", &choice);
        clrscr();
    }
    printf("\n");
    clrscr();
}

void multiplayerinsertF()
{
    char vh;
    char bin[4];
    int x, y, i, k;
    Ship ship;
    input = fopen("input.txt", "r");
    fscanf(input, "%d\n", &n);
    fscanf(input, "%d\n", &ships);
    fscanf(input, "%s", name1);
    while (bin[0] != '-')
    {
        fscanf(input, "%d %d %d\n", &ship.x, &ship.y, &ship.no);
        for (i = 0; i < ship.no; i++)
        {
            fscanf(input, "%d %d %c\n", &x, &y, &vh);
            area1(ship, x, y, vh);
        }
        fscanf(input, "%s\n", bin);
    }
    fscanf(input, "%s", name2);
    while (bin[0] != '-')
    {
        fscanf(input, "%d %d %d", &ship.x, &ship.y, &ship.no);
        for (i = 0; i < ship.no; i++)
        {
            fscanf(input, "%d %d %c %c\n", &x, &y, &vh, &vh);
            area2(ship, x, y, vh);
        }
        fscanf(input, "%s", bin);
    }
    fscanf(input, "%d", &repair);
    fclose(input);
}

void multiplayergame()
{
    int acount, bcount, x, y, choice, i, turn = 0;
    char command = '0';
    boardfiller();
    acount = ship_check1();
    bcount = ship_check2();
    arepair = brepair = repair;
    clrscr();
    printf("\n\nIf you want to exit the game , enter e\n\nIf you want to repair , enter r.");
    Sleep(2500);
    clrscr();
    for (; acount != 0 && bcount != 0;)
    {
        if (turn % 2 == 0)
        {
            printf("commander %s 's turn\n\n", name1);
            board2();
            printf("\nRemaining Repairs: %d\n", arepair);
            printf("\nCommander %s Attack!\n", name1);
            scanf("%c", &command);
            while (command != 'r' && command != 'e' && !(command >= '1' && command <= '9'))
            {
                scanf("%c", &command);
            }
            if (command == 'e')
            {
                savegame();
                exit(EXIT_SUCCESS);
            }
            else if (command == 'r')
            {
                clrscr();
                if (arepair == 0)
                {
                    printf("You don't have any repairs left\n");
                    break;
                }
                printf("%s\n\n", name1);
                board1();
                scanf("%d %d", &x, &y);
                while (FOCP1[x][y] != '*')
                {
                    printf("Please enter correct coordinates:\n");
                    scanf("%d %d", &x, &y);
                }
                FOCP1[x][y] = '^';
                arepair--;
                clrscr();
                board1();
                Sleep(2500);
                clrscr();
                savereplay();
            }
            else if (command >= '1' && command <= '9')
            {
                scanf("%d", &y);
                x = command - '0';
                while (x > n || y > n)
                {
                    Beep(1000, 500);
                    printf("\nOut of bounds . Please try again :\n");
                    scanf("%d %d", &x, &y);
                }
                put2(x, y);
                savereplay();
                clrscr();
                board2();
                if (FOCP2[x][y] == '*')
                    bcount--;
                if (bcount == 0)
                    break;
                Sleep(2500);
                clrscr();
            }
            clrscr();
            turn++;
        }
        else
        {
            printf("commander %s 's turn\n\n", name2);
            board1();
            printf("\nRemaining Repairs: %d\n", brepair);
            printf("\nCommander %s Attack!\n", name2);
            scanf("%c", &command);
            while (command != 'r' && command != 'e' && !(command >= '1' && command <= '9'))
            {
                scanf("%c", &command);
            }
            if (command == 'e')
            {
                savegame();
                exit(EXIT_SUCCESS);
            }
            else if (command == 'r')
            {
                clrscr();
                if (brepair == 0)
                {
                    printf("You don't have any repairs left\n");
                    break;
                }
                printf("%s\n\n", name2);
                board2();
                scanf("%d %d", &x, &y);
                while (FOCP2[x][y] != '*')
                {
                    printf("Please enter correct coordinates:\n");
                    scanf("%d %d", &x, &y);
                }
                FOCP2[x][y] = '^';
                brepair--;
                clrscr();
                board2();
                Sleep(2500);
                clrscr();
                savereplay();
            }
            else if (command >= '1' && command <= '9')
            {
                scanf("%d", &y);
                x = command - '0';
                while (x > n || y > n)
                {
                    Beep(1000, 500);
                    printf("\nOut of bounds . Please try again :\n");
                    scanf("%d %d", &x, &y);
                }
                put1(x, y);
                savereplay();
                clrscr();
                board1();
                if (FOCP1[x][y] == '*')
                    acount--;
                if (acount == 0)
                    break;
                Sleep(2500);
                clrscr();
            }
            clrscr();
            turn++;
        }
    }
    clrscr();
    if (acount == 0)
        printf("Commander %s Won", name2);
    else if (bcount == 0)
        printf("Commander %s Won", name1);
}

int main()
{
    clrscr();
    welcome();
    battleship();
    int i, res, res1 = menu();
    while (res1 == 1)
    {
        res = menucheck(1);
        while (res == 1)
        {
            i = continuegame();
            if (i != 0)
            {
                battleship();
                res1 = menu();
                res = menucheck(1);
            }
            else
            {
                deletereplay();
                singleplayergame();
                credits();
            }
        }
        if (res == 2)
        {
            deletereplay();
            /*singleplayerinsert();
            AIinsert(n, ships);
            boardfiller();
            singleplayergame();
            credits();*/
        }
    }
    while (res1 == 2)
    {
        res = menucheck(2);
        while (res == 3)
        {
            clrscr();
            i = continuegame();
            if (i != 0)
            {
                battleship();
                res1 = menu();
                res = menucheck(2);
            }
            else
            {
                deletereplay();
                multiplayergame();
                credits();
            }
        }
        if (res == 4)
        {
            deletereplay();
            multiplayerinsertT();
            boardfiller();
            multiplayergame();
            credits();
        }
        else if (res == 5)
        {
            deletereplay();
            clrscr();
            continuegame();
            multiplayergame();
            credits();
        }
        else if (res == 6)
        {
            deletereplay();
            multiplayerinsertF();
            boardfiller();
            multiplayergame();
            credits();
        }
    }
    while (res1 == 3)
    {
        replaing();
        Sleep(2500);
    }
}