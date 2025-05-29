cmake_minimum_required(VERSION 3.16)
project(CoupGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(COPY display/arial.ttf DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/display)

add_executable(CoupGame
        display/Gui.cpp
        Player.cpp
        BoardGame.cpp
        GameRules.cpp
        RolesC/Baron.cpp
        RolesC/General.cpp
        RolesC/Governor.cpp
        RolesC/Judge.cpp
        RolesC/Merchant.cpp
        RolesC/Spy.cpp
        main.cpp
)

target_link_libraries(CoupGame sfml-graphics sfml-window sfml-system)
