#pragma once

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include "circle.hpp"
#include "brick.hpp"

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

protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);
    /** Function called when the mouse is moved */
    void mouseMoveEvent(QMouseEvent *event);

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
    /** The speed of the circle */
    vec2 speed;
    /** The time integration step */
    float dt;

    /** The bricks */
    brick bricks;

    /** A vector of previous position when the circle is grabbed */
    std::list<vec2> stored_motion;
    /** A vector of previous time when the circle is grabbed */
    std::list<int> stored_time;
    /** The position of the previous click */
    vec2 click_previous;



    /** Timer for periodic time iteration */
    QTimer timer;
    /** Time accessor */
    QTime time;

};

#endif
