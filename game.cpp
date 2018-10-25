/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "astroid.h"
#include "bigRock.h"
#include "mediumRock.h"
#include "smallRock.h"


#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{
    // Set up the initial conditions of the game
    for (int i = 0; i < 5; i++)
    {
        astroids.push_back(createAstroids());
    }
    score = 0;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently a bird allocated
   //       and if so, delete it.

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
    advanceBullets();
    advanceAstroids();
    advanceShip();
    
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].advanceCleanupCount();
    }

    handleCollisionsBulletVsAstroid();
    handleCollisionsShipVsAstroids();
    cleanUpZombies();
    cleanUpStrayBullets();
    
    if ((astroids.size() <= 0) && ship.isAlive())
    {
        for (int i = 0; i < 5; i++)
        {
            astroids.push_back(createAstroids());
        }
    }
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceShip()
{
      // make sure ship's alive
      if (ship.isAlive())
      {
         // move it forward
         ship.advance();
      }
}

/**************************************************************************
 * GAME :: ADVANCE ASTROIDS
 * Check for a collision between a bullet and an astroid.
 **************************************************************************/
void Game :: advanceAstroids()
{
    for(list<Astroid*> :: iterator it = astroids.begin();
        it != astroids.end();
        ++it)
    {
        if ((*it)->isAlive())
        {
            (*it)->advance();
        }
    }
}

/**************************************************************************
 * GAME :: CREATE ASTROIDS
 * Create an astroid of a random type according to the rules of the game.
 **************************************************************************/
Astroid* Game :: createAstroids()
{

    int bigBang = random(1, 4);
    
    Astroid* newAstroid = NULL;
    switch (bigBang)
    {
        case 3:
            newAstroid = new BigRock;
            break;
        case 2:
            newAstroid = new MediumRock();
            break;
        case 1:
            newAstroid = new SmallRock;
            break;
        default:
            break;
    }
    return newAstroid;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS BULLET VS ASTROID
 * Check for a collision between a bullet and an astroid.
 **************************************************************************/
void Game :: handleCollisionsBulletVsAstroid()
{
// now check for a hit (if it is close enough to any live bullets)
for(list<Astroid*> :: iterator it = astroids.begin();
       it != astroids.end(); ++it)    
    {
        for (int i = 0; i < bullets.size(); i++)
        {
            if (bullets[i].isAlive())
            {
                if ((getClosestDistance(bullets[i], **it) < CLOSE_ENOUGH_BIG)
                        && ((*it)->getType() == 3) && ((*it)->isAlive()))
                {
                    // kill big astroid
                    (*it)->kill();
                    // add three new astroids (2Xmed, 1Xsmall)
                    astroids.push_back(new MediumRock((*it)->getPoint(), (*it)->getVelocity(), 1));
                    astroids.push_back(new MediumRock((*it)->getPoint(), (*it)->getVelocity(), -1));
                    astroids.push_back(new SmallRock((*it)->getPoint(), (*it)->getVelocity(), 2));
                    // add points
                    score += 1;
                    // the bullet is dead as well
                    bullets[i].kill();
                }
                else if ((getClosestDistance(bullets[i], **it) < CLOSE_ENOUGH_MED)
                            && ((*it)->getType() == 2) && ((*it)->isAlive()))
                {
                        // kill big astroid
                        (*it)->kill();
                        //add 2 small astroids
                        astroids.push_back(new SmallRock((*it)->getPoint(), (*it)->getVelocity(), 3));
                        astroids.push_back(new SmallRock((*it)->getPoint(), (*it)->getVelocity(), -3));
                        // add points
                        score += 3;
                        // the bullet is dead as well
                        bullets[i].kill();
                }
                else if ((getClosestDistance(bullets[i], **it) < CLOSE_ENOUGH_SMALL)
                        && ((*it)->getType() == 1) && ((*it)->isAlive()))
                {
                    // kill big astroid
                    (*it)->kill();
                    // add points
                    score += 5;
                    // the bullet is dead as well
                    bullets[i].kill();
                }
            }
        }
    }
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS SHIP VS ASTROID
 * Check for a collision between the ship and an stroid.
 **************************************************************************/
void Game :: handleCollisionsShipVsAstroids()
{
for(list<Astroid*> :: iterator it = astroids.begin();
    it != astroids.end(); ++it)
    {
        if (ship.getBoolShields())
        {
            if (((getClosestDistance(ship, **it) < CLOSE_ENOUGH_SHIP)) &&  ((*it)->isAlive()))
            ship.hit();
        }
        else if ((getClosestDistance(ship, **it) < CLOSE_ENOUGH_SHIP) &&  ((*it)->isAlive()))
        {
            ship.kill();
        }
    }
    
}

/**************************************************************************
 * GAME :: CLEAN UP STRAY BULLETS
 * Kill bullets after 40 frames and no contact
 **************************************************************************/
void Game :: cleanUpStrayBullets()
{
    vector<Bullet>:: iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end())
    {
        Bullet bullet = *bulletIt;
        
        if (bullet.getCleanupCount() <= 0)
        {
            bulletIt->kill();
            bulletIt++;
        }
        else
        {
            bulletIt++;
        }
    }
    
    
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, destroy astroids)
 * creates new astroids when bullets are clean
 **************************************************************************/
void Game :: cleanUpZombies()
{
    //cout << "Astroid count: " << astroids.size() << endl;
    if(astroids.size() == 0 || !ship.isAlive())
       {
           // Look for dead bullets
           vector<Bullet>::iterator bulletIt = bullets.begin();
           while (bulletIt != bullets.end())
           {
               Bullet bullet = *bulletIt;
               // Asteroids Hint:
               // If we had a list of pointers, we would need this line instead:
               //Bullet* pBullet = *bulletIt;
               if (bullet.isAlive())
               {
                   bulletIt = bullets.erase(bulletIt);
               }
               else
               {
                   bulletIt++; // advance
               }
           }
       }
    
    // Look for dead Astroids
    list<Astroid*>::iterator astroidIt = astroids.begin();
    while (astroidIt != astroids.end())
    {
        Astroid* pAstroid = *astroidIt;
        // Asteroids Hint:
        // If we had a list of pointers, we would need this line instead:
        //Bullet* pBullet = *bulletIt;
        if (!pAstroid->isAlive() || !ship.isAlive())
        {
            // If we had a list of pointers, we would need to delete the memory here...
            delete pAstroid;
            // remove from list and advance
            astroidIt = astroids.erase(astroidIt);
        }
        else
        {
            astroidIt++; // advance
        }
    }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the Ship
   if (ui.isLeft())
   {
      ship.rotateLeft();
       
   }
   if (ui.isRight())
   {
      ship.rotateRight();
   }
    
    // Move the Ship forward, turn on fire
   if (ui.isUp())
   {
       ship.moveForward();
       ship.setThrust(true);
   }
   else if (!ui.isUp())
   {
       ship.setThrust(false);
   }
    
    // Turn on shield
   if (ui.isDown())
   {
       ship.shieldsAlive(true);
       ship.hit();
       drawCircle(ship.getPoint(), 10);
   }
   else if (!ui.isDown())
   {
       ship.shieldsAlive(false);
   }
    
   // Check for "Spacebar
   if (ui.isSpace())
   {
      Bullet newBullet;
      newBullet.fire(ship.getPoint(), ship.getRotation(), ship.getVelocity());
      bullets.push_back(newBullet);
       
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the Asteroids
    for(list<Astroid*> :: iterator it = astroids.begin();
        it != astroids.end();
        ++it)
    {
        if ((*it)->isAlive())
        {
            (*it)->draw();
        }
    }
  

   // draw the ship
    ship.draw();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
 

   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
    
   // Put Shield Health on the Screen
   Point shieldLocation;
   shieldLocation.setX(topLeft.getX() + 5);
   shieldLocation.setY(topLeft.getY() - 30);
   
    // Draw Shield Health
   drawNumber(scoreLocation, score);
   drawNumber(shieldLocation, ship.getShields());

}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
    // find the maximum distance traveled
    float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
    dMax = max(dMax, abs(obj2.getVelocity().getDx()));
    dMax = max(dMax, abs(obj2.getVelocity().getDy()));
    dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
    
    float distMin = std::numeric_limits<float>::max();
    for (float i = 0.0; i <= dMax; i++)
    {
        Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
        Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
        
        float xDiff = point1.getX() - point2.getX();
        float yDiff = point1.getY() - point2.getY();
        
        float distSquared = (xDiff * xDiff) + (yDiff * yDiff);
        
        distMin = min(distMin, distSquared);
    }
    
    return sqrt(distMin);
}
