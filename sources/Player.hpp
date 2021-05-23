#pragma once
#include <unordered_set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace pandemic{
  class Player{
  protected:
    Board& board;
    City city;
    unordered_set<City> cards;
    string playerRole;
  public:
    Player(Board& board_ ,City city_,string role_):board(board_),city(city_),playerRole(role_){}

    Player& take_card(City c);
    string role();
    virtual Player& drive(City c);
    virtual Player& fly_charter(City c);
    virtual Player& fly_shuttle(City c);
    virtual Player& fly_direct(City c);
    virtual Player& build();
    virtual Player& discover_cure(Color c);
    virtual Player& treat(City c);
  };
}
