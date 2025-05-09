cmake_minimum_required(VERSION 3.31)
project(MySFMLGame)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.0)
FetchContent_MakeAvailable(SFML)


set(CMAKE_CXX_STANDARD 20)

add_executable(MySFMLGame main.cpp
        CircleDrawer.cpp
        CircleDrawer.h
        Behaviour.cpp
        Behaviour.h
)

target_link_libraries(MySFMLGame sfml-graphics sfml-window sfml-audio sfml-system)

