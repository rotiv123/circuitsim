//
// Created by vitor on 13-08-2018.
//

#ifndef PROJECT_BASIC_COMPONENT_HH
#define PROJECT_BASIC_COMPONENT_HH

#include <cassert>
#include <array>
#include <string>

namespace circuitsim {

    template<class Derived, std::size_t NPorts>
    struct basic_component {
        explicit basic_component(std::string name) noexcept
                : name_{std::move(name)}, ports_{} {
        }

        std::string_view name() const {
            return name_;
        }

        int port(unsigned ix) const {
            return ports_[ix];
        }

        void port(unsigned ix, int val) {
            impl().check_set_port(ix, val);
            ports_[ix] = val;
        }

    protected:
        void check_set_port(unsigned ix, int val) const {
            assert(ix < NPorts);
        }

    private:
        std::string name_;
        std::array<int, NPorts> ports_;

        const Derived &impl() const {
            return *static_cast<const Derived *>(this);
        }

        Derived &impl() {
            return *static_cast<Derived *>(this);
        }
    };

}


#endif //PROJECT_BASIC_COMPONENT_HH
