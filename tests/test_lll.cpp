#include <NTL/ZZ.h>
#include <NTL/LLL.h>

using namespace std;
using namespace NTL;

int main()
{
    Mat<ZZ> b;
    b.SetDims(2, 2);
    b[0][0] = 11;
    b[0][1] = 0;
    b[1][0] = 2;
    b[1][1] = 1;
    ZZ det;

    LLL(det, b);

    cout << b << "\n";
}