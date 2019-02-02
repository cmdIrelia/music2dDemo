//
// File: music2D_rtwutil.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//
#ifndef MUSIC2D_RTWUTIL_H
#define MUSIC2D_RTWUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void emlrtFreeThreadStackData();
extern music2DTLS *emlrtGetThreadStackData();
extern void emlrtInitThreadStackData();
extern double rt_hypotd_snf(double u0, double u1);
extern double rt_remd_snf(double u0, double u1);

#endif

//
// File trailer for music2D_rtwutil.h
//
// [EOF]
//
