#include "Player.h"

int main() {
    srand(time(NULL));

    Player p1;  // gets two random weapons when constructed
    Player p2;  // same

    // // Hmmm. Look familiar? (operator overloading)
    int step = 25;
    while (--step) {
        if (p1 > p2) {
            cout << "Player 1's " << p1.resHand << " beat Player 2's " << p2.resHand << "!" << endl;
        } else if (p2 > p1) {
            cout << "Player 2's " << p2.resHand
                 << " beat Player 1's " << p1.resHand << "!" << endl;
        } else {
            cout << "It's a tie!" << endl;
            // print all 4 weapons here...
            cout << "Player 1's " << p1.weapon1 << " and " << p1.weapon2 << "!" << endl;
            cout << "Player 2's " << p2.weapon1 << " and " << p2.weapon2 << "!" << endl;
        }
        // Reset weapons
        p1.change();
        p2.change();
    }
    return 0;
}
