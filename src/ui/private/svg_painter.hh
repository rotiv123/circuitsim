//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_SVG_PAINTER_HH
#define CIRCUITSIM_SVG_PAINTER_HH

#include <sstream>
#include <iomanip>
#include "ui/svg_painter.hpp"
#include "../circuit2d.hpp"
#include "draw_context_view.hh"

namespace circuitsim::ui {

    struct svg_context_view_model final : public draw_context_view::concept {

        svg_context_view_model(unsigned w, unsigned h) : result_{}, w_{w}, h_{h} {
            result_ << "<svg viewBox=\"-" << w / 2 << " -" << h / 2 << " " << w << " " << h << "\""
                    << " height=\"" << h << "\" width=\"" << w << "\""
                    << R"#( stroke="black" fill="none" stroke-width="0.0625" transform="scale(40,-40)" >)#"
                    << std::endl;
        }

        void start_g() {
            result_ << R"#( <g transform="translate(0,0) rotate(0)>)#"
                    << std::endl;
        }

        void line(float x1, float y1, float x2, float y2) final {
            result_ << "  <line x1=\"" << x1 << "\""
                    << " x2=\"" << x2 << "\""
                    << " y1=\"" << y1 << "\""
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

        void end_g() {
            result_ << " </g>" << std::endl;
        }

        std::string to_svg() {
            result_ << "</svg>" << std::endl;
            return result_.str();
        }

    private:
        std::ostringstream result_;
        unsigned w_, h_;
    };

    class svg_painter::impl {
    public:
        std::string draw(const circuit2d &c) {
            svg_context_view_model ctx{800, 600};
            draw_context_view ctx_view{&ctx};
            c.visit([&](const component2d_view &x) {
                ctx.start_g();
                x.draw(ctx_view);
                ctx.end_g();
            });

            return ctx.to_svg();
        }
    };
}


#endif //CIRCUITSIM_SVG_PAINTER_HH
