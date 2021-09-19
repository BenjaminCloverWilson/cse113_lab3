/**
 * @file credit.c
 * @author Benjamin Wilson
 * @date September 18, 2021
 * @brief determine if a credit card is valid using Luhn's algorithm.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1
#define SIZE 32

void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);
void double_card(int card[], int num_digits);
int double_digits(int card[], int num_digits);
int undoubled_digits(int card[], int num_digits);
void validity(int card[], int sum);
void card_number(int card[], int size);


int main(void)
{
	int card[NUM_DIGITS];
        /* use visa to store the credit card number from stdin */
        char visa[SIZE + 1];

	/* Store sum information */
	int sum_doubled;
	int sum_undoubled;
	int sum;

	/* User input */
	printf("Please enter your (16 digit) credit card number: ");
	fgets(visa, SIZE + 1, stdin);

	/* Converts input into a number array for calculations and prints it out*/
	convert_card(card, visa, NUM_DIGITS);
	//print_card(card, NUM_DIGITS); /* Prints array for debugging */
	card_number(card, NUM_DIGITS);
	
	/* Luhn's Algorithm */
	double_card(card, NUM_DIGITS);
	//print_card(card, NUM_DIGITS); /* Prints array for debugging */
	sum_doubled = double_digits(card, NUM_DIGITS);
	sum_undoubled = undoubled_digits(card, NUM_DIGITS);
	sum = sum_doubled + sum_undoubled;

	/* Says if the card came back valid or not */
	validity(card, sum);

	return 0;

}

void convert_card(int card[], char num[], int num_digits)
{
	int i;

	for(i = 0; i < num_digits; i++)
		card[i] = num[i] - '0';

}


void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

/** Doubles every other number starting at the second to last number in array
 * @param card[] Array of card numbers
 */
void double_card(int card[], int num_digits)
{
	int i;
	for (i = num_digits - 2; i >= 0; i = i - 2)
	{
		card[i] *= 2;
	}
}

/** Sums the digits of all the doubled numbers in double_card()
 * @param card[] The array of all the card numbers (modified or not)
 * @result The sum of all the digits of the doubled numbers
 */
int double_digits(int card[], int num_digits)
{
	int i;
	int sum_multiply = 0;
	int m_tens;
	int m_ones;
	for(i = num_digits - 2; i >= 0; i = i - 2)
	{
		if (card[i] % 10 != 0)
		{
			m_ones = card[i] % 10;
		}

		m_tens = card[i] / 10;

		sum_multiply = sum_multiply + m_tens + m_ones;
	}
	
	return sum_multiply;
}

/** Sums the digits of all the unmodified numbers in double_card()
*@param card[] Array of card numbers (modified and unmodified)
* @result The sum of all the undoubled numbers in the array.
*/
int undoubled_digits(int card[], int num_digits)
{
	int i;
	int sum_undoubled = 0;
	/*adds the sum of the digits of the undoubled numbers and the sum 
	of the digits of the doubled numbers*/
	for(i = num_digits - 1; i >= 0; i = i - 2)
	{
		sum_undoubled = sum_undoubled + card[i];
	}
	
	return sum_undoubled;
}

/** Tests if the card is valid and prints out the result
* @param card[] Array of all the modified card numbers
* @param sum The sum of the results from double_digits() and undoubled_digits()
*/
void validity(int card[], int sum)
{
	/*
	This if value checks the validity of the card by taking the moldulo by 10 and checking if its zero
	*/
		if (sum % 10 != 0)
	{
		printf("\n\nCard is invalid\n\n");
	} else 
	{
		printf("\n\nCard is valid\n\n");
	}
}

/** Prints out the card number based on the inputted array's index values
 * @param card[] Array of card numbers.
 * @param size The size of the array.
 */
void card_number(int card[], int size)
{
	int i;
	printf("\nThe card number is: ");
	/*Prints out the value of the card number by printing the values of the array
*/
	for(i = 0; i < size; i++)
	{
		printf("%d", card[i]);
	}
	printf("\n");
}