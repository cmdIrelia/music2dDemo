//
// File: sum.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "sum.h"

// Function Definitions

//
// Arguments    : const double x[36421]
//                double y[301]
// Return Type  : void
//
void b_sum(const double x[36421], double y[301])
{
  int i;
  int xpageoffset;
  int k;
  for (i = 0; i < 301; i++) {
    xpageoffset = i * 121;
    y[i] = x[xpageoffset];
    for (k = 0; k < 120; k++) {
      y[i] += x[(xpageoffset + k) + 1];
    }
  }
}

//
// Arguments    : const double x[301]
// Return Type  : double
//
double c_sum(const double x[301])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 300; k++) {
    y += x[k + 1];
  }

  return y;
}

//
// Arguments    : const boolean_T x[36421]
//                double y[301]
// Return Type  : void
//
void d_sum(const boolean_T x[36421], double y[301])
{
  int i;
  int xpageoffset;
  int k;
  for (i = 0; i < 301; i++) {
    xpageoffset = i * 121;
    y[i] = x[xpageoffset];
    for (k = 0; k < 120; k++) {
      y[i] += (double)x[(xpageoffset + k) + 1];
    }
  }
}

//
// Arguments    : const double x[903]
//                double y[301]
// Return Type  : void
//
void sum(const double x[903], double y[301])
{
  int k;
  int xoffset;
  int j;
  memcpy(&y[0], &x[0], 301U * sizeof(double));
  for (k = 0; k < 2; k++) {
    xoffset = (k + 1) * 301;
    for (j = 0; j < 301; j++) {
      y[j] += x[xoffset + j];
    }
  }
}

//
// File trailer for sum.cpp
//
// [EOF]
//
