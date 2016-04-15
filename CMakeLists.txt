cmake_minimum_required(VERSION 3.3)
project(mEyeSaver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Network Widgets Test)

set(SOURCE_FILES main.cpp
        Views/WelcomeWindow/WelcomeWindow.cpp Views/WelcomeWindow/WelcomeWindow.h
        Initializer.cpp Initializer.h
        Resting/RestDialog/RestDialog.cpp Resting/RestDialog/RestDialog.h
        Views/Tray/TrayIcon.cpp Views/Tray/TrayIcon.h
        Views/Tray/TrayMenu.cpp Views/Tray/TrayMenu.h
        SettingsController/SettingsController.cpp SettingsController/SettingsController.h
        Resting/TimerSettings/TimerSettings.cpp Resting/TimerSettings/TimerSettings.h
        Resting/TimerController/TimerController.cpp Resting/TimerController/TimerController.h)

set(RESOURCES Resources/resources.qrc)
qt5_add_resources(RESOURCES_RCC ${RESOURCES})
add_executable(mEyeSaver ${SOURCE_FILES} ${RESOURCES_RCC})

target_include_directories(mEyeSaver PUBLIC /usr/include/qt5)
target_link_libraries(mEyeSaver Qt5::Widgets)

# Testing.
enable_testing()
add_executable(tests
        SettingsController/SettingsController.cpp SettingsController/SettingsController.h
        Resting/TimerController/TimerController.cpp Resting/TimerController/TimerController.h
        Resting/TimerSettings/TimerSettings.cpp Resting/TimerSettings/TimerSettings.h
        Resting/RestDialog/RestDialog.cpp Resting/RestDialog/RestDialog.h
        Tests/RestingTests.cpp Tests/RestingTests.h
)
add_test(tests tests)

target_link_libraries(tests Qt5::Test Qt5::Widgets)
