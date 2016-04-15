//
// Created by mvlabat on 12/17/15.
//

#ifndef MEYESAVER_TRAYICON_H
#define MEYESAVER_TRAYICON_H

#include <QString>
#include <QtWidgets/qsystemtrayicon.h>
#include <QtWidgets/qmenu.h>
#include <QtCore/qdiriterator.h>
#include <QtWidgets/qwidgetaction.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>

class TrayIcon
{
    QSystemTrayIcon trayIcon;
    QMenu menu;

    QWidgetAction *action;
    QWidget *testw;
    QPushButton *testp;
    QLabel *testl;

    QIcon icon;

public:
    TrayIcon() :
        icon(QString(":/images/icon16.png"))
    {
        icon.addFile(QString(":/images/icon24.png"));
        icon.addFile(QString(":/images/icon32.png"));

        action = new QWidgetAction(0);
        testw = new QWidget();
        //testp = new QPushButton(QString("RestingTests"), testw);
        testl = new QLabel(QString("RestingTests"), testw);

        action->setDefaultWidget(testl);

        menu.addAction(action);
        trayIcon.setContextMenu(&menu);
        trayIcon.setIcon(icon);

        trayIcon.show();
    }
};


#endif //MEYESAVER_TRAYICON_H
