#ifndef BubbleAudio_HEADER
#define BubbleAudio_HEADER

#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
using namespace std;

class BubbleAudio
{
public:
    BubbleAudio();
   virtual ~BubbleAudio();
   virtual void sound() = 0; //pure virtual function 
    Sound bSound;
    Sound sSound;
};


class SpecialBubble : public BubbleAudio
{
public:
     void sound() override {};
};





/*

};

class SpecialBubble : public BubbleAudio 
{
public:
    virtual void sound() override {};
};

class OtherBubble : public BubbleAudio
{
public:
    virtual void sound() override {};
};

*/

#endif