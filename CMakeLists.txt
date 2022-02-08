cmake_minimum_required(VERSION 3.10)

# set the project name
project(BoidsExample
	VERSION 1.0
    DESCRIPTION "Boids simulation"
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
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT BoidsExample)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SFML_DIR extern/SFML)

set(SFML_BUILD_WINDOW TRUE)
set(SFML_BUILD_GRAPHICS TRUE)
set(SFML_BUILD_AUDIO FALSE)
set(SFML_BUILD_NETWORK FALSE)
set(SFML_BUILD_DOC FALSE)
set(SFML_BUILD_EXAMPLES FALSE)

set(TGUI_DIR extern/TGUI)
set(TGUI_BUILD_GUI_BUILDER FALSE)

set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE )


if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
endif()



add_subdirectory(${SFML_DIR})
add_subdirectory(${TGUI_DIR})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${SFML_DIR}/include)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${TGUI_DIR}/include)

link_directories(${SFML_DIR}/lib/$<CONFIGURATION>)
link_directories(${TGUI_DIR}/lib/$<CONFIGURATION>)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-system)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-window)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE tgui)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${CMAKE_PROJECT_NAME}> $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
  COMMAND_EXPAND_LISTS
  )