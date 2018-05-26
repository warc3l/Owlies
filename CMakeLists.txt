cmake_minimum_required(VERSION 2.8)
project(Owlies)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES    dialogs/dialog_settings_creator.hpp dialogs/dialog_settings_creator.cc
                    dialogs/controllers/draw_settings_ctrl.hpp dialogs/controllers/draw_settings_ctrl.cc
                    dialogs/controllers/faces_settings_ctrl.hpp dialogs/controllers/faces_settings_ctrl.cc
                    dialogs/gui/ui_draw_settings.h
                    dialogs/controllers/thin_settings_ctrl.cc dialogs/controllers/thin_settings_ctrl.hpp
                    dialogs/gui/ui_thin_settings.h
                    dialogs/controllers/filters/bilateral_filter_settings_ctrl.cc dialogs/controllers/filters/bilateral_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_bilateral_filter_settings.h
                    dialogs/controllers/filters/blur_filter_settings_ctrl.cc dialogs/controllers/filters/blur_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_blur_filter_settings.h
                    dialogs/controllers/filters/box_filter_settings_ctrl.cc dialogs/controllers/filters/box_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_box_filter_settings.h
                    dialogs/controllers/filters/closing_filter_settings_ctrl.cc dialogs/controllers/filters/closing_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_closing_filter_settings.h
                    dialogs/controllers/filters/dilate_filter_settings_ctrl.cc dialogs/controllers/filters/dilate_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_dilate_filter_settings.h
                    dialogs/controllers/filters/erode_filter_settings_ctrl.cc dialogs/controllers/filters/erode_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_erode_filter_settings.h
                    dialogs/controllers/filters/gaussian_filter_settings_ctrl.cc dialogs/controllers/filters/gaussian_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_gaussian_filter_settings.h
                    dialogs/controllers/filters/laplacian_filter_settings_ctrl.cc dialogs/controllers/filters/laplacian_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_laplacian_filter_settings.h
                    dialogs/controllers/filters/median_filter_settings_ctrl.cc dialogs/controllers/filters/median_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_median_filter_settings.h
                    dialogs/controllers/filters/opening_filter_settings_ctrl.cc dialogs/controllers/filters/opening_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_opening_filter_settings.h
                    dialogs/controllers/filters/scharr_filter_settings_ctrl.cc dialogs/controllers/filters/scharr_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_scharr_filter_settings.h
                    dialogs/controllers/filters/sobel_filter_settings_ctrl.cc dialogs/controllers/filters/sobel_filter_settings_ctrl.hpp
                    dialogs/gui/filters/ui_sobel_filter_settings.h
                    model/image.hpp model/image.cc
                    main.cpp gui/ui_main_window.h gui/ui_toolbox.h
                    controllers/main_window.hpp controllers/main_window.cc
                    controllers/toolbox.hpp controllers/toolbox.cc
                    gui/subclasses/image_label.hpp gui/subclasses/image_label.cc
                    dialogs/gui/subclasses/color_label.hpp dialogs/gui/subclasses/color_label.cc)

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
