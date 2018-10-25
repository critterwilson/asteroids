#ifndef astroid_h
#define astroid_h

#include <stdio.h>
#include "flyingObject.h"


class Astroid : public FlyingObject
{
public:
    /*********************************************
     * Constructor: Astroid
     * Description: Default astroid constructor
     *********************************************/
    Astroid();
    /*********************************************
     * Function: getSpeed
     * Description: Returns speed of astroid.
     *********************************************/
    float getSpeed() const {return speed; }
    /*********************************************
     * Function: getRotation
     * Description: Returns the rotation of the
     * astroids
     *********************************************/
    float getRotation() const {return rotation; }
    /*********************************************
     * Function: getAstroidStartX
     * Description: Returns the X value of the
     * starting point of the astroid
     *********************************************/
    float getAstroidStartX() const {return astroidStartX; }
    /*********************************************
     * Function: getAstroidStartY
     * Description: Returns the Y value of the
     * starting point of the astroid
     *********************************************/
    float getAstroidStartY() const {return astroidStartY; }
    /*********************************************
     * Function: getType
     * Description: Returns the type of astroid
     *********************************************/
    int getType() const {return type; }
    
    /*********************************************
     * Function: setSpeed
     * Description: Sets the speed of the astroid.
     *********************************************/
    void setSpeed(float speed) {this->speed = speed; }
    /*********************************************
     * Function: setRotation
     * Description: Sets the rotation of the astroid.
     *********************************************/
    void setRotation(float rotation) {this->rotation += rotation; }
    /*********************************************
     * Function: setAstroidStartX
     * Description: Sets the X value of the
     * starting point of the astroid.
     *********************************************/
    void setAstroidStartX(float x) {this->astroidStartX = x; }
    /*********************************************
     * Function: setAstroidStartY
     * Description: Sets the Y value of the
     * starting point of the astroid.
     *********************************************/
    void setAstroidStartY(float y) {this->astroidStartY = y; }
    /*********************************************
     * Function: setType
     * Description: Sets the type of astroid
     *********************************************/
    void setType(int type) {this->type = type; }
    /*********************************************
     * Virtual Function: draw
     * Description: draws the astroids
     *********************************************/
    virtual void draw() = 0;
    
    
private:
    float speed;
    float astroidStartX;
    float astroidStartY;
    int type;
protected:
    float rotation;
};
#endif /* Astroid_h */
