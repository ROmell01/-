#pragma once
#include "Meteor.h"
class Full :
    public Meteor
{
public:
    Full(String name, int x, int y);
    ~Full();


    virtual void restart();

private:

    using Meteor::animation;

};

