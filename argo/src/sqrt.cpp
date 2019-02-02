//
// File: sqrt.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "sqrt.h"
#include "abs.h"
#include "music2D_rtwutil.h"

// Function Definitions

//
// Arguments    : creal_T *x
// Return Type  : void
//
void b_sqrt(creal_T *x)
{
  double xr;
  double xi;
  double yr;
  double absxr;
  xr = x->re;
  xi = x->im;
  if (xi == 0.0) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = sqrt(-xr);
    } else {
      yr = sqrt(xr);
      xr = 0.0;
    }
  } else if (xr == 0.0) {
    if (xi < 0.0) {
      yr = sqrt(-xi / 2.0);
      xr = -yr;
    } else {
      yr = sqrt(xi / 2.0);
      xr = yr;
    }
  } else if (rtIsNaN(xr)) {
    yr = xr;
  } else if (rtIsNaN(xi)) {
    yr = xi;
    xr = xi;
  } else if (rtIsInf(xi)) {
    yr = fabs(xi);
    xr = xi;
  } else if (rtIsInf(xr)) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = xi * -xr;
    } else {
      yr = xr;
      xr = 0.0;
    }
  } else {
    absxr = fabs(xr);
    yr = fabs(xi);
    if ((absxr > 4.4942328371557893E+307) || (yr > 4.4942328371557893E+307)) {
      absxr *= 0.5;
      yr = rt_hypotd_snf(absxr, yr * 0.5);
      if (yr > absxr) {
        yr = sqrt(yr) * sqrt(1.0 + absxr / yr);
      } else {
        yr = sqrt(yr) * 1.4142135623730951;
      }
    } else {
      yr = sqrt((rt_hypotd_snf(absxr, yr) + absxr) * 0.5);
    }

    if (xr > 0.0) {
      xr = 0.5 * (xi / yr);
    } else {
      if (xi < 0.0) {
        xr = -yr;
      } else {
        xr = yr;
      }

      yr = 0.5 * (xi / xr);
    }
  }

  x->re = yr;
  x->im = xr;
}

//
// Arguments    : double x[36421]
// Return Type  : void
//
void c_sqrt(double x[36421])
{
  int k;
  for (k = 0; k < 36421; k++) {
    x[k] = sqrt(x[k]);
  }
}

//
// File trailer for sqrt.cpp
//
// [EOF]
//
