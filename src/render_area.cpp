
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
      circ({350,340},7),
      ball_speed(0.0f,0.0f),
      bonus_speed(0.0f,0.0f),
      dt(1/5.0f),
      first_brick({0,30},60,20,none),
      brick_wall(setBrickWall(first_brick)),
      broken_bricks(),
      pad({300,350},100,10),
      stored_motion(),
      stored_time(),
      timer(),
      time()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    //timer calling the function update_timer periodicaly
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_timer()));

}

render_area::~render_area()
{}


void render_area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen;
    pen.setWidth((double) 0.2);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    QBrush brush = painter.brush();
    brush.setStyle(Qt::SolidPattern);

    //the actual drawing of the bricks
    brush.setColor(QColor(255,91,40,255));
    painter.setBrush(brush);
    for (B=brick_wall.begin();B!=brick_wall.end();B++)
    {
        if(!(B->is_broken))
            painter.drawRect(B->position.x,B->position.y,B->width,B->height);
    }

    //the actual drawing of the bonus
    for (B=broken_bricks.begin();B!=broken_bricks.end();B++)
    {
        if(B->is_broken && B->bonus != none)// if no bonus, no display
        {
            if(B->bonus == largerPad || B->bonus == slowerBall) // bonus in green
            {
                brush.setColor(QColor(20,255,50,255));
                painter.setBrush(brush);
                painter.drawRect(B->position.x+25,B->position.y+6,10,10);
            }
            if(B->bonus == shorterPad || B->bonus == fasterBall) //malus in red
            {
                brush.setColor(QColor(255,50,20,255));
                painter.setBrush(brush);
                painter.drawRect(B->position.x+25,B->position.y+6,10,10);
            }
        }
    }


    //the actual drawing of the ball
    brush.setColor(Qt::gray);
    painter.setBrush(brush);
    vec2 const& p=circ.center;
    float const r=circ.radius;
    painter.drawEllipse(p.x-r,p.y-r,2*r,2*r);


    //the actual drawing of the pad
    brush.setColor(QColor(10,10,10,255));
    painter.setBrush(brush);
    vec2 const& pos_pad=pad.position;
    float const w_pad=pad.width;
    float const h_pad=pad.height;
    painter.drawRect(pos_pad.x,pos_pad.y,w_pad,h_pad);


    // The end of the game
    if(score->text().toInt() >= 48)
        painter.drawText(280,210,200,100,1," You finished the level!\nClick Retry to play again!");

    if(p.y > pad.position.y+pad.height)
        painter.drawText(280,210,200,100,1," You lose!\nClick Retry to play again!");

    // Mouse detection
    this->setMouseTracking(true);

}



void render_area::mouseMoveEvent(QMouseEvent *event)
{

    QPoint mousePosition = event->pos();

    if (mousePosition.x()>pad.width/2 && mousePosition.x()+pad.width/2<width())
        {
        //translate the x coordonate of the paddle
        pad.position.x=mousePosition.x()-pad.width/2;
        if(start)
            circ.center.x=mousePosition.x();
        }
    repaint();
}

void render_area::mousePressEvent(QMouseEvent *event)
{
    if(start)
    {
        start=false;
        timer.start(30); //every 30ms
        ball_speed=speed_init;
        bonus_speed=speed_init;
        repaint();
    }
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
    vec2 const gravity={0.0f,0.0f};
    //the ball
    vec2& p=circ.center;
    //the bonus
    if (score->text().toInt() > 0 && score->text().toInt() < 48)
    {
        for (B=broken_bricks.begin();B!=broken_bricks.end();++B)
        {
            if (B->position.y < 400)
            {
                vec2& p2=B->position;
                bonus_speed = {0.0f,30.0f};
                p2      = p2+dt*bonus_speed;  //integrate position
            }
        }
    }

    if(score->text().toInt() >= 48)
    {
        ball_speed = {0.0f,0.0f};
        circ.center.x = pad.position.x+pad.width/2;
        circ.center.y = pad.position.y+pad.height/2;
    }
    ball_speed -= dt*damping*ball_speed; //apply damping
    p      = p+dt*ball_speed;          //integrate position


    // check if the bonus is finished
    duree_bonus=time.elapsed();
    if(duree_bonus>=15000 && bonus_enabled)
    {
        pad.width=pad_init.width;
        if (ball_speed.y<0) ball_speed.y=speed_init.y;
        else ball_speed.y=-speed_init.y;
        bonus_enabled=false;
    }

    //collision handling (set new position, and return a new speed value)
    ball_speed=collision_handling(p);
}

vec2 render_area::collision_handling(vec2& p)
{
    vec2 new_speed=ball_speed;
    int score_value=score->text().toInt();

    //size of the window
    float const h=height();
    float const w=width();

    //radius of the sphere
    float const r=circ.radius;

    //special condition in cases of collision
    bool collision=false;
    bool collision_wall=false;
    bool collision_brick=false;



    if( p.y+r<height() )
    {
        //collision with the ground
        if(p.y+r>h)
        {
            p.y=h+r;
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

        //collision with the bricks

        for (B=brick_wall.begin();B!=brick_wall.end();B++)
        {
            //will the ball hit the left or right part of the brick?
            if( isBallBrickCollison(B,p.x-r+dt*new_speed.x,p.x+r+dt*new_speed.x,p.y-r,p.y+r))
            {
                new_speed.x *= -1;
                B->is_broken=true;
                collision_brick = true;

            }

            //will the ball hit the top or bottom part of the brick?
            if( isBallBrickCollison(B,p.x-r,p.x+r,p.y-r+dt*new_speed.y,p.y+r+dt*new_speed.y) )
            {
                if(new_speed.x==0) new_speed.x=25.0f;

                new_speed.y *= -1;
                B->is_broken=true;
                collision_brick = true;

            }
            if (B->is_broken)  //if the brick is broken it is withdrawn from the list
                {
                    broken_bricks.push_back(*B);
                    brick_wall.erase(B);
                    break;
                }

        }

        // Collison Bonus/Pad
        for (B=broken_bricks.begin();B!=broken_bricks.end();B++)
        {
           if(B->is_broken && B->bonus != none)// if no bonus, no display
           {
               pre_bonus_speed=new_speed;
               if(     B->position.y>(pad.position.y) &&
                       B->position.y<height() &&
                       B->position.x<(pad.position.x+pad.width) &&
                       B->position.x>(pad.position.x) )
                {

                   selectBonus(&pad,&new_speed,B->bonus);
                   bonus_enabled=true;
                   if (time.isNull()) time.start();
                   else time.restart();
                   broken_bricks.erase(B);
                }
           }

        }


        //collision with the paddle
        if(p.y+r>(pad.position.y) && p.y<height() && p.x<(pad.position.x+pad.width) && p.x>(pad.position.x))
        {
            p.y=pad.position.y-r; // places the ball on the top side of the paddle
            new_speed.y *= -1;

            if(p.x<pad.position.x+3*pad.width/7) // if the ball touches the left part of the paddle
              {
                if (new_speed.x>0) // and comes from the left, it returns left
                    new_speed.x*=-1;
              }
            else if(p.x>pad.position.x+5*pad.width/7) // if the ball touches the right part of the paddle
            {
              if (new_speed.x<0) // and comes from the right, it returns right
                  new_speed.x*=-1;
            }

            collision=true;
        }
    }

    if(collision_brick && score!=nullptr)
    {
        //increase the information of the number of bounces
        score_value++;
        collision_brick = false;
        score->setText(QString::number(score_value));
    }


    return new_speed;

}

bool render_area::isBallBrickCollison(std::list<brick>::iterator B,float ballLeft, float ballRight, float ballTop, float ballBottom) {

  return ballRight > B->position.x &&
         ballBottom > B->position.y &&
         (B->position.x+B->width) > ballLeft &&
         (B->position.y+B->height) > ballTop;
}

void render_area::setup_score(QLabel* score_value)
{
    score=score_value;
}

void render_area::reset()
{
    score->setText(QString::number(0));
    pad=pad_init;
    circ.center=circ_init;
    ball_speed=speed_init;
    bonus_speed=speed_init;
    brick_wall=setBrickWall(first_brick);
    timer.stop();
    start=true;
    bonus_enabled=false;

    repaint();
}
