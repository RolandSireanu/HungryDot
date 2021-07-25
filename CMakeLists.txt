cmake_minimum_required(VERSION 2.8.9)
project(HungryDot)
set(CMAKE_BUILD_TYPE Debug)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17")


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

add_subdirectory(include)
add_subdirectory(sources)


include("./externalLibs/AddSfmlLibs.cmake")
# target_link_libraries(HungryDot sfml-graphics sfml-window sfml-audio sfml-system OpenGL)
