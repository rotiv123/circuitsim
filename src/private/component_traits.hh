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
        constexpr int default_port_value(check<int (*)(), &U::default_port_value> *) {
            return U::default_port_value();
        }

        template<typename U>
        constexpr int default_port_value(...) {
            return -1;
        }

        template<typename U>
        constexpr double default_value(check<double (*)(), &U::default_value> *) {
            return U::default_value();
        }

        template<typename U>
        constexpr double default_value(...) {
            return 0;
        }

        template<typename Component, class Traits>
        std::true_type has_stamp(check<void (*)(const Component &, dc_context_view &), &Traits::stamp> *);

        template<typename Component, class Traits>
        std::false_type has_stamp(...);

        template<typename Component, class Traits>
        void stamp(const Component &c, dc_context_view &ctx,
                   check<void (*)(const Component &, dc_context_view &), &Traits::stamp> *) {
            Traits::stamp(c, ctx);
        }

        template<typename Component, class Traits>
        void stamp(const Component &c, dc_context_view &ctx, ...) {
        }
    };

    template<class Component, class Traits = component_traits<Component>>
    inline static constexpr int default_port_value = detail::default_port_value<Traits>(nullptr);

    template<class Component, class Traits = component_traits<Component>>
    inline constexpr double default_value = detail::default_value<Traits>(nullptr);

    template<class Component, class Traits = component_traits<Component>>
    inline constexpr bool has_stamp_fn = decltype(detail::has_stamp<Component, Traits>(nullptr))::value;

    template<class Component, class Traits = component_traits<Component>>
    constexpr void do_stamp(const Component &c, dc_context_view &ctx) {
        detail::stamp<Component, Traits>(c, ctx, nullptr);
    }
}


#endif //CIRCUITSIM_COMPONENT_TRAITS_HH
