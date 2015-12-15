cmake_minimum_required(VERSION 3.3)
project(mEyeSaver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Network)
find_package(Qt5Widgets)
#qtquick_compiler_add_resources(RESOURCES example.qrc)
#add_executable(myapp ${SRC_LIST} ${RESOURCES)
#qt5_use_modules(myapp Quick Core Network)

set(SOURCE_FILES main.cpp Windows/WelcomeWindow/WelcomeWindow.cpp Windows/WelcomeWindow/WelcomeWindow.h Controller.cpp Controller.h Models/Settings.cpp Models/Settings.h Windows/RestDialog/RestDialog.cpp Windows/RestDialog/RestDialog.h)
add_executable(mEyeSaver ${SOURCE_FILES})

target_include_directories(mEyeSaver PUBLIC /usr/include/qt5)
target_link_libraries(mEyeSaver Qt5::Widgets)