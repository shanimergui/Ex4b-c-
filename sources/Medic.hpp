#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Medic: public Player{
    public:
      Medic(Board& board_,City city_):Player(board_,city_,"Medic"){}
      Player& treat(City c) override;
      Player& drive(City c) override;
      Player& fly_charter(City c) override;
      Player& fly_shuttle(City c) override;
      Player& fly_direct(City c) override;
  };
}
