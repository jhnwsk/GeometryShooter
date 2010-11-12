SOURCES += main.cpp \
    custom_widget.cpp \
    geometry_shooter.cpp \
    moving_target.cpp
INCLUDEPATH += /usr/lib
LIBS += /usr/lib/libopenal*
LIBS += /usr/lib/libalut*
QT += opengl
HEADERS += custom_widget.h \
    geometry_shooter.h \
    moving_target.h
RESOURCES += sounds.qrc
