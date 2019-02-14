//
// File: sortIdx.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//
#ifndef SORTIDX_H
#define SORTIDX_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void merge_block(int idx[25921], double x[25921], int offset, int n, int
  preSortLevel, int iwork[25921], double xwork[25921]);
extern void merge_pow2_block(int idx[25921], double x[25921], int offset);
extern void sortIdx(emxArray_real_T *x, emxArray_int32_T *idx);

#endif

//
// File trailer for sortIdx.h
//
// [EOF]
//
