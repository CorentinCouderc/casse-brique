#pragma once

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include "circle.hpp"
#include "brick.hpp"
#include "paddle.hpp"

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <list>

//forward declaration of QLabel
class QLabel;



class render_area : public QWidget
{
    Q_OBJECT
public:

    render_area(QWidget *parent = 0);
    ~render_area();


    /** Pass the pointer of the label for the score */
    void setup_score(QLabel* score_param);
    void reset();

protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);
    /** Function called when the mouse is moved */
    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);


private slots:

    /** Function called periodically at constant time interval by a timer */
    void update_timer();

private: //functions

    /** Insert current position and time inside the recording structures */
    void store_values(vec2 const& click);

    /** Deal with collision */
    vec2 collision_handling(vec2& p);

    /** Move forward in time */
    void numerical_integration();

private: //attributes

    /** Damping coefficient */
    float damping;
    /** Bouncing coefficient */
    float bounce_coeff;

    /** Label counting the number of bounces on the wall */
    QLabel *score;


    /** The circle */
    circle circ;
    vec2 circ_init={350,340};

    /** The speed of the circle */
    vec2 speed;

    /** The time integration step */
    float dt;

    /** The bricks */
    brick bricks;

    /** The paddle */
    paddle pad;
    vec2 pad_init={300,350};

    /** A vector of previous position when the circle is grabbed */
    std::list<vec2> stored_motion;
    /** A vector of previous time when the circle is grabbed */
    std::list<int> stored_time;



    /** Timer for periodic time iteration */
    QTimer timer;
    /** Time accessor */
    QTime time;

    // true if it's the beginnig of the game
    bool start=true;

};

#endif
