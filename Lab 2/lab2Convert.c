#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Name: Jaden Miguel
// Date: Summer 2020 - CSCI247
// Purpose: Lab 2: Bases & Bits


// i. itoa function 
char* itoa(int num, char* str, int base);
void numSwap(char* num1, char* num2);
char* reverseNumber(char* str, int a, int b);

// ii. bit manipulation
int countSetBits(unsigned int var);
int reverseBits(int var);
bool onlyOneBitSet(int aVar);


int main() {
    char buffer[50];

    int num1;
    int base;

    printf("\nWelcome to Jaden's lab2. Happy to have you! ☺️\n");
    printf("Enter two integers separated with a space. \nFirst is your specified integer and the second your desired base: ");
    scanf("%i %i", &num1, &base);

    printf("\nItoa invoked: %s \n", itoa(num1, buffer, base));

	printf("Number of set bits in first input: %i \n", countSetBits((unsigned)num1));

	printf("Reverse bit representation: %i \n", reverseBits(num1));
    
	printf("Only one bit is set: %s \n", (onlyOneBitSet(num1)) ? "true" : "false");
	printf("\n");


	// tests I initially used
    //printf("%s",itoa(456, buffer, 12));

    //unsigned int inputNum = 28;
    //printf("%d \n", countSetBits(inputNum));

    //int inputNum = 1;
    //printf("%d \n", reverseBits(inputNum));

    //int input = 4;
    //printf("%s \n", (onlyOneBitSet(input)) ? "true" : "false");

}


// this function should return true 
// if only one bit is set in the argument 
// passed in, and should return false otherwise.
bool onlyOneBitSet(int aVar) {
    int setBits = 0;
	int counter = 0x7FFFFFFF;
	
	while (counter) {
		if (aVar & 1) {
			setBits++;
		}
		aVar = aVar >> 1;
		counter = counter >> 1;
	}
	if (setBits == 1) {
		return true;
	} 
    else {
	    return false;
	}
}



// this function will return the reverse bit representation
int reverseBits(int var) {
    int mask_a = 85; //(0x55)
    int mask_b = 51; //(0x33)
    int mask_c = 15; //(0x33)
    int mask_d = 0; //(0x00)
    int mask_e = 255; //(0xff)
    
    mask_a = (mask_a | (mask_a<<8));
    mask_a = (mask_a | (mask_a<<16));
              
    mask_b = (mask_b | (mask_b<<8));
    mask_b = (mask_b | (mask_b<<16));
    

    mask_c = (mask_c | (mask_c<<8));
    mask_c = (mask_c | (mask_c<<16));
    
    mask_d = ((mask_d<<8) | 255); 
    mask_d = (mask_d | (mask_d<<16));
    
    mask_e = (mask_e | (mask_e<<8));
    mask_e = (mask_e | 00);
    
    var = ((var>>1)&(mask_a)) | ((var & mask_a)<<1);
    var = ((var>>2)&(mask_b)) | ((var & mask_b)<<2);
    var = ((var>>4)&(mask_c)) | ((var & mask_c)<<4);
    var = ((var>>8)&(mask_d)) | ((var & mask_d)<<8);
    var = ((var>>16)&(mask_e)) | ((var & mask_e)<<16);
    return var;
}



//return the number of set bits in an integer
int countSetBits(unsigned int var) {
	unsigned int numSetBits = 0;
	
	while (var) {
		numSetBits += var&1;
		var >>= 1;
	}	
	return numSetBits;
}


//swaps numbers, uses a temp variable
void numSwap(char* num1, char* num2){
	char temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


//function to reverse input
char* reverseNumber(char* str, int a, int b){
	while (a < b) {
	    numSwap(&str[a++], &str[b--]);
	}
	return str;
}

//will convert num to any base as specified
char* itoa(int num, char* str, int base) {
	
	int unsignedVal = abs(num);
	int i = 0;
	
	while (unsignedVal) {
		int remainder = unsignedVal % base;
		
		if (remainder >= 10) {
			str[i++] = 65 + (remainder - 10);
		}
		else {
			str[i++] = 48 + remainder;
		}
		unsignedVal = (unsignedVal / base);
	}
	
	if (i == 0) {
		str[i++] = '0';
	}
	
    if (num < 0) {
        str[i++] = '-';
    }
	
	str[i] = '\0';

	
	return reverseNumber(str, 0, i-1);

}










