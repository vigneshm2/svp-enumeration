#include "knapsack.h"
#include "util.h"
#include "svp.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>

void cjloss_svp(int argc, char *argv[])
{
    SetSeed(conv<ZZ>(101010));

    int n = 20;
    if (argc > 1)
        n = atoi(argv[1]);
    KnapSack k(n, 0.8);
    cout << k << "\n";
    Mat<ZZ> b;
    k.CJLOSS(b);
    printMat(b);

    Vec<ZZ> v;
    RR r = conv<RR>(sqrt(n + 1));
    cout << "r: " << r << "\n";

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
}

void svp1_time_data(int argc, char *argv[])
{
    // find times for [l..u] and output
    int l = atoi(argv[1]);
    int u = atoi(argv[2]);
    for (int i = l; i <= u; i++)
    {
        // cout << "at " << i << "\n";
        KnapSack k(i, 0.8);
        Mat<ZZ> b;
        k.CJLOSS(b);
        Vec<ZZ> v;
        RR r = conv<RR>(sqrt(i + 1));

        double t1 = clock();
        int succ = SVP_1(v, b, r);
        double t2 = clock();

        double t = (t2 - t1) / CLOCKS_PER_SEC;
        printf("%d, %.6f\n", i, t);
    }
}

int main(int argc, char *argv[])
{
    // svp1_time_data(argc, argv);
    cjloss_svp(argc, argv);
    return 0;
}