#include <string>
#include <fstream>
#include <set>

#include "card.cpp"
#include "deck.cpp"
#include "board.cpp"

#include "../include/pares.h"

// Global variables
bool start = true;
bool newRound = true;
bool firstSelection = true;
bool checkMatchPause = false;
Deck deck;
Board board;
int guess;
int guessOne = 99;
int guessTwo = 99;
std::set<int> matchedCards;

void loadDeck()
{
  std::string inFileName = "../data/words.txt";
  std::ifstream inFile;
  std::string enWord, esWord;

  inFile.open(inFileName);

  if (inFile.is_open())
  {
    while (inFile)
    {
      std::getline(inFile, enWord);
      std::getline(inFile, esWord);
      deck.addCard(Card(enWord, esWord));
      deck.addCard(Card(esWord, enWord));
    }

    inFile.close();
  }
}

void loadBoard()
{
  if (deck.getNumCards() >= 8)
  {
    board.addCard(Card(" ", " "), 0); // Empty ninth card

    for (int i = 1; i < board.getNumCards(); ++i)
    {
      board.addCard(deck.getCard(), i);
      deck.removeCard();
    }

    board.shuffleCards();
    board.setCardNumbers();
    board.setCardFillColors(0, 1, 1);
    board.setCardPositions();
  }
  else // Not enough cards in deck
  {
    exit(0);
  }
}

void checkCardMatch(int firstGuess, int secondGuess)
{
  if (board.getCardWord(firstGuess) == board.getCardMatch(secondGuess))
  {
    matchedCards.insert(firstGuess);
    matchedCards.insert(secondGuess);
  }
}

void flipUnmatchedCardsDown(int firstGuess, int secondGuess)
{
  if (!matchedCards.count(firstGuess))
  {
    board.flipCardDown(firstGuess);
    board.flipCardDown(secondGuess);
  }
}

void reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)width, 0.0, (GLdouble)height);
}

void display()
{
  if (start)
  {
    loadDeck();
    start = false;
  }

  if (newRound)
  {
    loadBoard();
    newRound = false;
  }

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // if (firstSelection)
  // {
  //   glRasterPos2i(5, 600);
  //   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
  // }
  // else
  // {
  //   glRasterPos2i(5, 600);
  //   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
  // }

  board.displayCards();
  glFlush();
  glutSwapBuffers();
}

void getKeyboardInput(unsigned char c, int x, int y)
{
  switch (c)
  {
    case '0':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '1':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '2':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '3':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '4':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '5':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '6':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '7':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case '8':
      guess = c - '0';

      if (matchedCards.count(guess) || guessOne == guess || checkMatchPause)
      {
        break;
      }
      else
      {
        board.flipCardUp(guess);
      }

      if (firstSelection)
      {
        guessOne = guess;
        firstSelection = false;
        break;
      }
      else
      {
        guessTwo = guess;
        checkCardMatch(guessOne, guess);
        firstSelection = true;
        checkMatchPause = true;
        break;
      }

    case 'q':
      exit(0);
      break;

    default:
      if (checkMatchPause)
      {
        flipUnmatchedCardsDown(guessOne, guessTwo);
        guessOne = 99;
        checkMatchPause = false;

        if (matchedCards.size() == 8)
        {
          matchedCards.clear();
          newRound = true;
        }

        break;
      }
      else
      {
        break;
      }
  }
}

void animate(int val)
{
  glutPostRedisplay();
  glutTimerFunc(ANIMATION_MSEC, animate, 0);
}
