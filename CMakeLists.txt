cmake_minimum_required(VERSION 3.12)
project(automatic_assignations)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")
set(CMAKE_CXX_FLAGS "-W -Wall -Wextra")

add_executable(automatic_assignations main.cpp src/Availability.cpp src/Astek.cpp src/Team.cpp src/Activity.cpp src/Planning.cpp)
