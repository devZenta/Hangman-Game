//
// Created by zenta on 24/11/2024.
//


#include "GameFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void HangmanDisplay(int lives) {
    switch (lives) {
        case 6:
            printf("\n     _______\n     |/    |\n     |     \n     |     \n     |     \n     |     \n     |_____\n");
        break;
        case 5:
            printf("\n     _______\n     |/    |\n     |     O\n     |     \n     |     \n     |     \n     |_____\n");
        break;
        case 4:
            printf("\n     _______\n     |/    |\n     |     O\n     |     |\n     |     \n     |     \n     |_____\n");
        break;
        case 3:
            printf("\n     _______\n     |/    |\n     |     O\n     |    /|\n     |     \n     |     \n     |_____\n");
        break;
        case 2:
            printf("\n     _______\n     |/    |\n     |     O\n     |    /|\\\n     |     \n     |     \n     |_____\n");
        break;
        case 1:
            printf("\n     _______\n     |/    |\n     |     O\n     |    /|\\\n     |    / \n     |     \n     |_____\n");
        break;
        case 0:
            printf("\n     _______\n     |/    |\n     |     O\n     |    /|\\\n     |    / \\\n     |     \n     |_____\n");
        break;
    }
}




char *wordsList[] = {"ordinateur", "voiture", "avion", "maison", "chat", "chien", "banane", "porte", "clavier", "table",
        "manger", "ecole", "jardin", "telephone", "montagne", "mer", "soleil", "lune", "nuage", "arbre",
        "foret", "fleur", "bicyclettes", "parapluie", "chaise", "stylo", "cafe", "musique", "peinture",
        "bureau", "papier", "compteur", "lampadaire", "valise", "bureau", "robot", "television", "programme",
        "internet", "guitare", "piano", "violon", "ballet", "danse", "chocolat", "bonbon",
        "caramel", "fromage", "pain", "croissant", "pizza", "poulet", "salade", "vin", "bordeaux",
        "champagne", "refrigerateur", "micro-ondes", "four", "chauffage", "climatisation", "ventilateur",
        "velo", "camion", "bateau", "piscine", "plage", "merveilleux", "supercalifragilisticexpialidocious",
        "python", "programmation", "algorithme", "developpeur", "compiler", "debuguer", "bug", "code",
        "application", "base", "donnees", "calculatrice", "serveur", "cloud", "machine",
        "apprentissage", "intelligence", "artificielle", "robotique", "scientifique", "revolutionnaire",
        "plomberie", "electricite", "isolation", "fenetre", "toiture", "plafond", "mur", "sol", "escaliers",
        "fenetre", "porte", "moquette", "parquet", "peinture", "decorateur", "cuisine", "salon", "chambre",
        "draps", "matelas", "oreiller", "grillade", "barbecue", "grill", "pain", "boisson", "soupe", "chiffre",
        "ciel", "flocon", "neige", "hiver", "automne", "printemps", "ete", "nuit", "jour", "merveille",
        "magie", "secret", "mystere", "dechiffrer", "enigme", "cache", "resoudre", "solution", "devinette",
        "pensee", "reflexion", "philosophie", "mysterieux", "etrange", "question", "reponse", "chercher",
        "trouver", "cle", "cadenas", "serrure", "coffre", "caisse", "portefeuille", "bourse", "argent", "bancaire",
        "banque", "credit", "investir", "finances", "economie", "monnaie", "taux", "inflation", "livret", "compte",
        "aventure", "decouverte", "liberte", "voyage", "exploration", "mars", "saturne", "planete", "astronaute",
        "espace", "asteroide", "comete", "galaxie", "univers", "etoile", "lune", "satellite", "astronomie",
        "boussole", "carte", "voyageur", "chemin", "route", "paysage", "monts", "village", "rues", "sentier",
        "colline", "rivieres", "mer", "océan", "continent", "atlantiques", "territoire", "frontiere", "pays",
        "vitesse", "accelerer", "frein", "motorisation", "drift", "circuit", "rallye", "compteurs", "carburant",
        "remorque", "batterie", "pneu", "chaussures", "veste", "doudoune", "pull", "chaussettes", "casquette",
        "epaule", "biceps", "sport", "entraineur", "courir", "sauter", "nager", "gymnastique", "flexion",
        "abdos", "casse", "energie", "muscles", "soulever", "force", "entrainement", "physique", "souplesse",
        "energie", "robuste", "endurance", "flexible", "perseverance", "volonte", "determination", "musicien",
        "instrument", "chorale", "orchestre", "concert", "symphonie", "basse", "batterie", "guitare", "piano",
        "chant", "composition", "melodie", "opera", "ballade", "festival", "composition", "artiste", "peintre",};



char* RandomWord() {
    int size = sizeof(wordsList) / sizeof(wordsList[0]);
    int randomNumber = rand() % size;
    return wordsList[randomNumber];
}




char* GetRandomWordTextFile(const char* filename) {
    static char word[256];
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    int wordCount = 0;
    while (fgets(word, sizeof(word), file)) {
        wordCount++;
    }

    if (wordCount == 0) {
        printf("Le fichier est vide.\n");
        fclose(file);
        exit(1);
    }

    srand(time(NULL));
    int randomIndex = rand() % wordCount;

    rewind(file);

    for (int i = 0; i <= randomIndex; i++) {
        fgets(word, sizeof(word), file);
    }

    word[strcspn(word, "\n")] = '\0';

    fclose(file);
    return word;
}



void LaunchDisplay() {

    printf("     +--------------------------------------------------+\n");
    printf("     |            Commencement de la partie             |\n");
    printf("     +--------------------------------------------------+\n");
}

int GameStatusCheck(int lives, char* word, char finalWord[100], int lettersFound, int wordSize) {

    int result = 0;

    if (lettersFound == wordSize - 2) {

        printf("\n");
        printf("     +---------------------------------------------------------------------------+\n");
        printf("             Bravo, vous avez trouve le mot mystere : %s\n", word);
        printf("     +---------------------------------------------------------------------------+\n");

        result = 1;
        return result;
    }

    if (lives == 0) {

        printf("\n");
        printf("     +---------------------------------------------------------------------------+\n");
        printf("             Votre derniere reponse : %s\n", finalWord);
        printf("             Dommage ! Vous avez perdu. Le mot etait : %s\n", word);
        printf("     +---------------------------------------------------------------------------+\n");

        result = 1;
        return result;
    }

    return result;
}

int PlayAgain() {
    int result = 1;

    printf("\n");
    printf("     +---------------------- +  +------------------------+\n");
    printf("     | 0. Quitter le jeu     |  | 1. Relancer une partie |\n");
    printf("     +---------------------- +  +------------------------+\n");
    printf("\n");
    scanf("%d", &result);

    if (result == 0) {
            printf("     +--------------------------------------------------+\n");
            printf("     |            Fin de la partie                      |\n");
            printf("     +--------------------------------------------------+\n");
        }

    return result;
}

void PlayHangmanGame(char* word) {

    char finalWord[100];
    int lives = 6;
    int wordSize;
    int lettersFound = 0;

    wordSize = strlen(word);

    for (int i = 0; i < wordSize; i++) {
        finalWord[i] = '_';
    }

    char firstLetter = word[0];
    char lastLetter = word[wordSize - 1];
    finalWord[0] = firstLetter;
    finalWord[wordSize - 1] = lastLetter;

    while (lives > 0 && lettersFound < wordSize - 2) {
        char letterRoundInput;
        int checkAddLiveOrSuprLive = 0;

        printf("\n");
        printf("     +---------------------------------------------------------------------------+\n");
        printf("             Mot a deviner : %s\n", finalWord);
        printf("     +---------------------------------------------------------------------------+\n");
        printf("             Vies restantes : %d\n", lives);
        printf("     +---------------------------------------------------------------------------+\n");
        printf("             Entrez une lettre :\n");
        printf("     +---------------------------------------------------------------------------+\n");

        scanf(" %c", &letterRoundInput);


        letterRoundInput = tolower(letterRoundInput);


        for (int i = 0; i < wordSize; i++) {
            if (word[i] == letterRoundInput && finalWord[i] == '_') {
                finalWord[i] = word[i];
                lettersFound++;
                checkAddLiveOrSuprLive = 1;
            }
        }

        if (checkAddLiveOrSuprLive == 0) {
            lives--;
            HangmanDisplay(lives);
        }

        if (GameStatusCheck(lives, word, finalWord, lettersFound, wordSize) == 1) {
            break;
        }
    }
}
