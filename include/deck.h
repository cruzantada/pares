#ifndef DECK_H
#define DECK_H

#include <queue>

#include "card.h"

class Deck
{
private:
  std::queue<Card> cards;

public:
  Card getCard();
  void addCard(Card card);
  void removeCard();
  int getNumCards();
  bool isEmpty();
};

#endif // DECK_H
