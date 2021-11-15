#include "HWfunctions.h"
#include <memory>
#include <chrono>

using namespace std;

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        /*
        using std::chrono::high_resolution_clock;
        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::milliseconds;
        */
        //auto t1 = high_resolution_clock::now();
        BallisticMovement solution(argv[1]);
        //unique_ptr<BallisticMovement> solution(new BallisticMovement("in.txt"));
        //auto t2 = high_resolution_clock::now();

        /* Getting number of milliseconds as a double. */
        //duration<double, std::milli> ms_double = t2 - t1;

        //cout << ms_double.count() << endl;

        solution.printAreaOfLanding();
        return 0;
    }
    else {
        cerr << "WRONG ARGUMENTS" << endl;
        return 1;
    }
}

