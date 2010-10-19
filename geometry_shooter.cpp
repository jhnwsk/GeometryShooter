#include "geometry_shooter.h"

#include <QApplication>
#include <QKeyEvent>

GLint GeometryShooter::play[NUM_SOURCES] = {true, false, false};

//GLfloat GeometryShooter::trianglePosition [] = {-1.5f,0.0f,-6.0f};
GLfloat GeometryShooter::SourcesPos [NUM_SOURCES][3] = {{33.0f,-13.0f,-38.0f},{3.0f,-1.0f,-7.0f},{-12.0f,7.0f,-45.0f}};
GLfloat GeometryShooter::SourcesVel [NUM_SOURCES][3] = {{.0f,.0f,.0f},{.0f,.0f,.0f},{.0f,.0f,.0f}};

void GeometryShooter::keyPressEvent(QKeyEvent *e)
{
    switch( e->key() )
    {
    case Qt::Key_H: alSourcePlay (helloSource); // alutSleep (1);
        break;

    //case Qt::Key_P: alSourcePlay(Sources[TRIANGLE]); break;
    //case Qt::Key_S: alSourceStop(sourceTriangle); break;
    //case Qt::Key_T: alSourcePause(sourceTriangle); break;
    case Qt::Key_Left:

        //SourcePos[0] += 5;
        //SourcePos[1] += 5;
        //SourcePos[2] += 5;

        //check = SourceVel[0];

        //SourceVel[0] += 10;
        //SourceVel[1] += 10;
        //SourceVel[2] += 10;

        //check = SourceVel[0];

        //alSourcefv(sourceTriangle, AL_POSITION, SourcePos);
        //alSourcefv(sourceTriangle, AL_VELOCITY, SourceVel);
        break;

    case Qt::Key_1: play[TRIANGLE] = !play[TRIANGLE]; break;
    case Qt::Key_2: play[SQUARE] = !play[SQUARE]; break;
    case Qt::Key_M: play[BACKGROUND] = !play[BACKGROUND]; break;
    case
            Qt::Key_Escape:
        KillALData();
        close();
    }
}

GeometryShooter::GeometryShooter(int argc, char **argv, int timerInterval) : CustomWidget( timerInterval )
{
    initializeAL(argc, argv);
    rtri = rquad = 0.0f;

    // Load the wav data.
    LoadALData();

    SetListenerValues();
}

GeometryShooter::GeometryShooter( QWidget *parent, char *name) : CustomWidget( 0, parent )
{
}

void GeometryShooter::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(play[TRIANGLE])
    {
        glLoadIdentity();

        glTranslatef(SourcesPos[TRIANGLE][0], SourcesPos[TRIANGLE][1], SourcesPos[TRIANGLE][2]);
        glRotatef(rtri,0.0f,1.0f,0.0f);

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
    if(play[SQUARE])
    {
        glLoadIdentity();
        glTranslatef(SourcesPos[SQUARE][0], SourcesPos[SQUARE][1], SourcesPos[SQUARE][2]);
        glRotatef(rquad,1.0f,0.0f,0.0f);

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

    playAL();
}

void GeometryShooter::playAL()
{
    ALint isPlaying = 0;

    alGetSourcei(Sources[BACKGROUND], AL_SOURCE_STATE, &isPlaying);
    if(play[BACKGROUND])
    {
        if(isPlaying != AL_PLAYING)
            alSourcePlay(Sources[BACKGROUND]);
    }
    else
    {
        if(isPlaying == AL_PLAYING)
            alSourceStop(Sources[BACKGROUND]);
    }

    alGetSourcei(Sources[TRIANGLE], AL_SOURCE_STATE, &isPlaying);
    if(play[TRIANGLE])
    {
        if(isPlaying != AL_PLAYING)
            alSourcePlay(Sources[TRIANGLE]);
    }
    else
    {
        if(isPlaying == AL_PLAYING)
            alSourceStop(Sources[TRIANGLE]);
    }

    isPlaying = 0;
    alGetSourcei(Sources[SQUARE], AL_SOURCE_STATE, &isPlaying);
    if(play[SQUARE])
    {
        if(isPlaying != AL_PLAYING)
            alSourcePlay(Sources[SQUARE]);
    }
    else
    {
        if(isPlaying == AL_PLAYING)
            alSourceStop(Sources[SQUARE]);
    }
}


ALboolean GeometryShooter::LoadALData(){
    // Variables to load into.
    ALboolean loop = true;
    // Variables to load into.

    ALenum format;
    ALsizei size;
    ALvoid* data;
    ALsizei freq;

    // Load wav data into a buffer.
    alGenBuffers(NUM_BUFFERS, Buffers);

    if (alGetError() != AL_NO_ERROR)
        return AL_FALSE;

    Buffers[BACKGROUND] = alutCreateBufferFromFile("strings.wav");
    Buffers[TRIANGLE] = alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, 440, 0, 10);
    Buffers[SQUARE] = alutCreateBufferWaveform(ALUT_WAVEFORM_SQUARE, 330, 0, 10);

    // alutLoadWAVFile("strings", &format, &data, &size, &freq, &loop);
    // alBufferData(Buffer, format, data, size, freq);
    // alutUnloadWAV(format, data, size, freq);


    // Bind buffer with a source.
    alGenSources(NUM_SOURCES, Sources);

    ALenum error = alGetError();

    if (error != AL_NO_ERROR)
        return AL_FALSE;

    alSourcei (Sources[BACKGROUND], AL_BUFFER,   Buffers[BACKGROUND]  );
    alSourcef (Sources[BACKGROUND], AL_PITCH,    1.0              );
    alSourcef (Sources[BACKGROUND], AL_GAIN,     0.1              );
    alSourcefv(Sources[BACKGROUND], AL_POSITION, SourcesPos[BACKGROUND]);
    alSourcefv(Sources[BACKGROUND], AL_VELOCITY, SourcesVel[BACKGROUND]);
    alSourcei (Sources[BACKGROUND], AL_LOOPING,  loop          );

    alSourcei (Sources[TRIANGLE], AL_BUFFER,   Buffers[TRIANGLE]  );
    alSourcef (Sources[TRIANGLE], AL_PITCH,    1.0            );
    alSourcef (Sources[TRIANGLE], AL_GAIN,     1.0            );
    alSource3f(Sources[TRIANGLE], AL_POSITION,
               SourcesPos[TRIANGLE][0],
               SourcesPos[TRIANGLE][1],
               SourcesPos[TRIANGLE][2]);
    alSource3f(Sources[TRIANGLE], AL_VELOCITY,
               SourcesVel[TRIANGLE][0],
               SourcesVel[TRIANGLE][1],
               SourcesVel[TRIANGLE][2]);
    alSourcei (Sources[TRIANGLE], AL_LOOPING,  loop       );

    alSourcei (Sources[SQUARE], AL_BUFFER,   Buffers[SQUARE]  );
    alSourcef (Sources[SQUARE], AL_PITCH,    1.0            );
    alSourcef (Sources[SQUARE], AL_GAIN,     1.0            );
    // alSourcefv(Sources[SQUARE], AL_POSITION, SourcesPos[SQUARE]);
    // alSourcefv(Sources[SQUARE], AL_VELOCITY, SourcesVel[SQUARE]);
    alSource3f(Sources[SQUARE], AL_POSITION,
               SourcesPos[SQUARE][0]*POSITION_OFFSET,
               SourcesPos[SQUARE][1]*POSITION_OFFSET,
               SourcesPos[SQUARE][2]);
    alSource3f(Sources[SQUARE], AL_VELOCITY,
               SourcesVel[SQUARE][0]*VELOCITY_OFFSET,
               SourcesVel[SQUARE][1]*VELOCITY_OFFSET,
               SourcesVel[SQUARE][2]*VELOCITY_OFFSET);
    alSourcei (Sources[SQUARE], AL_LOOPING,  loop       );

    // Do another error check and return.
    if (alGetError() == AL_NO_ERROR)
        return AL_TRUE;

    return AL_FALSE;
}
void GeometryShooter::SetListenerValues()
{
    alListenerfv(AL_POSITION,    ListenerPos);
    alListenerfv(AL_VELOCITY,    ListenerVel);
    alListenerfv(AL_ORIENTATION, ListenerOri);
}

void GeometryShooter::KillALData()
{
    alDeleteBuffers(1, &Buffers[TRIANGLE]);
    alDeleteSources(1, &Sources[TRIANGLE]);
    alutExit();
}
