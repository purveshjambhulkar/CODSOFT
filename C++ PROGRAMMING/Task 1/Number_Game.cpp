#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGame {
private:
    string player_name;
    int random_num;
    int wins = 0;
    int max_attempts = 7;
    int rounds = 1;

public:
    NumberGame() {
      
        srand(time(nullptr));
    }

    int randomNum() {
        random_num = rand() % 51;
        return random_num;
    }

    void game() {
        cout << "-----Round " << rounds << "-----" << endl;
        cout << "GUESS THE NUMBER FROM 1 TO 50" << endl;

        while (true) {
            if (max_attempts == 0) {
                cout << "SORRY!! YOU ARE OUT OF MOVES" << endl;
                break;
            }

            int num;
            cin >> num;

            if (num == random_num) {
                cout << "CONGRATS " << player_name << "!! YOU GUESSED CORRECTLY" << endl;
                wins++;
                break;
            } else if (num <= random_num + 5 && num >= random_num - 5) {
                if (num <= random_num + 5 && num >= random_num) {
                    cout << "Your guess is slightly high. Keep going!" << endl;
                } else if (num >= random_num - 5 && num <= random_num) {
                    cout << "Your guess is slightly low. Keep going!" << endl;
                }

                cout << "Attempts left: " << --max_attempts << endl;
                cout << "Guess Again" << endl;
            } else if (num <= random_num + 10 && num >= random_num - 10) {
                if (num <= random_num + 10 && num >= random_num) {
                    cout << "Your guess is slightly high. Keep going!" << endl;
                } else if (num >= random_num - 10 && num <= random_num) {
                    cout << "Your guess is slightly low. Keep going!" << endl;
                }

                cout << "Attempts left: " << --max_attempts << endl;
                cout << "Guess Again" << endl;
            } else {
                if (num > random_num) {
                    cout << "Your guess is too high. Try a smaller number" << endl;
                } else {
                    cout << "Your guess is too low. Try a larger number" << endl;
                }

                cout << "Attempts left: " << --max_attempts << endl;
                cout << "Guess Again" << endl;
            }
        }
    }

    void greet() {
        cout << "Enter your name: ";
        cin >> player_name;
        cout << "HELLO " << player_name << "!!!" << endl;
        cout << "WELCOME TO GUESS THE NUMBER GAME!!!" << endl;
        cout << "LET'S BEGIN!!!" << endl;
        cout << endl;
    }

    void play() {
        greet();

        while (true) {
            randomNum();
            game();
            cout << endl;
            cout << "You played " << rounds << " Round" << endl;
            cout << "Your Score is " << wins << endl;
            cout << endl;
            cout << "Do you want to play another round?" << endl;
            cout << "Enter 1 for Yes, 0 for No: ";
            
            int yes_no;
            cin >> yes_no;
            
            if (yes_no == 1) {
                rounds++;
                max_attempts = 7;
                cout << endl;
                continue;
            } else {
                cout << endl;
                cout << "You played " << rounds << " Rounds" << endl;
                cout << "Your Score is " << wins << endl;
                break;
            }
        }
    }
};

int main() {
    NumberGame obj1;
    obj1.play();
    return 0;
}
