/* 
Course: CSCI247 - Summer 2020
Filename: lab1Wow.c
Name: Jaden Miguel
*/


#include <stdio.h>
#include <string.h>

#define CHAR_DATA_TYPE "char"
#define INT_DATA_TYPE "int"
#define SIGNED_DATA_TYPE "signed"
#define SHORT_DATA_TYPE "short"
#define LONG_DATA_TYPE "long"
#define FLOAT_DATA_TYPE "float"
#define DOUBLE_DATA_TYPE "double"

void DataTypeSizes(void);

//read user input
char* GetStringFromStdin(char* str) {
    fgets(str, 100, stdin);
}

void DisplayString(const char* str) {
    printf("Your string is: %s", str);
}

int main(int argc, char* argv[]) {
    //print number of args
    printf("argc is: %d\n", argc);

    //print character args
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    printf("\n\n");

    DataTypeSizes();

    char str[100];
    
    printf("\nEnter a string: ");
    
    GetStringFromStdin(str);
    DisplayString(str);
}


void DataTypeSizes(void) {
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n", INT_DATA_TYPE, INT_DATA_TYPE, sizeof(int));
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n", SIGNED_DATA_TYPE, SIGNED_DATA_TYPE, sizeof(signed));
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n", SHORT_DATA_TYPE, SHORT_DATA_TYPE, sizeof(short));
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n", LONG_DATA_TYPE, LONG_DATA_TYPE, sizeof(long));
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n", FLOAT_DATA_TYPE, FLOAT_DATA_TYPE, sizeof(float));
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n", DOUBLE_DATA_TYPE, DOUBLE_DATA_TYPE, sizeof(double));
}
