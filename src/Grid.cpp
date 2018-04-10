#include "Grid.h"

Grid::Grid(float size)
{
    this->_size = size;
    this->prepareLines();
}

void Grid::prepareLines()
{
    for (int i = -1-this->_size; i < 1; i+=this->_size){
       // std::shared_ptr<LineSegment> vline(new LineSegment({i, 1}, {i,-1}));
        //this->verticalLines.emplace_back(vline);        
    }
}