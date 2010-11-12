#ifndef MOVING_TARGET_H
#define MOVING_TARGET_H

#include <QGLWidget>

class MovingTarget
{
private:
    MovingTarget();

protected:
    // displacement X
    // displacement Y
    GLfloat displacementX, displacementY;

    // rotation speed... what the heck ;)
    float rotationSpeed;
    GLfloat position[3];
    // initialize sound routine
    void initSound();

public:
    // which sound will you be playin'
    MovingTarget(short bufferNumber);
    // display routine
    virtual void paintGL() = 0;
    static void staticPaintGL(MovingTarget * obj);

};

class Triangle : public MovingTarget
{
private:
    Triangle();
public:
    Triangle(short bufferNumber);
    void paintGL();

};

#endif // MOVING_TARGET_H
