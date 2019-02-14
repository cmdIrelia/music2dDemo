//
// File: isequal.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "isequal.h"

// Function Definitions

//
// Arguments    : const double varargin_1[25281]
//                const double varargin_2[25281]
// Return Type  : boolean_T
//
boolean_T isequal(const double varargin_1[25281], const double varargin_2[25281])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 25281)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

//
// File trailer for isequal.cpp
//
// [EOF]
//
