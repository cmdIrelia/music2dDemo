//
// File: SteeringVector.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "SteeringVector.h"
#include "steeringvec.h"

// Function Definitions

//
// Arguments    : const double angArg[602]
//                creal_T sv[1204]
// Return Type  : void
//
void SteeringVector_stepImpl(const double angArg[602], creal_T sv[1204])
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
