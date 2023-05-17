#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <gtkmm-4.0/gtkmm.h>

class selection{
public:
    selection();
    ~selection();

    void sort(std::vector<int> &sort_me, int &index, gboolean go);
    int get_number_of_swaps(){return number_of_swaps;}

protected:
    int number_of_swaps = 0;
};