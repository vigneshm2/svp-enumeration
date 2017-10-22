#include "knapsack.h"
#include "util.h"

int main()
{
    KnapSack k(10, 0.8);
    cout << k << "\n";

    Mat<ZZ> b;
    k.CJLOSS(b);
    printMat(b);
    return 0;
}