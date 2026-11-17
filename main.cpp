#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

constexpr int MAX_PLAYERS = 10;
constexpr int small_b_val = 10, big_b_val = 20;
constexpr int starting_chips = 1000;

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
  int chips = starting_chips;
  int currentBet = 0;
  bool folded = false;

};

std::vector<Card> init_deck() {

  std::vector<Card> deck;
  std::cout << "Dealing ...\n";

  for (int suit = 0; suit < 4; ++suit) {
    for (int rank = 2; rank <= 14; ++rank) {
      deck.push_back(Card{static_cast<Rank>(rank),static_cast<Suit>(suit)});
    }
  }
  return deck;
}

std::vector<std::vector<Card>> shuffle_and_assign(int player_count,
                                                  std::vector<Card> deck,
                                                  std::vector<Player> &players)
{
 
  /* shuffle the deck */

  /* pseudorandom number generator named rng, init with a seed from random_device */
  std::mt19937 rng(std::random_device{}());
  std::shuffle(deck.begin(), deck.end(), rng);
  
  /* players and hands */
  std::vector<std::vector<Card>> hands(player_count);
  
  /* give two cards to each player, just choose from the back of the deck */
  for (int i = 0; i < 2; ++i) {
    for (int player = 0; player < player_count; ++player) {
        players[player].hand.push_back(deck.back());
        deck.pop_back(); 
    }
  }  
  return hands;
 
}

void play_game(int player_count) {
  /* init player vector */
  std::vector<Player> players(player_count);

  std::vector<Card> deck = init_deck();
  std::vector<std::vector<Card>> hands = shuffle_and_assign(player_count, deck,
                                                            players);
  int small_blind_i = 0;
  int big_blind_i = 1;
  
  /* enter the game */

  while (true) {
    int pot = 0;
    int min_bet = 0;
    players[small_blind_i].chips -= small_b_val; 
    pot += small_b_val;
    
    std::cout << "player " << small_blind_i << " paying " << small_b_val
              << " small blind\n";
    players[big_blind_i].chips -= big_b_val;
    std::cout << "player " << big_blind_i << " paying " << big_b_val
              << " big blind\n";
    pot += big_b_val;
    
    min_bet = big_b_val;

    /* now cycle throught the rest of them */
    
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
