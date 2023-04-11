#include "window.hpp"
#include <iostream>
s_window::s_window() :
    m_adjustment( Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0) ),
    m_adjustment_digits( Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0) ),
    m_HScale(m_adjustment, Gtk::Orientation::HORIZONTAL),
    m_Scale_Digits(m_adjustment_digits),
    start("start"),
    stop("stop"),
    randomize("r"),
    m_forground_colour({1,1,1})
{
    set_title("Sorting Algorithm Visulizer");
    set_size_request(400, 300);
    g_object_set(gtk_settings_get_default(),
    "gtk-application-prefer-dark-theme", TRUE,
    NULL);

    auto VBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL,5);
    
    algorithm_selection.set_size_request(150, 20);
    algorithm_selection.append("1", "Selection Sort");
    algorithm_selection.append("2", "Bubble Sort");
    algorithm_selection.append("3", "Insertion Sort");
    algorithm_selection.append("4", "Merge Sort");
    algorithm_selection.append("5", "Quick Sort");
    algorithm_selection.append("6", "Heap Sort");
    algorithm_selection.append("7", "Counting Sort");
    algorithm_selection.append("8", "Bucket Sort");
    algorithm_selection.append("9", "Bingo Sort");

    m_HScale.set_digits(0);
    m_HScale.set_value(1);
    m_HScale.set_value_pos(Gtk::PositionType::LEFT);
    m_HScale.set_draw_value();
    
    auto play_controls_layout = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL,5);
    play_controls_layout->append(start);
    play_controls_layout->append(stop);
    play_controls_layout->append(randomize);

    VBox->set_margin(5);
    VBox->set_homogeneous(true);
    VBox->append(algorithm_selection);
    VBox->append(m_HScale);
    VBox->append(m_description);
    VBox->append(*play_controls_layout);
    VBox->append(m_forground_colour);
    VBox->append(m_background_colour);
    
    Gtk::Box HBox;
    HBox.set_orientation(Gtk::Orientation::HORIZONTAL);
    HBox.append(*VBox);
    HBox.append(m_visulizer);

    this->handle_signals();

    set_child(HBox);

    go = true;
}

s_window::~s_window(){

}

void s_window::handle_signals(){
    m_forground_colour.signal_color_set().connect(sigc::mem_fun(*this, &s_window::on_forground_color_change));

    m_HScale.signal_value_changed().connect(sigc::mem_fun(*this, &s_window::on_range_change));
    start.signal_clicked().connect(sigc::mem_fun(*this, &s_window::on_start_clicked));
    stop.signal_clicked().connect(sigc::mem_fun(*this, &s_window::on_stop_clicked));
    randomize.signal_clicked().connect(sigc::mem_fun(*this, &s_window::on_randomize_clicked));
}

void run_selection_sort(Visulizer &m_visulizer, gboolean go) {
    static selection m_selection;
    int index = 0;
        m_selection.sort(std::ref(m_visulizer.get_display_vec()), std::ref(index), go);
    m_visulizer.draw();
}

void s_window::on_start_clicked(){
    go = true;
    int value;
    try {
    value = std::stoi(algorithm_selection.get_active_id());
    }
    catch (const std::invalid_argument& e) {
    }

    switch (value)
    {
    case 1:
        for (int i = 0; i < m_visulizer.get_display_vec().size(); i++){
        run_selection_sort(std::ref(m_visulizer), go);
        m_visulizer.draw();
        g_usleep(20000);
        }
        break;
    
    default:
        break;
    }
}

void s_window::on_stop_clicked(){
    go = false;
}

void s_window::on_randomize_clicked(){
    std::random_shuffle(m_visulizer.get_display_vec().begin(), m_visulizer.get_display_vec().end());
    m_visulizer.draw();
}

void s_window::beep(){
    std::cout << "asdkj" << std::endl;
    m_visulizer.draw();
}

void s_window::on_range_change(){
    m_visulizer.on_size_change(m_HScale.get_value());
    m_visulizer.draw();
}

void s_window::on_forground_color_change(){
    m_visulizer.change_forground(m_forground_colour.get_rgba());
}