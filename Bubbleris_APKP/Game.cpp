#include "Game.h"
#include <random>
#include <vector>
#include "Audio.h"

using namespace std;


Game::Game() //constructor 
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("MusicLoop.wav");
    PlayMusicStream(music); //If we want background music 
    rotateSound = LoadSound("RotatePop.wav");
    clearSound = LoadSound("ClearPop.mp3");
   // bSound = LoadSound("Bubblesound1");
   // sSound = LoadSound("Bubblesound2");

    Texture2D bog = LoadTexture("Bog.png");
}

Game::~Game() //destructor
{
    //deleting all blocks and pointers to blocks 
    delete currentBlock;
    delete nextBlock;
    for (Block* b : blocks)
    {
        delete b;
    }
    blocks.clear();
    
    //unloading audio 
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

Block* Game::GetRandomBlock() //Getting the random block from the pointer pointing to the block array
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block* block = blocks[randomIndex]; 
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}



vector <Block*> Game::GetAllBlocks()
{
    //Creates an instance of different bubble blocks for the pointer to access properly 
    return { new IBubbles(), new JBubbles(), new LBubbles(), new OBubbles(), new SBubbles(), new TBubbles(), new ZBubbles() };
}


void Game::Draw() //Drawing the varibles to play the game; the grid and what the current block is
{
    grid.Draw();
	DrawTexture(bog, 0, 0, WHITE);
    if (currentBlock) currentBlock ->Draw(11, 11);
    switch (nextBlock->bubbleID)
    {
    case 3:
        nextBlock->Draw(255, 290);
        break;
    case 4:
        nextBlock->Draw(255, 280);
        break;
    default:
        nextBlock->Draw(270, 270);
        break;
    }
}

void Game::HandleInput() //defining how the bubble blocks move 
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }

    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (!gameOver) //checks if game isnt over
    {
        currentBlock->Move(0, -1); //If the game isnt over than the current blocks gets moved now by 1 
        if (IsBlockOutside() || BlockFits() == false) 
        {
            currentBlock->Move(0, 1);
            //If the block is outside or doesnt fit, the block stays/is "moved" back in the last valid location
        }
    }
}

//The logic above defined for MoveBlockleft is the same for MoveBlockRight and MoveBlockDown

void Game::MoveBlockRight()
{
    if (!gameOver)
    {
        currentBlock->Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!gameOver)
    {
        currentBlock->Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(-1, 0);
            LockBlock();
        }
    }
}

bool Game::IsBlockOutside() // Checks if the block is outside the defined grid 
{
    vector<Position> tiles = currentBlock->GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock() //calls the rotate functions if it can be rotated or undo if it can't + plays sound when it can 
{
    if (!gameOver)
    {
        currentBlock->Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->UndoRotation();
        }
        else
        {
            PlaySound(rotateSound);
        }
    }
}

void Game::LockBlock()
{
    vector<Position> tiles = currentBlock->GetCellPositions();
    for (Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock->bubbleID;
    }

    //delete old current and move to next block in the array
    delete currentBlock;
    currentBlock = nextBlock;
    nextBlock = nullptr;

    //if block doesn't fit in the grid(aka overflow) then end the game
    if (BlockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    //rewarding player with points and sound effects for clearing a row
    if (rowsCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits() // checking if block fits
{
    vector<Position> tiles = currentBlock->GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    return true;
}

//resetting game
void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
    
    //deleting allocated block memory to clear up space
    for (Block* b : blocks)
    {
        delete b;
    }
    blocks.clear();

}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    //switch case for determining how many points a player is given for clearing lines
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    case 4: //for some reason there wasn't a case 4? so i added it
        score += 700;
        break;
    default:
        break;
    }

    //adding extra to the score depending on how many points from moving down you obtained
    score += moveDownPoints;
}



BubbleAudio :: BubbleAudio()
{
    bSound = LoadSound("Bubblesound1");
    sSound = LoadSound("Bubblesound2");

}

BubbleAudio :: ~BubbleAudio()
{
    UnloadSound(bSound);
    UnloadSound(sSound);
}


/*class SpecialBubble : public BubbleAudio
{
public:
   void sound() override
    {
       PlaySound(sSound);
    }

};
*/

/*
class OtherBubble : public BubbleAudio
{
public:
    virtual void sound() override
    {
        PlaySound(bSound);
    }

};


int main()
{
      BubbleAudio* bAuds;
    // BubbleAudio* bAudo;

   SpecialBubble sAud;
   //  OtherBubble oAud;

     bAuds = &sAud;
    //  bAudo = &oAud;
//
     bAuds->sound();
    //  bAudo->sound();
}

*/