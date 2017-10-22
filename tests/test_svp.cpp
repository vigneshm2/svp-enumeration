#include "knapsack.h"
#include "util.h"
#include "svp.h"

int main()
{
    SetSeed(conv<ZZ>(101010));

    int n = 10;
    KnapSack k(n, 0.8);
    cout << k << "\n";
    Mat<ZZ> b;
    k.CJLOSS(b);
    printMat(b);

    Vec<ZZ> v;
    RR r = conv<RR>(sqrt(n));
    int succ = SVP_1(v, b, r);
    if (succ)
    {
        cout << "SV: " << v << "\n";
    }
    else
    {
        cout << "None\n";
    }
    return 0;
}