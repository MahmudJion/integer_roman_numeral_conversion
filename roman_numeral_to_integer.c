/*
Applicants programming exercises for admission fall 2021
Assignment: Integer to roman numeral, and back again

Assignment (b)

Implementation of a C function roman_to_int() that takes the Roman numerals produced by the
function int_to_roman() in assignment (a) and convert them back to integers. The input is guaranteed
to be within the same range as in (a).
*/

#include<stdio.h>
#include<string.h>

int roman_to_int(char); //initialize conversion function with type

//main function where conversion of roman to integer function program run
int main(){

    char roman_Number[1000];
    int i=0;
    long int number =0;

    //user input a roman number with valid numerals
    printf("Enter any roman number with valid numerals are I, V, X, L, C, D, M:  \n");
    scanf("%s",roman_Number);

    //checking the input value with while loop and call the conversion function for integer to roman
    while(roman_Number[i]){
         if(roman_to_int(roman_Number[i]) < 0){
             printf("Invalid roman digit : %c",roman_Number[i]);
             return 0;
         }
         if((strlen(roman_Number) -i) > 2){
             if(roman_to_int(roman_Number[i]) < roman_to_int(roman_Number[i+2])){
                 printf("Invalid roman number");
                 return 0;
             }
         }
         if(roman_to_int(roman_Number[i]) >= roman_to_int(roman_Number[i+1]))
             number = number + roman_to_int(roman_Number[i]);
         else{
             number = number + (roman_to_int(roman_Number[i+1]) - roman_to_int(roman_Number[i]));
             i++;
         }
         i++;
    }


    //checking the output value with in range of 1 to 3999
    if(number <4000){
        printf("Its integer value is: %ld",number);
    } else {
        printf("Output data need be within the range from 1 to 3999.\n");
    }

    return 0;

}

// function to converting roman numeral
int roman_to_int(char numeral){

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
