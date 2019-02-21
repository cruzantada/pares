#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <array>

#include "card.h"

class Board
{
private:
  std::array<Card, 9> boardArr;

public:
  Board();
  void addCard(Card card, int index);
  std::string getCardWord(int index);
  std::string getCardMatch(int index);
  void flipCardUp(int index);
  void flipCardDown(int index);
  void setCardNumbers();
  void setCardFillColors(float r, float g, float b);
  void setCardPositions();
  void displayCards();
  int getNumCards();
  void shuffleCards();
};

#endif // BOARD_H
