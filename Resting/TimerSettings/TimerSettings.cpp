//
// Created by mvlabat on 4/14/16.
//

#include "TimerSettings.h"

void TimerSettings::setDefaults()
{
    shortWorkingTime = 1000 * 60 * 10;
    workingTime = 1000 * 60 * 60;
    // workingTime = 1000 * 5; // for debugging
    shortRestingTime = 1000 * 20;
    restingTime = 1000 * 60 * 10;
    postponeTime = 1000 * 60 * 3;
}

int TimerSettings::getShortWorkingTime()
{
    return shortWorkingTime;
}

int TimerSettings::getWorkingTime()
{
    return workingTime;
}

int TimerSettings::getRestingTime()
{
    return restingTime;
}

int TimerSettings::getShortRestingTime()
{
    return shortRestingTime;
}

int TimerSettings::getPostponeTime()
{
    return postponeTime;
}
