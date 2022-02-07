cmake_minimum_required(VERSION 3.10)

# set the project name
project(BoidsExample
	VERSION 1.0
    DESCRIPTION "A brief CMake experiment"
    LANGUAGES CXX)

set(SOURCE_FILES 
	BoidsExample/AlignmentController.h
	BoidsExample/AlignmentController.cpp
	BoidsExample/AlignmentRule.h
	BoidsExample/AlignmentRule.cpp
	BoidsExample/Application.h
	BoidsExample/Application.cpp
	BoidsExample/BasicController.h
	BoidsExample/BasicController.cpp
	BoidsExample/Boid.h
	BoidsExample/Boid.cpp
	BoidsExample/BoidsFactory.h
	BoidsExample/BoidsFactory.cpp
	BoidsExample/CohesionController.h
	BoidsExample/CohesionController.cpp
	BoidsExample/CohesionRule.h
	BoidsExample/CohesionRule.cpp
	BoidsExample/Flock.h
	BoidsExample/Flock.cpp
	BoidsExample/main.cpp
	BoidsExample/Math.h
	BoidsExample/Math.cpp
	BoidsExample/Rule.h
	BoidsExample/SeperationController.h
	BoidsExample/SeperationController.cpp
	BoidsExample/SeperationRule.h
	BoidsExample/SeperationRule.cpp)

# add the executable
add_executable(BoidsExample ${SOURCE_FILES})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(BoidsExample PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(BoidsExample PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # other macOS-specific flags for Clang
endif()

target_include_directories(BoidsExample PRIVATE 
	D:/3rd-party/SFML/build/include 
	D:/3rd-party/TGUI/build/include)

find_library(LIBRARY_SFML_SYSTEM sfml-system.lib)
find_library(LIBRARY_SFML_GRAPHICS sfml-graphics.lib)
find_library(LIBRARY_SFML_WINDOW sfml-window.lib)

if (LIBRARY_SFML_SYSTEM AND LIBRARY_SFML_GRAPHICS AND LIBRARY_SFML_WINDOW)
    target_link_libraries(BoidsExample PRIVATE ${LIBRARY_SFML_SYSTEM})
    target_link_libraries(BoidsExample PRIVATE ${LIBRARY_SFML_GRAPHICS})
    target_link_libraries(BoidsExample PRIVATE ${LIBRARY_SFML_WINDOW})
else()
    message(FATAL_ERROR "Could not find SFML")
endif()

find_library(LIBRARY_TGUI tgui.lib)

if (LIBRARY_TGUI)
    target_link_libraries(BoidsExample PRIVATE ${LIBRARY_TGUI})
else()
    message(FATAL_ERROR "Could not find TGUI")
endif()

