//
// Created by vitor on 01-09-2018.
//

#ifndef CIRCUITSIM_MAIN_WINDOW_HPP
#define CIRCUITSIM_MAIN_WINDOW_HPP

#include <gtkmm/window.h>
#include <ui/circuit2d.hpp>
#include <ui/circuit2d_painter.hpp>

class main_window final : public Gtk::Window {
public:
    main_window();

    ~main_window() final;

private:
    circuitsim::ui::circuit2d circuit_;
    circuitsim::ui::circuit2d_painter painter_;
    float zoom_, pan_, tilt_;

    bool on_my_draw(const ::Cairo::RefPtr<::Cairo::Context> &cr);
};


#endif //CIRCUITSIM_MAIN_WINDOW_HPP
