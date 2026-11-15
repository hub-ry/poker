#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

constexpr int MAX_PLAYERS = 10;

enum class Suit {
  Clubs, Diamonds, Hearts, Spades
};

enum class Rank {
  Two = 2, Three, Four, Five, Six, Seven,
  Eight, Nine, Ten, Jack, Queen, King, Ace
};

struct Card {
  Rank rank;
  Suit suit;
};

struct Player {
  std::vector<Card> hand;
  int chips = 1000;
  int currentBet = 0;
  bool folded = false;

};

int main() {
  
  int player_count;
 
  /* Start Menu */
  while (true) {
    std::cout << "How many players are playing?\n";
    std::cin >> player_count;

    if (player_count <= MAX_PLAYERS || player_count >= 2) {
      break;
    }
  }

  std::cout << "Dealing ...\n";
  

  /* Create the deck */
  
  std::vector<Card> deck;

  for (int suit = 0; suit < 4; ++suit) {
    for (int rank = 2; rank <= 14; ++rank) {
      deck.push_back(Card{static_cast<Rank>(rank),static_cast<Suit>(suit)});
    }
  }
  
  /* shuffle the deck */

  /* pseudorandom number generator named rng, init with a seed from random_device */
  std::mt19937 rng(std::random_device{}());
  std::shuffle(deck.begin(), deck.end(), rng);
  

  std::vector<Player> players;
  std::vector<std::vector<Card>> hands(player_count);
  for (int player = 0; i < player_count; ++player) {
    
     
     

  }

  return 0;
}
