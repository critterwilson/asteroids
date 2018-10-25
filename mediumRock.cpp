#include "mediumRock.h"
#include "uiDraw.h"

/**********************************************************
 * Constructor: MediumRock
 * Description: sets default speeds and rotations,
 * initial angles, and starting point
 **********************************************************/
MediumRock :: MediumRock()
{
    setAlive(true);
    setRotation(random(0, 361));
    setSpeed(2);
    setType(2);
    
    setAstroidStartX(random(-200.0, 200.0));
    setAstroidStartY(random(-200.0, 200.0));
    
    point.setX(getAstroidStartX());
    point.setY(getAstroidStartY());
    
    velocity.setDx(getSpeed() * (cos(M_PI / 180.0 * random(0,360))));
    velocity.setDy(getSpeed() * (sin(M_PI / 180.0 * random(0,360))));
}

/**********************************************************
 * Constructor: MediumRock
 * Description: sets default speeds and rotations,
 * initial angles, and starting point given values from
 * previously destroyed rock
 **********************************************************/
MediumRock :: MediumRock(Point newPoint, Velocity prevVelocity, int velocityModifier)
{
    setAlive(true);
    setRotation(random(0, 361));
    setSpeed(2);
    setType(2);
    
    setAstroidStartX(newPoint.getX());
    setAstroidStartY(newPoint.getY());
    
    point.setX(getAstroidStartX());
    point.setY(getAstroidStartY());
    
    velocity.setDx(prevVelocity.getDx());
    velocity.setDy(prevVelocity.getDy() + velocityModifier);
}

/**********************************************************
 * Function: draw
 * Description: uses uiDraw to draw the big rock
 **********************************************************/
void MediumRock :: draw()
{
    drawMediumAsteroid(point, rotation);
    rotation += 5;
}
