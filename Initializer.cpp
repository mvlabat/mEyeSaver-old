//
// Created by mvlabat on 12/7/15.
//

#include "Initializer.h"

void Initializer::initializeWorking()
{
    // Delete welcome window, which is no longer needed.
    delete welcomeWindow;

    // Initialize all the needed components.
    settingsController = new SettingsController();
    timerController = new TimerController();
    timerController->initialize(settingsController);
}
