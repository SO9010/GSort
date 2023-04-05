#include "selection_sort.hpp"
#include <bits/stdc++.h>

selection::selection(){

}

selection::~selection(){
    
}

void selection::sort(std::vector<int> &sort_me)
{
    int n = sort_me.size();
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          if (sort_me[j] < sort_me[min_idx])
              min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx!=i)
            std::swap(sort_me[min_idx], sort_me[i]);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        on_swap_alert.emit();
    }

}
 
