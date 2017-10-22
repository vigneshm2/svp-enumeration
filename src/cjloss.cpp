#include <NTL/ZZ.h>
#include "knapsack.h"

using namespace NTL;
using namespace std;

KnapSack::KnapSack(int _n, Vec<ZZ> _a, ZZ _s) : n(_n), a(_a), s(_s) {}
KnapSack::KnapSack(int _n, float d) : n(_n)
{
    // random knapsack with density < d
    // number of elements in sum  = n/2
    a.SetLength(n);
    int logA = (int)(n / d) + 1;
    ZZ asum;
    int n2 = (n >> 1);
    for (int i = 0; i < n; i++)
    {
        RandomBits(a[i], logA);
        asum += a[i];
    }

    // reservoir sample n2 elements
    Vec<ZZ> e;
    e.SetLength(n2);
    for (int i = 0; i < n2; i++)
        e[i] = a[i];
    for (int j = n2; j < n; j++)
    {
        int idx = RandomBnd(j + 1);
        if (idx < n2)
        {
            e[idx] = a[j];
        }
    }

    for (int i = 0; i < n2; i++)
        s += e[i];
    if (s < asum - s)
        s = asum - s;
    // cout << e;
}

void KnapSack::CJLOSS(Mat<ZZ> &b)
{
    ZZ N = SqrRoot(conv<ZZ>(n)) + 1;
    //
    b.SetDims(n + 1, n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        if (i < n)
        {
            // 0,...,2,...,Na_i
            b[i][i] = 2;
            b[i][n] = N * a[i];
        }
        else
        {
            // 1,1,....,Ns
            for (int j = 0; j < n; j++)
                b[i][j] = 1;
            b[i][n] = N * s;
        }
    }
}