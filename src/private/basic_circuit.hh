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
#include <functional>

namespace circuitsim {

    template<class ComponentFactory, class Concept>
    class basic_circuit : public Concept {
    public:
        using component_type = typename ComponentFactory::component_type;
        using components_type = std::vector<component_type>;
        using component_factory_type = ComponentFactory;

        basic_circuit() noexcept  : components_{}, factory_{}, max_node_{0} {
        }

        explicit basic_circuit(component_factory_type &&factory) noexcept
                : components_{}, factory_{std::move(factory)}, max_node_{0} {
        }

        const components_type &components() const {
            return components_;
        }

        virtual std::string add(std::string_view symbol) {
            auto name = std::string{symbol} + std::to_string(++names_[symbol]);
            auto c = factory_.create(symbol, std::move(name));
            check_add(c);
            components_.push_back(std::move(c));
            return std::string{get_name(components_.back())};
        }

        virtual void remove(std::string_view src) {
            components_.erase(std::remove_if(std::begin(components_),
                                             std::end(components_),
                                             [&](const auto &x) {
                                                 return get_name(x) == src;
                                             }),
                              std::end(components_));
        }

        virtual void connect(std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) {
            auto &source = get(src);
            auto &destination = get(dst);

            if (get_port(destination, dstp) == -1) {
                set_port(destination, dstp, ++max_node_);
            }

            set_port(source, srcp, get_port(destination, dstp));
        }

        virtual void ground(std::string_view src, unsigned srcp) {
            auto &source = get(src);

            set_port(source, srcp, 0);
        }

        virtual void value(std::string_view src, double val) {
            auto &source = get(src);

            set_value(source, val);
        }

        template<class Visitor>
        void visit(Visitor &&v) const {
            for (const auto &x : components_) {
                v(x);
            }
        }

        virtual std::size_t nodes() const {
            return (std::size_t) max_node_;
        }

        component_type &get(std::string_view name) {
            auto it = std::find_if(std::begin(components_),
                                   std::end(components_),
                                   [=](auto &&x) {
                                       return name == get_name(x);
                                   });

            assert(it != std::end(components_));
            return *it;
        }

    protected:
        void check_add(const component_type &c) const {
            assert(std::all_of(std::begin(components_),
                               std::end(components_),
                               [&](const auto &x) {
                                   return get_name(x) != get_name(c);
                               }));
        }

    private:
        std::unordered_map<std::string_view, int> names_;
        components_type components_;
        component_factory_type factory_;
        int max_node_;
    };
}


#endif //CIRCUITSIM_BASIC_CIRCUIT_HH
