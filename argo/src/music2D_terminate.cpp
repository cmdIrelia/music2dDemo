//
// File: music2D_terminate.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "music2D_terminate.h"
#include "music2D_rtwutil.h"
#include "music2D_data.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void music2D_terminate()
{
  emlrtFreeThreadStackData();
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

//
// File trailer for music2D_terminate.cpp
//
// [EOF]
//
