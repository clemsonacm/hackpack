#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{

	int i;
	int guess = 0;
	srand(time(NULL));
	int num_to_guess = rand()%10 + 1;

	for (i = 0; guess != num_to_guess && i < 10; ++i)
	{
		scanf("%d", &guess);	
		if (guess == num_to_guess){
			printf("That was correct!\n");

		} else if (guess < num_to_guess){
			printf("That was too low!\n");

		} else {
			printf("That was too high!\n");

		}
	}

	if ( guess != num_to_guess) {
		while(true){
			printf("Wow you are really bad at this");
		}
	}

	return 0;
}
