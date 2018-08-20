//
// Created by vitor on 12-08-2018.
//

#ifndef CIRCUITSIM_BASIC_CIRCUIT_HH
#define CIRCUITSIM_BASIC_CIRCUIT_HH


#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "component_factory.hh"

namespace circuitsim {

    template<class ComponentFactory>
    class basic_circuit {
	public:
        using component_type = typename ComponentFactory::component_type;
        using components_type = std::vector<component_type>;
        using component_factory_type = ComponentFactory;

        basic_circuit() noexcept  : components_{}, factory_{}, max_node_{0} {
        }

        explicit basic_circuit(component_factory_type &&factory) noexcept
                : components_{}, factory_{std::move(factory)}, max_node_{0} {
        }

        components_type &components() const {
            return components_;
        }

        std::string add(std::string_view symbol) {
            auto name = std::string{symbol} + std::to_string(++names_[symbol]);
            auto c = factory_.create(symbol, std::move(name));
            check_add(c);
            components_.push_back(std::move(c));
            return std::string{components_.back().name()};
        }

        void remove(std::string_view src) {
            components_.erase(std::remove_if(std::begin(components_),
                                             std::end(components_),
                                             [&](const auto &x) { return x.name() == src; }), std::end(components_));
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

        void value(std::string_view src, double val) {
            auto &source = get(src);

            source.value(val);
        }

        template<class Visitor>
        void visit(Visitor &&v) const {
            for (const auto &x : components_) {
                v(x);
            }
        }

        std::size_t nodes() const {
            return (std::size_t) max_node_;
        }

    private:
        std::unordered_map<std::string_view, int> names_;
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
    };
}


#endif //CIRCUITSIM_BASIC_CIRCUIT_HH
