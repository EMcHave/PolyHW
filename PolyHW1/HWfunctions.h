#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <vector>
#include <climits>
#include <float.h>

struct Point{
    int x;
    int y;
};

struct Answer
{
    Point left;

    Point right;        
};


/* 2nd HW */

Answer firstVar(const char* path);
Answer secondVar(const char* path);
//std::vector<Point> readFile(const char* path);

/*  1st HW */
int factorial(int);
int C_n_k(int, int);
double** funcValue(double x0, double xmax, double st, int& size, double (*fnc)(double));