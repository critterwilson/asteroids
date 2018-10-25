#ifndef bigRock_h
#define bigRock_h

#include <stdio.h>
#include "astroid.h"
#include "uiDraw.h"

class BigRock : public Astroid
{
public:
    /*********************************************
     * Constructor: BigRock
     * Description: Default astroid constructor
     *********************************************/
    BigRock();
    
    /*********************************************
     * Function: Draw
     * Description: draws the bigRock
     *********************************************/
    virtual void draw();
};

#endif /* BRock_h */
