#ifndef __SOLVE_H_INCLUDED__   
#define __SOLVE_H_INCLUDED__
	/** Dependecies **/
#include "board.hpp"
#include <vector>
#include <cstddef>
Board * solve(Board *b){
std::vector<int> possibilities;
int mini=10; int minj=10;int minlen=10;
for (int i = 0; i < 9; i++)
for (int j = 0; i < 9; j++)
{
	if (b->get(i,j)!=0) continue;
	
	possibilities = b->get_posibilities(i,j);
	if( possibilities.empty()) return NULL;
	if (possibilities.size()<minlen){
		minlen = possibilities.size();
		minj = j;
		mini = i; 

	}
}
if(minlen == 10)return b;
possibilities = b->get_posibilities(mini,minj);
if (possibilities.size() == 0)return NULL;
else{
	for (int k = 0; k < possibilities.size(); k++)
	{
		Board *nb,*pb;
		nb = b;
		nb->add(mini,minj,possibilities[k]);
		pb = solve(nb);
		if (pb!=NULL) return pb;
	}

	return NULL;
}
}	  
//TODO Implement solve functiond
#endif 