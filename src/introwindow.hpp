#pragma once
#ifndef INTROWINDOW_H
#define INTROWINDOW_H

#include <QMainWindow>
#include "window.hpp"


namespace Ui {
class IntroWindow;
}

/** Declaration of the Introwindow class */

class IntroWindow : public QMainWindow
{
    Q_OBJECT

    public:
        IntroWindow(QWidget *parent = 0);
        ~IntroWindow();

    public slots:

        void show_game();

    private:
        Ui::IntroWindow *ui;
        class::window game;
};

#endif // INTROWINDOW_H
