//
// File: meshgrid.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "meshgrid.h"

// Function Definitions

//
// Arguments    : const double x[301]
//                const double y[121]
//                double xx[36421]
//                double yy[36421]
// Return Type  : void
//
void meshgrid(const double x[301], const double y[121], double xx[36421], double
              yy[36421])
{
  int j;
  int i;
  for (j = 0; j < 301; j++) {
    memcpy(&yy[j * 121], &y[0], 121U * sizeof(double));
    for (i = 0; i < 121; i++) {
      xx[i + 121 * j] = x[j];
    }
  }
}

//
// File trailer for meshgrid.cpp
//
// [EOF]
//
