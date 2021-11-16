#include "HWfunctions.h"
#include <algorithm>

////////////////////// 3RD HW ///////////////////////

BallisticMovement::BallisticMovement(const char* inputFile)
    :wallHit(0), flyRight(true), isLanded(false), collided(false)
{
    readFile(inputFile);
    solution();
}

void BallisticMovement::readFile(const char* path)
{
    std::ifstream in(path);
    in >> h;
    in >> vx >> vy;

    walls.push_back(Wall{ 0, 0 });
    while (!in.eof())
    {
        Wall inWall;
        in >> inWall.x >> inWall.h;
        walls.push_back(inWall);
    }
    //std::sort(walls.begin(), walls.end(), [](Wall& w1, Wall& w2) {return w1.x < w2.x; });
}


double BallisticMovement::flyPath(double x)
{
    double v02 = vx * vx + vy * vy;
    double tan = vy / vx;
    return h + (x - walls.at(wallHit).x) * tan - (g * (x- walls.at(wallHit).x) * (x- walls.at(wallHit).x)) / (2 * v02) * (tan * tan + 1);
}

std::vector<double> BallisticMovement::roots(double a, double b, double c, double move)
{

    double dis = sqrt(b*b - 4*a*c);
    double x1 = (-b - dis) / (2*a);
    double x2 = (-b + dis) / (2*a);

    std::vector<double> ar{ x1 + move, x2 + move };
    
    return ar;
}


void BallisticMovement::solution()
{
    while (!isLanded)
    {
        if (flyRight) {
            for (int i = wallHit + 1; i < walls.size(); i++)
                if (!collided)
                    checkCollision(i);
        }
        else {
            for (int i = wallHit - 1; i >= 1; i--)
                if (!collided)
                    checkCollision(i);
        }
        if (!collided) landing();
        else collided = false;
    }
}

void BallisticMovement::checkCollision(int i)
{
    double temp = flyPath(walls[i].x);
    if (temp <= walls[i].h && temp >= 0)
    {
        collided = true;
        flyRight = !flyRight;
        h = temp;
        vy = vy - g * (walls[i].x - walls[wallHit].x) / vx;
        vx = -vx;
        wallHit = i;
        //std::cout << wallHit <<' '<< vx << ' ' << vy << ' ' << h << std::endl;
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
    for (size_t i = 0; i < walls.size() - 1; i++)
        if (pointOfLanding > walls[i].x && pointOfLanding < walls[i + 1].x)
        {
            std::cout << i << std::endl;
        }
    if (pointOfLanding > walls.at(walls.size() - 1).x)
        std::cout << walls.size() - 1 << std::endl;
    else if (pointOfLanding <= 0)
        std::cout << 0 << std::endl;
}

BallisticMovement::~BallisticMovement() {}
