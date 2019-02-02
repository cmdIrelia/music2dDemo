//
// File: SystemCore.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "SystemCore.h"
#include "SteeringVector.h"
#include "SpatialCovEstimator.h"
#include "MUSICEstimator2D.h"
#include "AbstractSpectralDOA.h"

// Function Declarations
static void SystemCore_setupAndReset(phased_MUSICEstimator2D *obj);

// Function Definitions

//
// Arguments    : phased_MUSICEstimator2D *obj
// Return Type  : void
//
static void SystemCore_setupAndReset(phased_MUSICEstimator2D *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  AbstractSpectralDOA_setupImpl(obj);
  obj->isSetupComplete = true;
}

//
// Arguments    : phased_MUSICEstimator2D *obj
//                const creal_T varargin_1[4000]
//                phased_URA *iobj_0
//                phased_IsotropicAntennaElement *iobj_1
//                double varargout_1[36421]
//                double varargout_2[2]
// Return Type  : void
//
void SystemCore_parenReference(phased_MUSICEstimator2D *obj, const creal_T
  varargin_1[4000], phased_URA *iobj_0, phased_IsotropicAntennaElement *iobj_1,
  double varargout_1[36421], double varargout_2[2])
{
  if (obj->isInitialized != 1) {
    SystemCore_setupAndReset(obj);
  }

  MUSICEstimator2D_stepImpl(obj, varargin_1, iobj_0, iobj_1, varargout_1,
    varargout_2);
}

//
// Arguments    : c_phased_internal_SpatialCovEst *obj
//                const creal_T varargin_1[4000]
//                creal_T varargout_1[16]
// Return Type  : void
//
void SystemCore_step(c_phased_internal_SpatialCovEst *obj, const creal_T
                     varargin_1[4000], creal_T varargout_1[16])
{
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;
  }

  SpatialCovEstimator_stepImpl(varargin_1, varargout_1);
}

//
// Arguments    : phased_SteeringVector *obj
//                const double varargin_2[602]
//                phased_URA *iobj_0
//                phased_IsotropicAntennaElement *iobj_1
//                creal_T varargout_1[1204]
// Return Type  : void
//
void b_SystemCore_step(phased_SteeringVector *obj, const double varargin_2[602],
  phased_URA *iobj_0, phased_IsotropicAntennaElement *iobj_1, creal_T
  varargout_1[1204])
{
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    iobj_0->Element = iobj_1;
    iobj_0->matlabCodegenIsDeleted = false;
    obj->cSensorArray = iobj_0;
    obj->isSetupComplete = true;
  }

  SteeringVector_stepImpl(varargin_2, varargout_1);
}

//
// File trailer for SystemCore.cpp
//
// [EOF]
//
