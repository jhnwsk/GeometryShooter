#include "custom_widget.h"

#include <QApplication>
#include <QTimer>
#include <QKeyEvent>

ALfloat CustomWidget::ListenerPos[] = { 0.0, 0.0, 0.0 };
ALfloat CustomWidget::ListenerVel[] = { 0.0, 0.0, 0.0 };
ALfloat CustomWidget::ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };

CustomWidget::CustomWidget( int timerInterval, QWidget *parent ) : QGLWidget( parent )
{
    if( timerInterval == 0 )
        m_timer = 0;
    else
    {
        m_timer = new QTimer( this );
        connect( m_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()) );
        m_timer->start( timerInterval );
    }
}

// initializes openGL
void CustomWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// gl resize procedure
void CustomWidget::resizeGL( int width, int height )
{
    height = height?height:1;

    glViewport( 0, 0, (GLint)width, (GLint)height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void CustomWidget::initializeAL(int argc, char**argv)
{
    alutInit (&argc, argv);
    alGetError();
}


void CustomWidget::timeOut()
{
    rtri += 0.5f;
    rquad -= 0.25f;

    updateGL();
}

void CustomWidget::timeOutSlot()
{
    timeOut();
}
