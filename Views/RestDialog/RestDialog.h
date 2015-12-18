//
// Created by mvlabat on 12/14/15.
//

#ifndef MEYESAVER_RESTDIALOG_H
#define MEYESAVER_RESTDIALOG_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QDateTime>
#include <QString>

class RestDialog : public QWidget
{
    Q_OBJECT

    QWidget* wrapper;
    QVBoxLayout* widgetLayout;
    QHBoxLayout* buttonsLayout;
    QLabel* timerLabel;
    QPushButton* postponeButton;
    QPushButton* returnButton;
    QPushButton* skipButton;
    QDateTime endTime;
public:
    RestDialog() :
        QWidget(),
        widgetLayout(new QVBoxLayout(this)),
        timerLabel(new QLabel),
        buttonsLayout(new QHBoxLayout),
        postponeButton(new QPushButton(QString("Postpone"))),
        returnButton(new QPushButton(QString("Return to work"))),
        skipButton(new QPushButton(QString("Skip")))
    {
        //this->setAttribute(Qt::WA_TranslucentBackground);
        this->setWindowState(Qt::WindowFullScreen);
        this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);

        this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);

        widgetLayout->addWidget(timerLabel);
        widgetLayout->addLayout(buttonsLayout);
        buttonsLayout->addWidget(postponeButton);
        buttonsLayout->addWidget(returnButton);
        buttonsLayout->addWidget(skipButton);

        connect(postponeButton, &QPushButton::clicked, this, &RestDialog::postponed, Qt::QueuedConnection);
        connect(returnButton, &QPushButton::clicked, this, &RestDialog::returned, Qt::QueuedConnection);
        connect(skipButton, &QPushButton::clicked, this, &RestDialog::skipped, Qt::QueuedConnection);
    }

    void setRestingTime(int secs);

public slots:
    void updateTimer();
    void enableReturn();

signals:
    void postponed();
    void returned();
    void skipped();
};


#endif //MEYESAVER_RESTDIALOG_H
