//
// File: sort1.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//
#ifndef SORT1_H
#define SORT1_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void b_sort(double x[36421], int idx[36421]);
extern void c_sort(emxArray_real_T *x, emxArray_int32_T *idx);
extern void sort(double x[4], int idx[4]);

#endif

//
// File trailer for sort1.h
//
// [EOF]
//
