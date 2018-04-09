#pragma once
#include "TexturedModel.h"
#include <vector>
#include <math.h>


struct Position{
    float x,y;
};

class LineSegment{

    private:    
    double calculateLenght(glm::vec2, glm::vec2);
    double calculateLenght();
    double calculateAngle(glm::vec2, glm::vec2);
    double calculateDensity(double angle);

    

    void prepareFactors();
    bool preparePoints();
    void updatePoints();

    public:
    double x,y;
    double angle, angleInDeg;
    double lenght;
    Position factor;
    double density=1000, pointQuantity;
    void SetAngle(double angle);
    void Update();
    LineSegment(glm::vec2 begin, glm::vec2 end);
    std::vector<std::shared_ptr<TexturedModel>> points;
    void Draw();
};
