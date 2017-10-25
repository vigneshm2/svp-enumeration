#ifndef __KNAPSACK_H
#define __KNAPSACK_H 1

#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/matrix.h>
using namespace NTL;
using namespace std;

class KnapSack
{
  public:
    int n;     // number of elements
    Vec<ZZ> a; // elements
    ZZ s;      // target sum
    KnapSack(int _n, Vec<ZZ> _a, ZZ _s);
    KnapSack(int _n, float d);

    void CJLOSS(Mat<ZZ> &b);
    double density();
};

inline ostream &operator<<(ostream &o, KnapSack k)
{
    o << "elements: " << k.a << " , target: " << k.s << ", density: " << k.density();
    return o;
}
#endif