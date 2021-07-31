cmake_minimum_required(VERSION 3.20)
project(desctop_norm)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/alex/Qt/5.15.2/gcc_64")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Svg
        REQUIRED)

add_executable(desctop_norm
        main.cpp
        mainwindow.cpp
        mainwindow.h
        in_page.cpp
        in_page.h
        reg_page.cpp
        reg_page.h
        home_page.cpp
        home_page.h
        customshadoweffect.cpp
        customshadoweffect.h
        round_graph.cpp
        round_graph.h
        )
target_link_libraries(desctop_norm
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Svg
        )

