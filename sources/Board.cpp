#include "Board.hpp"
namespace pandemic {

bool Board::is_clean(){
        for(auto & p: this->diseasCubes) {
                if(p.second>0) {
                        return false;
                }
        }
        return true;
}

int & Board::operator[](City city){
        return this->diseasCubes[city];
}

void Board::remove_cures(){
        this->discoverd.clear();
}

void Board::remove_stations(){
        this->station.clear();
}

ostream& operator<<(ostream& os,const Board& board){

        os<<"                  Diseas Cubes               "<<'\n';
        for(const auto & p:board.diseasCubes) {
                os<<"City: "<<city_to_string[p.first] << " Cost Cubes: "<< p.second<<'\n';
        }
        os<<"                  discoverd               "<<'\n';
        for(const auto & d:board.discoverd) {
                os<<"Discoverd cure: "<<colors[d]<<'\n';
        }

        os<<"                  station               "<<'\n';
        for(const auto & s:board.station) {
                os<<"Station: "<<city_to_string[s]<<'\n';
        }

        return os;
}

void Board::addToStation(City c){
        this->station.insert(c);
}

bool Board::exsistStation(City c){
        return this->station.contains(c);
}

bool Board::is_neighbor(City c1,City c2){
        return graph.at(c1).contains(c2);
}

void Board::save_discoverd(Color color){
        this->discoverd.insert(color);
}

bool Board::exsistDiscoverd(City c){
        return this->discoverd.contains(colors_city[c]);
}
}
