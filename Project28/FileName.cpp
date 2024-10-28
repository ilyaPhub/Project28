#include <iostream>
#include <ctime>
using namespace std;

const int NUM_SYMBOLS = 6;
const char* symbols[NUM_SYMBOLS] = { "🍒", "🔔", "💎", "🍋", "⭐", "🍀" };

void spinReels(const char*& reel1, const char*& reel2, const char*& reel3) {
    reel1 = symbols[rand() % NUM_SYMBOLS];
    reel2 = symbols[rand() % NUM_SYMBOLS];
    reel3 = symbols[rand() % NUM_SYMBOLS];
}

bool isWinningCombo(const char* reel1, const char* reel2, const char* reel3) {
    return (reel1 == reel2 && reel2 == reel3);
}

void playGame() {
    char choice;
    do {
        const char* reel1;
        const char* reel2;
        const char* reel3;

        cout << "\n--- Spinning the reels! ---" << endl;

        spinReels(reel1, reel2, reel3);

        cout << reel1 << " " << reel2 << " " << reel3 << endl;

        if (isWinningCombo(reel1, reel2, reel3)) {
            cout << "Congratulations! You won!" << endl;
        }
        else {
            cout << "Try again." << endl;
        }

        cout << "Press Enter to play again (or any other key to exit): ";
        cin.ignore();
        choice = cin.get();

    } while (choice == '\n');
}

int main() {
    srand(time(0));

    cout << "Welcome to the \"One-Armed Bandit\" game!" << endl;
    playGame();

    return 0;
}
