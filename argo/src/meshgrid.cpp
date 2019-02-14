//
// File: meshgrid.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "meshgrid.h"

// Function Definitions

//
// Arguments    : const double x[161]
//                const double y[161]
//                double xx[25921]
//                double yy[25921]
// Return Type  : void
//
void meshgrid(const double x[161], const double y[161], double xx[25921], double
              yy[25921])
{
  int j;
  int i;
  for (j = 0; j < 161; j++) {
    memcpy(&yy[j * 161], &y[0], 161U * sizeof(double));
    for (i = 0; i < 161; i++) {
      xx[i + 161 * j] = x[j];
    }
  }
}

//
// File trailer for meshgrid.cpp
//
// [EOF]
//
