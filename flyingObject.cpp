#include "flyingObject.h"

#define OFF_SCREEN 215

/**************************************************************************
 * FlyingObject :: isAlive()
 * returns the alive member variable
 **************************************************************************/
bool FlyingObject:: isAlive() const
{
    return alive;
}

/**************************************************************************
 * FlyingObject :: kill
 * sets the alive member variable to false
 **************************************************************************/
void FlyingObject :: kill()
{
    setAlive(false);
}

/**************************************************************************
 * FlyingObject :: advance
 * makes everything move
 **************************************************************************/
void FlyingObject :: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());

    if (point.getX() > OFF_SCREEN)
        point.setX(point.getX() * -1);
    else if (point.getX() < -OFF_SCREEN)
        point.setX(point.getX() * -1);
    
    if (point.getY() > OFF_SCREEN)
        point.setY(point.getY() * -1);
    else if (point.getY() < -OFF_SCREEN)
        point.setY(point.getY() * -1);
}
