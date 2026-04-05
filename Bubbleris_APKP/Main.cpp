#include <raylib.h>
#include "Game.h"
#include "Colors.h"
#include <iostream>
#include <fstream>
using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    ofstream leaderboard;
    
    //drawing the game window + setting 
    InitWindow(500, 620, "BUBBLETRIS - AKKP");
    SetTargetFPS(60);
	Font font = LoadFont("BubbleFont.ttf");

    Game game = Game();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        //
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();

        }

        BeginDrawing();
        ClearBackground(darkBlue);
		DrawTextEx(font, "Score", { 370, 15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", { 320, 400 }, 38, 2, WHITE);
           
        }
        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, purple); //score box

        char scoreText[10];
        sprintf_s(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        
        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }
    leaderboard.open("leaderboard.txt", ios::app);
    leaderboard << "Score: " << game.score;
    leaderboard.close();

    CloseWindow();
}