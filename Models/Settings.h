//
// Created by mvlabat on 12/7/15.
//

#ifndef MEYESAVER_SETTINGS_H
#define MEYESAVER_SETTINGS_H


#include <QtCore/qsettings.h>

class Settings
{
    QSettings settings;
public:
    Settings():
        settings("mvlabat's Soft", "mEyeSaver")
    {

    }
};


#endif //MEYESAVER_SETTINGS_H
