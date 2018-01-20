#ifndef __BOARD_H_INCLUDED__   
#define __BOARD_H_INCLUDED__ 
//random_shuffle(&a[0], &a[10]);
#include<map>
#include<vector>
#include <cstddef>
#include <iostream>
int block(int i,int j){

	return ((i / 3) * 3) + j / 3;
}
class Board
{
public:
	Board();
	bool valid ();
	std::vector<int> get_posibilities(int i ,int j);
	bool conflict(int i1,int j1,int i2,int j2);
	int get(int i,int j);
	void hide(int i ,int j);
	void add(int i,int j , int value);
	void update_possibilities();
	Board* solve();
private:
	std::map <int,std::vector<int> > c_possibilities;	
	int c_board[9][9];
	
};

Board::Board(){
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
		c_board[i][j]=0;
	

	static const int arr[] = {1,2,3,4,5,6,7,8,9};
	
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			//because it's empty so you have all possiblities intially 
			c_possibilities[(i*10) +j] = std::vector<int>  (arr, arr + sizeof(arr) / sizeof(arr[0]) ); 
	//std::cout << c_possibilities[1][1];

}

void Board::update_possibilities(){
	int cell ;int row_digits[10][10];int column_digits[10][10] ;int block_digits[10][10]; 
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			row_digits[i][j]=1;
			column_digits[i][j]=1;
			block_digits[i][j]=1;
					}
	}


	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++)
		{
			cell = this->c_board[i][j];
			
			if (cell!=0)
			{
			    row_digits[i][cell] = 0;
	            column_digits[j][cell] = 0;
	            block_digits[block(i, j)][cell] = 0;
			}
		}
	}
	c_possibilities.clear();
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++)
		{
			if (this->c_board[i][j]!=0) continue;
			
			int possibilites[] = {1,1,1,1,1,1,1,1,1,1};

			//dd
			for (int k = 1; k < 10; k++)
			{
				if (!row_digits[i][k])possibilites[k] = 0;
				if (!column_digits[j][k])possibilites[k] = 0;
				if (!block_digits[block(i, j)][k])possibilites[k] = 0;
				
			}

			std::vector<int> temp;
			
			for (int x = 1; x <10 ; x++)
			{
				if (possibilites[x])temp.push_back(x);
				
			}

			c_possibilities[(i*10) + j] = temp;


		}	
	}
}


int Board::get(int i,int j ){return this->c_board[i][j];}

void Board::add(int i ,int j,int value){
	this->c_board[i][j] = value;
	this->update_possibilities();
}
 void Board::hide(int i , int j ){
 	if (this->c_board[i][j] == 0) return;
 	else {
 		this->c_board[i][j]=0;
 		this-> update_possibilities();	
 	}
 
 }

 std::vector<int> Board::get_posibilities(int i,int j) {

 	if (this->c_board[i][j]!=0) throw "cell is not empty";
 	std::map <int,std::vector<int> >::const_iterator it = this->c_possibilities.find(i*10 + j);
 	if (it!=c_possibilities.end()) return this->c_possibilities[i*10 + j];
 	else return {};
 }

 bool Board::conflict(int i1,int j1,int i2, int j2){
 	if (this->c_board[i1][j1]==0 || this->c_board[i2][j2]==0 )return false;
 	if (this->c_board[i1][j1] != this->c_board[i2][j2]) return false;
 	if (i1 == i2) return true;	
 	if (j1 == j2) return true;
 	if (block(i1,j1)==block(i2,j2))return true;
 	return false;	
 }
 bool Board::valid(){

 	for (int i1 = 0; i1 < 9; i1++)
 		 	for (int j1 = 0; j1 < 9; j1++)
 		 		 	for (int i2 = 0; i2 < 9; i2++)
 		 		 		 	for (int j2 = 0; j2 < 9; j2++)
 		 		 		 		{
 		 		 		 			if (i1*10 +j1 ==i2*10 +j2 ) continue;
 		 		 		 			if(this->conflict(i1,j1,i2,j2))return false;
 		 		 		 		}
 	return true	; 		 		 	



 }

Board* Board::solve(){
std::vector<int> possibilities;
int mini=10; int minj=10;int minlen=10;
for (int i = 0; i < 9; i++)
for (int j = 0; j < 9; j++)
{
	if (this->get(i,j)!=0) continue;
	
	possibilities = this->get_posibilities(i,j);
	if( possibilities.empty()) return NULL;
	if (possibilities.size()<minlen){
		minlen = possibilities.size();
		minj = j;
		mini = i; 

	}
}
if(minlen == 10)return this;
possibilities = this->get_posibilities(mini,minj);
if (possibilities.size() == 0)return NULL;
else{
	for (int k = 0; k < possibilities.size(); k++)
	{
		
		this->add(mini,minj, possibilities [k]);

		if (this->solve()!=NULL) return this->solve();
	}

	return NULL;
}
}	 
//TODO Implement Board class 
#endif 