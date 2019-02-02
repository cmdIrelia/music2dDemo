//
// File: abs.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "abs.h"
#include "music2D_rtwutil.h"

// Function Definitions

//
// Arguments    : const creal_T x[903]
//                double y[903]
// Return Type  : void
//
void b_abs(const creal_T x[903], double y[903])
{
  int k;
  for (k = 0; k < 903; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
