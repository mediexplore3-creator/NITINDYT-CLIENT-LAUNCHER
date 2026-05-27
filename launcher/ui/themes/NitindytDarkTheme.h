#pragma once

#include "FusionTheme.h"

class NitindytDarkTheme : public FusionTheme {
   public:
    virtual ~NitindytDarkTheme() {}

    QString id() override;
    QString name() override;
    QString tooltip() override;
    bool hasStyleSheet() override;
    QString appStyleSheet() override;
    QPalette colorScheme() override;
    double fadeAmount() override;
    QColor fadeColor() override;
};
