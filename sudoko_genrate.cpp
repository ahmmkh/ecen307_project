#include <stdio.h>
#include<iostream>
#include "board.hpp"
#include"la.hpp"

void set_diff(int diff,  Board* x){
	int check = 0, max =0;
	switch (diff){
		case 1:
			max = 41;
			break;
		case 2:
			max = 48;
			break;
		case 3:
			max = 51;
			break;

		}

	while (check < max) {

		int r = ((double) rand() / (RAND_MAX)*10)-1;
		int p = ((double) rand() / (RAND_MAX)*10)-1;
		if (x->get(r,p)!=0) {
			x-> hide(r,p);
			check++;
		}
	}	
}

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
		std::cout<<"\n";
		for (int j = 0; j < 9; j++) { 
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
			else {
				return true;
			}		
		}
	}
}

int main(int argc, char const *argv[])
{
	std::srand ( unsigned ( std::time(0) ) );
	Board* x = valid_board();
	Board  base;
	std::cout << "Choose difficulty(Easy:1 Meduim:2 Hard:3)\n";	
	set_diff(get_value(1,3),x);
	base = *x;
	while(1){
		print_board(x);
		std::cout << "Choose row (1-9)\n";
		int i = get_value(0,8);
		std::cout << "Choose Column (1-9)\n";
		int j = get_value(0,8);
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
			break;
		}
	}
	
	return 0;
}