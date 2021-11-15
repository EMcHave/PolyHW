#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <vector>


struct Wall
{
    double x;
    double h;
};

/* 3rd HW*/
class BallisticMovement {
private:
    std::vector<Wall> walls;
    double vx;
    double vy;
    double h;
    const double g = 9.81;

    bool isLanded;
    bool flyRight;
    bool collided;

    double wallHit;
    int n;
    double pointOfLanding;

    void readFile(char*);
    static double* roots(double, double, double, double);
    double flyPath(double x);
    void checkCollision(int i);
    void landing();

    void solution();

public:
    BallisticMovement(char*);
    void printAreaOfLanding();
    ~BallisticMovement();
};
