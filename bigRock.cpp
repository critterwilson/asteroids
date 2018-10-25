#include "bigRock.h"

/**********************************************************
 * Constructor: BigRock
 * Description: sets default speeds and rotations,
 * initial angles, and starting point
 **********************************************************/
BigRock :: BigRock()
{
    setAlive(true);
    setRotation(random(0, 361));
    setSpeed(1);
    setType(3);

    setAstroidStartX(random(-200.0, 200.0));
    setAstroidStartY(random(-200.0, 200.0));
    
    point.setX(getAstroidStartX());
    point.setY(getAstroidStartY());
    
    velocity.setDx(getSpeed() * (cos(M_PI / 180.0 * random(0,360))));
    velocity.setDy(getSpeed() * (sin(M_PI / 180.0 * random(0,360))));
}
/**********************************************************
 * Function: draw
 * Description: uses uiDraw to draw the big rock
 **********************************************************/
void BigRock :: draw()
{
    drawLargeAsteroid(point, rotation);
    rotation += 2;
}
