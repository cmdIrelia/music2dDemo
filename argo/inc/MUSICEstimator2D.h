//
// File: MUSICEstimator2D.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//
#ifndef MUSICESTIMATOR2D_H
#define MUSICESTIMATOR2D_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void MUSICEstimator2D_stepImpl(phased_MUSICEstimator2D *obj, const
  creal_T X[4000], phased_URA *iobj_0, phased_IsotropicAntennaElement *iobj_1,
  double scanpattern[25921], double doasOut[2]);

#endif

//
// File trailer for MUSICEstimator2D.h
//
// [EOF]
//
