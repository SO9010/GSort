#include "window.hpp"
#include <gtkmm-4.0/gtkmm/application.h>

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create("org.gtkmm.sorting");
    return app->make_window_and_run<s_window>(argc, argv);
}