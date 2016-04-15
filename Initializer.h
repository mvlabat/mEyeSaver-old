//
// Created by mvlabat on 12/7/15.
//

#ifndef MEYESAVER_CONTROLLER_H
#define MEYESAVER_CONTROLLER_H

#include <QtCore/qtimer.h>

#include "Views/WelcomeWindow/WelcomeWindow.h"
#include "SettingsController/SettingsController.h"
#include "Resting/TimerController/TimerController.h"
#include "Views/Tray/TrayIcon.h"

class Initializer : public QObject
{
    Q_OBJECT

private:
    TrayIcon tray;
    WelcomeWindow* welcomeWindow;
    SettingsController* settingsController;
    TimerController* timerController;

public:
    Initializer() :
        QObject(),
        welcomeWindow(new WelcomeWindow)
    {
        QObject::connect(welcomeWindow, &WelcomeWindow::windowClosed, this, &Initializer::initializeWorking);
        welcomeWindow->show();
    }

    ~Initializer() {
        delete settingsController;
        delete timerController;
    }

private slots:
    void initializeWorking();
};


#endif //MEYESAVER_CONTROLLER_H
