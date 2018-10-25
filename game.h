/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include <limits>
#include <algorithm>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"


// TODO: include your bullet and Astroid classes
#include "astroid.h"
#include "bullet.h"

#define CLOSE_ENOUGH_BIG 16
#define CLOSE_ENOUGH_MED 8
#define CLOSE_ENOUGH_SMALL 4
#define CLOSE_ENOUGH_SHIP 10


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
    
    float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
   
private:
   // The coordinates of the screen
    Point topLeft;
    Point bottomRight;
   
    int score;
   
    std::vector<Bullet> bullets;
    std::list<Astroid*> astroids;
    
    Ship ship;


   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceShip();
   void advanceAstroids();
   Astroid* createAstroids();
   
   void handleCollisionsBulletVsAstroid();
   void handleCollisionsShipVsAstroids();
   void cleanUpZombies();
   void cleanUpStrayBullets();
};

#endif /* GAME_H */
