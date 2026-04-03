#pragma once
#include <vector>
#include "Position.h"
#include "Colors.h"
using namespace std;

class Block
{
public:
   Block();
   virtual  ~Block() = default; //destructor to mark as virtual
   virtual  void Draw(int offsetX, int offsetY); //drawing based on base - virtual to overrride
   virtual  void Move(int rows, int columns) = 0; //movement (different per block therefore can be overrriden)

   virtual vector<vector<Position>> GetInitialCells() const = 0;


   vector<Position> GetCellPositions();
   void Rotate(); //Both rotation functions follow the same thing for each block so no need to abc them **COME BACK TO THIS STUFF 
   void UndoRotation();
   int id;
   vector<vector<Position>> cells;


   void InitializeShape()
   {
       rotationState = 0;
       cells = GetInitialCells();
   }

private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int columnOffset;
};