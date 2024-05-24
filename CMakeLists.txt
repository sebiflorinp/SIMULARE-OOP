cmake_minimum_required(VERSION 3.28)
project(SIMULARE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(SIMULARE main.cpp
        Models/Pen.cpp
        Models/Pen.h
        Repositories/PenRepository.cpp
        Repositories/PenRepository.h
        Controllers/PenController.cpp
        Controllers/PenController.h
        UI/UI.cpp
        UI/UI.h)
target_link_libraries(SIMULARE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

