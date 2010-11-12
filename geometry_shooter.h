#ifndef SHOOTER_H
#define SHOOTER_H

#include "custom_widget.h"
#include "moving_target.h"
#include <list>
#include <QFile>

// Maximum data buffers we will need.
#define NUM_BUFFERS 3

// Maximum emissions we will need.
#define NUM_SOURCES 3

// These index the buffers and sources.
#define BACKGROUND      0
#define TRIANGLE        1
#define SQUARE          2

#define VELOCITY_OFFSET    3
#define POSITION_OFFSET    3

using namespace std;

class GeometryShooter : public CustomWidget
{
public:
        GeometryShooter(int argc, char **argv, int timerInterval);
        GeometryShooter( QWidget *parent=0, char *name=0 );

private:

        // objects on screen
        static GLint play[NUM_SOURCES];

        // object positions
        // Position of the source sounds.
        static GLfloat SourcesPos[NUM_SOURCES][3];

        // Velocity of the source sounds.
        static ALfloat SourcesVel[NUM_SOURCES][3];

        // the list of moving targets
        std::list<MovingTarget*> movingTargets;

        // Buffers hold sound data.
        ALuint Buffers[NUM_BUFFERS];

        // Sources are points of emitting sound.
        ALuint Sources[NUM_SOURCES];

        void paintGL();
        void playAL();
        void keyPressEvent(QKeyEvent *e);

        // openAL initializers
        ALboolean LoadALData();
        void SetListenerValues();
        void KillALData();
};


#endif // SHOOTER_H
