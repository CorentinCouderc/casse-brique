
#include "render_area.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QLabel>

#include <iostream>
#include <cassert>

render_area::render_area(QWidget *parent)
    :QWidget(parent),
      damping(0.0),
      bounce_coeff(1.0),
      score(nullptr),
      circ({350,330},5),
      speed(0.0f,0.0f),
      dt(1/5.0f),
      bricks({0,0},30,10),
      stored_motion(),
      stored_time(),
      click_previous(),
      timer(),
      time()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    //timer calling the function update_timer periodicaly
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_timer()));
    timer.start(30); //every 30ms
}

render_area::~render_area()
{}



void render_area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen;
    pen.setWidth(0.2);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    QBrush brush = painter.brush();
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    //the actual drawing of the circle
    vec2 const& p=circ.center;
    float const r=circ.radius;
    painter.drawEllipse(p.x-r,p.y-r,2*r,2*r);

    //the actual drawing of the bricks
    vec2 const& pos=bricks.position;
    float const w=bricks.width;
    float const h=bricks.height;
    painter.drawRect(pos.x,pos.y,w,h);
    painter.drawRect(pos.x+w,pos.y,w,h);
}





void render_area::mouseMoveEvent(QMouseEvent *event)
{
    /*
    //compute the current translation of the mouse
    vec2 const click=vec2(event->x(),event->y());
    vec2 const translate=click-click_previous;

    //translate the center of the circle
    circ.center+=translate;

    //store previous values
    click_previous=click;
    store_values(click);

    repaint();
    */
}

void render_area::store_values(vec2 const& click)
{
    int const N_last_position = 5;

    assert(N_last_position>1);

    //store at most the N last position and time of the circle
    stored_motion.push_back(click);
    if( stored_motion.size()>N_last_position )
        stored_motion.pop_front();

    stored_time.push_back(time.elapsed());
    if( stored_time.size()>N_last_position )
        stored_time.pop_front();
}




void render_area::update_timer()
{
    //called periodically
    numerical_integration();

    repaint();
}

void render_area::numerical_integration()
{
    //numerical integration using Forward Euler method
    vec2 const gravity={0.0f,9.81f};
    vec2& p=circ.center;

    speed  = speed+dt*gravity;  //integrate speed
    speed -= dt*damping*speed; //apply damping
    p      = p+dt*speed;          //integrate position

    //collision handling (set new position, and return a new speed value)
    speed=collision_handling(p);
}

vec2 render_area::collision_handling(vec2& p)
{
    vec2 new_speed=speed;

    //size of the window
    float const h=height();
    float const w=width();

    //radius of the sphere
    float const r=circ.radius;

    //special condition in cases of collision
    bool collision=false;
    bool collision_wall=false;

    //collision with the ground
    if(p.y+r>h)
    {
        p.y=h-r;
        new_speed.y *= -1;
        collision=true;
    }
    //collision with the left wall
    if(p.x-r<0)
    {
        p.x=r;
        new_speed.x *= -1;
        collision=true;
        collision_wall=true;
    }
    //collision with the right wall
    if(p.x+r>w)
    {
        p.x=w-r;
        new_speed.x *= -1;
        collision=true;
        collision_wall=true;
    }
    //collision with the top wall
    if(p.y-r<0)
    {
        p.y=r;
        new_speed.y *= -1;
        collision=true;
        collision_wall=true;
    }

    //decrease speed with respect to the bouncing coefficient
    if(collision)
        new_speed *= 0.0;

    if(collision_wall && score!=nullptr)
    {
        //increase the information of the number of bounces
        int score_value=score->text().toInt();
        score_value++;
        score->setText(QString::number(score_value));
    }


    return new_speed;

}



void render_area::setup_score(QLabel* score_value)
{
    score=score_value;
}
