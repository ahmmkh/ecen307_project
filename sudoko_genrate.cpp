#include <stdio.h>
#include<iostream>
#include "board.hpp"
#include"la.hpp"

int main(int argc, char const *argv[])
{
	std::srand ( unsigned ( std::time(0) ) );
	Board* x = valid_board();

// 	x.add(0,0,1);
	//x.solve();
//std::vector<int> v=	x.get_posibilities(0,1);
	for (int i = 0; i < 9; i++)
	{
		std::cout<<"\n";
		for (int j = 0; j < 9; j++)
		{
			std::cout<<x->get(i,j)<<" ";
		}
	}
	std::cout<<x->valid();
std::map<int,int> first;


	
	 // std::vector<int> v= x.get_posibilities(0,1);
	 // std::cout<<v[1];
	//std::cout<<x.get(0,0);
	/* code */
	return 0;
}