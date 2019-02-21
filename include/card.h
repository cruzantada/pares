#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
private:
  std::string word, match;
  bool faceUp;
  float r, g, b;
  int num, lX, lY, rX, rY;

public:
  Card();
  Card(std::string cardWord, std::string matchWord);
  std::string getWord();
  std::string getMatch();
  void setFaceUp(bool isFaceUp);
  void setFillColor(float red, float green, float blue);
  void setPosition(int leftX, int leftY, int rightX, int rightY);
  void setNum(int number);
  void display();
};

#endif // CARD_H
