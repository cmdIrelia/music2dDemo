//
// File: issorted.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "issorted.h"

// Function Definitions

//
// Arguments    : const double x[25921]
// Return Type  : boolean_T
//
boolean_T issorted(const double x[25921])
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  double d1;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 25920)) {
    d1 = x[k + 1];
    if ((x[k] <= d1) || rtIsNaN(d1)) {
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
