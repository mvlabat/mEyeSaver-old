//
// Created by mvlabat on 4/14/16.
//

#include "TimerController.h"

void TimerController::initialize(SettingsController *pSettingsController)
{
    settingsController = pSettingsController;
    timerSettings = settingsController->getTimerSettings();
    connectDialogSignals();
    initSession();
}

void TimerController::showRestDialog()
{
    restDialogUpdateTimer.start();
    restDialog.show();
}

void TimerController::hideRestDialog()
{
    restDialogUpdateTimer.stop();
    restDialog.hide();
}

void TimerController::connectDialogSignals()
{
    // Connect rest dialog buttons with corresponding controller slots.
    connect(&restDialog, &RestDialog::postponed, this, &TimerController::postponeResting);
    connect(&restDialog, &RestDialog::returned, this, &TimerController::initWorking);
    connect(&restDialog, &RestDialog::skipped, this, &TimerController::skipResting);
    connect(&restTimer, &QTimer::timeout, &restDialog, &RestDialog::enableReturn);

    // Init a timer for rest dialog text updating.
    restDialogUpdateTimer.setInterval(1000 / 25);
    connect(&restDialogUpdateTimer, &QTimer::timeout, &restDialog, &RestDialog::updateTimer);
}

void TimerController::initSession()
{
    connect(&workTimerShort, &QTimer::timeout, this, &TimerController::initShortResting);
    connect(&workTimer, &QTimer::timeout, this, &TimerController::initResting);

    workTimer.setSingleShot(true);
    workTimer.start(timerSettings->getWorkingTime());
    workTimerShort.setSingleShot(true);
    workTimerShort.start(timerSettings->getShortWorkingTime());

    restTimer.setSingleShot(true);
}

void TimerController::initShortResting()
{
    longResting = false;
    restDialog.setRestingTime(timerSettings->getShortRestingTime());
    restTimer.start(timerSettings->getShortRestingTime());
    showRestDialog();
}

void TimerController::initResting()
{
    longResting = true;
    restDialog.setRestingTime(timerSettings->getRestingTime());
    restTimer.start(timerSettings->getRestingTime());
    showRestDialog();
}

void TimerController::postponeResting()
{
    if (longResting || workTimer.remainingTime() <= timerSettings->getShortWorkingTime()) {
        workTimer.start(timerSettings->getPostponeTime());
    }
    else {
        restTimer.start(timerSettings->getPostponeTime());
    }
    hideRestDialog();
}

void TimerController::initWorking()
{
    if (longResting) {
        workTimer.start(timerSettings->getWorkingTime());
    }
    if (workTimer.remainingTime() > timerSettings->getShortWorkingTime()) {
        workTimerShort.start(timerSettings->getShortWorkingTime());
    }
    hideRestDialog();
}

void TimerController::skipResting()
{
    initWorking();
}
