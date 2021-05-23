#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic{
  class Board{
    private:
      unordered_map<City,int> diseasCubes;
      unordered_set<Color> discoverd;
      unordered_set<City> station;
    public:
      void addToStation(City c);
      bool exsistStation(City c);
      static bool is_neighbor(City c1,City c2);
      void save_discoverd(Color color);
      bool exsistDiscoverd(City c);

      bool is_clean();
      void remove_cures();
      void remove_stations();
      int & operator[](City city);
      friend ostream& operator<<(ostream& os,const Board& board);
  };
}
