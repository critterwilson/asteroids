#ifndef velocity_h
#define velocity_h
class Velocity
{
public:
    /*********************************************
     * CONSTRUCTOR: velocity()
     * default constructor
     *********************************************/
    Velocity();
    
    /*********************************************
     * CONSTRUCTOR: Velocity (float, float)
     * Non-default constructor that accepts change
     * in Y and X values
     *********************************************/
    Velocity (float x, float y);
    
    /*********************************************
     * Function: getDx
     * returns the change in x
     *********************************************/
    float getDx() const
    {
        return Dx;
    }
    
    /*********************************************
     * Function: getDy
     * returns the change in y
     *********************************************/
    float getDy() const
    {
        return Dy;
    }
    
    /*********************************************
     * Function: setDx
     * applies Dx to be used
     *********************************************/
    void setDx(float Dx)
    {
        this->Dx += Dx;
    }
    
    /*********************************************
     * Function: setDy
     * applies Dy to be used
     *********************************************/
    void setDy(float Dy)
    {
        this->Dy += Dy;
    }
    
private:
    float Dx;
    float Dy;
    
};

#endif /* velocity.h */
