/*
Applicants’ programming exercises for admission fall 2021
Assignment: Integer to roman numeral, and back again

assignment (a)

Implementation of a C function int_to_roman() that converts an integer to a roman numeral. The
input is guaranteed to be within the range of 1 to 3999 (inclusive).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void num_to_char(char **val, int bit, int n) // function to convert number to char
{
    int i;
    char low, mid, high;
    char *p = *val;

    switch (n) {
    case 2:
        low = 'C';
        mid = 'D';
        high = 'M';
    break;
    case 1:
        low = 'X';
        mid = 'L';
        high = 'C';
    break;
    case 0:
        low = 'I';
        mid = 'V';
        high = 'X';
    break;
    }

    if (bit > 0) {
        switch (bit) {
        case 1:
        case 2:
        case 3:
            for (i = 0; i < bit; i++) {
                *p++ = low;
            }
            break;
        case 4:
            *p++ = low;
            *p++ = mid;
            break;
        case 5:
            *p++ = mid;
            break;
        case 6:
        case 7:
        case 8:
            *p++ = mid;
            for (i = 5; i < bit; i++) {
                *p++ = low;
            }
            break;
        case 9:
            *p++ = low;
            *p++ = high;
            break;
        }
    }

    *val = p;
}

static char roman_numeral[64]; //array for storing roman number

static char *int_to_roman(int val)  // function to convert integer to roman numerals
{
    char *p = &roman_numeral[0];
    int thousand_bit_num = val / 1000;
    int hundred_bit_num = (val % 1000) / 100;
    int ten_bit_num = (val % 100) / 10;
    int one_bit_num = val % 10;
    int i;

    memset(roman_numeral, 0, sizeof(roman_numeral));

    if (thousand_bit_num > 0) {
        if (thousand_bit_num < 4) {
            for (i = 0; i < thousand_bit_num; i++) {
                *p++ = 'M';
            }
        }
    }

    num_to_char(&p, hundred_bit_num, 2);
    num_to_char(&p, ten_bit_num, 1);
    num_to_char(&p, one_bit_num, 0);

    return roman_numeral;
}

int main(void) //main function for running the integer to roman function
 {
	int number;
	printf("Enter an integer: "); //user input for an integer value
    scanf("%d",&number);


    if(number<=1 || number>=4000){ //checking the input value in the range of 1 to 3999
        printf("Input must be within the range from 1 to 3999.\n");
    }else{
        printf("\nRoman numeral: %s", int_to_roman(number)); //call the conversion function integer to roman as the input value in range of 1 - 3999
    }

    return 0;
}
