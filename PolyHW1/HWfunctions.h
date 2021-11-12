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
<<<<<<< HEAD
Answer firstVar(const char* path);
=======
Answer firstVar(const std::vector<Point>& input);
>>>>>>> e8bc553fb87dcd7ebd3135bf6c8a8e45ac39a245
Answer secondVar(const char* path);
//std::vector<Point> readFile(const char* path);

/*  1st HW */
int factorial(int);
int C_n_k(int, int);
double** funcValue(double x0, double xmax, double st, int& size, double (*fnc)(double));