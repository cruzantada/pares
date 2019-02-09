#ifndef PARES_H
#define PARES_H

#include <set>

#include "card.h"
#include "deck.h"
#include "board.h"

class Pares
{
private:
  Deck deck;
  Board board;
  int roundNum;
  std::set<int> matchedCards;

public:
  Pares();
  void loadBoard();
  void checkMatch(int firstGuess, int secondGuess);
  void getGuesses();
  bool play();
};

#endif // PARES_H
