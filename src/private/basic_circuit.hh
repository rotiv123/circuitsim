//
// Created by vitor on 12-08-2018.
//

#ifndef CIRCUITSIM_BASIC_CIRCUIT_HH
#define CIRCUITSIM_BASIC_CIRCUIT_HH


#include <cassert>
#include <vector>
#include <algorithm>
#include <string>

namespace circuitsim {

    template<class ComponentFactory>
    struct basic_circuit {

        using component_type = typename ComponentFactory::component_type;
        using components_type = std::vector<component_type>;
        using component_factory_type = ComponentFactory;

        basic_circuit() noexcept  : components_{}, factory_{}, max_node_{0} {
            init();
        }

        explicit basic_circuit(component_factory_type &&factory) noexcept
                : components_{}, factory_{std::move(factory)}, max_node_{0} {
            init();
        }

        components_type &components() const {
            return components_;
        }

        void add(std::string_view symbol, std::string name) {
            auto c = factory_.create(symbol, std::move(name));
            check_add(c);
            components_.push_back(std::move(c));
        }

        void connect(std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) {
            auto &source = get(src);
            auto &destination = get(dst);

            if (destination.port(dstp) == -1) {
                destination.port(dstp, ++max_node_);
            }

            source.port(srcp, destination.port(dstp));
        }

        void ground(std::string_view src, unsigned srcp) {
            auto &source = get(src);

            source.port(srcp, 0);
        }

    private:
        components_type components_;
        component_factory_type factory_;
        int max_node_;

        void check_add(const component_type &c) const {
            assert(std::all_of(std::begin(components_),
                               std::end(components_),
                               [&](const auto &x) {
                                   return x.name() != c.name();
                               }));
        }

        component_type &get(std::string_view name) {
            auto it = std::find_if(std::begin(components_),
                                   std::end(components_),
                                   [=](auto &&x) {
                                       return name == x.name();
                                   });

            assert(it != std::end(components_));
            return *it;
        }

        void init() {
            add("0", "");
        }
    };
}


#endif //CIRCUITSIM_BASIC_CIRCUIT_HH
