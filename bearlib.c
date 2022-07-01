#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int CardID(const char * str) {
    char * s = strdup(str);
    s[2] = '\0';
    int card_id = atoi(s);
    free(s);
    return card_id;
}

int CastingOutNines(int n) { 
    if (n >= 10) {
        n -= 9; 
    }
    return n;        
}

bool Luhn(const char * str) {
    int len = strlen(str); 
    char * card_num = malloc(len * sizeof(int)); 
    card_num = strcpy(card_num, str);
    for (int i = 0; i < len; i++) {
        card_num[i] -= '0';
    }
    
    int total = 0;
    for (int i = len - 2; i >= 0; i--) { 
        if (i % 2 == 0) {
            card_num[i] *= 2;
            card_num[i] = CastingOutNines(card_num[i]);
            total += card_num[i];
        } else {
            total += card_num[i];
        }
    }
    free(card_num);

    if (total % 10 == 0) {
        return true;
    }
    return false;

    
}
void CardType(const char * str) {
    int len = strlen(str);
    char * card_num = malloc(len * sizeof(int));

    int card_id = CardID(card_num);
    bool is_visa = card_num[0] == '4';
        if ((card_id == 34 || card_id == 37) && (len == 15)) {
            printf("AMEX\n");
        } else if((card_id >= 51 && card_id <= 55) && (len == 16)) {
            printf("MC\n");
        } else if ((is_visa) && ((len == 16) || (len == 13))) {
            printf("VISA\n");
        }
    free(card_num);
    return;
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: %s [card number]", argv[0]);
        return 1;
    }

    if (Luhn(argv[1])) {
        puts("Valid card");
    } else {
        puts("Invalid card");
    }
}
