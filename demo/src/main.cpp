//
// Created by vitor on 12-08-2018.
//

#include <iostream>
#include <iomanip>
#include <circuitsim.h>
#include <circuit.hpp>
#include <ui/circuit2d.hpp>
#include <primitives.hpp>
#include <ui/primitives2d.hpp>
#include <dc_solver.hpp>
#include <ui/circuit2d_painter.hpp>
#include <ui/draw_context_view.hpp>
#include <ui/point2d.hpp>

#include <private/primitives.hh>
#include <ui/private/primitives2d.hh>

#include <gtkmm/application.h>

#include "main_window.hpp"

struct svg_context_view_model final : public circuitsim::ui::draw_context_view::concept {

    svg_context_view_model(unsigned w, unsigned h) : result_{}, w_{w}, h_{h} {
        result_ << "<g height=\"" << h << "\" width=\"" << w << "\" >" << std::endl;
    }

    void begin(float x, float y, float r) final {
        result_ << " <g transform=\"translate(" << x << "," << y << ") rotate(" << r << ")\">"
                << std::endl;
    }

    void line(float x1, float y1, float x2, float y2) final {
        result_ << "  <line x1=\"" << x1 << "\""
                << " y1=\"" << y1 << "\""
                << " x2=\"" << x2 << "\""
                << " y2=\"" << y2 << "\" />"
                << std::endl;
    }

    void rect(float x, float y, float w, float h) final {
        result_ << "  <rect x=\"" << x << "\""
                << " y=\"" << y << "\""
                << " width=\"" << w << "\""
                << " height=\"" << h << "\" />"
                << std::endl;
    }

    void circle(float cx, float cy, float r) final {
        result_ << "  <circle cx=\"" << cx << "\""
                << " cy=\"" << cy << "\""
                << " r=\"" << r << "\" />"
                << std::endl;
    }

    void end() final {
        result_ << " </g>" << std::endl;
    }

    std::string to_svg() {
        result_ << "</g>" << std::endl;
        return result_.str();
    }

private:
    std::ostringstream result_;
    unsigned w_, h_;
};

void test1() {
    std::cout << "circuitsim version: " << circuitsim_version() << std::endl;

    using namespace circuitsim;
    using namespace circuitsim::ui;

    circuit2d c{};

    auto v1 = c.add("V");
    auto v2 = add_voltage_source(c);
    auto r1 = add_resistor(c);
    auto r2 = add_resistor(c);
    auto r3 = add_resistor(c);
    auto r4 = add_resistor(c);
    auto r5 = add_resistor(c);

    c.value(v1, 9);
    c.value(v2, 9);
    c.value(r2, 200);
    c.value(r3, 200);

    c.ground(v1, 1);
    c.connect(v1, 0, r1, 0);
    c.connect(r1, 1, r2, 0);
    c.connect(r3, 0, r2, 0);
    c.ground(r2, 1);
    c.connect(r5, 1, r5, 0);

    c.remove(v1);
    c.connect(r1, 0, v2, 0);
    c.ground(v2, 1);

    c.visit([](auto &&x) {
        auto n1 = x.port(0);
        auto n2 = x.port(1);
        std::cout << x.name() << " " << n1 << " " << n2 << " " << x.value() << std::endl;
    });
    std::cout << std::endl;

    dc_solver dc;
    std::cout << "dc solving..." << std::endl;
    if (!dc.solve(c)) {
        std::cout << "ups... :(" << std::endl;
    } else {
        dc.visit([](auto &&dp) {
            std::visit([](auto &&x) {
                using T = std::decay_t<decltype(x)>;
                if constexpr (std::is_same_v<T, circuitsim::node_voltage>) {
                    std::cout << "v_" << x.node_id << " = " << x.value << std::endl;
                } else if constexpr (std::is_same_v<T, circuitsim::voltage_source_current>) {
                    std::cout << "i_" << x.voltage_source_id << " = " << x.value << std::endl;
                }
            }, dp);
        });
    }
}

void test2() {
    using namespace circuitsim;
    using namespace circuitsim::ui;

    circuit2d c{};

    auto v1 = add_voltage_source(c, 9, {-3, 0});
    auto r1 = add_resistor(c, 200, {0, 3});
    auto r2 = add_resistor(c, 200, {3, 0}, -90);

    c.ground_move_to(0, -5);

    c.ground(v1, 1);
    c.connect(v1, 0, r1, 0);
    c.connect(r1, 1, r2, 0);
    c.ground(r2, 1);

    c.move_to(r2, 1, 0);

    circuit2d_painter painter;
    std::cout << R"__(<svg viewBox="-400 -300 800 600" height="600" width="800">)__" << std::endl;
    std::cout << R"__(<g fill="none" stroke="black" stroke-width="0.0625" transform="scale(40,-40)">)__" << std::endl;
    std::cout << R"__(<rect x="-10" y="-10" width="20" height="20" fill="white" stroke="none" />)__" << std::endl;
    std::cout << R"__(<g stroke="silver" stroke-width="0.0375" >)__" << std::endl;
    std::cout << R"__(<line x1="0" y1="-7" x2="0" y2="7" stroke-width="0.0625" />)__" << std::endl;
    std::cout << R"__(<line x1="-7" y1="0" x2="7" y2="0" stroke-width="0.0625" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="1" x2="6" y2="1" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="2" x2="6" y2="2" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="3" x2="6" y2="3" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="4" x2="6" y2="4" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="5" x2="6" y2="5" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="6" x2="6" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="-1" x2="6" y2="-1" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="-2" x2="6" y2="-2" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="-3" x2="6" y2="-3" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="-4" x2="6" y2="-4" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="-5" x2="6" y2="-5" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="-6" x2="6" y2="-6" />)__" << std::endl;
    std::cout << R"__(<line x1="1" y1="-6" x2="1" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="2" y1="-6" x2="2" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="3" y1="-6" x2="3" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="4" y1="-6" x2="4" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="5" y1="-6" x2="5" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="6" y1="-6" x2="6" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="-1" y1="-6" x2="-1" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="-2" y1="-6" x2="-2" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="-3" y1="-6" x2="-3" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="-4" y1="-6" x2="-4" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="-5" y1="-6" x2="-5" y2="6" />)__" << std::endl;
    std::cout << R"__(<line x1="-6" y1="-6" x2="-6" y2="6" />)__" << std::endl;
    std::cout << "</g>" << std::endl;

    svg_context_view_model ctx{800, 600};
    draw_context_view ctx_view{&ctx};
    painter.draw(c, ctx_view);
    std::cout << ctx.to_svg() << std::endl;
    std::cout << "</g>" << std::endl;
    std::cout << "</svg>" << std::endl;
}

void test3() {
    using namespace circuitsim;
    using namespace circuitsim::ui;

    std::cout << "sizeof(primitive) " << sizeof(primitive) << " bytes" << std::endl;
    std::cout << "sizeof(resistor) " << sizeof(resistor) << " bytes" << std::endl;
    std::cout << "sizeof(voltage_source) " << sizeof(voltage_source) << " bytes" << std::endl;
    std::cout << std::endl;
    std::cout << "sizeof(primitive2d) " << sizeof(primitive2d) << " bytes" << std::endl;
    std::cout << "sizeof(ground2d) " << sizeof(ground2d) << " bytes" << std::endl;
    std::cout << "sizeof(wire2d) " << sizeof(wire2d) << " bytes" << std::endl;
    std::cout << "sizeof(resistor2d) " << sizeof(resistor2d) << " bytes" << std::endl;
    std::cout << "sizeof(voltage_source2d) " << sizeof(voltage_source2d) << " bytes" << std::endl;
}

int teste4(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    main_window window;
    window.set_default_size(800, 600);
    window.show_all();

    return app->run(window);
}

int main(int argc, char *argv[]) {

    return teste4(argc, argv);
}