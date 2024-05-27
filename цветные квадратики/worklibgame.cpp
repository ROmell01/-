#include "worklibgame.h"

void playermove(Sprite& player, Vector2f& moveRec)
{
    player.move(moveRec);
    Vector2f pos = player.getPosition();
    if (pos.x > 1200) player.setPosition(1200, pos.y);
    if (pos.x < 50) player.setPosition(50, pos.y);
    if (pos.y > 660) player.setPosition(pos.x, 660);
    if (pos.y < 110) player.setPosition(pos.x, 110);
    if ((pos.x > 1200) && (pos.y < 110)) player.setPosition(1200, 110);
    if ((pos.x > 1200) && (pos.y > 660)) player.setPosition(1200, 660);
    if ((pos.x < 50) && (pos.y < 110)) player.setPosition(50, 110);
    if ((pos.x < 50) && (pos.y > 660)) player.setPosition(50, 660);
}

void playeranim(Sprite& player, FrameAnim& FramePlAnim, int traffic)
{
    FramePlAnim.Frame += FramePlAnim.Step;
    player.setTextureRect(IntRect(0, FramePlAnim.Frame, 90, 90));

    if (traffic) if (FramePlAnim.Frame > 0) FramePlAnim.Step = -100;  else FramePlAnim.Step = 0;
    else {
        if (FramePlAnim.Frame == 800) FramePlAnim.Step = 0;
        if (FramePlAnim.Frame <= 700) FramePlAnim.Step = 100;
    }
}
void Correct(Full& canister, int i, Meteor* meteor, int nmeteor)
{

    for (int i1 = 0; i1 < nmeteor; i1++)
    {
        if (i1 != i) {
            if (meteor[i1].Collision(meteor[i].getMeteorBounds()))
            {
                meteor[i].restart();  Correct(canister, i, meteor, nmeteor); break;
            }
        }
    }

    if (canister.Collision(meteor[i].getMeteorBounds())) { meteor[i].restart(); Correct(canister, i, meteor, nmeteor); }
}

void CorrectFull(Full& canister, Meteor* meteor, int nmeteor)
{
    for (int i1 = 0; i1 < nmeteor; i1++)
    {
        if (meteor[i1].Collision(canister.getMeteorBounds()))
        {
            canister.restart(); CorrectFull(canister, meteor, nmeteor); break;
        }
    }
}

string IntToStr(int number)
{
    ostringstream TextString;   
    TextString << number;		
    return TextString.str();
}

