#pragma once

#include <gtkmm-4.0/gtkmm.h>
#include "equations/selection_sort.hpp"

class Visulizer : public Gtk::DrawingArea {
public:
    Visulizer();
    virtual ~Visulizer();

    void on_size_change(int x);
    void change_forground(Gdk::RGBA x);
    void on_vec_change();

    void set_display_vec(std::vector<int> x) {display_vec = x;}
    std::vector<int> &get_display_vec() {return display_vec;}

    sigc::signal<void()> signal_drawing_complete;


    void draw();
protected:
    std::vector<int> display_vec = {89, 7, 41, 58, 66, 35, 97, 9, 32, 78, 88, 11, 56, 73, 42, 51, 26, 22, 14, 59, 15, 46, 21, 71, 68, 52, 92, 85, 40, 36, 33, 90, 50, 30, 61, 29, 12, 44, 49, 83, 64, 19, 75, 99, 53, 25, 81, 17, 5, 76, 2, 91, 72, 57, 18, 95, 48, 3, 80, 86, 65, 27, 67, 96, 39, 70, 31, 45, 55, 98, 69, 34, 28, 79, 94, 10, 62, 6, 23, 43, 37, 77, 54, 1, 24, 16, 84, 87, 8, 63, 47, 38, 74, 20, 60, 82, 13};
    bool process_next = true;
    int array_size = 1;
    Gdk::RGBA forground = {0.9, 0.9, 0.9};
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};