//
// File: eps.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "eps.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : double
//
double eps()
{
  int exponent;
  frexp(1.0, &exponent);
  return 2.2204460492503131E-16;
}

//
// File trailer for eps.cpp
//
// [EOF]
//
