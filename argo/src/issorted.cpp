//
// File: issorted.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "issorted.h"

// Function Definitions

//
// Arguments    : const double x[36421]
// Return Type  : boolean_T
//
boolean_T issorted(const double x[36421])
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  double d0;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 36420)) {
    d0 = x[k + 1];
    if ((x[k] <= d0) || rtIsNaN(d0)) {
    } else {
      y = false;
    }

    if (!y) {
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

//
// File trailer for issorted.cpp
//
// [EOF]
//
