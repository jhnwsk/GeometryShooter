#ifndef MOVING_TARGET_H
#define MOVING_TARGET_H

#include <QObject>
#include <QGLWidget>
#include <QTimer>
#include <math.h>

class MovingTarget : public QObject
{
    Q_OBJECT
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
    virtual void timeOut();

public:
    // which sound will you be playin'
    MovingTarget(short bufferNumber);
    // display routine
    virtual void PaintGL() = 0;
    virtual void PlayAL();
    static void StaticPaintGL(MovingTarget * obj);
    static void StaticPLayAL(MovingTarget * obj);

protected slots:
    virtual void timeOutSlot();

private:
    QTimer *m_timer;

};

class Triangle : public MovingTarget
{
    Q_OBJECT
private:
    Triangle();
public:
    Triangle(short bufferNumber);
    void PaintGL();
    void PlayAL();
};

class Square : public MovingTarget
{
    Q_OBJECT
private:
    Square();
public:
    Square(short bufferNumber);
    void PaintGL();
    void PlayAL();
};

class Sphere : public MovingTarget
{
    Q_OBJECT
private:
    Sphere();
    static const double mPi; // = 3.14;
    double r, lats, longs;
public:
    Sphere(short bufferNumber);
    void PaintGL();
    void PlayAL();
    void drawSphere(double r, int lats, int longs);
};

#endif // MOVING_TARGET_H
