//
// Created by mvlabat on 4/14/16.
//

#ifndef MEYESAVER_SETTINGSCONTROLLER_H
#define MEYESAVER_SETTINGSCONTROLLER_H

#include "../Resting/TimerSettings/TimerSettings.h"

class SettingsController
{
    TimerSettings timerSettings;
public:
    SettingsController() {
        timerSettings.setDefaults();
    }

    TimerSettings* getTimerSettings();
};


#endif //MEYESAVER_SETTINGSCONTROLLER_H
