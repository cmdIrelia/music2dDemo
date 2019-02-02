//
// File: abs.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "abs.h"
#include "music2D_rtwutil.h"

// Function Definitions

//
// Arguments    : const creal_T x[483]
//                double y[483]
// Return Type  : void
//
void b_abs(const creal_T x[483], double y[483])
{
  int k;
  for (k = 0; k < 483; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
