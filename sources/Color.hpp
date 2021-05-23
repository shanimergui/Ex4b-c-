#pragma once

#include <unordered_map>
#include <string>
using namespace std;
enum Color {Blue,Yellow,Black,Red};



static unordered_map< Color,string > colors =
{
        {Color::Blue,"Blue"},
        {Color::Yellow,"Yellow"},
        {Color::Black,"Black"},
        {Color::Red,"Red"}
};
