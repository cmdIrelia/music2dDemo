//
// File: sum.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "sum.h"

// Function Definitions

//
// Arguments    : const double x[25921]
//                double y[161]
// Return Type  : void
//
void b_sum(const double x[25921], double y[161])
{
  int i;
  int xpageoffset;
  int k;
  for (i = 0; i < 161; i++) {
    xpageoffset = i * 161;
    y[i] = x[xpageoffset];
    for (k = 0; k < 160; k++) {
      y[i] += x[(xpageoffset + k) + 1];
    }
  }
}

//
// Arguments    : const double x[161]
// Return Type  : double
//
double c_sum(const double x[161])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 160; k++) {
    y += x[k + 1];
  }

  return y;
}

//
// Arguments    : const boolean_T x[25921]
//                double y[161]
// Return Type  : void
//
void d_sum(const boolean_T x[25921], double y[161])
{
  int i;
  int xpageoffset;
  int k;
  for (i = 0; i < 161; i++) {
    xpageoffset = i * 161;
    y[i] = x[xpageoffset];
    for (k = 0; k < 160; k++) {
      y[i] += (double)x[(xpageoffset + k) + 1];
    }
  }
}

//
// Arguments    : const double x[483]
//                double y[161]
// Return Type  : void
//
void sum(const double x[483], double y[161])
{
  int k;
  int xoffset;
  int j;
  memcpy(&y[0], &x[0], 161U * sizeof(double));
  for (k = 0; k < 2; k++) {
    xoffset = (k + 1) * 161;
    for (j = 0; j < 161; j++) {
      y[j] += x[xoffset + j];
    }
  }
}

//
// File trailer for sum.cpp
//
// [EOF]
//
