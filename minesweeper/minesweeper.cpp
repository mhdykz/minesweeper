#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#pragma warning (disable:4996)
typedef enum //definite colors for this program
{
    BLACK = 0, BLUE = 1, GREEN = 2,
    AQUA = 3, RED = 4, PURPLE = 5,
    YELLOW = 6, WHITE = 7, GRAY = 8,
    LIGHT_BLUE = 9, LIGHT_GREEN = 10,
    LIGHT_AQUA = 11, LIGHT_RED = 12,
    LIGHT_PURPLE = 13, LIGHT_YELLOW = 14,
    LIGHT_WHITE = 15
} ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground)
{
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if (!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
        return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}
typedef struct
{
    char name[30];
    int played;
    int winner;
    int loser;
} profile_type;
//global variables
profile_type fact;
int lose = 0;
int win = 0;
int a;
int c;
const int bomb = -1;
int amn = 0;
void welcome()
{
    //prompt user a massage
    setTextColor(LIGHT_BLUE);

    printf("\t\t\t\t\t\tHi!\n");
    Sleep(1000);
    printf("W      WW      W  EEEEEEE  L     CCCCCCC  OOOOOOO     MMMMM   MMMMM  EEEEEEE\n");
    printf(" W     WW     W   EE       L     C        O     O     MM  MM MM  MM  EE     \n");
    printf("  W   W  W   W    EEEEE    L     C        O     O     MM   MMM   MM  EEEEE  \n");
    printf("   W W    W W     EE       L     C        O     O     MM         MM  EE     \n");
    printf("    W      W      EEEEEEE  LLLL  CCCCCCC  OOOOOOO     MM         MM  EEEEEEE\n");
    Sleep(1000);
    setTextColor(YELLOW);
    printf("\t\t\t\t\t\tto\n");
    Sleep(1000);
    setTextColor(LIGHT_AQUA);

    printf("MMMMM   MMMMM  III    NN   NN   EEEEEEE   SSSSSS  W      WW      W    EEEEEEE  EEEEEEE   PPPPPP  EEEEEEE  RRRRRR\n");
    printf("MM  MM MM  MM  III    NNN  NN   EE        SS       W     WW     W     EE       EE        P    P  EE       RR   RR\n");
    printf("MM   MMM   MM  III    NNNN NN   EEEEE      SSSS     W   W  W   W      EEEEE    EEEEE     PPPPPP  EEEEE    RRRRRR\n");
    printf("MM         MM  III    NN NNNN   EE            SS     W W    W W       EE       EE        P       EE       RR  RR\n");
    printf("MM         MM  III    NN  NNN   EEEEEEE   SSSSSS      W      W        EEEEEEE  EEEEEEE   P       EEEEEEE  RR   RR\n");
    Sleep(3000);
    system("cls||clear");

}
void profile()
{
    setTextColor(LIGHT_BLUE);
    //prompt user a massage
    printf("Enter your name please:\n");

    //getting username for profile and completing info
    fgets(fact.name, 30, stdin);
    size_t username = strlen(fact.name);
    fact.name[username - 1] = '\0';
    fact.played = 0;
    fact.winner = 0;
    fact.loser = 0;
    system("cls||clear");

}
int mini_menu() {
    setTextColor(GREEN);
    printf("\t\t\t\t\t\tMAIN MENU\n");
    printf("\t\t\t\t\t\t1.play\n");
    printf("\t\t\t\t\t\t2.exit\n");
    printf("\t\t\t\t\t\t3.setting\n");
    int a1;
    int c1;
    int b1;
    setTextColor(WHITE);
    scanf("%d", &a1);
    if (a1 == 1) {
        return 100;
    }
    else if (a1 == 2) {
        setTextColor(RED);
        printf("\t\t\t\t\t\tIt seems that u have a better game!!!");
        exit(0);
    }
    else if (a1 == 3) {
        while (1) {
            setTextColor(PURPLE);
            printf("\t\t\t\t\t\tChosse your game\n");
            printf("\t\t\t\t\t\t1-Easy:8*8\n");
            printf("\t\t\t\t\t\t2-Normal:16*16\n");
            scanf("%d", &b1);
            if (b1 == 1) {
                return 100;
            }
            else if (b1 == 2) {
                return 200;
            }
            else {
                break;
            }
        }
    }
    else if (a1 != 2 && a1 != 1 && a1 != 3) {
        setTextColor(RED);
        printf("\t\t\t\t\t\tBULLSHIT!!!\n");
        Sleep(1000);
        printf("\t\t\t\t\t\tEnter a currect number\n");
        setTextColor(WHITE);
        scanf("%d", &c1);
        while (1) {
            if (c1 == 1) {
                a1 = 1;
                break;
            }
            else if (c1 == 3) {
                a1 = 3;
                break;
            }
            else {
                setTextColor(RED);
                printf("\t\t\t\t\t\tIt seems that u have a problem!!!");
                exit(0);
            }
        }
    }

    else {
        return 100;
        system("cls||clear");
    }

    system("cls||clear");
}
void build_outside_8(char jadval[8][8]) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            jadval[i][j] = 14;
        }
    }
}
void build_outside_16(char jadval[16][16]) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            jadval[i][j] = 14;
        }
    }
}
void build_inside_16(int khane[16][16], int row[16], int col[16]) {
    int x;
    int y;
    int count = 0;
    for (int i = 0; i < 40; i++) {
        x = rand() % 16;
        y = rand() % 16;
        if (khane[x][y] != -1) {
            khane[x][y] = -1;
            row[x]++;
            col[y]++;
            if (row[x] == 3 || col[y] == 3) {
                khane[x][y] = 0;
                i--;
                continue;
            }
        }
        else {
            i--;
        }
    }

    x = 0;
    y = 0;
    for (x = 0; x < 16; x++) {
        for (y = 0; y < 16; y++) {
            if (khane[x][y] == -1) {
                continue;
            }
            else if ((khane[x + 1][y - 1] == -1 && (x + 1 < 17) && (y - 1 >= 0)) || (khane[x + 1][y] == -1 && (x + 1 < 17) && (y >= 0)) || (khane[x + 1][y + 1] == -1 && (x + 1 < 17) && (y + 1 < 17)) || (khane[x][y - 1] == -1 && (y - 1 >= 0) && (x >= 0)) || (khane[x][y + 1] == -1 && (y + 1 < 17) && (x >= 0)) || (khane[x - 1][y - 1] == -1 && (x - 1 >= 0) && (y - 1 >= 0)) || (khane[x - 1][y] == -1 && (x - 1 >= 0) && (y >= 0)) || (khane[x - 1][y + 1] == -1 && (x - 1 >= 0) && (y + 1 < 17))) {
                if ((khane[x + 1][y - 1] == -1 && (x + 1 < 17) && (y - 1 >= 0)))
                {
                    count++;
                }
                if ((khane[x + 1][y] == -1 && (x + 1 < 17) && (y >= 0)))
                {
                    count++;
                }
                if ((khane[x + 1][y + 1] == -1 && (x + 1 < 17) && (y + 1 < 17)))
                {
                    count++;
                }
                if ((khane[x][y - 1] == -1 && (y - 1 >= 0) && (x >= 0)))
                {
                    count++;
                }
                if ((khane[x][y + 1] == -1 && (y + 1 < 17) && (x >= 0)))
                {
                    count++;
                }
                if ((khane[x - 1][y - 1] == -1 && (x - 1 >= 0) && (y - 1 >= 0)))
                {
                    count++;
                }
                if ((khane[x - 1][y] == -1 && (x - 1 >= 0) && (y >= 0)))
                {
                    count++;
                }
                if ((khane[x - 1][y + 1] == -1 && (x - 1 >= 0) && (y + 1 < 17)))
                {
                    count++;
                }
                khane[x][y] = count;
                count = 0;
            }
        }
    }
}
void build_inside_8(int khane[8][8], int row[8], int col[8]) {
    int x;
    int y;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        x = rand() % 8;
        y = rand() % 8;
        if (khane[x][y] != -1) {
            khane[x][y] = -1;
            row[x]++;
            col[y]++;
            if (row[x] == 3 || col[y] == 3) {
                khane[x][y] = 0;
                i--;
                continue;
            }
        }
        else {
            i--;
        }
    }

    x = 0;
    y = 0;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            if (khane[x][y] == -1) {
                continue;
            }
            else if ((khane[x + 1][y - 1] == -1 && (x + 1 < 9) && (y - 1 >= 0)) || (khane[x + 1][y] == -1 && (x + 1 < 9) && (y >= 0)) || (khane[x + 1][y + 1] == -1 && (x + 1 < 9) && (y + 1 < 9)) || (khane[x][y - 1] == -1 && (y - 1 >= 0) && (x >= 0)) || (khane[x][y + 1] == -1 && (y + 1 < 9) && (x >= 0)) || (khane[x - 1][y - 1] == -1 && (x - 1 >= 0) && (y - 1 >= 0)) || (khane[x - 1][y] == -1 && (x - 1 >= 0) && (y >= 0)) || (khane[x - 1][y + 1] == -1 && (x - 1 >= 0) && (y + 1 < 9))) {
                if ((khane[x + 1][y - 1] == -1 && (x + 1 < 9) && (y - 1 >= 0)))
                {
                    count++;
                }
                if ((khane[x + 1][y] == -1 && (x + 1 < 9) && (y >= 0)))
                {
                    count++;
                }
                if ((khane[x + 1][y + 1] == -1 && (x + 1 < 9) && (y + 1 < 9)))
                {
                    count++;
                }
                if ((khane[x][y - 1] == -1 && (y - 1 >= 0) && (x >= 0)))
                {
                    count++;
                }
                if ((khane[x][y + 1] == -1 && (y + 1 < 9) && (x >= 0)))
                {
                    count++;
                }
                if ((khane[x - 1][y - 1] == -1 && (x - 1 >= 0) && (y - 1 >= 0)))
                {
                    count++;
                }
                if ((khane[x - 1][y] == -1 && (x - 1 >= 0) && (y >= 0)))
                {
                    count++;
                }
                if ((khane[x - 1][y + 1] == -1 && (x - 1 >= 0) && (y + 1 < 9)))
                {
                    count++;
                }
                khane[x][y] = count;
                count = 0;
            }
        }
    }
}
void table(char jadval[8][8]) {
    char q = 1;
    printf("\t\t\t\t\t\t%c 1  2  3  4  5  6  7  8\n", q);
    for (int i = 0; i < 8; i++) {
        printf("\t\t\t\t\t\t%d", i + 1);
        for (int j = 0; j < 8; j++) {
            printf(" %c", jadval[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void table2(char jadval[16][16]) {
    char q = 1;
    printf("\t\t\t\t\t\t%c 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16\n", q);
    for (int i = 0; i < 16; i++) {
        printf("\t\t\t\t\t\t%d", i + 1);
        for (int j = 0; j < 16; j++) {
            printf(" %c", jadval[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void pasokhname(char jadval[8][8], int khane[8][8]) {
    char q = 1;
    char o = 15;
    char oo = 14;
    printf("\t\t\t\t\t\t%c 1  2  3  4  5  6  7  8\n", q);
    for (int i = 0; i < 8; i++) {
        printf("\t\t\t\t\t\t%d", i + 1);
        for (int j = 0; j < 8; j++) {
            if (khane[i][j] == -1) {
                printf(" %c ", o);
            }
            else {
                printf(" %c ", oo);
            }
        }
        printf("\n");
    }
}
void pasokhname2(char jadval2[16][16], int khane2[16][16]) {
    char q = 1;
    char o = 15;
    char oo = 14;
    printf("\t\t\t\t\t\t%c 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16\n", q);
    for (int i = 0; i < 16; i++) {
        printf("\t\t\t\t\t\t%d", i + 1);
        for (int j = 0; j < 16; j++) {
            if (khane2[i][j] == -1) {
                printf(" %c ", o);
            }
            else {
                printf(" %c ", oo);
            }
        }
        printf("\n");
    }
}
void openZeroHouses(int khane[8][8], char jadval[8][8], int i, int j) {
    int a;
    // Base condition
    if (i < 0 || i >= 8 || j < 0 || j >= 8) {
        return;
    }

    // If the current house is not opened and its number is 0
    if (jadval[i][j] != 'O' && khane[i][j] == 0) {
        // Open the house
        jadval[i][j] = 'O';

        // Recursive call
        openZeroHouses(khane, jadval, i - 1, j);    // Up
        openZeroHouses(khane, jadval, i + 1, j);    // Down
        openZeroHouses(khane, jadval, i, j - 1);    // Left
        openZeroHouses(khane, jadval, i, j + 1);    // Right
    }
    else if (jadval[i][j] != 'O' && khane[i][j] != 0) {
        a = khane[i][j];
        a = a + 48;
        jadval[i][j] = a;
        table(jadval);
    }
}


/** for (int k = 0; k < 8; k++) {
     for (int p = 0; p < 8; p++) {
     printf
     }
 }
}
}
*/
void select1(int khane[8][8], char jadval[8][8]) {
    int copy[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            copy[i][j] = khane[i][j];
        }
    }
    int row;
    int col;
    char type;
    while (1) {
        scanf("%d %d %c\n", &row, &col, &type);
        if (row > 8 || col > 8 || row < 1 || col < 1) {
            setTextColor(RED);
            printf("Wrong order.Enter a new one.");
            setTextColor(WHITE);
            // break;
        }
        else {
            row--;
            col--;
            while (1) {
                if (type == 'l') {
                    if (khane[row][col] == -1) {
                        printf("You lose!\n");
                        lose++;//!!!!!
                        char q = 1;
                        char o = 15;
                        char oo = 14;
                        printf("\t\t\t\t\t\t%c 1  2  3  4  5  6  7  8\n", q);
                        for (int i = 0; i < 8; i++) {
                            printf("\t\t\t\t\t\t%d", i + 1);
                            for (int j = 0; j < 8; j++) {
                                if (khane[i][j] == -1) {
                                    if (row == i && col == j) {
                                        printf(" Q ");
                                        j++;
                                    }
                                    printf(" %c ", o);
                                }
                                else {
                                    printf(" %c ", oo);
                                }
                            }
                            printf("\n");
                        }
                        break;
                    }
                    else if (khane[row][col] == 0) {
                        openZeroHouses(khane, jadval, row, col);
                        // return 2;
                        break;
                    }
                    else {
                        // return 3;
                    }
                }
                else if (type == 'r') {
                    jadval[row][col] = 6;
                    if (copy[row][col] == -1) {
                        copy[row][col] = 50;
                        for (int x = 0; x < 8; x++) {
                            for (int y = 0; y < 8; y++) {
                                if ((khane[x][y]) == -1) {
                                    if (copy[x][y] == 50) {
                                        printf("You won!");
                                        //won++
                                    }
                                }
                            }
                        }
                    }
                    //return 4;
                    break;
                }
                else {
                    printf("Wrong charactor.Enter a new one.");
                    break;
                }
            }
        }
    }
}
int select2(int khane2[16][16], char jadval2[16][16], int row2, int col2, char g2) {
    while (1) {
        if (row2 > 16 || col2 > 16 || row2 < 1 || col2 < 1) {
            setTextColor(RED);
            printf("Wrong order.Enter a new one.");
            setTextColor(WHITE);
            break;
        }
        else {
            row2--;
            col2--;
            while (1) {
                if (g2 == 'l') {
                    if (khane2[row2][col2] == -1) {
                        printf("You lose!");
                        system("cls||clear");
                        return 1;
                    }
                    else if (khane2[row2][col2] == 0) {
                        return 2;
                    }
                    else {
                        return 3;
                    }
                }
                else if (g2 == 'r') {
                    jadval2[row2][col2] = 6;
                    if (khane2[row2][col2] == -1) {
                        khane2[row2][col2] = 5;
                    }
                    return 4;
                }
                else {
                    printf("Wrong charactor.Enter a new one.");
                    break;
                }
            }
        }
    }
}

void openZeroHouses2(int khane2[16][16], char jadval2[16][16], int i2, int j2) {
    int a;
    // Base condition
    if (i2 < 0 || i2 >= 16 || j2 < 0 || j2 >= 8) {
        return;
    }

    // If the current house is not opened and its number is 0
    if (jadval2[i2][j2] != 'O' && khane2[i2][j2] == 0) {
        // Open the house
        jadval2[i2][j2] = 'O';

        // Recursive call
        openZeroHouses2(khane2, jadval2, i2 - 1, j2);    // Up
        openZeroHouses2(khane2, jadval2, i2 + 1, j2);    // Down
        openZeroHouses2(khane2, jadval2, i2, j2 - 1);    // Left
        openZeroHouses2(khane2, jadval2, i2, j2 + 1);    // Right
    }
    else if (jadval2[i2][j2] != 'O' && khane2[i2][j2] != 0) {
        a = khane2[i2][j2];
        a = a + 48;
        jadval2[i2][j2] = a;
    }
}
int main()
{
    //welcome();
    profile();
    int h = mini_menu();
    if (h == 100) {
        int flag = 8;
        char jadval[8][8];
        build_outside_8(jadval);
        table(jadval);
        int khane[8][8] = { 0 };
        int row[8] = { 0 };
        int col[8] = { 0 };
        build_inside_8(khane, row, col);
        printf("\n\n\n\n");
        char fl = 6;
        printf("\t\t\t\t\t\t%c:%d", fl, flag);
        setTextColor(LIGHT_BLUE);
        printf("\n\n\n\n");
        pasokhname(jadval, khane);
        setTextColor(GREEN);
        printf("Write row,column & type in order");
        setTextColor(WHITE);
        //int ro;
        //int co;
        //char type;
        int neshan;
        // while (1) {
             //scanf("%d %d %c\n", &ro, &co, &type);
             //int b = 
        select1(khane, jadval);
        /*if (b == 1) {
            lose++;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (i == ro - 1 && j == co - 1) {
                        jadval[i][j] = 247;
                    }
                    else if (khane[i][j] == -1) {
                        jadval[i][j] = 15;
                    }
                    else {
                        jadval[i][j] = 14;
                    }
                }
            }

            continue;
        }*/
        /* if (b == 2) {
             openZeroHouses(khane, jadval, ro - 1, co - 1);
         }
         if (b == 3) {
             neshan = khane[ro - 1][co - 1];
             sprintf(&jadval[ro - 1][co - 1], "%d", neshan);
         }
         if (b == 4) {
             flag--;
         }
         system("cls||clear");
         table(jadval);
         printf("\n\n\n\n");
         printf("\t\t\t\t\t\t%c:%d", fl, flag);
         setTextColor(LIGHT_BLUE);
         printf("\n\n\n\n");
         pasokhname(jadval, khane);
         setTextColor(GREEN);
         printf("Write row,column & type in order");
         setTextColor(WHITE);
     }
 } *
 else if (h == 200) {
     int flag2 = 40;
     char jadval2[16][16];
     build_outside_16(jadval2);
     table2(jadval2);
     int khane2[16][16] = { 0 };
     int row2[16] = { 0 };
     int col2[16] = { 0 };
     build_inside_16(khane2, row2, col2);
     printf("\n\n\n\n");
     char fl2 = 6;
     printf("\t\t\t\t\t\t%c:%d", fl2, flag2);
     setTextColor(LIGHT_BLUE);
     printf("\n\n\n\n");
     pasokhname2(jadval2, khane2);
     setTextColor(GREEN);
     printf("Write row,column & type in order");
     setTextColor(WHITE);
     int ro2;
     int co2;
     char type2;
     int neshan2;
     while (1) {
         scanf("%d %d %c\n", &ro2, &co2, &type2);
         int b = select2(khane2, jadval2, ro2, co2, type2);
         if (b == 1) {
             lose++;
             for (int i = 0; i < 8; i++) {
                 for (int j = 0; j < 8; j++) {
                     if (i == ro2 - 1 && j == co2 - 1) {
                         jadval2[i][j] = 247;
                     }
                     else if (khane2[i][j] == -1) {
                         jadval2[i][j] = 15;
                     }
                     else {
                         jadval2[i][j] = 14;
                     }
                 }
             }

             continue;
         }
         if (b == 2) {
             openZeroHouses2(khane2, jadval2, ro2 - 1, co2 - 1);
         }
         if (b == 3) {
             neshan2 = khane2[ro2 - 1][co2 - 1];
             sprintf(&jadval2[ro2 - 1][co2 - 1], "%d", neshan2);
         }
         if (b == 4) {
             flag2--;
         }
         system("cls||clear");
         table2(jadval2);
         printf("\n\n\n\n");
         printf("\t\t\t\t\t\t%c:%d", fl2, flag2);
         setTextColor(LIGHT_BLUE);
         printf("\n\n\n\n");
         pasokhname2(jadval2, khane2);
         setTextColor(GREEN);
         printf("Write row,column & type in order");
         setTextColor(WHITE);
     }
 }
 */
 // }
    }
}