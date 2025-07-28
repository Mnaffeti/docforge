cmake_minimum_required(VERSION 3.12)
project(MathLibrary VERSION 1.2.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")

# Include directories
include_directories(include)

# Find required packages
find_package(Threads REQUIRED)

# Source files
set(SOURCES
    src/calculator.cpp
)

# Header files
set(HEADERS
    include/calculator.h
    include/memory_manager.h
    include/data_structures.h
)

# Create static library
add_library(mathlib STATIC ${SOURCES} ${HEADERS})
target_include_directories(mathlib PUBLIC include)
target_link_libraries(mathlib Threads::Threads)

# Create shared library
add_library(mathlib_shared SHARED ${SOURCES} ${HEADERS})
target_include_directories(mathlib_shared PUBLIC include)
target_link_libraries(mathlib_shared Threads::Threads)
set_target_properties(mathlib_shared PROPERTIES OUTPUT_NAME mathlib)

# Example executable
add_executable(calculator_demo src/main.cpp)
target_link_libraries(calculator_demo mathlib)

# Test executable
add_executable(run_tests tests/test_calculator.cpp)
target_link_libraries(run_tests mathlib)

# Installation rules
install(TARGETS mathlib mathlib_shared calculator_demo
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES ${HEADERS} DESTINATION include/mathlib)

# Package configuration
set(CPACK_PACKAGE_NAME "MathLibrary")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A comprehensive C++ mathematics library")
set(CPACK_PACKAGE_VENDOR "Math Library Team")

include(CPack)

# Enable testing
enable_testing()
add_test(NAME BasicTests COMMAND run_tests)

# Documentation target (requires Doxygen)
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs)
    
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in 
                   ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()

# Code coverage (requires gcov)
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if(ENABLE_COVERAGE)
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    endif()
endif()

# Static analysis (requires cppcheck)
find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    add_custom_target(cppcheck
        COMMAND ${CPPCHECK} --enable=all --std=c++17 --inconclusive 
                --xml --xml-version=2 ${CMAKE_CURRENT_SOURCE_DIR}/src 
                2> cppcheck-report.xml
        COMMENT "Running static analysis with cppcheck"
    )
endif()

# Print configuration summary
message(STATUS "")
message(STATUS "Configuration Summary:")
message(STATUS "  Project: ${PROJECT_NAME} ${PROJECT_VERSION}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  Install Prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "  Doxygen Found: ${DOXYGEN_FOUND}")
message(STATUS "  CPPCheck Found: ${CPPCHECK}")
message(STATUS "")
