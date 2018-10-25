#ifndef ship_h
#define ship_h

#include <stdio.h>
#include "flyingObject.h"
#include "uiDraw.h"



#endif /* ship_h */

class Ship : public FlyingObject
{
public:
    /*********************************************
     * SHIP
     * A Constructor.
     *********************************************/
    Ship();
    
    /*********************************************
     * Draw
     * Draws the ship.
     *********************************************/
    void draw();
    
    /*********************************************
     * GETROTATION
     * Returns the angle of the ship.
     *********************************************/
    int getRotation() const {return rotation; }
    
    /*********************************************
     * GETSHIELDS
     * Returns the health of the shields.
     *********************************************/
    int getShields() const {return shields; }
    
    /*********************************************
     * GET BOOL SHIELDS
     * Returns a boolean indicating the validity of
     * the shields.
     *********************************************/
    bool getBoolShields() const {return boolShields; }
    
    /*********************************************
     * POINT
     * Indicates whether the fire should be drawn.
     *********************************************/
    bool getThrust() const {return thrust; }
    
    /*********************************************
     * HIT
     * Damages the shields.
     *********************************************/
    void hit();
    
    /*********************************************
     * SET ROTATION
     * Sets the angle of the ship.
     *********************************************/
    void setRotation(int rotation) {this->rotation = rotation; }
    
    /*********************************************
     * SET SHIELDS
     * Sets the amount of damage shields can take.
     *********************************************/
    void setShields(int shieldPower) {this->shields = shieldPower; }
    
    /*********************************************
     * SET THRUST
     * Turns fire on or off.
     *********************************************/
    void setThrust(bool thrust) {this->thrust = thrust; }
    
    /*********************************************
     * SHIELDS ALIVE
     * Allows shields to be used or not.
     *********************************************/
    void shieldsAlive(bool alive) {this->boolShields = alive; }
    
    /*********************************************
     * ROTATE RIGHT
     * Rotates the ship to the right.
     *********************************************/
    void rotateRight();
    
    /*********************************************
     * ROTATE LEFT
     * Rotate the ship to the left.
     *********************************************/
    void rotateLeft();
    
    /*********************************************
     * MOVE FORWARD
     * Moves the ship in the direction it is facing.
     *********************************************/
    void moveForward();
    
private:
    int rotation;
    int shields;
    bool boolShields;
    bool thrust;
    
    
};
