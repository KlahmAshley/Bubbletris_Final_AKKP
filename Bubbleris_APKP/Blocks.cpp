#include "Block.h"
#include "Position.h"
#include <vector>
using namespace std;

class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        InitializeShape();
        Move(0, 3);
    }

    vector<vector<Position>> GetInitialCells() const override
    {
        return {
            { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) },
            { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) },
            { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) },
            { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) }
        };
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        InitializeShape();
        Move(0, 3);
    }

    vector<vector<Position>> GetInitialCells() const override
    {
        return {
            { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) },
            { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) },
            { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) },
            { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) }
        };
    }
};



class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        InitializeShape();
		Move(-1, 3);
    }

	vector<vector<Position>> GetInitialCells() const override
    {
        return{
        { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) },
        { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) },
        { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) },
        { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) }
        };    
    }
};



class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        InitializeShape();
		Move(0, 4);
    }

	vector<vector<Position>> GetInitialCells() const override
    {
        return{
              { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) }
        };
    
    }
};



class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
		InitializeShape();
        Move(0, 3);
    }
	vector<vector<Position>> GetInitialCells() const override
    {
        return{

        { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) },
        { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) },
        { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) },
        { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) }

        };
       
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        InitializeShape();
		Move(0, 3);
    }
    vector<vector<Position>> GetInitialCells() const override
    {
        return{

        { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) },
        { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) },
        { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) },
        { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) }

        };

    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
		InitializeShape();
		Move(0, 3);
    }
	vector<vector<Position>> GetInitialCells() const override   
    { 
        return{

        {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) },
        {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) },
        {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) },
        {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) }

        };
    }
};