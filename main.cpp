#include "custom_widget.h"
#include "geometry_shooter.h"

#include <QApplication>

int main(int argc, char **argv)
{
    // time interval value for all timeout slots
    int appSpeed = 5;
    QApplication a( argc, argv );

    GeometryShooter *w = new GeometryShooter(argc, argv, appSpeed);

    // a.setMainWidget( w );
    w->show();
    return a.exec();

}
