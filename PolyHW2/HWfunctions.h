#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <vector>

struct Point{
    int x;
    int y;
};

struct Answer
{
    Point left;
    Point right;        
};

struct Wall
{
    double x;
    double h;
};

struct System
{
    double startHeight;
    Wall* walls;
    double vx;
    double vy;
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
    void flight(int i);
    void landing();

    void solution();

public:
    BallisticMovement(char*);
    void printAreaOfLanding();
    ~BallisticMovement();
};

/* 2nd HW */
Answer firstVar(Point* input, int n);
Answer secondVar(Point* in, int n);
Point* readFile(char* path, int& n);

/*  1st HW */
int factorial(int);
int C_n_k(int, int);
double** funcValue(double x0, double xmax, double st, int& size, double (*fnc)(double));