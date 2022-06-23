#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char tl;
    char tm;
    char tr;
    char ml;
    char mm;
    char mr;
    char bl;
    char bm;
    char br;
}Board;

void PrintBoard(char tl, char tm, char tr, char ml, char mm, char mr, char bl, char bm, char br); 

int main(void) 
{
    Board tictac = {
        .tl = 'A',
        .tm = 'B',
        .tr = 'C',
        .ml = 'D',
        .mm = 'E',
        .mr = 'F',
        .bl = 'G',
        .bm = 'H',
        .br = 'I',
    };

    PrintBoard(tictac.tl, tictac.tm, tictac.tr, tictac.ml, tictac.mm, tictac.mr, tictac.bl, tictac.bm, tictac.br); 

    char turn = 'X';
    for (int i = 0; i < 9; i++) {
        printf("Turn for %c\n", turn);
        printf("Please enter tile's name\n");
        
    }
    return EXIT_SUCCESS;
}

void PrintBoard(char tl, char tm, char tr, char ml, char mm, char mr, char bl, char bm, char br) {
    printf("%c", tl);
    printf("|");
    printf("%c", tm);
    printf("|");
    printf("%c", tr);
    printf("\n");
    printf("-+-+-");

    printf("\n");

    printf("%c", ml);
    printf("|");
    printf("%c", mm);
    printf("|");
    printf("%c", mr);
    printf("\n");
    printf("-+-+-");

    printf("\n");

    printf("%c", br);
    printf("|");
    printf("%c", bm;
    printf("|");
    printf("%c", bl;
    printf("\n");


}
