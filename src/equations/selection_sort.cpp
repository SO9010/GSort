#include "selection_sort.hpp"
#include <bits/stdc++.h>

selection::selection(){

}

selection::~selection(){
    
}

void selection::sort(std::vector<int> &sort_me, int &index, gboolean go)
{   
    // This is one pass.
    while (index < sort_me.size() && go) {
        int minIndex = index; 
        for (int i = index; i < index + 2 && i < sort_me.size(); i++) {
            if (sort_me[i] > sort_me[minIndex]) {
                minIndex = i;
            }
        }

        if (minIndex != index) {
            std::swap(sort_me[index], sort_me[minIndex]);
        }
        index += 1;
        while (Glib::MainContext::get_default()->iteration(false)) {}
    }
}

