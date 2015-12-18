//
// Created by mvlabat on 12/7/15.
//

#ifndef MEYESAVER_CONTROLLER_H
#define MEYESAVER_CONTROLLER_H

#include <QtCore/qtimer.h>

#include "Views/WelcomeWindow/WelcomeWindow.h"
#include "Views/RestDialog/RestDialog.h"

class Controller : public QObject
{
    Q_OBJECT

private:
    WelcomeWindow* welcomeWindow;
    RestDialog* restDialog;
    QTimer* workTimer;
    QTimer* workTimerShort;
    QTimer* restTimer;
    QTimer* restDialogUpdateTimer;
    //const int workingTime = 1000 * 5; // for debugging
    const int shortWorkingTime = 1000 * 60 * 10;
    const int workingTime = 1000 * 60 * 60;
    const int shortRestingTime = 1000 * 20;
    const int restingTime = 1000 * 60 * 10;
    const int postponeTime = 1000 * 60 * 3;
    bool longResting;

    void showRestDialog();
    void hideRestDialog();

public:
    Controller() :
        QObject(),
        welcomeWindow(new WelcomeWindow),
        restDialog(new RestDialog)
    {
        QObject::connect(welcomeWindow, &WelcomeWindow::windowClosed, this, &Controller::initSession);
        welcomeWindow->show();
    }

    ~Controller()
    {
        delete workTimer;
        delete restTimer;
        delete restDialog;
    }

private slots:
    void initSession();
    void initShortResting();
    void initResting();
    void postponeResting();
    void initWorking();
    void skipResting();

};


#endif //MEYESAVER_CONTROLLER_H
