#include "LineSegment.h"

const double PI = 3.14159265359;

LineSegment::LineSegment(glm::vec2 p1, glm::vec2 p2)
{
    this->calculateAngle(p1, p2);
    this->calculateLenght();
    this->prepareFactors();
    this->preparePoints();
}

double LineSegment::calculateAngle(glm::vec2 p1, glm::vec2 p2)
{
    this->x = p2.x - p1.x;
    this->y = p2.y - p1.y;
    this->angle = glm::atan<double>(this->y, this->x);
    this->angleInDeg = this->angle * (180 / PI);

    return this->angle;
}

double LineSegment::calculateLenght()
{
    this->lenght = sqrt(this->x * this->x + this->y * this->y);
    return this->lenght;
}

double LineSegment::calculateLenght(glm::vec2 p1, glm::vec2 p2)
{
    float x = glm::sqrt(p1.x * p1.x + p2.x * p2.x);
    float y = glm::sqrt(p1.y * p1.y + p2.y * p2.y);

    return sqrt(x * x + y * y);
}

void LineSegment::prepareFactors()
{
    this->factor.x = cos(angle) / density;
    this->factor.y = sin(angle) / density;
}

bool LineSegment::preparePoints()
{
    if (!(this->lenght == 0))
    {
        this->pointQuantity = this->lenght * this->density;
        for (unsigned int i = 0; i <= this->pointQuantity; i++)
        {
            std::shared_ptr<TexturedModel> point(new TexturedModel({(float)(i * this->factor.x), (float)(i * this->factor.y)}));
            this->points.emplace_back(point);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
