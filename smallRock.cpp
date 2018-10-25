#include "smallRock.h"
#include "uiDraw.h"

/**********************************************************
 * Constructor: Small Rock
 * Description: sets default speeds and rotations,
 * initial angles, and starting point
 **********************************************************/
SmallRock :: SmallRock()
{
    setAlive(true);
    setRotation(random(0, 361));
    setSpeed(5);
    setType(1);
    
    setAstroidStartX(random(-200.0, 200.0));
    setAstroidStartY(random(-200.0, 200.0));
    
    point.setX(getAstroidStartX());
    point.setY(getAstroidStartY());
    
    velocity.setDx(getSpeed() * (cos(M_PI / 180.0 * random(0,360))));
    velocity.setDy(getSpeed() * (sin(M_PI / 180.0 * random(0,360))));
}

/**********************************************************
 * Constructor: SmallRock
 * Description: sets default speeds and rotations,
 * initial angles, and starting point given values from
 * previously destroyed rock
 **********************************************************/
SmallRock :: SmallRock(Point newPoint, Velocity prevVelocity, int velocityModifier)
{
    setAlive(true);
    setRotation(random(0, 361));
    setSpeed(10);
    setType(1);
    
    setAstroidStartX(newPoint.getX());
    setAstroidStartY(newPoint.getY());
    
    point.setX(getAstroidStartX());
    point.setY(getAstroidStartY());
    
    velocity.setDx(prevVelocity.getDx() + velocityModifier);
    velocity.setDy(prevVelocity.getDy());
}

/**********************************************************
 * Function: draw
 * Description: uses uiDraw to draw the big rock
 **********************************************************/
void SmallRock :: draw()
{
    drawSmallAsteroid(point, rotation);
    rotation += 10;
}
