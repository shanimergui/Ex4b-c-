#include "Dispatcher.hpp"
namespace pandemic{
  Player& Dispatcher::fly_direct(City c){

    if(this->city==c){throw invalid_argument{"this is my city"};}

    if(!this->board.exsistStation(this->city)){
      return Player::fly_direct(c);
    }
      this->city=c;

    return *this;
  }
}
