#include "Bubble.h"
#include <vector>
using namespace std;

Block::Block()//constructor 
{

    cellSize = 30;
    rotationState = 0;
    //
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    //initializing an array of tiles to draw the bubble group in
    vector <Position> tiles = GetCellPositions();
    for (Position item : tiles)
    {
        //Drawing the bubbles! 
        DrawCircleGradient(item.column * cellSize + offsetX + 14, item.row * cellSize + offsetY, cellSize - 14, colors[bubbleID], SKYBLUE);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

vector <Position> Block::GetCellPositions()
{
    vector <Position> tiles = cells[rotationState];
    vector <Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}



void Block::Rotate()
{

    rotationState++; //when function is called, rotate cell
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}

Block::~Block()//destructor
{

}   

