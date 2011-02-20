#include "moving_target.h"

MovingTarget::MovingTarget(short bufferNumber) : QObject(0)
{
    m_timer = new QTimer( this );
    connect( m_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()) );
    m_timer->start( bufferNumber );
}

void MovingTarget::StaticPaintGL(MovingTarget * obj)
{
    obj->PaintGL();
}

void MovingTarget::StaticPLayAL(MovingTarget *obj)
{
    obj->PlayAL();
}

void MovingTarget::PlayAL()
{

}

void MovingTarget::timeOut()
{
    rotationSpeed += 0.5f;
}

void MovingTarget::timeOutSlot()
{
    timeOut();
}

// the TRIANGLE
Triangle::Triangle(short bufferNumber) : MovingTarget(bufferNumber)
{
    rotationSpeed = 2.0f;
    position[0] = -25.0f;
    position[1] = 20.0f;
    position[2] = -50.0f;

    position[0] = -5.0f;
    position[1] = 0.0f;
    position[2] = -10.0f;
}

void Triangle::PlayAL()
{

}

void Triangle::PaintGL()
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

// the SQUARE
Square::Square(short bufferNumber) : MovingTarget(bufferNumber)
{
    rotationSpeed = 2.0f;
    position[0] = 5.0f;
    position[1] = 0.0f;
    position[2] = -10.0f;
}

void Square::PlayAL()
{

}

void Square::PaintGL()
{
    glLoadIdentity();
    glTranslatef(position[0], position[1], position[2]);
    glRotatef(rotationSpeed,1.0f,0.0f,0.0f);

    glColor3f(0.5f,0.5f,1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glColor3f(1.0f,0.5f,0.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,0.0f,1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glEnd();
}

const double Sphere::mPi = 3.14;

// the SPHERE
Sphere::Sphere(short bufferNumber) : MovingTarget(bufferNumber)
{
    rotationSpeed = 2.0f;
    position[0] = 0.0f;
    position[1] = 0.0f;
    position[2] = -10.0f;

    // sphere specific
    r = lats = longs = 10;
}

void Sphere::PaintGL()
{
    glLoadIdentity();
    glTranslatef(position[0], position[1], position[2]);
    glRotatef(rotationSpeed,1.0f,0.0f,0.0f);

    drawSphere(this->r, this->lats, this->longs);
}

void Sphere::PlayAL()
{

}

void Sphere::drawSphere(double r, int lats, int longs)
{
    int i, j;
    for(i = 0; i <= lats; i++) {
        double lat0 = mPi * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);

        double lat1 = mPi * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++) {
            double lng = 2 * mPi * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);

            glColor3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr0, y * zr0, z0);
            glColor3f(x * zr1, y * zr1, z1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
}
