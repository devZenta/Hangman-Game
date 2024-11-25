//
// Created by zenta on 24/11/2024.
//

#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

void HangmanDisplay(int lives);
char* RandomWord();
char* GetRandomWordTextFile(const char* filename);
void LaunchDisplay();
int GameStatusCheck(int lives, char* word, char finalWord[100], int lettersFound, int wordSize);
int PlayAgain();
void PlayHangmanGame(char* word);

#endif //GAMEFUNCTIONS_H
