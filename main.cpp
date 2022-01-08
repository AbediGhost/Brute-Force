#include "AlgoPrincipal.h"

using namespace std;

int main()
{
    int abedi = 12345;
    std::string test;
    test.append(abedi,sizeof(abedi));
    std::cout <<abedi;
    getch();
    BruteCrack ghost;
    ghost.Run();
    return 0;
}
