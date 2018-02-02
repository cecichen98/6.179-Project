#include <iostream>
#include <string>

bool isValidGuess(const char guess, std::string attemptedGuesses)
{
    for (std::string::size_type i = 0; i != attemptedGuesses.size(); i++)
    {
        if (guess == attemptedGuesses[i]) 
        {
            return false;
        }
    }
    return true;
}

bool isCorrectGuess(const char guess, std::string const& word) 
{
    return (word.find(guess) != std::string::npos);
}

std::string updateWrongGuesses(const char guess, std::string wrongGuesses)
{
    return wrongGuesses += guess;
}

std::string updateCorrectGuesses(const char guess, std::string const& word, std::string correctGuesses)
{
    for (std::string::size_type i = 0; i != word.size(); ++i)
    {
        if (word[i] == guess)
        {
            correctGuesses[i] = guess;
        }
    }

    return correctGuesses;
}

void displayStatus(const unsigned int triesLeft, std::string const& guessedWord, std::string const& wrongGuesses)
{
    std::cout << "\nRemaining Tries: " << triesLeft;
    std::cout << "\nWrong Guesses  : " << wrongGuesses;
    std::cout << "\n\n" << guessedWord ;
}

int main()
{
    const std::string word = "coding";

    std::string guessedWord;

    for (std::string::size_type i = 0; i != word.size(); ++i)
    {
        guessedWord += (isspace(word[i])) ? ' ' : '*';
    }

    unsigned int triesLeft = 5;
    std::string wrongGuesses;

    displayStatus(triesLeft, guessedWord, wrongGuesses);

    std::string attemptedGuesses;

    while (triesLeft > 0 && guessedWord != word)
    {
        std::cout << "\n\nGuess a letter: ";
        char guess;
        std::cin >> guess;
        guess = tolower(guess);
        
        if (isValidGuess(guess, attemptedGuesses)) {
            attemptedGuesses += guess;
            if (isCorrectGuess(guess, word))
            {
                guessedWord = updateCorrectGuesses(guess, word, guessedWord);
            }
            else
            {
                wrongGuesses = updateWrongGuesses(guess, wrongGuesses);
                triesLeft--;
            }
        }
        else
        {
            std::cout << "\nInvalid guess! Try again.\n\n";
        }

        displayStatus(triesLeft, guessedWord, wrongGuesses);
    }

    if (guessedWord == word)
    {
        std::cout << "\nYou've guessed the word/phrase!\n";
    }
    else
    {
        std::cout << "\n\nGame Over :(\n\n";
        std::cout << "The word is: " << word;
        std::cout << "\n";
    }
}