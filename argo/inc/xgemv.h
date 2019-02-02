//
// File: xgemv.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//
#ifndef XGEMV_H
#define XGEMV_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void xgemv(int m, int n, const creal_T A[16], int ia0, const creal_T x[16],
                  int ix0, creal_T y[4]);

#endif

//
// File trailer for xgemv.h
//
// [EOF]
//
