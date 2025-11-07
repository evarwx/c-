# include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int random , guess;
    int no_of_guess =0;
    srand(time(NULL));

    printf ("Welcome to the Guessing Game!\n");
    random =rand()  % 100 +1; // Generate a random number between 1 and 100
    
    do {
        printf("plese enter your guess between  (1 to 100): ");
        scanf ("%d",&guess);
        no_of_guess++;

        if (guess < random ){
            printf ("guess a larger number. \n");
        } else if (guess > random ){
            printf ("guess a smaller number.\n");

        }else {
            printf ("congratulations  !!!You have guessed correct number in %d attempts",no_of_guess);
        }


    }while (guess != random);

    printf("\n thank you for playing have a good day");


}