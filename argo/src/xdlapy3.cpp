//
// File: xdlapy3.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xdlapy3.h"

// Function Definitions

//
// Arguments    : double x1
//                double x2
//                double x3
// Return Type  : double
//
double xdlapy3(double x1, double x2, double x3)
{
  double y;
  double a;
  double b;
  double c;
  a = fabs(x1);
  b = fabs(x2);
  c = fabs(x3);
  y = fmax(a, b);
  if (c > y) {
    y = c;
  }

  if ((y > 0.0) && (!rtIsInf(y))) {
    a /= y;
    b /= y;
    c /= y;
    y *= sqrt((a * a + c * c) + b * b);
  } else {
    y = (a + b) + c;
  }

  return y;
}

//
// File trailer for xdlapy3.cpp
//
// [EOF]
//
