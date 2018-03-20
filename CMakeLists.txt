cmake_minimum_required(VERSION 2.8)
project(Owlies)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp GUI/mainwindow.cpp)

# Boost
set(Boost_INCLUDE_DIR /home/marcel/devs/boost-build/include)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.61 COMPONENTS system regex)
include_directories(/home/marcel/devs/boost-build/include)
link_directories(/home/marcel/devs/boost-build/lib)

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Qt
find_package(Qt5 COMPONENTS Core Widgets)
include_directories(${Qt_includes})

add_executable(Owlies ${SOURCE_FILES})

# Target Link Boost
target_link_libraries(Owlies ${Boost_LIBRARIES})

# Target Link OpenCV
target_link_libraries(Owlies ${OpenCV_LIBS})

# Target Link Qt5
target_link_libraries(Owlies Qt5::Core Qt5::Gui Qt5::Widgets)