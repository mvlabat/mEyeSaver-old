//
// Created by mvlabat on 12/14/15.
//

#include <iostream>
#include "RestDialog.h"

void RestDialog::setRestingTime(int secs)
{
    endTime = QDateTime::currentDateTime().addMSecs(secs);
    returnButton->setEnabled(false);
}

void RestDialog::enableReturn()
{
    returnButton->setEnabled(true);
}

QString RestDialog::getTimerString(qint64 secs)
{
    secs = llabs(secs);
    return QString("%1:%2:%3")
        .arg((int)secs / 60 / 60, 2, 10, QLatin1Char('0'))
        .arg((int)(secs / 60) % 60, 2, 10, QLatin1Char('0'))
        .arg((int)secs % 60, 2, 10, QLatin1Char('0'));
}

void RestDialog::updateTimer()
{
    qint64 secs = QDateTime::currentDateTime().msecsTo(endTime) / 1000;
    timerLabel->setText("Time to rest" + getTimerString(secs));
}
