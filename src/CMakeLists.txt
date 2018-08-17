cmake_minimum_required(VERSION 3.12)
project(circuitsim)

include(GenerateExportHeader)

set(CMAKE_CXX_STANDARD 17)

add_library(circuitsim SHARED
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
        component.cpp
        component.hpp
        private/component.hh
        primitives.cpp
        primitives.hpp
        dc_solver.cpp
        dc_solver.hpp
        private/matrix.hh
        private/algebra.hh
        dc_context.cpp
        dc_context.hpp
        private/dc_context.hh matrix.cpp matrix.hpp)


target_include_directories(circuitsim PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/include)

generate_export_header(circuitsim
        BASE_NAME CIRCUITSIM
        EXPORT_MACRO_NAME CIRCUITSIM_API
        NO_EXPORT_MACRO_NAME CIRCUITSIM_PRIVATE
        EXPORT_FILE_NAME include/circuitsim/config/export.h
        STATIC_DEFINE CIRCUITSIM_STATIC)

set_target_properties (circuitsim PROPERTIES
        DEFINE_SYMBOL CIRCUITSIM_EXPORTS
        CXX_VISIBILITY_PRESET hidden
        C_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN ON)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DESTINATION include/circuitsim
        COMPONENT dev
        FILES_MATCHING PATTERN "*.hpp")

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/circuitsim.h
        DESTINATION include
        COMPONENT dev)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/circuitsim/config/export.h
        DESTINATION include/circuitsim/config
        COMPONENT dev)

install(TARGETS circuitsim
        RUNTIME DESTINATION bin COMPONENT runtime
        LIBRARY DESTINATION lib COMPONENT runtime
        ARCHIVE DESTINATION include COMPONENT dev)