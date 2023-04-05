#include "window.hpp"
#include <iostream>
s_window::s_window() :
    m_adjustment( Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0) ),
    m_adjustment_digits( Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0) ),
    m_HScale(m_adjustment, Gtk::Orientation::HORIZONTAL),
    m_Scale_Digits(m_adjustment_digits),
    start("start"),
    stop("stop"),
    m_forground_colour({1,1,1}),
    m_WorkerThread(nullptr)

{
    set_title("Sorting Algorithm Visulizer");
    set_size_request(400, 300);
    g_object_set(gtk_settings_get_default(),
    "gtk-application-prefer-dark-theme", TRUE,
    NULL);

    auto VBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL,5);
    
    algorithm_selection.set_size_request(150, 20);
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    algorithm_selection.set_model(m_refTreeModel);

    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 1;
    row[m_Columns.m_col_name] = "Selection Sort";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 2;
    row[m_Columns.m_col_name] = "Bubble Sort";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 3;
    row[m_Columns.m_col_name] = "Insertion Sort";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 4;
    row[m_Columns.m_col_name] = "Merge Sort";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 5;
    row[m_Columns.m_col_name] = "Quick Sort";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 6;
    row[m_Columns.m_col_name] = "Heap Sort";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 7;
    row[m_Columns.m_col_name] = "Counting Sort";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 8;
    row[m_Columns.m_col_name] = "Radix Sort";
    
    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 9;
    row[m_Columns.m_col_name] = "Bucket Sort";
    
    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 10;
    row[m_Columns.m_col_name] = "Bingo Sort";

    algorithm_selection.pack_start(m_Columns.m_col_id);
    algorithm_selection.pack_start(m_Columns.m_col_name);

    m_HScale.set_digits(0);
    m_HScale.set_value(1);
    m_HScale.set_value_pos(Gtk::PositionType::LEFT);
    m_HScale.set_draw_value();
    
    auto play_controls_layout = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL,5);
    play_controls_layout->append(start);
    play_controls_layout->append(stop);

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
}

s_window::~s_window(){

}

void s_window::handle_signals(){
    m_forground_colour.signal_color_set().connect(sigc::mem_fun(*this, &s_window::on_forground_color_change));

    m_HScale.signal_value_changed().connect(sigc::mem_fun(*this, &s_window::on_range_change));
    start.signal_clicked().connect(sigc::mem_fun(*this, &s_window::on_start_clicked));

}
void s_window::on_start_clicked(){
}
void s_window::beep(){
    std::cout << "asdkj" << std::endl;
    m_visulizer.draw();
}

void s_window::on_range_change(){
    m_visulizer.on_size_change(m_HScale.get_value());
}

void s_window::on_forground_color_change(){
    m_visulizer.change_forground(m_forground_colour.get_rgba());
}