#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"
using namespace std;

class Block
{
public:
    Block(); //constructor
    virtual ~Block(); //destructor

    void Draw(int offsetX, int offsetY); //drawing the bubble groups
    void Move(int rows, int columns); //moving the block
    vector <Position> GetCellPositions(); //getting the position of each cell

    //functions dealing with block rotation
    void Rotate();
    void UndoRotation();

    int bubbleID; //id for the type of bubble group
    map <int, vector<Position>> cells; //array of cells

private:
    int cellSize; //size of the cell
    int rotationState; //tracking the current rotation state a block is in
    vector <Color> colors; //colours!
    //offsets for spaces within the grid
    int rowOffset; 
    int columnOffset;
};

