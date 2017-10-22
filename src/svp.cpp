#include "svp.h"
#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/matrix.h>
#include <NTL/LLL.h>
using namespace NTL;
using namespace std;

int SVP_1_main(Vec<ZZ> &v, Mat<ZZ> &b, RR R, int n);

int SVP_1(Vec<ZZ> &a, Mat<ZZ> &b, RR R)
{
    // main code in SVP_1_main
    // this just convert output to lat vector
    Vec<ZZ> v;
    int n = b.NumRows();
    int succ = SVP_1_main(v, b, R, n);
    if (!succ)
        return succ;
    a.SetLength(n);
    for (int i = 0; i < n; i++)
    {
        a += v[i] * b[i];
    }
    return succ;
}

int SVP_1_main(Vec<ZZ> &v, Mat<ZZ> &b, RR R, int n)
{
    RR Rs = sqr(R);
    Mat<RR> gu;    // gs mu
    Vec<RR> gnorm; // gs norms
    ComputeGS(b, gu, gnorm);

    Vec<RR> norm, c;
    norm.SetLength(n + 1);
    c.SetLength(n);
    Vec<ZZ> w;
    v.SetLength(n);
    v[0] = 1;
    w.SetLength(n);
    int last_nz = 1, k = 1;

    while (true)
    {
        norm[k - 1] = norm[k] + sqr(conv<RR>(v[k - 1]) - c[k - 1]) * gnorm[k - 1];
        if (norm[k - 1] <= Rs)
        {
            if (k == 1)
            {
                return true;
            }
            else
            {
                k--;
                c[k - 1] = 0;
                for (int i = k + 1; i < n + 1; i++)
                    c[k - 1] -= conv<RR>(v[i - 1]) * gu[i - 1][k - 1];
                v[k - 1] = conv<ZZ>(round(c[k - 1]));
                w[k - 1] = 1;
            }
        }
        else
        {
            k++;
            if (k > n)
            {
                return 0;
            }
            if (k >= last_nz)
            {
                last_nz = k;
                v[k - 1] += 1;
            }
            else
            {
                if (conv<RR>(v[k - 1]) > c[k - 1])
                {
                    v[k - 1] -= w[k - 1];
                }
                else
                {
                    v[k - 1] += w[k - 1];
                }
                w[k - 1]++;
            }
        }
    }
}