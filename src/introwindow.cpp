
#include "introwindow.hpp"
#include "ui_introwindow.h"


IntroWindow::IntroWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IntroWindow)
{
    ui->setupUi(this);

    //Connection with signals
    connect(ui->start_push_button,SIGNAL(clicked()),this,SLOT(show_game()));
}


IntroWindow::~IntroWindow()
{}

/** Shows the game and hides the IntroWindow
 */
void IntroWindow::show_game()
{
    game.show();
    this->hide();
}
