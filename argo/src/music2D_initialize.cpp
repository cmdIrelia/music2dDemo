//
// File: music2D_initialize.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "music2D_initialize.h"
#include "music2D_rtwutil.h"
#include "music2D_data.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void music2D_initialize()
{
  rt_InitInfAndNaN(8U);
  omp_init_nest_lock(&emlrtNestLockGlobal);
  emlrtInitThreadStackData();
}

//
// File trailer for music2D_initialize.cpp
//
// [EOF]
//
