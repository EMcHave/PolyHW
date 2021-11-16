#include "HWfunctions.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        BallisticMovement* solution = new BallisticMovement(argv[1]);
        solution->printAreaOfLanding();
        delete solution;
        return 0;
    }
    else {
        cerr << "WRONG ARGUMENTS" << endl;
        return 1;
    }
}

