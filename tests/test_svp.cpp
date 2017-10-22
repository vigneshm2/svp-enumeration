#include "knapsack.h"
#include "util.h"
#include "svp.h"
#include <ctime>

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

    double t1 = clock();
    int succ = SVP_1(v, b, r);
    double t2 = clock();
    if (succ)
    {
        cout << "SV: " << v << "\n";
    }
    else
    {
        cout << "None\n";
    }
    double t = (t2 - t1) / CLOCKS_PER_SEC;
    cout << "Took " << t << "s\n";
    return 0;
}