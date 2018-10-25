#include "velocity.h"
/*********************************************
 * Velocity :: Velocity()
 * the Default constructor for Velocity
 *********************************************/
Velocity :: Velocity() : Dx(0), Dy(0)
{
    setDx(Dx);
    setDy(Dy);
}

/*********************************************
 * Velocity :: Velocity(float, float)
 * constructor for Velocity that accepts a change
 * in y or x
 *********************************************/
Velocity :: Velocity(float Dx, float Dy)
{
    setDx(Dx);
    setDy(Dy);
}
