#pragma once
#include <raylib.h>
#include <vector>
using namespace std;

//Creating Colour variables
//"extern" is a keyword that we're using here to allow the colour variables to be created here, but easily accessible and defined in Colours.cpp
extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

//Getter function for the colours
vector <Color> GetCellColors();