/* Homework 1 Modified code from Head First C pg 37

	Alison Berkowitz 2014

	Evaluates values of cards and keeps a running count of the card game
*/

#include <stdio.h>
#include <stdlib.h>

/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(const char *prompt, char *card_name)
{
	puts(prompt);
	scanf("%2s", card_name);
}


/* 	Takes in a card_name and returns the value of the card
*/
int val(char *card_name)
{
	int val = 0;
	switch(card_name[0]){
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			break;
		default:
			val = atoi(card_name);
			if ((val<1)||(val>10)){
				puts("I don't understand that value");
			}
	}
	return val;
}


/*	Helps keep track of the number of high-value cards left

	If the card value is 10, the count goes down by 1
	If the card value is 3, 4, 5, or 6, the count goes up by 1

	value: integer value of the card
	count: the current count
*/
void counter(int *value, int *count)
{
	if ((*value>2) && (*value<7)){
		*count = *count+1;
	} else if (*value==10) {
		*count = *count-1;
	}
}

int main()
{
	char card_name[3];
	int value = 0;
	int count = 0;
	const char prompt[] = "Enter the card_name";
	while (card_name[0]!='X') {
		get_card_name(prompt,card_name);
		value = val(card_name);
		counter(&value, &count);
		printf("Current count: %i\n", count);
	}
	return 0;
}