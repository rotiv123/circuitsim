//
// Created by vitor on 01-09-2018.
//

#include "main_window.hpp"
#include <ui/draw_context_view.hpp>
#include <ui/circuit2d_painter.hpp>
#include <ui/primitives2d.hpp>
#include <algorithm>

static constexpr double PI = 3.1415926535897932384626433;

static constexpr double to_rad(double deg) {
    return deg * PI / 180.0;
}

struct draw_context final : public circuitsim::ui::draw_context_view::concept {

    explicit draw_context(const ::Cairo::RefPtr<::Cairo::Context> &cr, float cx, float cy, float zoom)
            : cr_{cr}, cx_{cx}, cy_{cy}, zoom_{zoom} {
    }

    void draw_background() {
        cr_->set_source_rgb(1, 1, 1);
        cr_->rectangle(0, 0, cx_ * 2, cy_ * 2);
        cr_->fill();

        cr_->set_source_rgb(0.8, 0.8, 0.8);
        cr_->set_identity_matrix();

        cr_->translate(cx_, cy_);
        cr_->scale(zoom_, -1 * zoom_);
        cr_->set_line_width(1.5 / zoom_);

        auto dim = (int) std::max(cx_ / zoom_ + 1, cy_ / zoom_ + 1);

        for (auto i = -dim; i < dim; ++i) {
            cr_->move_to(i, -dim);
            cr_->line_to(i, dim);

            cr_->move_to(-dim, i);
            cr_->line_to(dim, i);
        }

        cr_->stroke();
    }

    void begin(float x, float y, float r) final {

        cr_->set_antialias(::Cairo::Antialias::ANTIALIAS_SUBPIXEL);
        cr_->set_line_join(::Cairo::LineJoin::LINE_JOIN_ROUND);
        cr_->set_line_cap(::Cairo::LineCap::LINE_CAP_ROUND);
        cr_->set_identity_matrix();
        cr_->translate(cx_, cy_);
        cr_->scale(zoom_, -1 * zoom_);
        cr_->translate(x, y);
        cr_->rotate(to_rad(r));

        cr_->set_source_rgb(0, 0, 0);
        cr_->set_line_width(2.5 / zoom_);
    }

    void line(float x1, float y1, float x2, float y2) final {
        cr_->move_to(x1, y1);
        cr_->line_to(x2, y2);
    }

    void rect(float x, float y, float w, float h) final {
        cr_->rectangle(x, y, w, h);
    }

    void circle(float cx, float cy, float r) final {
        cr_->arc(cx, cy, r, 0, to_rad(360));
    }

    void end() final {
        cr_->stroke();
    }

private:
    const ::Cairo::RefPtr<::Cairo::Context> cr_;
    float cx_, cy_, zoom_;
};

main_window::main_window() : circuit_{}, painter_{}, zoom_{40}, pan_{}, tilt_{} {
    set_app_paintable(true);
    signal_draw().connect(sigc::mem_fun(this, &main_window::on_my_draw));

    using namespace circuitsim;
    using namespace circuitsim::ui;

    auto v1 = add_voltage_source(circuit_, 9, {-3, 0});
    auto r1 = add_resistor(circuit_, 200, {0, 3});
    auto r2 = add_resistor(circuit_, 200, {3, 0}, -90);

    circuit_.ground_move_to(0, -5);

    circuit_.ground(v1, 1);
    circuit_.connect(v1, 0, r1, 0);
    circuit_.connect(r1, 1, r2, 0);
    circuit_.ground(r2, 1);

    circuit_.move_to(r2, 1, 0);
}

bool main_window::on_my_draw(const ::Cairo::RefPtr<::Cairo::Context> &cr) {
    Gtk::Allocation allocation = get_allocation();
    auto mw = allocation.get_width() / 2.0f;
    auto mh = allocation.get_height() / 2.0f;
    using namespace circuitsim;
    using namespace circuitsim::ui;
    draw_context ctx{cr, mw, mh, zoom_};

    ctx.draw_background();
    draw_context_view ctx_view{&ctx};
    painter_.draw(circuit_, ctx_view);

    return true;
}

main_window::~main_window() = default;
