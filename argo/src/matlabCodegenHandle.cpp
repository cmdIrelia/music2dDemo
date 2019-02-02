//
// File: matlabCodegenHandle.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "matlabCodegenHandle.h"

// Function Definitions

//
// Arguments    : phased_URA *obj
// Return Type  : void
//
void c_matlabCodegenHandle_matlabCod(phased_URA *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }
}

//
// Arguments    : phased_MUSICEstimator2D *obj
// Return Type  : void
//
void d_matlabCodegenHandle_matlabCod(phased_MUSICEstimator2D *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      if (obj->isSetupComplete) {
        if (obj->cSteeringVector.isInitialized == 1) {
          obj->cSteeringVector.isInitialized = 2;
        }

        if (obj->cCovEstimator.isInitialized == 1) {
          obj->cCovEstimator.isInitialized = 2;
        }
      }
    }
  }
}

//
// Arguments    : c_phased_internal_SpatialCovEst *obj
// Return Type  : void
//
void e_matlabCodegenHandle_matlabCod(c_phased_internal_SpatialCovEst *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }
}

//
// Arguments    : phased_SteeringVector *obj
// Return Type  : void
//
void f_matlabCodegenHandle_matlabCod(phased_SteeringVector *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }
}

//
// File trailer for matlabCodegenHandle.cpp
//
// [EOF]
//
