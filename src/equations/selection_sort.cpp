#include "selection_sort.hpp"
#include <bits/stdc++.h>

selection::selection(){

}

selection::~selection(){
    
}

void selection::sort(std::vector<int> &sort_me, int &index, int &numThreads)
{   
    // This is one pass.
    while (index < sort_me.size()) {
        int minIndex = index; 
        for (int i = index; i < index + numThreads && i < sort_me.size(); i++) {
            if (sort_me[i] < sort_me[minIndex]) {
                minIndex = i;
            }
        }

        if (minIndex != index) {
            std::swap(sort_me[index], sort_me[minIndex]);
        }
        index += 1;
    }
}
 
