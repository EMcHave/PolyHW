#include "HWfunctions.h"

////////////////////// 3RD HW ///////////////////////

BallisticMovement::BallisticMovement(char* inputFile)
    :wallHit(0), flyRight(true), isLanded(false), collided(false)
{
    readFile(inputFile);
    solution();
}

void BallisticMovement::readFile(char* path)
{

    std::ifstream in(path);
    if (in.is_open())
    {
        in >> h;
        in >> vx >> vy;

        walls.push_back(Wall{ 0, h });
        while (!in.eof())
        {
            Wall inWall;
            in >> inWall.x >> inWall.h;
            walls.push_back(inWall);
        }
    }
    else {
        throw std::runtime_error("No file!");
    }
}


double BallisticMovement::flyPath(double x)
{
    double v02 = vx * vx + vy * vy;
    double tan = vy / vx;
    return h + (x - walls.at(wallHit).x) * tan - (g * (x- walls.at(wallHit).x) * (x- walls.at(wallHit).x)) / (2 * v02) * (tan * tan + 1);
}

double* BallisticMovement::roots(double a, double b, double c, double move)
{

    double dis = sqrt(b*b - 4*a*c);
    double x1 = (-b - dis) / (2*a);
    double x2 = (-b + dis) / (2*a);

    double ar[2]{ x1 + move, x2 + move };
    return ar;
}


void BallisticMovement::solution()
{
    while (!isLanded)
    {

        if (flyRight) {
            for (int i = wallHit + 1; i < walls.size() - 1; i++)
                if (!collided)
                    flight(i);
        }
        else {
            for (int i = wallHit - 1; i >= 1; i--)
                if (!collided)
                    flight(i);
        }
        if (!collided)
            landing();
        else collided = false;
    }
}

void BallisticMovement::flight(int i)
{
    double temp = flyPath(walls[i].x);
    //std::cout << temp << std::endl;
    if (temp < walls[i].h && temp > 0)
    {
        
        collided = true;
        flyRight = !flyRight;
        h = temp;
        //std::cout << walls[i].x - walls[wallHit].x << std::endl;
        vy = vy - g * (walls[i].x - walls[wallHit].x) / vx;
        vx = -vx;
        wallHit = i;
        //std::cout << wallHit <<' ' << vx << ' ' << vy << ' ' << h << std::endl;
    }
}

void BallisticMovement::landing()
{
    isLanded = true;
    double v0 = vx * vx + vy * vy;
    double tan = vy / vx;
    int root;
    if (flyRight) root = 0;
    else root = 1;

    pointOfLanding = roots(-g / (2 * v0) * (tan * tan + 1), tan, h, walls[wallHit].x)[root];
}

void BallisticMovement::printAreaOfLanding()
{
    //std::cout << pointOfLanding << std::endl;
    for (int i = 0; i < walls.size() - 1; i++)
        if (pointOfLanding > walls[i].x && pointOfLanding < walls[i + 1].x)
        {
            std::cout << i << std::endl;
        }
    if (pointOfLanding > walls.at(walls.size()-1).x) std::cout << walls.size() - 1 << std::endl;
}

BallisticMovement::~BallisticMovement() {}



