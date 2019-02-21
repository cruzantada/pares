#ifndef PARES_H
#define PARES_H

#include "card.h"
#include "deck.h"
#include "board.h"

const int ANIMATION_MSEC = 5;

// Function prototypes
void loadDeck();
void loadBoard();
void checkCardMatch(int firstGuess, int secondGuess);
void flipUnmatchedCardsDown(int firstGuess, int secondGuess);
void reshape(int width, int height);
void display();
void getKeyboardInput(unsigned char c, int x, int y);
void animate(int val);

#endif // PARES_H
