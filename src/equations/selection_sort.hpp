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

    void sort(std::vector<int> &sort_me, int &index, int &numThreads);

    sigc::signal<void()> on_swap_alert;
protected:
    int number_of_swaps = 0;
};