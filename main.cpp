#include <iostream>
#include <QtWidgets>

#include "Initializer.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    a.setQuitOnLastWindowClosed(false);
    Initializer controller;

    return a.exec();
}
