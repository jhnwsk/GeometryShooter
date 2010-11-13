#ifndef MOVING_TARGET_H
#define MOVING_TARGET_H

#include <QObject>
#include <QGLWidget>
#include <QTimer>

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
    virtual void paintGL() = 0;
    static void staticPaintGL(MovingTarget * obj);

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
    void paintGL();
};

#endif // MOVING_TARGET_H
