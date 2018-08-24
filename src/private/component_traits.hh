//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_TRAITS_HH
#define CIRCUITSIM_COMPONENT_TRAITS_HH

#include <string_view>

namespace circuitsim {

    class dc_context_view;

    template<typename T, T>
    struct check;

    template<class Component>
    struct component_traits;

    namespace detail {
        template<typename U>
        static constexpr int default_port_value(check<int (*)(), &U::default_port_value> *) {
            return U::default_port_value();
        }

        template<typename U>
        static constexpr int default_port_value(...) {
            return -1;
        }

        template<typename U>
        static constexpr double default_value(check<double (*)(), &U::default_value> *) {
            return U::default_value();
        }

        template<typename U>
        static constexpr double default_value(...) {
            return 0;
        }

        template<typename Component, class Traits>
        static std::true_type has_stamp(check<void (*)(const Component &, dc_context_view &), &Traits::stamp> *);

        template<typename Component, class Traits>
        static std::false_type has_stamp(...);
    };

    template<class Component, class Traits = component_traits<Component>>
    inline static constexpr int default_port_value_v = detail::default_port_value<Traits>(nullptr);

    template<class Component, class Traits = component_traits<Component>>
    inline constexpr double default_value_v = detail::default_value<Traits>(nullptr);

    template<class Component, class Traits = component_traits<Component>>
    inline constexpr bool has_stamp_fn_v = decltype(detail::has_stamp<Component, Traits>(nullptr))::value;
}


#endif //CIRCUITSIM_COMPONENT_TRAITS_HH
