cmake_minimum_required(VERSION 2.8.9)
project(HungryDot)

include_directories(include)
file(GLOB SOURCES "sources/*.cpp")

add_executable(HungryDot ${SOURCES})
target_link_libraries(HungryDot sfml-graphics sfml-window sfml-audio sfml-system OpenGL)