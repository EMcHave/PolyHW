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
    const int MAX = 10;
    char buffer[MAX];
    std::ifstream in(path);
    if (in.is_open())
    {
        while (!in.eof())
        {
            in.getline(buffer, MAX);
            n++;
        }
        in.seekg(0);
        in >> h;
        in >> vx >> vy;

        walls.push_back(Wall{ 0, h });
        n = 1;
        while (!in.eof())
        {
            Wall inWall;
            in >> inWall.x >> inWall.h;
            walls.push_back(inWall);
            n++;
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
        if (flyRight)
            for (int i = wallHit + 1; i < n; i++)
                if (!collided)
                    flight(i);
        else
            for (int i = wallHit - 1; i >= 1; i--)
                if (!collided)
                    flight(i);
        if (!collided)
            landing();
        else collided = false;
    }
}

void BallisticMovement::flight(int i)
{
    double temp = flyPath(walls[i].x);
    if (temp < walls[i].h && temp > 0)
    {
        collided = true;
        flyRight = !flyRight;
        wallHit = i;
        h = temp;
        vy = vy - g * walls[i].x / vx;
        vx = -vx;
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
    for (int i = 0; i < n - 1; i++)
        if (pointOfLanding > walls[i].x && pointOfLanding < walls[i + 1].x)
        {
            std::cout << "Area of landing: " << i << std::endl;
        }
    if (pointOfLanding > walls.at(walls.size()-1).x) std::cout << "Area of landing: " << n << std::endl;
}

BallisticMovement::~BallisticMovement() {}


////////////////////// 2ND HW ///////////////////////

Answer firstVar(Point* input, int n)
{
    /* расстояние d = x*cos(a) + b*sin(a) ; x,y - точка, cos(a), sin(a) - компоненты нормали 
    к направляющему вектору прямой разделяющей плооскость 
    d > 0 - точка справа от прямой, d < 0 - точка слева*/
    double sin = -input[0].x/sqrt(input[0].x*input[0].x + input[0].y*input[0].y);
    double cos = input[0].y/sqrt(input[0].x*input[0].x + input[0].y*input[0].y);

    
    double maxRight = 0;
    Point maxRightPoint{0,0};

    double maxLeft = 0;
    Point maxLeftPoint{0,0};

    for (int i = 1; i < n; i++)
    {
        double dist = input[i].x*cos + input[i].y*sin;

        if (dist > maxRight)
        {
            maxRight = dist;
            maxRightPoint = input[i];
        }
        else if (dist <= maxLeft)
        {
            maxLeft = dist;
            maxLeftPoint = input[i];
        }
    }

    return Answer {maxLeftPoint, maxRightPoint};
}

Answer secondVar(Point* in, int n)
{
    double cos = in[0].x/sqrt(in[0].x*in[0].x + in[0].y*in[0].y);
    double sin = in[0].y/sqrt(in[0].x*in[0].x + in[0].y*in[0].y);
    
    double maxRight = 1;
    Point maxRightPoint{0,0};

    double maxLeft = 1;
    Point maxLeftPoint{0,0};

    for( int i = 1; i < n; i++)
    {
        double temp = in[i].x*sin + in[i].y*(-cos);
        double cs = (in[i].x*cos + in[i].y*sin)/sqrt(in[i].x*in[i].x + in[i].y*in[i].y);

        if(cs <= maxRight && temp >= 0)
        {
            maxRight = cs;
            maxRightPoint = in[i];   
        }
        else if(cs <= maxLeft && temp < 0)
        {
            maxLeft = cs;
            maxLeftPoint = in[i];
        }
    }
    return Answer{maxLeftPoint, maxRightPoint};
}

Point* readFile(char* path, int& n)
{   
    const int MAX = 10;
    char buffer[MAX];
    std::ifstream in(path);
    if(in.is_open())
    {
        while(!in.eof())
        {
            in.getline(buffer, MAX);
            n++;
        }

        

        Point* points = new Point[n-1];
        n = 0;
        in.seekg(0);
        while(!in.eof())
        {
            Point inPoint;
            in >> inPoint.x >> inPoint.y;
            points[n] = inPoint;
            n++;
        }

        return points;
    }
    else {
        throw std::runtime_error("No file!");
    }    
}



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
