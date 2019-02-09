#include <queue>

#include "../include/deck.h"

Card Deck::getCard()
{
  return cards.front();
}

void Deck::addCard(Card card)
{
  cards.push(card);
}

void Deck::removeCard()
{
  cards.pop();
}

int Deck::getNumCards()
{
  return cards.size();
}

bool Deck::isEmpty()
{
  return cards.empty();
}
