#ifndef SELECT_SORT
#define SELECT_SORT

#include <iostream>
using namespace std;

template <typename Iterator>
void select_sort(Iterator first, Iterator last){
	for(Iterator i = first; i != last - 1; i++){
		Iterator najmniejszy = i;

		for(Iterator j = i + 1; j != last; j++){
			if(*j < *najmniejszy) najmniejszy = j;
		}

		if(najmniejszy != i){
			swap(*i, *najmniejszy);
		}
	}
}

#endif
