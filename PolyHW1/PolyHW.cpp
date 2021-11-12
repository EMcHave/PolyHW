#include "HWfunctions.h"

using namespace std;


int main()
{
<<<<<<< HEAD
    //vector<Point> points = readFile("in.txt");
    Answer res = firstVar("in.txt");
=======

    //vector<Point> points = readFile("in.txt");
    Answer res = secondVar("in.txt");
>>>>>>> e8bc553fb87dcd7ebd3135bf6c8a8e45ac39a245

    cout << "Leftmost: " << res.left.x << ' ' << res.left.y << '\n' <<
            "Rightmost: " <<  res.right.x << ' ' << res.right.y << endl;
    return 0;
    
}
