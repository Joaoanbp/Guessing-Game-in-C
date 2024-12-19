#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ATTEMPTS 3

int main(){
    printf("-----------------------------\n");
    printf("*Welcome to the Guessing Game!*\n");
    printf("-----------------------------\n\n");

    srand(time(0));
    int numerosecreto = rand() % 100;

    int guess, nivel, totaltentativas, correct;
    double pontos = 1000;

    printf("What level of difficulty you want?\n");
    printf("-> (1) Easy - (2) Medium - (3) Hard\n\n");
    scanf("%d", &nivel);

switch(nivel){
    case 1:
        totaltentativas = 15;
        break;
    case 2:
        totaltentativas = 10;
        break;
    default:
    totaltentativas = 5;
        break;
}
//loop principal do jogo
   for(int i = 1; i <= totaltentativas; i++){
        printf("-> What will be your %dº of %d attempt?\n", i, totaltentativas);
        scanf("%d", &guess);
        int correct = guess == numerosecreto;

        if(guess < 0){
            printf("You can't guess negative numbers. Please try again.\n");
            i--;
            continue;
        }


        if(correct){
            printf("Congratulations! You guessed it right!\n\n");
            printf("You win and made %.2f points!\n", pontos);
            break;         
        }else if(guess > numerosecreto){
            printf("\nYour guess was higher than the secret one. Try again!\n");
        }else{
            printf("\nYour guess was lower than the secret one. Try again!\n");
        }
        

        //quantidade de pontos
        double pontosperdidos = abs(guess - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }
        if(!correct){
        printf("\nYou lose! Try again!\n\n");
        }

    return 0;
}