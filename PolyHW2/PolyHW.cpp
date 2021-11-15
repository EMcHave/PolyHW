#include "HWfunctions.h"


using namespace std;

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        BallisticMovement solution(argv[1]);
        double pointOfLanding = solution.pointOfLanding;
        for (int i = 0; i < solution.walls.size() - 1; i++)
            if (pointOfLanding > solution.walls[i].x && pointOfLanding < solution.walls[i + 1].x)
            {
                std::cout << i << std::endl;
            }
        if (pointOfLanding > solution.walls.at(solution.walls.size() - 1).x)
            std::cout << solution.walls.size() - 1 << std::endl;
        if (pointOfLanding < 0)
            std::cout << 0 << std::endl;
        return 0;
    }
    else {
        cerr << "WRONG ARGUMENTS" << endl;
        return 1;
    }
}

