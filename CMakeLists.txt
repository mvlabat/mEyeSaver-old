cmake_minimum_required(VERSION 3.3)
project(mEyeSaver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

if ( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    set(Qt5_DIR ${TOOLCHAIN_INCLUDE_PREFIX}/qt5/lib/cmake/Qt5)
endif()

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

target_include_directories(mEyeSaver PUBLIC ${TOOLCHAIN_INCLUDE_PREFIX}/qt5/${TOOLCHAIN_INCLUDE_SUFFIX})
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

target_include_directories(tests PUBLIC ${TOOLCHAIN_INCLUDE_PREFIX}/qt5/${TOOLCHAIN_INCLUDE_SUFFIX})
target_link_libraries(tests Qt5::Test Qt5::Widgets)

# Installing.
if ( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    set(RUNTIME_DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
    set(RUNTIME_DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
endif()

install(TARGETS mEyeSaver
        RUNTIME DESTINATION ${RUNTIME_DESTINATION}
)

if ( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    set(REGEXPOR .*\(libpcre16-0\\\\.dll|libpng16-16\\\\.dll\))
    install(CODE "execute_process(COMMAND ${CMAKE_SOURCE_DIR}/create_windows_bundle.sh -e ${CMAKE_INSTALL_PREFIX}/mEyeSaver.exe -d ${CMAKE_INSTALL_PREFIX} -t ${CMAKE_FIND_ROOT_PATH} -o \"${REGEXPOR}\")")
endif()
