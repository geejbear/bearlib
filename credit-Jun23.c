#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define ARRAY_SIZE 100

//converts the first two items of the array into a single int
int ConvertArrayToInt(int a, int b);
int CardID(int a, int b); 
int CastingOutNines(int n); 

int main(int argc, char * argv[]) {
    
    if (argc != 2) {
        printf("usage: %s [credit card number]", argv[0]); 
        return EXIT_FAILURE;
    }
    
    int card_num[ARRAY_SIZE] = { 0 };
 
    int len = strlen(argv[1]); 
    for (int i = 0; i < len; i++) {
        argv[1][i] -= '0';
    }
    
    //saving the first two arrey indexes as an int
    int card_id = CardID(argv[1][0], argv[1][1]);

    bool is_visa = argv[1][0] == '4';

    /// *** build modular programs -> write 'bool Luhn(const char * card_num)' ***
    int total = 0;

    for (int i = len - 2; i >= 0; i -= 2) { 
        argv[1][i] *= 2;
        argv[1][i] = CastingOutNines(argv[1][i]);
        total += argv[1][i];
    } printf("\n");
    for (int j = len - 1; j >= 0; j -= 2) {
        total += argv[1][j];
    }            

    if (total % 10 == 0) {
        printf("VALID ");
        if ((card_id == 34 || card_id == 37) && (len == 15)) {
            printf("AMEX\n");
        } else if((card_id >= 51 && card_id <= 55) && (len == 16)) {
            printf("MC\n");
        } else if ((is_visa) && ((len == 16) || (len == 13))) {
            printf("VISA\n");
        } else {
            printf("UNKNOWN\n");
        }
    } else {
        printf("INVALID\n");
    } 

    return EXIT_SUCCESS;
}

int CardID(int a, int b) {
    a *= 10; 
    return a + b;   
}
/*
int CardID(char * card_num) {
    char * s = strdup(card_num);
    s[2] = '\0';
    printf("\n%i\n", atoi(s));
    int card_id = atoi(s);
    free(s);
    return card_id;
}
*/
int CastingOutNines(int n) { 
    if (n >= 10) {
        n -= 9; 
    }
    return n;        
}


