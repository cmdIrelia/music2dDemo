//
// File: AbstractSpectralDOA.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//
#ifndef ABSTRACTSPECTRALDOA_H
#define ABSTRACTSPECTRALDOA_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void AbstractSpectralDOA_setupImpl(phased_MUSICEstimator2D *obj);
extern void c_AbstractSpectralDOA_privFindP(const double X[25921], double
  RowIndex_data[], int RowIndex_size[1], double ColIndex_data[], int
  ColIndex_size[1]);

#endif

//
// File trailer for AbstractSpectralDOA.h
//
// [EOF]
//
