
#include "window.hpp"

#include "render_area.hpp"
#include "ui_mainwindow.h"

#include <iostream>

window::window(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow),render(new render_area)
{
    ui->setupUi(this);
    ui->layout_scene->addWidget(render);
    render->setup_score(ui->score_value);

    //Connection with signals
    connect(ui->quit,SIGNAL(clicked()),this,SLOT(action_quit()));
    connect(ui->retry,SIGNAL(clicked()),this,SLOT(action_retry()));
}


window::~window()
{}

void window::action_quit()
{
    close();
}

void window::action_retry()
{
    render->reset();
}
