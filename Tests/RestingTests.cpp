#include "RestingTests.h"

QString TestRestDialog::getTimerStringTest(qint64 secs)
{
    return getTimerString(secs);
}

void TestTimerController::initWorking()
{
    TimerController::initWorking();
}

void RestingTests::getTimerStringTest() {
    TestRestDialog testRestDialog;
    QCOMPARE(testRestDialog.getTimerStringTest(32), QString("00:00:32"));
    QCOMPARE(testRestDialog.getTimerStringTest(-32), QString("00:00:32"));
    QCOMPARE(testRestDialog.getTimerStringTest(3550), QString("00:59:10"));
    QCOMPARE(testRestDialog.getTimerStringTest(-3550), QString("00:59:10"));
    QCOMPARE(testRestDialog.getTimerStringTest(39550), QString("10:59:10"));
    QCOMPARE(testRestDialog.getTimerStringTest(-39550), QString("10:59:10"));
}

void RestingTests::testTimerScenario1()
{
    QDateTime timeStarted = QDateTime::currentDateTime();
    TestTimerControllerScenario1 testTimerController;
    QTest::qWait(10000);
    QCOMPARE(testTimerController.spyWorkTimer.count(), 1);
    QCOMPARE(testTimerController.spyWorkTimerShort.count(), 1);
    QCOMPARE(testTimerController.spyRestTimer.count(), 2);
}

QTEST_MAIN(RestingTests)
