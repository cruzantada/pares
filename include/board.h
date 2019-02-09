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
  int getSize();
  void shuffle();
  void display();
  void addCard(Card card, int index);
  std::string getCardWord(int index);
  std::string getCardMatch(int index);
  void flipCardUp(int index);
  void flipCardDown(int index);
};

#endif // BOARD_H
