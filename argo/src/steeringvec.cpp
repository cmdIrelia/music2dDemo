//
// File: steeringvec.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "steeringvec.h"
#include "elemdelay.h"

// Function Definitions

//
// Arguments    : const double pos[12]
//                const double ang[602]
//                creal_T sv[1204]
// Return Type  : void
//
void steeringvec(const double pos[12], const double ang[602], creal_T sv[1204])
{
  double dv10[1204];
  int k;
  double re;
  double im;
  double r;
  elemdelay(pos, ang, dv10);
  for (k = 0; k < 1204; k++) {
    re = dv10[k] * -0.0;
    im = dv10[k] * -1.8849555921538758E+9;
    sv[k].re = re;
    sv[k].im = im;
    if (im == 0.0) {
      re = exp(re);
      sv[k].re = re;
      sv[k].im = 0.0;
    } else {
      r = exp(re / 2.0);
      re = r * (r * cos(im));
      im = r * (r * sin(im));
      sv[k].re = re;
      sv[k].im = im;
    }
  }
}

//
// File trailer for steeringvec.cpp
//
// [EOF]
//
