//
// File: sind.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "sind.h"
#include "music2D_rtwutil.h"

// Function Definitions

//
// Arguments    : double x[161]
// Return Type  : void
//
void b_sind(double x[161])
{
  int k;
  double b_x;
  double absx;
  signed char n;
  for (k = 0; k < 161; k++) {
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
        x[k] = sin(b_x);
      } else if (n == 1) {
        x[k] = cos(b_x);
      } else if (n == -1) {
        x[k] = -cos(b_x);
      } else {
        x[k] = -sin(b_x);
      }
    }
  }
}

//
// File trailer for sind.cpp
//
// [EOF]
//
