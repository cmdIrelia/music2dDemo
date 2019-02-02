//
// File: all1.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "all1.h"

// Function Definitions

//
// Arguments    : const boolean_T x[284648]
//                boolean_T y[35581]
// Return Type  : void
//
void all(const boolean_T x[284648], boolean_T y[35581])
{
  int iy;
  int i1;
  int i2;
  int j;
  int ix;
  boolean_T exitg1;
  for (iy = 0; iy < 35581; iy++) {
    y[iy] = true;
  }

  iy = -1;
  i1 = 0;
  i2 = 249067;
  for (j = 0; j < 35581; j++) {
    i1++;
    i2++;
    iy++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!x[ix - 1]) {
        y[iy] = false;
        exitg1 = true;
      } else {
        ix += 35581;
      }
    }
  }
}

//
// File trailer for all1.cpp
//
// [EOF]
//
