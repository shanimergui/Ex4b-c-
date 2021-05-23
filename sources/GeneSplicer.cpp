#include "GeneSplicer.hpp"
namespace pandemic{
    Player& GeneSplicer::discover_cure(Color c) {
      //if my city not have a station
      if(!this->board.exsistStation(this->city)){
        throw invalid_argument{"not exsist station"};
      }
      //if exsist 5 cards
      int counter=0;
      for(const auto& card : cards){
          counter++;
      }
      const int num5=5;
      if(counter<num5){
          throw invalid_argument{"not have 5 card"};
      }
        // drop 5 cards
        counter = 1;
        for(auto it = cards.begin(); it != cards.end(); counter++) {
                if(counter == num5) { break; }
                it = this->cards.erase(it);
        }


      board.save_discoverd(c);
      return *this;
    }
}
