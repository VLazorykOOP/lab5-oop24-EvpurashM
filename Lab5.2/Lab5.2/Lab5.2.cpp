#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Enum for suits
enum Suit { Hearts, Diamonds, Clubs, Spades };

// Struct for a card
struct Card {
    int rank; // 1 - 13 (Ace, 2-10, Jack, Queen, King)
    Suit suit;

    // Print the card nicely
    void print() const {
        string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string ranks[] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
        cout << ranks[rank] << " of " << suits[suit];
    }

    // Check if the card is red
    bool isRed() const {
        return suit == Hearts || suit == Diamonds;
    }
};

// Base class Deck
class Deck {
protected:
    vector<Card> cards;
public:
    Deck(bool shuffled = false) {
        for (int s = Hearts; s <= Spades; ++s) {
            for (int r = 1; r <= 13; ++r) {
                cards.push_back(Card{ r, static_cast<Suit>(s) });
            }
        }
        if (shuffled) {
            shuffleDeck();
        }
    }

    void shuffleDeck() {
        static random_device rd;
        static mt19937 g(rd());
        shuffle(cards.begin(), cards.end(), g);
    }

    void printDeck() const {
        for (const auto& card : cards) {
            card.print();
            cout << endl;
        }
    }

    bool empty() const {
        return cards.empty();
    }

    int size() const {
        return cards.size();
    }
};

// Derived class Solitaire
class Solitaire : public Deck {
public:
    Solitaire(bool shuffled = true) : Deck(shuffled) {}

    void play() {
        for (int round = 1; round <= 3; ++round) {
            cout << "\n--- Round " << round << " ---" << endl;
            vector<Card> new_deck;
            int i = 0;
            while (i < cards.size()) {
                if (i + 2 < cards.size()) {
                    Card first = cards[i];
                    Card middle = cards[i + 1];
                    Card last = cards[i + 2];

                    // Check if first and last cards have the same color
                    if (first.isRed() == last.isRed()) {
                        cout << "Removing: ";
                        first.print();
                        cout << ", ";
                        middle.print();
                        cout << ", ";
                        last.print();
                        cout << endl;
                        i += 3; // Skip these three cards
                        continue;
                    }
                }
                // Otherwise keep the card
                new_deck.push_back(cards[i]);
                ++i;
            }
            cards = new_deck; // Update the deck
            cout << "Cards remaining after round " << round << ": " << cards.size() << endl;
        }
    }
};

int main() {
    Solitaire solitaire(true); // create a shuffled deck
    cout << "Initial deck:\n";
    solitaire.printDeck();

    solitaire.play();

    cout << "\nFinal deck:\n";
    solitaire.printDeck();

    return 0;
}
