//
// Created by vitor on 13-08-2018.
//

#ifndef PROJECT_RESISTOR_HH
#define PROJECT_RESISTOR_HH

#include "basic_resistor.hh"

namespace circuitsim {

    class resistor final : public basic_resistor<resistor> {
    public:
        using base = basic_resistor<resistor>;
        using base::base;
    };

    template<>
    struct component_traits<resistor> final : resistor_traits<resistor> {
    };

}


#endif //PROJECT_RESISTOR_HH
