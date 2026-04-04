#include "Colors.h"

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

std::vector<Color> GetCellColors()
{
    return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}