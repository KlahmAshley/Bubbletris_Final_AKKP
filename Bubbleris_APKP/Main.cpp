#include <raylib.h>
#include "Game.h"
#include "Colors.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double lastUpdateTime = 0;
static bool canRecordScore = true;
bool readyToDraw = false;

bool EventTriggered(double interval) //keeping track of time 
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
    vector<int> lbScores;

    bool swapped;
    //drawing the game window, setting target FPS and loading font
    InitWindow(500, 620, "BUBBLETRIS - AKKP");
    SetTargetFPS(60);
	Font font = LoadFont("BubbleFont.ttf");
    Texture2D McGee = LoadTexture("LeaderBoardFloaty.png");

    Game game = Game();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        //
        if (EventTriggered(0.4)) //Time between moving block down over time 
        {
            game.MoveBlockDown();

        }

        //starts drawing - mainly the visual things like background, shapes and text 
        BeginDrawing(); 
        ClearBackground(darkBlue);
		DrawTextEx(font, "Score", { 370, 15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
  
        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, purple); //score box

        char scoreText[10];
        sprintf_s(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        
        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
        game.Draw(); //Begins to draw the game 
        
        if (game.gameOver && canRecordScore) //game is over means you can view the leaderboard
        {
           // cout << "testing game over yay wow yay score is being recorded\n";
            leaderboard.open("leaderboard.txt", ios::app);
            leaderboard << game.score << "\n";
            leaderboard.close();

            ifstream file("leaderboard.txt"); //getting the text file / info inside it 
            if (!file.is_open()) {
                cerr << "Error: Unable to open file."; //Incase it is unable to be found or corrupt it outputs error
                return 1;
            }
            int j;

            //changing leader board positions based on score using selection sort (?) ask katie about this?? 
            while (file >> j) {
                lbScores.push_back(j);
            }
            int temp;
            int n = lbScores.size();
            for (int j = 0; j < n - 1; j++) {
                int min = lbScores.at(j);
                temp = j;
                for (int i = j + 1; i < n; i++) {
                    if (min < lbScores.at(i)) {
                        min = lbScores.at(i);
                        temp = i;
                    }                    
                }
                swap(lbScores.at(j), lbScores.at(temp));
            }

            if (lbScores.size() > 5) {
                lbScores.erase(lbScores.begin() + 5, lbScores.end());
            }


            readyToDraw = true;

            for (int i = 0; i < lbScores.size(); i++) {
                cout << "Score: " << lbScores[i] << "\n";
            }
            
            
            file.close();
            canRecordScore = false;
            
        }
        if (game.gameOver && readyToDraw) //actual display for thje leaderboard
        {
 
            DrawRectangleRounded({ 75, 50, 350, 500 }, 0.3, 6, cyan);

            DrawRectangleRounded({ 85, 60, 330, 480 }, 0.3, 6, pink);
            DrawTextEx(font, "GAME OVER!", { 175, 75 }, 38, 2, WHITE);
            DrawTextEx(font, "LEADERBOARD:", { 155, 115 }, 38, 2, WHITE);
            DrawTextEx(font, TextFormat("#1 : %i", lbScores[0]), { 100, 150}, 38, 2, WHITE);
            DrawTextEx(font, TextFormat("#2 : %i", lbScores[1]), { 100, 200 }, 38, 2, WHITE);
            DrawTextEx(font, TextFormat("#3 : %i", lbScores[2]), { 100, 250 }, 38, 2, WHITE);
            DrawTextEx(font, TextFormat("#4 : %i", lbScores[3]), { 100, 300 }, 38, 2, WHITE);
            DrawTextEx(font, TextFormat("#5 : %i", lbScores[4]), { 100, 350 }, 38, 2, WHITE);
            DrawTexture(McGee, 0, 0, WHITE);

            

        }
        if (!game.gameOver) {
            canRecordScore = true;
            lbScores.clear();
            readyToDraw = false;
        }
        
        EndDrawing();
    }
    
    

    CloseWindow();
}

