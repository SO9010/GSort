#pragma once
#include <gtkmm-4.0/gtkmm.h>
#include "visulizer.hpp"

class s_window : public Gtk::Window {
public:
    s_window();
    virtual ~s_window();

protected:
    // Widget declorations

    // Algorithm options
    Gtk::ComboBox algorithm_selection;

    // Tree model columns
    class ModelColumns : public Gtk::TreeModel::ColumnRecord{
    public:
        ModelColumns()
        { add(m_col_id); add(m_col_name); }

        Gtk::TreeModelColumn<int> m_col_id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };
    ModelColumns m_Columns;

    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

    Glib::RefPtr<Gtk::Adjustment> m_adjustment, m_adjustment_digits;
    Gtk::Scale m_HScale, m_Scale_Digits;
    
    Gtk::Label m_description;
    
    // Play back options
    Gtk::Button start, stop;

    Gtk::ColorButton m_forground_colour;
    Gtk::ColorButton m_background_colour;
    Visulizer m_visulizer;

    selection m_selection;

    Glib::Dispatcher m_Dispatcher;
    std::thread* m_WorkerThread;

    // Widget signal handeling
    void handle_signals();
    void on_start_clicked();
    void on_range_change();
    void on_forground_color_change();
    void beep();
};