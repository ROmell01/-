#pragma once
#include <SFML/Graphics.hpp>
#include "worklibgame.h"
using namespace sf;
void playermove(RectangleShape& player, Vector2f& moveRec){


    player.move(moveRec);
    Vector2f pos = player.getPosition();
    if (pos.x > 1200) player.setPosition(1200, pos.y);
    if (pos.x < 50) player.setPosition(50, pos.y);
    if (pos.x > 670) player.setPosition(pos.x, 670);
    if (pos.x < 120) player.setPosition(pos.x, 120);
    if ((pos.x > 1200) && (pos.y < 120)) player.setPosition(1200, 120);
    if ((pos.x < 1200) && (pos.y > 670)) player.setPosition(1200, 670);
    if ((pos.x > 50) && (pos.y < 120)) player.setPosition(50, 120);
    if ((pos.x < 50) && (pos.y > 670)) player.setPosition(50, 670);
}
 
