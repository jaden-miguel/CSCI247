#include <stdio.h>
#include <string.h>

/* Name: Jaden Miguel
 * Date: Summer 2020 - CSCI247
 * Purpose: This program converts a decimal to either
 * binary or hexadecimal. Utilizes command line arguments.
 */


// function to read a decimal input from stdin
int read_int() {
    int val; 
    scanf("%d", &val);
    return val;
}


// function to print binary representation of 
// an integer value. progressively divide by two
// then stack remainders. binary is obtained
void print_binary(int val) {
    char binary_rep[32];
    int index = -1;

    // value has to be greater than zero
    while (val > 0) {
        int remainder = (val % 2);
        char current = '0' + remainder;
        index++;
        binary_rep[index] = current;
        (val /= 2);
    }

    //check if index is neg
    if (index == -1) {
        index++;
        binary_rep[index] = '0';
    }

    int i = index;
    for (; i >= 0; i--) {
        printf("%c", binary_rep[i]);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}


// function to print hex representation of an integer value
// the given decimal value is progressively divided by 16
// and saving the remainder. hex is obtained by reading the 
// remainders.
void print_hex(int val) {
    char hex_rep[32];
    int index = -1;

    while (val > 0) {
        int remainder = val % 16;
        char current;
        if (remainder >= 10) {current = 'A' + remainder - 10;}
        else {
            current = '0' + remainder;
        }
        index++;
        hex_rep[index] = current;
        (val /= 16);
    }

    //check if index is neg
    if (index == -1) {
        index++;
        hex_rep[index] = '0';
    }

    printf("0x");
    int i = index;

    for (; i >= 0; i--) {
        printf("%c", hex_rep[i]);
    }
    printf("\n");
}


//main argument, based on command arguments
int main(int argc, char** argv) {
    //check for number of args, print usage
    if (argc != 2) {
        printf("Usage: ./convert [-x|-b]\n");
        return 0;
    }
    else if (strcmp(argv[1], "-b") == 0) {
        int val;
        // check for value, not eof
        while (scanf("%d", &val) != EOF) {
            print_binary(val);
        }
    }
    else if (strcmp(argv[1], "-x") == 0) {
        int val;
        // check for value, not eof
        while (scanf("%d", &val) != EOF) {
            print_hex(val);
        }
    }
    else {
        printf("incorrect argument, try again.\n");
        return 0;
    }
}