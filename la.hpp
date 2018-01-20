#ifndef __LA_H_INCLUDED__   
#define __LA_H_INCLUDED__  
#include "board.hpp"
#include "solve.hpp"
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib> 
#include <cstddef>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>
template<class BidiIter >
BidiIter random_unique(BidiIter begin, BidiIter end, size_t num_random) {
    size_t left = std::distance(begin, end);
    while (num_random--) {
        BidiIter r = begin;
        std::advance(r, rand()%left);
        std::swap(*begin, *r);
        ++begin;
        --left;
    }
    return begin;
}
/** std::sample(in.begin(), in.end(), std::back_inserter(out),
                5, std::mt19937{std::random_device{}()}); **/
Board * backtrack(Board* b,std::vector<int> set,int pos){
	  std::srand ( unsigned ( std::time(0) ) );

if (pos>(int)set.size()) return b;

int i = set[pos]/10;
int j = set[pos]%10;

std::vector<int>possib;

possib = b->get_posibilities(i,j);

random_shuffle(possib.begin(),possib.end());

for (int x = 0; x < possib.size(); x++)
{
	b->add(i,j,possib[x]);
	Board *sol = backtrack(b,set,pos+1);
	if (sol!=NULL)return sol;

}
return NULL;
}


Board * la (int s_c ){
std::vector<int> places;
for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
	{
		places.push_back((i*10)+j);
	}
	std::vector<int> choices;
 random_unique(places.begin(),places.end(),s_c);
for (int k = 0; k < s_c; k++)
{
	choices.push_back(places[k]);
	//std::cout<<choices[k]<<" ";
}

Board* in_b = new Board();
Board *in_c = backtrack(in_b,choices,0);
Board *sol = in_c->solve();
return sol;


}
Board* valid_board(){

	while(true){
		Board* b = la(11);
		if (b!=NULL) return b;
	}
}


//TODO GENERATE A SOLVED PUZZLE BOARD USING SOLVE FUNCTION 
#endif 