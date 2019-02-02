//
// File: cosd.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "cosd.h"
#include "sind.h"
#include "music2D_rtwutil.h"

// Function Definitions

//
// Arguments    : double x[301]
// Return Type  : void
//
void b_cosd(double x[301])
{
  int k;
  double b_x;
  double absx;
  signed char n;
  for (k = 0; k < 301; k++) {
    if (rtIsInf(x[k]) || rtIsNaN(x[k])) {
      x[k] = rtNaN;
    } else {
      b_x = rt_remd_snf(x[k], 360.0);
      absx = fabs(b_x);
      if (absx > 180.0) {
        if (b_x > 0.0) {
          b_x -= 360.0;
        } else {
          b_x += 360.0;
        }

        absx = fabs(b_x);
      }

      if (absx <= 45.0) {
        b_x *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (b_x > 0.0) {
          b_x = 0.017453292519943295 * (b_x - 90.0);
          n = 1;
        } else {
          b_x = 0.017453292519943295 * (b_x + 90.0);
          n = -1;
        }
      } else if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 180.0);
        n = 2;
      } else {
        b_x = 0.017453292519943295 * (b_x + 180.0);
        n = -2;
      }

      if (n == 0) {
        x[k] = cos(b_x);
      } else if (n == 1) {
        x[k] = -sin(b_x);
      } else if (n == -1) {
        x[k] = sin(b_x);
      } else {
        x[k] = -cos(b_x);
      }
    }
  }
}

//
// File trailer for cosd.cpp
//
// [EOF]
//
