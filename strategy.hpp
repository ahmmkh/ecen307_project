#ifndef __STRATEGY_H_INCLUDED__
#define __STRATEGY_H_INCLUDED__

#include<vector>
#include<algorithm>
#include <iostream>
#include "board.hpp"
//Board xs;

class Strategy
{
public:
    Strategy(int difficulty);
    void randomizingGlobally();
    void jumpingOneCell();
    void wandringAlongS();
    void leftRightTopBottom();
    bool canBeDug(Board* b,int i,int j);
    int maximumEmptyCells;
    int limitOfEmptyCells;
    std::vector<int> boardCells;
};
Strategy::Strategy(int difficulty){
    switch(difficulty){
    case 1:
        this->randomizingGlobally();
        this->maximumEmptyCells=4;
        this->limitOfEmptyCells=31;
        break;
    case 2:
        this->randomizingGlobally();
        this->maximumEmptyCells=5;
        this->limitOfEmptyCells=32;
        break;
    case 3:
        this->jumpingOneCell();
        this->maximumEmptyCells=6;
        this->limitOfEmptyCells=46;
        break;
    case 4:
        this->wandringAlongS();
        this->maximumEmptyCells=7;
        this->limitOfEmptyCells=50;
        break;
    case 5:
        this->leftRightTopBottom();
        this->maximumEmptyCells=9;
        this->limitOfEmptyCells=54;
        break;
    default:
        std::cout<<"Please enter difficulty from 1 to 5 "<<std::endl;
        break;
    }

}
void Strategy::leftRightTopBottom(){
    this->boardCells.clear();
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            this->boardCells.push_back((i*10)+j);
        }
    }
}
void Strategy::wandringAlongS(){
   this->boardCells.clear();
    for(int i=0; i<9; i++){
        for(int j=0; j<9;j++){
            if(i%2==0){
                this->boardCells.push_back(i*10+(10-j));
            }
            else{
                this->boardCells.push_back(i*10+j);
            }
        }
    }
}
void Strategy::jumpingOneCell(){
    this->boardCells.clear();
    for(int i=0; i<9;i++){
        for(int j=0; j<9 ; j+=2){
            if(i%2==0){
                this->boardCells.push_back((i*10)+j);
            }
            else{
                this->boardCells.push_back(i*10+ (8-j));
            }
        }
    }
    for(int i=0; i<9;i++){
        for(int j=1; j<9 ; j+=2){
            if(i%2==0){
                this->boardCells.push_back(i*10+(8-j));
            }
            else{
                this->boardCells.push_back(i*10+j);
            }
        }
    }
}
void Strategy::randomizingGlobally(){
    this->boardCells.clear();
    for(int i=0; i<9 ;i++){
        for(int j=0; j<9; j++){
            this->boardCells.push_back(i*10+j);
        }
    }
    random_shuffle(this->boardCells.begin(), this->boardCells.end());
}

bool Strategy::canBeDug(Board *b, int i, int j) {
    int emptyCell=0;
    for(int k=0; k<9;k++){
        if(b->get(i,k)==0) emptyCell++;
    }

    if (emptyCell >= this->maximumEmptyCells) return false;

    emptyCell=0;
    for(int x=0; x<9;x++){
        if(b->get(j,x)==0) emptyCell++;
    }

    if (emptyCell>= this->maximumEmptyCells) return false;

    return true;
}




// TODO Implement startegy for digging holes in the puzzle
#endif
