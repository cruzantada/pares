#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>

#include "../include/board.h"

Board::Board()
{
  boardArr = { };
}

int Board::getSize()
{
  return boardArr.size();
}

void Board::shuffle()
{
  // Obtain time-based seed
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  std::shuffle(boardArr.begin(), boardArr.end(), std::default_random_engine(seed));
}

void Board::display()
{
  for (int i = 0; i < boardArr.size(); ++i)
  {
    if (boardArr[i].getFaceUp())
    {
      std::cout << boardArr[i].getWord() << ' ';
    }
    else
    {
      std::cout << i << ' ';
    }

    if (i == 2 || i == 5 || i == 8)
    {
      std::cout << std::endl;
    }
  }
}

void Board::addCard(Card card, int index)
{
  boardArr[index] = card;
}

std::string Board::getCardWord(int index)
{
  return boardArr[index].getWord();
}

std::string Board::getCardMatch(int index)
{
  return boardArr[index].getMatch();
}

void Board::flipCardUp(int index)
{
  boardArr[index].setFaceUp(true);
}

void Board::flipCardDown(int index)
{
  boardArr[index].setFaceUp(false);
}
