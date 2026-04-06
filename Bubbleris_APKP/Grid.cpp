#include "Grid.h"
#include <iostream>
#include "Colors.h"
using namespace std;

Grid::Grid()//constrcutor 
{
    numRows = 20; 
    numCols = 10; 
    cellSize = 30; 
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()//Initalizing the size of the grid 
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

/*void Grid::Print() //Just to check if its correct in console
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            cout << grid[row][column] << " ";
        }
        cout << endl;
    }
}
*/

void Grid::Draw() //Drawing the actual grid to the screen 
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column) //parameters of the grid; what is outside and inside grid 
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column) //Checking if each cell is empty 
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows() 
// calling other functions that are checking if the row of the grid is full of bubble blocks
// and if so it clears them and move the next rows down 1 
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)//actual function doing the checking if the row of the grid is full
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)//actual function doing the clearing of the row 
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows) //actual function doing the moving of rows down 
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}