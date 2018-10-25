#ifndef smallRock_h
#define smallRock_h

#include <stdio.h>
#include "astroid.h"

class SmallRock : public Astroid
{
public:
    /*********************************************
     * Constructor: SmallRock
     * Description: Constructor for small rocks that spawn
     * when other rocks are destroyed
     *********************************************/
    SmallRock();
    
    /*********************************************
     * Constructor: SmallRock
     * Description: Constructor for rocks that spawn
     * when other rocks are destroyed
     *********************************************/
    SmallRock(Point pointm, Velocity prevVelocity, int velocityModifier);
    
    /*********************************************
     * Function: Draw
     * Description: draws the bigRock
     *********************************************/
    virtual void draw();
    
    
};

#endif /* smallRock_h */
