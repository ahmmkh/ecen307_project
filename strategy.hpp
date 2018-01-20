#ifndef __STRATEGY_H_INCLUDED__
#define __STRATEGY_H_INCLUDED__

#include<vector>
#include<algorithm>
class strategy
{
public:
    strategy(int difficulty);
    void randomizingGlobally();
    void jumpingOneCell();
    void wandringAlongS();
    void leftRightTopBottom();
    bool canBeDug();
    int maximumEmptyCells=0;
    int limitOfEmptyCells =0;
};
strategy::strategy(int difficulty){
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
        cout<<"Please enter difficulty from 1 to 5 "<<endl;
        break;
    }

}
void strategy::leftRightTopBottom(){
    vector<int> boardCells;
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            boardCells.push_back(i*10+j);
        }
    }
}
void strategy::wandringAlongS(){
    vector<int> boardCells;
    for(int i=1; i<10; i++){
        for(int j=1; j<10;j++){
            if(i%2==0){
                boardCells.push_back(i*10+(10-j));
            }
            else{
                boardCells.push_back(i*10+j);
            }
        }
    }
}
void strategy::jumpingOneCell(){
    vector<int> boardCells;
    for(int i=1; i<10;i++){
        for(int j=1; j<10 ; j+=2){
            if(i%2==0){
                boardCells.push_back(i*10+(10-j));
            }
            else{
                boardCells.push_back(i*10+j);
            }
        }
    }
    for(int i=1; i<10;i++){
        for(int j=2; j<10 ; j+=2){
            if(i%2==0){
                boardCells.push_back(i*10+(10-j));
            }
            else{
                boardCells.push_back(i*10+j);
            }
        }
    }
}
void strategy::randomizingGlobally(){
    vector<int> boardCells;
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            boardCells.push_back(i*10+j);
        }
    }
    random_shuffle(boardCells.begin(), boardCells.end());
}

bool strategy::canBeDug(board, row, column){
    int emptyCelss=0;
    for(int i=1; i<10;i++){

    }
}




// TODO Implement startegy for digging holes in the puzzle
#endif
