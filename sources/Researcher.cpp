#include "Researcher.hpp"
namespace pandemic{
    Player& Researcher::discover_cure(Color c) {

      //if exsist 5 card same color
      int counter=0;
      for(const auto& card : cards){
        if(colors_city[card] == c){
          counter++;
        }
      }
      const int num5=5;
      if(counter<num5){
          throw invalid_argument{"not have 5 cards"};
      }
        // drop 5 cards
        counter = 1;
        for(auto it = cards.begin(); it != cards.end(); counter++) {
                if(counter == num5) { break; }
                if(colors_city[*it] == c) {
                        it = this->cards.erase(it);
                }else {
                        ++it;
                }
        }

      board.save_discoverd(c);
      return *this;
    }
}
