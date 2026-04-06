#include "Bubble.h"
#include "Position.h"

//File for storing the data of each bubble group in order to access them and draw when needed
class LBubbles : public Block
{
public:
    LBubbles()
    {
        //bubbleID stores the ID number of each bubble group for ease of calling + determines the bubble colour 
        bubbleID = 1;
        //Storing the shape of each bubble group when rotated in an array  
        cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
        cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
        Move(0, 3); 
    }
};
//Logic commented in LBubbles are the same for JBubbles, IBubbles, SBubbles, TBubbles and ZBubbles 


class JBubbles : public Block
{
public:
    JBubbles()
    {
        bubbleID = 2;
        cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
        Move(0, 3);
    }
};

class IBubbles : public Block
{
public:
    IBubbles()
    {
        bubbleID = 3;
        cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
        cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
        cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
        Move(-1, 3);
    }
};

class OBubbles : public Block
{
public:
    OBubbles()
    {
        //Rotation doesnt change its positions as this bubble set is square shaped therefore only 1 shape in array
        bubbleID = 4;
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) }; 
        Move(0, 4);
    }
};

class SBubbles : public Block
{
public:
    SBubbles()
    {
        bubbleID = 5;
        cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
        cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
        Move(0, 3);
    }
};

class TBubbles : public Block
{
public:
    TBubbles()
    {
        bubbleID = 6;
        cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
        Move(0, 3);
    }
};

class ZBubbles : public Block
{
public:
    ZBubbles()
    {
        bubbleID = 7;
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
        Move(0, 3);
    }
};