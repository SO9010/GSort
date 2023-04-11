#include "visulizer.hpp"
#include <iostream>
#include <vector>

#include <chrono>
#include <thread>

Visulizer::Visulizer(){
    set_content_width(590);
    set_content_height(300);
    set_draw_func(sigc::mem_fun(*this, &Visulizer::on_draw));
}

Visulizer::~Visulizer(){
}

void Visulizer::on_size_change(int x){
    array_size = x;
    queue_draw();
}

void Visulizer::change_forground(Gdk::RGBA x){
    forground.swap(x);
    queue_draw();
}

void Visulizer::draw(){
    queue_draw();
}
void Visulizer::on_vec_change(){

    int min_idx;
    for(int i = 0; i < int(display_vec.size()) - 1; i++){
        min_idx = i;
        for (int j = i+1; j < int(display_vec.size()); j++)
        {
            if (display_vec[j] < display_vec[min_idx]){
            min_idx = j;
            }
        }
        if (min_idx!=i){
            int tmp = display_vec.at(min_idx);
            display_vec.at(min_idx) = display_vec.at(i);
            display_vec.at(i) = tmp;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            this->draw();
        }
    }
  
}
void Visulizer::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height){
    cr->set_line_width(4.0);
    cr->set_source_rgba(forground.get_red(), forground.get_green(), forground.get_blue(), forground.get_alpha());
    for(int i = 0; i < 100; i++){
        cr->move_to(i * 6 + 5, height);
        cr->line_to(i * 6 + 5, height - display_vec[i]*3);
    }
    cr->stroke();
    signal_drawing_complete.emit();
}
