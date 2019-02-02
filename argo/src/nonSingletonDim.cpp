//
// File: nonSingletonDim.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "nonSingletonDim.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
// Return Type  : int
//
int nonSingletonDim(const emxArray_real_T *x)
{
  int dim;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  return dim;
}

//
// File trailer for nonSingletonDim.cpp
//
// [EOF]
//
