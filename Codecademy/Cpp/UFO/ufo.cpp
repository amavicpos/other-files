#include "ufo_functions.hpp"

int main() {
  greet();

  string codeword = "codecademy";
  string answer = "__________";
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;
  char letter;

  while ((answer != codeword) && (misses < 7)) {
    display_misses(misses);
    display_status(incorrect, answer);

    cout << "Please enter your guess: ";
    cin >> letter;
    for (int i = 0; i < codeword.length(); ++i) {
      if (letter == codeword[i]) {
        answer[i] = letter;
        guess = true;
      }
    }

    if (guess) {
      cout << "Correct!" << endl;
    } else {
      cout << "Incorrect! The tractor beam pulls the person in further." << endl;
      incorrect.push_back(letter);
      ++misses;
    }

    guess = false;
  }

  end_game(answer, codeword);

  return 0;
}
