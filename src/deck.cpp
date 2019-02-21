#include "../include/deck.h"

void Deck::addCard(Card card)
{
  cards.push(card);
}

void Deck::removeCard()
{
  cards.pop();
}

Card Deck::getCard()
{
  return cards.front();
}

int Deck::getNumCards()
{
  return cards.size();
}
