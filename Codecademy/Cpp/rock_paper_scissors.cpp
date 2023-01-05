/*
Rock, Paper, Scissors, Lizard, Spock:
This program takes the user's input, compares it with a random element among the game options and informs the user who the winner is.
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

int main() {
  srand (time(NULL));
  int computer = rand() % 3 + 1;
  string user = "";
  int user_int = 0;

  cout << "====================\n";
  cout << "rock paper scissors!\n";
  cout << "====================\n";
  
  cout << "1) Rock\n";
  cout << "2) Paper\n";
  cout << "3) Scissors\n";
  cout << "4) Lizard\n";
  cout << "5) Spock\n";
  cout << "Make your choice: ";

  while (true) {
    try {
      cin >> user;
      user_int = stoi(user);
      break;
    }
    catch (invalid_argument) {
      cout << "Please enter a number: ";
    }
  }

  while (user_int < 1 || user_int > 5) {
    cout << "Please enter a valid number: ";
    cin >> user_int;
  }

  int comb[2] = {user_int, computer};
  string choices[5] = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};
  cout << "Your choice: " << choices[comb[0]-1] << endl;
  cout << "The choice of the computer: " << choices[comb[1]-1] << endl;

  int winning_combinations[10][2] = {{3, 2}, {2, 1}, {1, 4}, {4, 5}, {5, 3}, {3, 4}, {4, 2}, {2, 5}, {5, 1}, {1, 3}};
  for (int i = 0; i < 10; ++i) {
    if (comb[0] == comb[1]) {
      cout << "It is a tie." << endl;
      break;
    }
    if (winning_combinations[i][0] == comb[0] && winning_combinations[i][1] == comb[1]) {
        cout << "You won, congratulations!" << endl;
        break;
    } else if (winning_combinations[i][0] == comb[1] && winning_combinations[i][1] == comb[0]) {
        cout << "The computer won." << endl;
        break;
    }

  }

  return 0;
}
