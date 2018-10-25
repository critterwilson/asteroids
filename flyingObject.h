#ifndef flyingObject_h
#define flyingObject_h

#include <stdio.h>
#include "velocity.h"
#include "point.h"
using namespace std;


class FlyingObject
{
public:
    /*********************************************
     * Constructor: FlyingObject
     * Description: Makes any flying object alive
     *********************************************/
    FlyingObject() {setAlive(true); }
    
    /*********************************************
     * Function: getVelocity
     * Description: returns Velocity
     *********************************************/
    Velocity getVelocity() const          {return velocity; }
    
    /*********************************************
     * Function: getPoint
     * Description: returns the point
     *********************************************/
    Point getPoint() const                {return point; }
    
    /*********************************************
     * Function: setVelocity
     * Description: sets velocity to given value
     *********************************************/
    void setVelocity(Velocity velocity)   {this->velocity = velocity; }
    
    /*********************************************
     * Function: setPoint
     * Description: sets point to given value
     *********************************************/
    void setPoint(Point point)            {this->point = point; }
    
    /*********************************************
     * Function: setAlive
     * Description: Resurrects or kills
     *********************************************/
    void setAlive(bool alive) {this->alive = alive; }
    
    /*********************************************
     * Function: kill
     * Description: sets alive to false
     *********************************************/
    void kill();
    
    /*********************************************
     * Function: isAlive
     * Description: returns alive (a boolean getter)
     *********************************************/
    bool isAlive() const;
    
    /*********************************************
     * Function: advance
     * Description: tells everything to keep moving
     *********************************************/
    void advance();
    
protected:
    Velocity velocity;
    Point point;

private:
    bool alive;
};

#endif /* flyingObject_h */
