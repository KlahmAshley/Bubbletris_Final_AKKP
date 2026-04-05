#include "Game.h"
#include <random>
#include <vector>

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
    PlayMusicStream(music);
    rotateSound = LoadSound("RotatePop.wav");
    clearSound = LoadSound("ClearPop.mp3");
    Texture2D bog = LoadTexture("Bog.png");
}

Game::~Game() //destructor
{
    delete currentBlock;
    delete nextBlock;
    for (Block* b : blocks)
    {
        delete b;
    }
    blocks.clear();

    
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

Block* Game::GetRandomBlock()
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
    return { new IBubbles(), new JBubbles(), new LBubbles(), new OBubbles(), new SBubbles(), new TBubbles(), new ZBubbles() };
}


void Game::Draw()
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

void Game::HandleInput()
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
    if (!gameOver)
    {
        currentBlock->Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(0, 1);
        }
    }
}

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

bool Game::IsBlockOutside()
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

void Game::RotateBlock()
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

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock->GetCellPositions();
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