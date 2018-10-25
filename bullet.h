#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"
#include "uiDraw.h"

class Bullet : public FlyingObject
{
public:
    /*********************************************
     * Constructor: bullet
     * Description: constructs the bullet
     *********************************************/
    Bullet();
    
    /*********************************************
     * Function: fire
     * Description: sets the position of the bullet
     *********************************************/
    void fire(Point point, float angle, Velocity velocity);
    
    /*********************************************
     * Function: draw
     * draws a dot
     *********************************************/
    void draw() const;
    
    /*********************************************
     * Function: getCleanupCount
     * counts how many frames the bullet has traveled
     *********************************************/
    int getCleanupCount() {return cleanupCount; }
    
    /*********************************************
     * Function: setCleanupCount
     * sets how many frames the bullet can travel
     *********************************************/
    void setCleanupCount(int count) {this->cleanupCount = count; }
    
    /*********************************************
     * Function: advanceCleanupCount
     * counts each frame
     *********************************************/
    void advanceCleanupCount() {cleanupCount--; }
    
private:
    float angle;
    int cleanupCount;
    
};

#endif /* bullet_h */
