#include "OperationsExpert.hpp"
namespace pandemic{
  Player& OperationsExpert::build(){
    board.addToStation(city);
    return *this;
  }
}
