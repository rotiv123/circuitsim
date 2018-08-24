//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_TRAITS_HH
#define CIRCUITSIM_COMPONENT_TRAITS_HH

#include <string_view>

namespace circuitsim {

    template<class Component>
    struct component_traits {
        static constexpr std::string_view symbol() {
            return Component::symbol();
        }
    };
}


#endif //CIRCUITSIM_COMPONENT_TRAITS_HH
