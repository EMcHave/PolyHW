#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include "GJK.h"


int main()
{/*
    stringstream ss;
    string line = "";
    getline(cin, line, '\n');
    while (line != "END")
    {
        if (line == "RECTANGLE")
        {
            getline(cin, line, '\n');
            point p1, p2;
            ss << line << endl;
            ss >> p1.x >> p1.y;
            getline(cin, line, '\n');
            ss << line << std::endl;
            ss >> p2.x >> p2.y;
            getline(cin, line, '\n');
        }
        else if (line == "CIRCLE")
        {
            circle c;
            cin >> c.r;
            cin.ignore(10, '\n');
            getline(cin, line, '\n');
            ss << line << endl;
            ss >> c.x >> c.y;
            cout << c.r << ' ' << c.y << ' ' << c.x << endl;
            getline(cin, line, '\n');
        }
        else if (line == "POLYGON")
        {
            vector<float> v;
            getline(cin, line, '\n');
            while (line != "RECTANGLE" && line != "CIRCLE" && line != "POLYGON" && line != "END")
            {
                float n1, n2;
                ss << line << endl;
                ss >> n1 >> n2;
                v.push_back(n1);
                v.push_back(n2);
                getline(cin, line, '\n');
            }
        }
    }
    */
    vector<Simplex*> polygons;
    //polygons.push_back(new Polygon(vector<float>{-15, 4, -10, 5, -1, 3, -3, -2, -7, -6, -13, -3}));
    polygons.push_back(new Circle(3, 0, 4));
    polygons.push_back(new Rect(2, 8, 13, 0.5));



    bool i = Simplex::intersects(new Circle(3, 0, 4), new Rect(6, 8, 13, 0.5));

    cout << i << endl;

    return 0;
}