SOURCES += main.cpp \
    custom_widget.cpp \
    geometry_shooter.cpp
INCLUDEPATH += /usr/lib
LIBS += /usr/lib/libopenal*
LIBS += /usr/lib/libalut*
QT += opengl
HEADERS += custom_widget.h \
    geometry_shooter.h
RESOURCES += sounds.qrc
