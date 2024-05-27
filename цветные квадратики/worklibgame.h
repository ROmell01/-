#pragma once
#include "Meteor.h";
#include "Full.h";
#include <sstream>
#include <string>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

struct FrameAnim
{
	int Frame = 0;
	int Step = 100;
	int Frame1 = 0;
	int Step1 = 100;
};

void playermove(Sprite & player, Vector2f & moveRec);

void playeranim(Sprite& player, FrameAnim& FramePlAnim, int traffic);

void Correct(Full & canister, int i, Meteor * meteor, int nmeteor );  

void CorrectFull(Full& canister, Meteor* meteor, int nmeteor);

string IntToStr(int number);