#include "selection_sort.hpp"
#include "misc.h"

class run{
    public:
    selection n_selection;

    void print();
    void runIT();
};
void run::print(){
    std::cout << "asdasd" << std::endl;
}
void run::runIT(){
    n_selection.sort(sortMe);
    n_selection.on_swap_alert.connect(sigc::mem_fun(*this, &run::print));
}
int main(){
    run runnnn;
    runnnn.runIT();
    return 0;
}