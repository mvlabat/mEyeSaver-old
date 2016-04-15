//
// Created by mvlabat on 4/14/16.
//

#ifndef MEYESAVER_TIMERSETTINGS_H
#define MEYESAVER_TIMERSETTINGS_H


class TimerSettings
{
    friend class SettingsController;

protected:
    int shortWorkingTime;
    int workingTime;
    int shortRestingTime;
    int restingTime;
    int postponeTime;

    void setDefaults();

public:
    int getShortWorkingTime();
    int getWorkingTime();
    int getShortRestingTime();
    int getRestingTime();
    int getPostponeTime();
};


#endif //MEYESAVER_TIMERSETTINGS_H
