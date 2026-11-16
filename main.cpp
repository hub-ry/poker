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

void play_game(player_count) {
  
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
  

  std::vector<Player> players(player_count);
  std::vector<std::vector<Card>> hands(player_count);
  
  /* give two cards to each player, just choose from the back of the deck */
  for (int i = 0; i < 2; ++i) {
    for (int player = 0; player < player_count; ++player) {
        players[player].hand.push_back(deck.back());
        deck.pop_back(); 
    }
  }    

  
  int small_blind = 0;
  int big_blind = 1;

  while (true) {
    
    players[small_blind].chips -= 1;
    players[small_blind].currentBet = 1;

    players[big_blind].chips -= 2;
    players[big_blind].currentBet = 2;

    int pot = 3;

    for (int i

    small_blind = (small_blind + 1) % player_count;
    big_blind = (big_blind + 1) % player_count;
  } 
}

int main() {
  
  int player_count;
 
  /* Start Menu */
  while (true) {
    std::cout << "How many players are playing?\n";
    std::cin >> player_count;

    if (player_count <= MAX_PLAYERS && player_count >= 2) {
      break;
    }
  }
  

  play_game(player_count);

  return 0;
}
