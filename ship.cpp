#include "ship.h"
#include <cmath>

/*********************************************
 * Constructor: Ship
 * Description: sets default values for Ship
 *********************************************/
Ship :: Ship()
{
    setAlive(true);
    shieldsAlive(false);
    setShields(250);
    setThrust(false);
}

/*********************************************
 * Function: draw
 * Description: draws the ship and flames,
 * when necessary
 *********************************************/
void Ship :: draw()
{
    if (isAlive())
        drawShip(point, getRotation(), getThrust());
    else
    {
        drawLanderFlames(point, true, true, true);
        drawText(Point(-50, 0), "MISSION FAILED");
    }
}

/*********************************************
 * Function: rotateRight
 * Description: rotates the ship to the right
 *********************************************/
void Ship :: rotateRight()
{
    int newRotation = getRotation() - 6;
    setRotation(newRotation);
}

/*********************************************
 * Function: rotateLeft
 * Description: rotates the ship to the left
 *********************************************/
void Ship :: rotateLeft()
{
    int newRotation = getRotation() + 6;
    setRotation(newRotation);
    
}

/*********************************************
 * Function: moveForward
 * Description: moves ship in whatever direction
 * it is facing
 *********************************************/
void Ship :: moveForward()
{
    int newRotation = getRotation() - 270;

    velocity.setDx(.5*(cos(M_PI / 180.0 * newRotation)));
    velocity.setDy(.5*(sin(M_PI / 180.0 * newRotation)));
    
}

/*********************************************
 * Function: hit
 * Description: handles shield's health
 *********************************************/
void Ship :: hit()
{
    if (getShields() > 0)
    {
        shields -= 1;
    }
    else if (getShields() <= 0)
    {
        shieldsAlive(false);
    }
}
