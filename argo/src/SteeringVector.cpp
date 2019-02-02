//
// File: SteeringVector.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "SteeringVector.h"
#include "steeringvec.h"

// Function Definitions

//
// Arguments    : const double angArg[322]
//                creal_T sv[644]
// Return Type  : void
//
void SteeringVector_stepImpl(const double angArg[322], creal_T sv[644])
{
  static const double dv6[12] = { 0.0, -0.25, 0.25, 0.0, -0.25, -0.25, 0.0, 0.25,
    0.25, 0.0, 0.25, -0.25 };

  steeringvec(dv6, angArg, sv);
}

//
// File trailer for SteeringVector.cpp
//
// [EOF]
//
