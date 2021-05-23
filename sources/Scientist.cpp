#include "Scientist.hpp"
namespace pandemic{
    Player& Scientist::discover_cure(Color c) {
      //if my city not have a station
      if(!board.exsistStation(this->city)){
        throw invalid_argument{"not exsist station"};
      }
      //if exsist 5 card same color
      int counter=0;
      for(const auto& card : cards){
          counter++;
      }
      if(counter<n){
          throw invalid_argument{"not have "+to_string(n)+" cards"};
      }
        // drop n cards
        counter = 1;
        for(auto it = cards.begin(); it != cards.end(); counter++) {
                if(counter == n) { break; }
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
