#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
private:
  std::string word;
  std::string match;
  bool faceUp;

public:
  Card();
  Card(std::string cardWord, std::string matchWord);
  std::string getWord();
  std::string getMatch();
  bool getFaceUp();
  void setFaceUp(bool isFaceUp);
};

#endif // CARD_H
