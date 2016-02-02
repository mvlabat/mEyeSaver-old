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

set(SOURCE_FILES main.cpp Views/WelcomeWindow/WelcomeWindow.cpp Views/WelcomeWindow/WelcomeWindow.h Controller.cpp Controller.h Models/Settings.cpp Models/Settings.h Views/RestDialog/RestDialog.cpp Views/RestDialog/RestDialog.h Views/Tray/TrayIcon.cpp Views/Tray/TrayIcon.h Views/Tray/TrayMenu.cpp Views/Tray/TrayMenu.h)
set(RESOURCES Resources/resources.qrc)
qt5_add_resources(RESOURCES_RCC ${RESOURCES})
add_executable(mEyeSaver ${SOURCE_FILES} ${RESOURCES_RCC})

target_include_directories(mEyeSaver PUBLIC /usr/include/qt5)
target_link_libraries(mEyeSaver Qt5::Widgets)