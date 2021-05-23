#include "Player.hpp"


namespace pandemic{
  Player& Player::take_card(City c){
      cards.insert(c);
    return *this;
  }

  Player& Player::discover_cure(Color c){
    //if my city not have a station
    if(!this->board.exsistStation(this->city)){
      throw invalid_argument{"not exsist station"};
    }
    //if exsist 5 card same color
    int counter=0;
    for(const auto& card : cards){
      if(colors_city[card] == c){
        counter++;
      }
    }
    const int num5=5;
    if(counter<num5){
        throw invalid_argument{"not have 5 card"};
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

  string Player::role(){return this->playerRole;}
  Player& Player::drive(City c){
    // if exsist cards
    if(this->city==c){throw invalid_argument{"this is my city"};}
    // neighbor
    if(!Board::is_neighbor(this->city,c)){throw invalid_argument{"is not neighbor"};}
    city=c;
    return *this;
  }
  Player& Player::build(){
    if(!cards.contains(this->city)){
      throw invalid_argument{"card is not exsist"};
    }
    this->board.addToStation(this->city);
    cards.erase(this->city);
    return *this;
  }
  Player& Player::fly_direct(City c){
    // if this is my city or not
    if(this->city==c){throw invalid_argument{"this is my city"};}
    // if card not exsist
    if(!cards.contains(c)){
      throw invalid_argument{"card is not exsist"};
    }
    cards.erase(c);
    this->city=c;
    return *this;
  }
  Player& Player::fly_charter(City c){
    // if this is my city or not
    if(this->city==c){throw invalid_argument{"this is my city"};}
    // if card exsist
    if(!cards.contains(this->city)){
      throw invalid_argument{"card is not exsist"};
    }
    cards.erase(this->city);
    this->city=c;
    return *this;
    }

  Player& Player::fly_shuttle(City c){
    // if this is my city or not
    if(this->city==c){throw invalid_argument{"this is my city"};}

    //exsist station in my city and in other city
    if(this->board.exsistStation(this->city)&&this->board.exsistStation(c)){
      this->city=c;
    }else{
      throw invalid_argument{"no have research station"};
    }
    return *this;
  }

  Player& Player::treat(City c){
    if(this->city==c){
      if(this->board[c]==0){
          throw invalid_argument{"no have cubes"};
      }
        if(this->board.exsistDiscoverd(c)){
          this->board[c]=0;
        }else{
          this->board[c]--;
        }

    }else{
      throw invalid_argument{"is'nt my city"};
    }
    return *this;
  }
}
