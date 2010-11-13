#include "moving_target.h"

MovingTarget::MovingTarget(short bufferNumber) : QObject(0)
{
    m_timer = new QTimer( this );
    connect( m_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()) );
    m_timer->start( bufferNumber );
}

void MovingTarget::staticPaintGL(MovingTarget * obj)
{
    obj->paintGL();
}

Triangle::Triangle(short bufferNumber) : MovingTarget(bufferNumber)
{
    rotationSpeed = 2.0f;
    position[0] = 3.0f;
    position[1] = -1.0f;
    position[2] = -7.0f;
}

void Triangle::paintGL()
{
    glLoadIdentity();

    glTranslatef(position[0], position[1], position[2]);
    glRotatef(rotationSpeed,0.0f,1.0f,0.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f,-1.0f, -1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f,-1.0f, -1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f, -1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glEnd();
}

void MovingTarget::timeOut()
{
    rotationSpeed += 0.5f;
}

void MovingTarget::timeOutSlot()
{
   timeOut();
}
