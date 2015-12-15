//
// Created by mvlabat on 11/18/15.
//

#include "WelcomeWindow.h"

void WelcomeWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
}