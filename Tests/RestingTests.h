//
// Created by mvlabat on 4/14/16.
//

#ifndef MEYESAVER_TEST_H
#define MEYESAVER_TEST_H

#include <QTest>
#include <QtTest/QSignalSpy>
#include "../Resting/TimerController/TimerController.h"
#include "../Resting/TimerSettings/TimerSettings.h"
#include "../Resting/RestDialog/RestDialog.h"

class TestRestDialog : public RestDialog
{
public:
    TestRestDialog() {}
    QString getTimerStringTest(qint64 secs);
};

class TestTimerSettings : public TimerSettings {
public:
    TestTimerSettings() {
        shortWorkingTime = 1000 * 2;
        workingTime = 1000 * 5;
        shortRestingTime = 1000 * 2;
        restingTime = 1000 * 4;
        postponeTime = 1000 * 2;
    }
};

class TestTimerController : public TimerController {
    Q_OBJECT

public:
    QSignalSpy spyWorkTimer;
    QSignalSpy spyWorkTimerShort;
    QSignalSpy spyRestTimer;

    TestTimerController() :
        spyWorkTimer(&workTimer, &QTimer::timeout),
        spyWorkTimerShort(&workTimerShort, &QTimer::timeout),
        spyRestTimer(&restTimer, &QTimer::timeout)
    {
        timerSettings = new TestTimerSettings();
        TimerController::initSession();
    }

protected:
    void showRestDialog() {}
    void hideRestDialog() {}

public slots:
    void initWorking();
};

class TestTimerControllerScenario1 : public TestTimerController {
public:
    TestTimerControllerScenario1()
    {
        TestTimerController::initSession();
        connect(&restTimer, &QTimer::timeout, this, &TestTimerController::initWorking);
    }
};

class RestingTests : public QObject
{
    Q_OBJECT
private slots:
    void getTimerStringTest();
    void testTimerScenario1();
};


#endif //MEYESAVER_TEST_H
