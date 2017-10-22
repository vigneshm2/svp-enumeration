#ifndef __UTIL_H
#define __UTIL_H 1

#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/matrix.h>
using namespace NTL;
using namespace std;

template <typename T>
void printMat(Mat<T> b)
{
    cout << "[";
    for (int i = 0; i < b.NumRows(); i++)
    {
        cout << "[";
        for (int j = 0; j < b.NumCols(); j++)
        {
            cout << b[i][j];
            if (j < b.NumCols() - 1)
                cout << ", ";
        }
        if (i < b.NumRows() - 1)
            cout << "],\n";
        else
            cout << "]]\n";
    }
}

#endif