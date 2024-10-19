#include <iostream>
#include <random>
#include <string>

using namespace std;

// Function to provide feedback on the guess
void provideFeedback(const string& guess, const string& randomNumber) {
    string feedback;

    for (int i = 0; i < 4; ++i) {
        if (guess[i] == randomNumber[i]) {
            feedback += '+'; // Correct place
        } else if (randomNumber.find(guess[i]) != string::npos) {
            feedback += '-'; // Wrong place
        } else {
            feedback += 'X'; // Incorrect digit
        }
    }

    cout << "Feedback: " << feedback << endl;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);

    // Generate a random number and convert it to string
    const int random_number = dis(gen);
    //cout<<random_number<<endl;
    const string randomNumber = to_string(random_number);

    string user_guess;
    const string players[2] = {"Player 1", "Player 2"};
    int currentPlayer = 0;

    cout << "Try to guess the number!" << endl;

    while (true) {
        cout << players[currentPlayer] << ", enter your guess (4-digit number): ";
        cin >> user_guess;

        // Check if the input is a valid 4-digit number
        if (user_guess.length() != 4){
            cout << "Please enter a valid 4-digit number." << endl;
            continue;
        }

        // Check if the guess is correct
        if (user_guess == randomNumber) {
            cout << "Congratulations " << players[currentPlayer] << " Won!" << endl;
            break;
        } else {
            // Provide feedback on the guess
            provideFeedback(user_guess, randomNumber);
            // Switch to the next player
            currentPlayer = (currentPlayer + 1) % 2;
        }
    }

    return 0;
}