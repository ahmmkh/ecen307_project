
#ifndef __DIGGER_H_INCLUDED__   
#define __DIGGER_H_INCLUDED__  
#include"strategy.hpp"
#include "board.hpp"
Board* dig(Strategy s,Board *b){
int dig_counter=0;
std::cout<<s.boardCells[0];
for (unsigned int k = 0; k < s.boardCells.size(); k++)
{
	int i = s.boardCells[k]/10;
	int j = s.boardCells[k]%10;

	if (!(s.canBeDug(b,i,j)))continue;

	int pre_value = b->get(i,j);
	b->hide(i,j);
	//std::cout<<k;
	std::vector<int> poss;

	poss = b->get_posibilities(i,j);
// 	std::vector<int>::iterator it = poss.begin();
// while ( it != poss.end())
// {
// 	if (*it == pre_value)
// 	{
// 		it =poss.erase(it);
// 		break;
// 	}
// 	else it++;
// }

	bool another_sol = false;
	//std::cout<<poss.size();
	for (unsigned int x = 0; x < poss.size(); x++)
	{
		if (poss[x]==pre_value)continue;

		else{

		b->add(i,j,poss[x]);
		Board tes = *b;
		if (tes.solve()!=NULL){ another_sol = true;break;}
		}
	}

	if (another_sol)
	
	{
		b->add(i,j,pre_value);
	}
	else{
		b->hide(i,j);
		dig_counter++;
	}

	if (dig_counter>=s.limitOfEmptyCells)
	{
		return b;
	}
}
return b;

}
/** TODOs implement digger class for using diggingstrategy object and terminal_pattern(sudoko board)
 **/ 
#endif 
