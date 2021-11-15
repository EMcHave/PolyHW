#include "HWfunctions.h"


using namespace std;

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        BallisticMovement solution(argv[1]);
        solution.printAreaOfLanding();
        return 0;
    }
    else {
        cerr << "WRONG ARGUMENTS" << endl;
        return 1;
    }
}

