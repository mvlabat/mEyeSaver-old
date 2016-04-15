//
// Created by mvlabat on 4/14/16.
//

#ifndef MEYESAVER_TIMERCONTROLLER_H
#define MEYESAVER_TIMERCONTROLLER_H

#include <QtCore/QTimer>

#include "../../SettingsController/SettingsController.h"
#include "../TimerSettings/TimerSettings.h"
#include "../RestDialog/RestDialog.h"

class TimerController : public QObject
{
    Q_OBJECT

protected:
    SettingsController* settingsController;
    TimerSettings* timerSettings;
    RestDialog restDialog;

    bool longResting;
    QTimer workTimer;
    QTimer workTimerShort;
    QTimer restTimer;
    QTimer restDialogUpdateTimer;

public:
    void initialize(SettingsController* pSettingsController);

protected:
    void connectDialogSignals();
    void initSession();
    virtual void showRestDialog();
    virtual void hideRestDialog();

protected slots:
    void initShortResting();
    void initResting();
    void postponeResting();
    void initWorking();
    void skipResting();
};


#endif //MEYESAVER_TIMERCONTROLLER_H
