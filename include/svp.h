#ifndef __SVP_H
#define __SVP_H 1

#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <NTL/matrix.h>
using namespace NTL;
using namespace std;

int SVP_1(Vec<ZZ> &a, Mat<ZZ> &b, RR R);

#endif