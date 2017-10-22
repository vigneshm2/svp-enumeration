#include "knapsack.h"
#include "util.h"
#include "svp.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

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

    auto t1 = Clock::now();
    int succ = SVP_1(v, b, r);
    auto t2 = Clock::now();
    if (succ)
    {
        cout << "SV: " << v << "\n";
    }
    else
    {
        cout << "None\n";
    }
    int t = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    cout << "Took " << t << "ms\n";
    return 0;
}