#include "selection_sort.hpp"

selection::selection(){

}

selection::~selection(){
    
}
 
// Return minimum index
int selection::minIndex(std::vector<int> sort_me, int i, int j)
{
    if (i == j)
        return i;
 
    // Find minimum of remaining elements
    int k = minIndex(sort_me, i + 1, j);
 
    // Return minimum of current and remaining.
    return (sort_me[i] < sort_me[k])? i : k;
}
 
void selection::sort(std::vector<int> &sort_me, int n, int index){
// Return when starting and size are same
    int tmp;
    if (index == n)
       return;
    // calling minimum index function for minimum index
    int k = selection::minIndex(sort_me, index, n-1);
 
    // Swapping when index and minimum index are not same
    if (k != index){
        tmp = sort_me[index];
        sort_me[index] = sort_me[k];
        sort_me[k] = tmp;
    }
 
    // Recursively calling selection sort function
    selection::sort(sort_me, n, index + 1);
    on_swap_alert.emit();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}