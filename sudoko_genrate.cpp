#include <stdio.h>
#include<iostream>
#include "board.hpp"
#include "strategy.hpp"
#include "digger.hpp"
#include"la.hpp"

// void set_diff(int ,  Stratagy* x){
// 	int check = 0, max =0;
// 	switch (diff){
// 		case 1:
// 			Stratagy d(1);
// 			break;
// 		case 2:
// 			max = 48;
// 			break;
// 		case 3:
// 			max = 51;
// 			break;

// 		}

// 	while (check < max) {

// 		int r = ((double) rand() / (RAND_MAX)*10)-1;
// 		int p = ((double) rand() / (RAND_MAX)*10)-1;
// 		if (x->get(r,p)!=0) {
// 			x-> hide(r,p);
// 			check++;
// 		}
// 	}	
// }

int get_value(int mn, int mx) {
	int diff;
	for (diff = -1; !(mn-1 < diff && diff < mx+1); ) {
		if (!(std::cin >> diff) || diff>mx || diff <mn) {			
        	std::cout << "invalid character\n";
         	std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return diff;
}

void print_board(Board* x) {
	for (int i = 0; i < 9; i++) {
		if (i ==3|| i==6) {
			std::cout << "\n-------------------";
		}
		std::cout<<"\n";
		for (int j = 0; j < 9; j++) { 
			if (j==3 || j==6) {
				std::cout << "|";
			}
			std::cout<<x->get(i,j)<<" ";
		}
	}
	std::cout << "\n";
}

bool is_full(Board* x) { 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) { 
			if (x->get(i,j)==0){
				return false;
			}		
		}
	}
	return true;
	
}

int main(int argc, char const *argv[])
{
	int diff;
	std::srand ( unsigned ( std::time(0) ) );
	Board* x = valid_board();
	Board  base;
	std::cout << "Choose difficulty(Super easy:1 Easy:2 Meduim:3 Hard:4 Evil:5)\n";
	diff = get_value(1,5);
	Strategy d (diff);
	Board* c = dig(d,x);			
	// set_diff(get_value(1,3));
	base = *c;
	while(1){
		print_board(x);
		std::cout << "Choose row (1-9)\n";
		int i = get_value(1,9)-1;
		std::cout << "Choose Column (1-9)\n";
		int j = get_value(1,9)-1;
		if (base.get(i,j)==0 ) {
			std::cout << "Choose Value (1-9)\n";
			int v = get_value(1,9);
			x->add(i,j,v);
			if (!(x->valid())) {
				x->add(i,j,0);
				std::cout << "Input repeated in row,column or box\n";
			}
		}
		else {
			std::cout << "Cell can not be edited\n";
		}

		if (is_full(x) && (x->valid())) {
			std::cout << "You Win";
			break;
		}
	}
	
	return 0;
}