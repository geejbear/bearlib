#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


int CardID(int a, int b) {
    a *= 10; 
    return a + b;
}

int CastingOutNines(int n) { 
    if (n >= 10) {
        n -= 9; 
    }
    return n;        
}
bool Luhn(char * card_num) {
    
    card_num = malloc(sizeof(card_num) * sizeof(int));
    int len = strlen(card_num); 
    for (int i = 0; i < len; i++) {
        card_num[i] -= '0';
        printf("card number: %c\n", card_num[i]);
    }
    
    int total = 0;
    //TODO bring back double for loops
    for (int i = len - 2; i >= 0; i++) { 
        if (i % 2 == 0) {
            card_num[i] *= 2;
            card_num[i] = CastingOutNines(card_num[i]);
            total += card_num[i];
        } else {
            total += card_num[i];
        }
    }
    printf("%d\n", total);

    free(card_num);

    if (total % 10 == 0) {
        return true;
    }
    return false;

    
}
void CardType(char * card_num) {
    card_num = malloc(sizeof(card_num) * sizeof(int));
    int len = strlen(card_num); 

    int card_id = CardID(card_num[0], card_num[1]);
    bool is_visa = card_num[0] == '4';
        if ((card_id == 34 || card_id == 37) && (len == 15)) {
            printf("AMEX\n");
        } else if((card_id >= 51 && card_id <= 55) && (len == 16)) {
            printf("MC\n");
        } else if ((is_visa) && ((len == 16) || (len == 13))) {
            printf("VISA\n");
        }
    return;
}
int main(int argc, char ** argv)
{
    if (argc != 2) {
         printf("usage: %s [credit card number]", argv[0]);
         return EXIT_FAILURE;
    }
    
    if (Luhn(argv[1]) == true) {
        printf("yes");
    } else {
        printf("no");
    }
    
    return EXIT_SUCCESS;
}
