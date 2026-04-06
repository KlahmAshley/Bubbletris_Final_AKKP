#pragma once
#include "Grid.h"
#include "Bubbles.cpp"
#include <vector>

using namespace std;

class Game
{
public:
    Game(); //constructor
    ~Game(); //destructor
    void Draw(); //handles drawing everything onscreen
    void HandleInput(); //input manager
    void MoveBlockDown(); //moving a block down when you have it in position already

    //variables
    bool gameOver;
    int score;
    Music music;

private:
    //functions for moving blocks
    void MoveBlockLeft();
    void MoveBlockRight();

    bool IsBlockOutside(); //checking if block is outside of the grid or not
    void RotateBlock(); //rotate block
    void LockBlock(); //locking block in place once it touches the blocks below it
    bool BlockFits(); //checking if block fits within 
    void Reset(); //resets the board after a game over
    void UpdateScore(int linesCleared, int moveDownPoints); //updates score when row is cleared
    Grid grid;
    //block variables and pointers (note to delete later: i moved a few lines down here for organization purposes)
    Block* GetRandomBlock();
    vector<Block*> GetAllBlocks();
    vector<Block*> blocks;
    Block* currentBlock;
    Block* nextBlock;
    //sound effects
    Sound rotateSound;
    Sound clearSound;
    Texture2D bog = LoadTexture("Bog.png"); //bog the bubble dog :)
};