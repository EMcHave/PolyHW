#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include "GJK.h"


int main()
{
    vector<Simplex*> polygons;
    /*
    stringstream ss;
    string line = "";
    getline(cin, line, '\n');
    while (line != "END")
    {
        if (line == "RECTANGLE")
        {
            getline(cin, line, '\n');
            float f1, f2, f3, f4;
            ss << line << endl;
            ss >> f1 >> f2;
            getline(cin, line, '\n');
            ss << line << std::endl;
            ss >> f3 >> f4;
            polygons.push_back(new Rect(f1, f2, f3, f4));
            getline(cin, line, '\n');
        }
        else if (line == "CIRCLE")
        {
            float r, cx, cy;
            cin >> r;
            cin.ignore(10, '\n');
            getline(cin, line, '\n');
            ss << line << endl;
            ss >> cx >> cy;
            polygons.push_back(new Circle(r, cx, cy));
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
            polygons.push_back(new Polygon(v));
        }
    }
    */
    polygons.push_back(new Polygon(vector<float>{-15, 4, -10, 5, -1, 3, -3, -2, -7, -6, -13, 3}));
    polygons.push_back(new Circle(3, 0, 4));
    polygons.push_back(new Rect(2, 8, 13, 0.5));
    polygons.push_back(new Polygon(vector<float>{-3, 5, -3, 8, 4, 9}));
    polygons.push_back(new Circle(1, -1, 1));
    polygons.push_back(new Rect(1, -1, 5, -5));



    for (size_t i = 0; i < polygons.size(); i++)
        for (size_t j = 0; j < polygons.size(); j++)
            if (i != j)
                if (Simplex::intersects(polygons[i], polygons[j]))
                    cout << i << ' ' << j << endl;
    return 0;
}