//
// File: anyNonFinite.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "anyNonFinite.h"

// Function Definitions

//
// Arguments    : const creal_T x[16]
// Return Type  : boolean_T
//
boolean_T anyNonFinite(const creal_T x[16])
{
  boolean_T p;
  int k;
  p = true;
  for (k = 0; k < 16; k++) {
    if (p && ((!rtIsInf(x[k].re)) && (!rtIsInf(x[k].im)) && ((!rtIsNaN(x[k].re))
          && (!rtIsNaN(x[k].im))))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

//
// File trailer for anyNonFinite.cpp
//
// [EOF]
//
