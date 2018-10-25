#include "bullet.h"
#include "uiDraw.h"

#define BULLET_SPEED 10.0

/**************************************************************************
 * Bullet :: Bullet
 * sets a bullet to life! then sets its angle depending on the cannon
 **************************************************************************/
Bullet :: Bullet()
{
    setAlive(true);
    angle = 60.0;
    setCleanupCount(40);
}

/**************************************************************************
 * Bullet :: fire
 * fires the bullet and an angle determined by the cannon's angle
 **************************************************************************/
void Bullet :: fire(Point point, float angle, Velocity velocity)
{
    int newAngle = angle - 270;
    
    setPoint(point);
    
    this->velocity.setDx(velocity.getDx() + BULLET_SPEED * (cos(M_PI / 180.0 * newAngle)));
    this->velocity.setDy(velocity.getDy() + BULLET_SPEED * (sin(M_PI / 180.0 * newAngle)));
    
}

/**************************************************************************
 * FlyingObject :: draw
 * draws the bullet as a dot
 **************************************************************************/
void Bullet::  draw()  const
{
    drawDot(point);
}
