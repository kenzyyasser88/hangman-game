#include <iostream>
using namespace std;
bool checkGuess(char guess, string secret, string* displayWord) {
    bool found = false;
    for (int i = 0; i < secret.length(); i++) {
        if (secret[i] == guess) {
        
            (*displayWord)[i] = guess;
            found = true;
        }
    }
    return found;
}
void startGame() {
   
    string secretWord = "programming";
    string guessedWord(secretWord.length(), '_');
    int lives = 6;
    char userGuess;

   
    int* pLives = &lives;

    cout << "--- Welcome to Hangman Game ---" << endl;

    while (*pLives > 0 && guessedWord != secretWord) {
        cout << "\nWord: " << guessedWord << endl;
        cout << "Lives left: " << *pLives << endl;
        cout << "Enter a letter: ";
        cin >> userGuess;

        if (checkGuess(userGuess, secretWord, &guessedWord)) {
            cout << "Good job! Correct letter." << endl;
        }
        else {
            (*pLives)--;
            cout << "Wrong guess! Try again." << endl;
        }
    }

    if (guessedWord == secretWord) {
        cout << "\nCongratulations! You guessed the word: " << secretWord << endl;
    }
    else {
        cout << "\nGame Over! The word was: " << secretWord << endl;
    }
}

int main() {
   
    startGame();
    return 0;
}
