#include "HWfunctions.h"

using namespace std;


int main()
{

    //vector<Point> points = readFile("in.txt");
    Answer res = firstVar("in.txt");

    cout << "Leftmost: " << res.left.x << ' ' << res.left.y << '\n' <<
            "Rightmost: " <<  res.right.x << ' ' << res.right.y << endl;
    return 0;
    
}
