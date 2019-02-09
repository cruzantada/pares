#include <iostream>
#include <fstream>
#include <set>
#include <tuple>

#include "card.cpp"
#include "deck.cpp"
#include "board.cpp"

#include "../include/pares.h"

Pares::Pares()
{
  roundNum = 1;
  std::string inFileName = "../data/words.txt";
  std::ifstream inFile;

  inFile.open(inFileName);

  if (inFile.is_open())
  {
    std::string enWord;
    std::string esWord;

    while (inFile)
    {
      std::getline(inFile, enWord);
      std::getline(inFile, esWord);
      deck.addCard(Card(enWord, esWord));
      deck.addCard(Card(esWord, enWord));
    }

    inFile.close();
  }
  else
  {
    std::cout << "Cannot open file: " << inFileName << std::endl;
  }
}

void Pares::loadBoard()
{
  board.addCard(Card(" ", " "), 0); // Empty ninth card

  for (int i = 1; i < board.getSize(); ++i)
  {
    board.addCard(deck.getCard(), i);
    deck.removeCard();
  }

  board.shuffle();
}

void Pares::checkMatch(int firstGuess, int secondGuess)
{
  if (board.getCardWord(firstGuess) == board.getCardMatch(secondGuess))
  {
    matchedCards.insert(firstGuess);
    matchedCards.insert(secondGuess);
  }
  else
  {
    board.flipCardDown(firstGuess);
    board.flipCardDown(secondGuess);
  }
}

void Pares::getGuesses()
{
  int guess;
  int guesses[2] = { 9, 9 };

  board.display();

  for (int i = 0; i < 2; ++i)
  {
    std::cout << "\nPlease select a card number: ";
    std::cin >> guess;

    while (guess < 0 || guess > 8 || guess == guesses[0] || matchedCards.count(guess) || std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please select a card number: ";
      std::cin >> guess;
    }

    guesses[i] = guess;
    board.flipCardUp(guess);

    std::cout << std::endl;
    board.display();
  }

  checkMatch(guesses[0], guesses[1]);
}

bool Pares::play()
{
  while (deck.getNumCards() >= board.getSize())
  {
    std::cout << "\n-- Round " << roundNum++ << " --\n";
    loadBoard();

    while (matchedCards.size() < board.getSize() - 1)
    {
      std::cout << std::endl;
      getGuesses();
      std::cout << "\n----\n";

      if (matchedCards.size() == 8)
      {
        matchedCards.clear();
        break;
      }
    }
  }
}
