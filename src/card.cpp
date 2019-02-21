#include <GL/glut.h>

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

void Card::setFaceUp(bool isFaceUp)
{
  faceUp = isFaceUp;
}

void Card::setFillColor(float red, float green, float blue)
{
  r = red;
  g = green;
  b = blue;
}

void Card::setPosition(int leftX, int leftY, int rightX, int rightY)
{
  lX = leftX;
  lY = leftY;
  rX = rightX;
  rY = rightY;
}

void Card::setNum(int number)
{
  num = number;
}

void Card::display()
{
  glColor3f(r, g, b);
  glRecti(lX, lY, rX, rY);
  glColor3f(1.0, 0.0, 0.0);

  if (faceUp)
  {
    glRasterPos2i(lX + 15, lY + 68);

    for (int i = 0; i < word.length(); i++)
    {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, word[i]);
    }
  }
  else
  {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(lX + 69, lY + 68);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0' + num);
  }
}
