#include <string>

#include "../include/card.h"

Card::Card()
{
  word = "";
  match = "";
  faceUp = false;
}

Card::Card(std::string cardWord, std::string matchWord)
{
  word = cardWord;
  match = matchWord;
  faceUp = false;
}

std::string Card::getWord()
{
  return word;
}

std::string Card::getMatch()
{
  return match;
}

bool Card::getFaceUp()
{
  return faceUp;
}

void Card::setFaceUp(bool isFaceUp)
{
  faceUp = isFaceUp;
}
