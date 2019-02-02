//
// File: SpatialCovEstimator.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//
#ifndef SPATIALCOVESTIMATOR_H
#define SPATIALCOVESTIMATOR_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void SpatialCovEstimator_stepImpl(const creal_T X[4000], creal_T Sx[16]);

#endif

//
// File trailer for SpatialCovEstimator.h
//
// [EOF]
//
