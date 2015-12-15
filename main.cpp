#include <iostream>
#include <QtWidgets>

#include "Controller.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    a.setQuitOnLastWindowClosed(false);
    Controller controller;

    return a.exec();
}
