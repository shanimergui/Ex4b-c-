#include "Medic.hpp"
namespace pandemic {
Player& Medic::treat(City c){
        if(city==c) {
                if(board[c]==0) {
                        throw invalid_argument{"no have cubes"};
                }
                        board[c]=0;

        }else{
                throw invalid_argument{"is'nt my city"};
        }
        return *this;
}


Player& Medic::drive(City c){
        Player::drive(c);
        if(board.exsistDiscoverd(c)) {
                board[c]=0;
        }
        return *this;
}
Player& Medic::fly_charter(City c){
        Player::fly_charter(c);
        if(board.exsistDiscoverd(c)) {
                board[c]=0;
        }
        return *this;
}
Player& Medic::fly_shuttle(City c){
        Player::fly_shuttle(c);
        if(board.exsistDiscoverd(c)) {
                board[c]=0;
        }
        return *this;
}
Player& Medic::fly_direct(City c){
        Player::fly_direct(c);
        if(board.exsistDiscoverd(c)) {
                board[c]=0;
        }
        return *this;
}
}
