#include "Colors.h"
#include <vector>
using namespace std;

//shapes and colours.......

//Defining all of the colours by implementing their hex codes
const Color darkGrey = { 25, 0, 47, 255 };
const Color green = { 171, 255, 191, 255 };
const Color red = { 255, 171, 171, 255 };
const Color orange = { 255, 207, 171, 255 };
const Color yellow = { 255, 252, 171, 255 };
const Color purple = { 207, 171, 255, 255 };
const Color cyan = { 171, 245, 255, 255 };
const Color blue = { 174, 171, 255, 255 };
const Color lightBlue = { 171, 198, 255, 255 };
const Color darkBlue = {108, 100, 219, 255 };

vector <Color> GetCellColors()
{
    //Function that returns all of the colours so a different file can use them
    return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}