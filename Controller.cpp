//
// Created by mvlabat on 12/7/15.
//

#include "Controller.h"

void Controller::showRestDialog()
{
    restDialogUpdateTimer->start();
    restDialog->show();
}

void Controller::hideRestDialog()
{
    restDialogUpdateTimer->stop();
    restDialog->hide();
}

void Controller::initSession()
{
    // Delete welcome window, which is no longer needed.
    delete welcomeWindow;

    // Connect rest dialog buttons with corresponding controller slots.
    connect(restDialog, &RestDialog::postponed, this, &Controller::postponeResting);
    connect(restDialog, &RestDialog::returned, this, &Controller::initWorking);
    connect(restDialog, &RestDialog::skipped, this, &Controller::skipResting);

    // Init a timer for rest dialog text updating.
    restDialogUpdateTimer = new QTimer();
    restDialogUpdateTimer->setInterval(1000 / 25);
    connect(restDialogUpdateTimer, &QTimer::timeout, restDialog, &RestDialog::updateTimer);

    // Init timers both for working and resting. Start only the timer for working.
    workTimer = new QTimer();
    workTimerShort = new QTimer();
    restTimer = new QTimer();

    connect(workTimerShort, &QTimer::timeout, this, &Controller::initShortResting);
    connect(workTimer, &QTimer::timeout, this, &Controller::initResting);
    connect(restTimer, &QTimer::timeout, restDialog, &RestDialog::enableReturn);
    workTimer->setSingleShot(true);
    workTimer->start(workingTime);
    workTimerShort->setSingleShot(true);
    workTimerShort->start(shortWorkingTime);

    restTimer->setSingleShot(true);
}

void Controller::initShortResting()
{
    longResting = false;
    restDialog->setRestingTime(shortRestingTime);
    restTimer->start(shortRestingTime);
    showRestDialog();
}

void Controller::initResting()
{
    longResting = true;
    restDialog->setRestingTime(restingTime);
    restTimer->start(restingTime);
    showRestDialog();
}

void Controller::postponeResting()
{
    if (longResting || workTimer->remainingTime() <= shortWorkingTime) {
        workTimer->start(postponeTime);
    }
    else {
        restTimer->start(postponeTime);
    }
    hideRestDialog();
}

void Controller::initWorking()
{
    if (longResting) {
        workTimer->start(workingTime);
    }
    if (workTimer->remainingTime() > shortWorkingTime) {
        workTimerShort->start(shortWorkingTime);
    }
    hideRestDialog();
}

void Controller::skipResting()
{
    initWorking();
}
