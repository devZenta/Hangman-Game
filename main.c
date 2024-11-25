#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GameFunctions.h"

/*
 *Code utile pour piocher un mot aléatoire dans la words list dans le fichier GameFunctions.c
 *(PS : enlever la fonction qui va chercher un mot aleatoire dans le fichier .txt)
 * char* word = RandomWord();
*/


/*
 *Code pour jouer de façon à ce que l'utilisateur rentre le mot à deviner
 * const char word[100];
 * printf("Entrez le mot a deviner : \n");
 * scanf("%s", word);
*/



int main(void) {
    srand(time(NULL));

    int playAgain = 1;

    while (playAgain) {

        LaunchDisplay();

        char* word = GetRandomWordTextFile("words.txt");

        PlayHangmanGame(word);

        playAgain = PlayAgain();
    }
    return 0;
}