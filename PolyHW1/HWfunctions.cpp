#include "HWfunctions.h"


////////////////////// 2ND HW ///////////////////////

Answer secondVar( const char* path)
{
    std::ifstream in(path);

    int sin, cos, x, y;
    in >> sin >> cos;

    int maxRight = 0;
    Point maxRightPoint{0,0};

    int maxLeft = -1;
    Point maxLeftPoint{0,0};

    while (in >> x >> y)
    {
        int dist = x * cos + y * (- sin);

        if (dist >= maxRight)
        {
            maxRight = dist;
            maxRightPoint = Point{ x, y };
        }
        else if (dist <= maxLeft)
        {
            maxLeft = dist;
            maxLeftPoint = Point{ x, y };
        }
    }

    return Answer{ maxLeftPoint, maxRightPoint }; 
}

Answer firstVar(const char* path)
{
    std::ifstream in(path);
    int sin, cos, x, y;

    in >> cos >> sin;

    float maxRight = 1; 
    Point maxRightPoint{0,0};

    float maxLeft = 1;
    Point maxLeftPoint{0,0};

    while (in >> x >> y)
    {
        int temp = x*sin + y*(-cos);
        float cs = (x * cos + y * sin) / (sqrt(x * x + y * y) * sqrt(cos * cos + sin * sin));
        
        if(cs <= maxRight && temp >= 0)
        {
            maxRight = cs;
            maxRightPoint = Point{ x, y };
        }
        if(cs <= maxLeft && temp < 0)
        { 
            maxLeft = cs;
            maxLeftPoint = Point{ x, y };
        }
    }
    
    return Answer{ maxLeftPoint, maxRightPoint };
}
/*
std::vector<Point> readFile(const char* path)
{   
    using namespace std;




    vector<Point> points;

    while(!in.eof())
    {
        Point inPoint;
        in >> inPoint.x >> inPoint.y;
        points.push_back(inPoint);
    }

    return points;
 
}
*/


///////////////////// 1ST HW /////////////////////


using namespace std;
int factorial(int n){
    if(n > 1)
        return n*factorial(n-1);
    else if(n < 0)
        cout << "Иди учи гамма функцию Эйлера";
    else
        return 1;
} 

int C_n_k(int n, int k){
    return factorial(n)/(factorial(k)*factorial(n-k));
}

double** funcValue(double x0, double xmax, double st, int& size, double (*fnc)(double))
{
    size = (xmax - x0)/st;
    double* x = new double[size]; 
    double* y = new double[size];

    for (int i = 0; i < size; i++)
    {
        x[i] = x0 + i*st;
        y[i] = fnc(x0 + i*st);
    }

    return new double*[2]{x, y};
}
