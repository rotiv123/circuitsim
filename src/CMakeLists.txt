cmake_minimum_required(VERSION 3.10)
project(CIRCUITSIM)

include(GenerateExportHeader)

set(CMAKE_CXX_STANDARD 17)

add_library(CIRCUITSIM SHARED
        circuitsim.cpp
        circuitsim.h
        private/component_factory.hh
        private/primitives.hh
        circuit.cpp
        circuit.hpp
        private/basic_circuit.hh
        private/basic_component.hh
        private/resistor.hh
        component_factory.cpp
        component_factory.hpp
        component_view.cpp
        component_view.hpp
        primitives.cpp
        primitives.hpp
        dc_solver.cpp
        dc_solver.hpp
        private/matrix.hh
        private/algebra.hh
        dc_context_view.cpp
        dc_context_view.hpp
        private/dc_context.hh
        ui/circuit2d.cpp
        ui/circuit2d.hpp
        ui/private/basic_component2d.hh
        ui/private/resistor2d.hh
        ui/private/primitives2d.hh
        ui/private/component2d_factory.hh
        ui/component2d_factory.cpp
        ui/component2d_factory.hpp
        ui/component2d_view.cpp
        ui/component2d_view.hpp
        ui/private/basic_circuit2d.hh
        private/circuit.hh
        ui/private/circuit2d.hh
        private/component_view.hh
        private/basic_component_view.hh
        ui/private/basic_component2d_view.hh
        ui/private/component2d_view.hh
        ui/private/voltage_source2d.hh
        ui/point2d.hpp
        ui/draw_context_view.cpp
        ui/draw_context_view.hpp
        ui/svg_painter.cpp
        ui/svg_painter.hpp
        ui/private/svg_painter.hh
        ui/private/draw_context_view.hh
        private/component_traits.hh
        ui/private/ground2d.hh ui/private/wire2d.hh)


target_include_directories(CIRCUITSIM PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/include)

generate_export_header(CIRCUITSIM
        BASE_NAME CIRCUITSIM
        EXPORT_MACRO_NAME CIRCUITSIM_API
        NO_EXPORT_MACRO_NAME CIRCUITSIM_INTERNAL
        EXPORT_FILE_NAME include/circuitsim/config/export.h
        STATIC_DEFINE CIRCUITSIM_STATIC)

set_target_properties (CIRCUITSIM PROPERTIES
        DEFINE_SYMBOL CIRCUITSIM_EXPORTS
        CXX_VISIBILITY_PRESET hidden
        C_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN ON)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION include/circuitsim
        COMPONENT dev
        FILES_MATCHING PATTERN "*.hpp")

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ui
        DESTINATION include/circuitsim/ui
        COMPONENT dev
        FILES_MATCHING PATTERN "*.hpp")

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/circuitsim.h
        DESTINATION include
        COMPONENT dev)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/circuitsim/config/export.h
        DESTINATION include/circuitsim/config
        COMPONENT dev)

install(TARGETS CIRCUITSIM
        RUNTIME DESTINATION bin COMPONENT runtime
        LIBRARY DESTINATION lib COMPONENT runtime
        ARCHIVE DESTINATION lib COMPONENT dev)