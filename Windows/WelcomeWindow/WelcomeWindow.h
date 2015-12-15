//
// Created by mvlabat on 11/18/15.
//

#ifndef MEYESAVER_WELCOMEWINDOW_H
#define MEYESAVER_WELCOMEWINDOW_H


#include <QtCore/qobjectdefs.h>
#include <QtGui/qwindow.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>

class WelcomeWindow : public QWidget
{
    Q_OBJECT

    QVBoxLayout* layout;
    QPushButton* okButton;
    QLabel* welcomeTextLabel;
protected:
    void closeEvent(QCloseEvent *event);

public:
    WelcomeWindow() :
        QWidget(),
        layout(new QVBoxLayout(this)),
        okButton(new QPushButton(QString("Start working!"))),
        welcomeTextLabel(new QLabel("Welcome text"))
    {
        // Setting window's appearance.
        this->setFixedSize(300, 200);

        welcomeTextLabel->setAlignment(Qt::AlignCenter);
        okButton->setFixedSize(120, 40);

        layout->addWidget(welcomeTextLabel);
        layout->addWidget(okButton, 0, Qt::AlignHCenter);

        // Connecting signals and slots.
        connect(okButton, &QPushButton::clicked, this, &WelcomeWindow::windowClosed, Qt::QueuedConnection);
    }

signals:
    void windowClosed();
};

#endif //MEYESAVER_WELCOMEWINDOW_H
