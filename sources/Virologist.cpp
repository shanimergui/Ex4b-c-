#include "Virologist.hpp"
namespace pandemic {
Player& Virologist::treat(City c){
        if(this->city!=c) {
                if(!cards.contains(c)) {
                        throw invalid_argument{"no have card"};
                }
                cards.erase(c);
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
