#include "HWfunctions.h"
#include <memory>

using namespace std;

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        unique_ptr<BallisticMovement> solution(new BallisticMovement(argv[1]));

        solution->printAreaOfLanding();

        cin.clear();
        cin.ignore(1024, '\n');

        return 0;
    }
    else {
        cerr << "WRONG ARGUMENTS" << endl;
        return 1;
    }
}

