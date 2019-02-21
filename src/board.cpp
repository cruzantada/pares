#include <algorithm>
#include <random>
#include <chrono>

#include "../include/board.h"

Board::Board()
{
  boardArr = { };
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

void Board::setCardNumbers()
{
  for (int i = 0; i < boardArr.size(); ++i)
  {
    boardArr[i].setNum(i);
  }
}

void Board::setCardFillColors(float r, float g, float b)
{
  for (int i = 0; i < boardArr.size(); ++i)
  {
    boardArr[i].setFillColor(r, g, b);
  }
}

void Board::setCardPositions()
{
  boardArr[0].setPosition(50, 450, 200, 600);
  boardArr[1].setPosition(250, 450, 400, 600);
  boardArr[2].setPosition(450, 450, 600, 600);

  boardArr[3].setPosition(50, 250, 200, 400);
  boardArr[4].setPosition(250, 250, 400, 400);
  boardArr[5].setPosition(450, 250, 600, 400);

  boardArr[6].setPosition(50, 50, 200, 200);
  boardArr[7].setPosition(250, 50, 400, 200);
  boardArr[8].setPosition(450, 50, 600, 200);
}

void Board::displayCards()
{
  for (int i = 0; i < boardArr.size(); ++i)
  {
    boardArr[i].display();
  }
}

int Board::getNumCards()
{
  return boardArr.size();
}

void Board::shuffleCards()
{
  // Obtain time-based seed
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  std::shuffle(boardArr.begin(), boardArr.end(), std::default_random_engine(seed));
}
