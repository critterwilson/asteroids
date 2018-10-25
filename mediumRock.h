#ifndef mediumRock_h
#define mediumRock_h

#include <stdio.h>
#include "astroid.h"

class MediumRock : public Astroid
{
public:
    /*********************************************
     * Constructor: MediumRock
     * Description: Default astroid constructor
     *********************************************/
    MediumRock();
    
    /*********************************************
     * Constructor: MediumRock
     * Description: Constructor for rocks that spawn
     * when other rocks are destroyed
     *********************************************/
    MediumRock(Point point, Velocity prevVelocity, int velocityModifier);
    
    /*********************************************
     * Function: Draw
     * Description: draws the bigRock
     *********************************************/
    virtual void draw();
    
    
};

#endif /* mediumRock_h */
