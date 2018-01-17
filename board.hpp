#ifndef __BOARD_H_INCLUDED__   
#define __BOARD_H_INCLUDED__ 
//random_shuffle(&a[0], &a[10]);
#include<map>
#include<vector>
int block(int i,int j){

	return ((i / 3) * 3) + j / 3;
}
class Board
{
public:
	Board();
	void update_possibilities();
private:
	int c_board[9][9];
	std::map <int,std::vector<int> > c_possibilities;	
};

Board::Board(){
	this->c_board[9][9] = {1};
	static const int arr[] = {1,2,3,4,5,6,7,8,9};
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			c_possibilities[(i*10) +j] = std::vector<int>  (arr, arr + sizeof(arr) / sizeof(arr[0]) ); 
			//std::cout << c_possibilities[11][1];

}

void Board::update_possibilities(){
	int cell, possibilites[10] ={1},row_digits[10][10]={1} ,column_digits[10][10]={1} ,block_digits[10][10]={1}; 
	std::vector<int> temp;
	for (int i = 0; i < 9; i++)
		for (int j = 0; i < 9; j++)
		{
			cell = this->c_board[i][j];
			if (cell)
			{
			    row_digits[i][cell] = 0;
	            column_digits[j][cell] = 0;
	            block_digits[block(i, j)][cell] = 0;
			}
		}

	for (int i = 0; i < 9; i++)
		for (int j = 0; i < 9; j++)
		{
			if (this->c_board[i][j]) continue;
			
			possibilites[10] = {1};
			
			for (int k = 1; i < 10; k++)
			{
				if (!row_digits[i][k])possibilites[k] = 0;
				if (!column_digits[j][k])possibilites[k] = 0;
				if (!block_digits[block(i, j)][k])possibilites[k] = 0;
				
			}

			for (int x = 1; x <10 ; x++)
			{
				if (possibilites[x])temp.push_back(x);
				
			}
			c_possibilities[(i*10) + j] = temp;


		}	
}
//TODO Implement Board class 
#endif 