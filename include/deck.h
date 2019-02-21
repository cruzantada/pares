#ifndef DECK_H
#define DECK_H

#include <queue>

#include "card.h"

class Deck
{
private:
  std::queue<Card> cards;

public:
  void addCard(Card card);
  void removeCard();
  Card getCard();
  int getNumCards();
};

#endif // DECK_H
