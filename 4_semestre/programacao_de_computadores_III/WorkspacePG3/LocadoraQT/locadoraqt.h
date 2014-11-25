#ifndef LOCADORAQT_H
#define LOCADORAQT_H

#include <QtGui/QWidget>
#include "ui_locadoraqt.h"

class LocadoraQT : public QWidget
{
    Q_OBJECT

public:
    LocadoraQT(QWidget *parent = 0);
    ~LocadoraQT();

private:
    Ui::LocadoraQTClass ui;
};

#endif // LOCADORAQT_H
