#pragma once
#include "DisplayMenager.h"
#include "LineSegment.h"
#include <vector>
#include <memory>

class Grid
{
    
    float _size;
    void prepareLines();

  public:
    Grid(float size);
    std::vector<std::shared_ptr<LineSegment>> verticalLines;
    std::vector<std::shared_ptr<LineSegment>> horizontalLines;
};