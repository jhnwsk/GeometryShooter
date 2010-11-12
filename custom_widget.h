#ifndef CUSTOM_WIDGET_H
#define CUSTOM_WIDGET_H

#include <QGLWidget>
#include <stdlib.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/alut.h>

class QTimer;

/*
 * The custom widget class. All init procedures, general slots and signals
 * and non gameplay functionality goes here.
 */

class CustomWidget : public QGLWidget
{
        Q_OBJECT

public:
        CustomWidget( int timerInterval=0, QWidget *parent=0 );

protected:

        virtual void initializeGL();
        virtual void resizeGL( int width, int height );
        virtual void initializeAL(int argc, char **argv);
        virtual void paintGL() = 0;

        virtual void keyPressEvent( QKeyEvent *e ) = 0;

        virtual void timeOut();

        ALuint helloBuffer, helloSource;

        // translate constants
        GLfloat rtri, rquad;

        // Position of the listener.
        static ALfloat ListenerPos[];
        // Velocity of the listener.
        static ALfloat ListenerVel[];
        // Orientation of the listener. (first 3 elements are "at", second 3 are "up")
        static ALfloat ListenerOri[];
        
protected slots:
        virtual void timeOutSlot();

private:
        QTimer *m_timer;
};

#endif // CUSTOM_WIDGET_H
