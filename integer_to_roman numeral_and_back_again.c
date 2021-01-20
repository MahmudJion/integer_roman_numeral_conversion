/*
Applicants programming exercises for admission fall 2021
Assignment: Integer to roman numeral, and back again

assignment (c)

A program that uses the functions from (a) and (b) from assigment to write out all the numbers from
1 to 3999 as Roman numerals, and then convert them back to, and print them out, as integers.*/

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

static char *int_to_roman(int val) // function to convert integer to roman numerals
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

int roman_to_int (char);  //function prototype of conversion function

int roman_to_int(char numeral){ // function to converting roman numeral

    int value=0;

    switch(numeral){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1;
    }

    return value;
}

int main(void) //main function for running the integer to roman function and roman to integer
 {
	int number;

	int i = 1;
    char roman_Number[4000]; //array for storing roman number

    for(number=1; number<4000; number++)
    {
        printf("\nRoman numerals: %s", int_to_roman(number)); //displaying converted integer values
    }

    for(number=1; number<4000; number++)
    {
        roman_Number[4000] = int_to_roman(number);

        while(roman_Number[i]){ //checking the input value with while loop and call the conversion function for integer to roman
             if(roman_to_int(roman_Number[i]) >= roman_to_int(roman_Number[i+1]))
                 number = number + roman_to_int(roman_Number[i]);
             else{
                 number = number + (roman_to_int(roman_Number[i+1]) - roman_to_int(roman_Number[i]));
             }
             i++;
        }

        printf("\nInteger Values: %d",number); //displaying converted integer values

    }

    return 0;
}
