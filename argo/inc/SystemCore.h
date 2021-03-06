//
// File: SystemCore.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//
#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "music2D_types.h"

// Function Declarations
extern void SystemCore_parenReference(phased_MUSICEstimator2D *obj, const
  creal_T varargin_1[4000], phased_URA *iobj_0, phased_IsotropicAntennaElement
  *iobj_1, double varargout_1[25921], double varargout_2[2]);
extern void SystemCore_step(c_phased_internal_SpatialCovEst *obj, const creal_T
  varargin_1[4000], creal_T varargout_1[16]);
extern void b_SystemCore_step(phased_SteeringVector *obj, const double
  varargin_2[322], phased_URA *iobj_0, phased_IsotropicAntennaElement *iobj_1,
  creal_T varargout_1[644]);

#endif

//
// File trailer for SystemCore.h
//
// [EOF]
//
