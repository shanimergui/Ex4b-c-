#include "FieldDoctor.hpp"
namespace pandemic {
Player& FieldDoctor::treat(City c){
        if(this->city!=c&&!Board::is_neighbor(this->city,c)) {
                throw invalid_argument{"is'nt my city or is not connected"};
        }
        if(this->board[c]==0) {
                throw invalid_argument{"no have cubes"};
        }

        if(this->board.exsistDiscoverd(c)) {
                this->board[c]=0;
        }else{
                this->board[c]--;
        }

        return *this;
}
}
