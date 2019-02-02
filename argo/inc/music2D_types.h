//
// File: music2D_types.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//
#ifndef MUSIC2D_TYPES_H
#define MUSIC2D_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
typedef struct {
  unsigned int f1[8];
} cell_wrap_3;

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_3 inputVarSize[1];
} c_phased_internal_SpatialCovEst;

struct emxArray_int16_T
{
  short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_uint16_T
{
  unsigned short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

typedef struct {
  struct {
    int unusedExpr[36421];
  } f0;
} music2DTLS;

typedef struct {
  int __dummy;
} phased_IsotropicAntennaElement;

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  phased_IsotropicAntennaElement *Element;
} phased_URA;

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  boolean_T isSetupComplete;
  phased_URA *SensorArray;
  phased_URA *cSensorArray;
} phased_SteeringVector;

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_3 inputVarSize[1];
  phased_URA *SensorArray;
  c_phased_internal_SpatialCovEst cCovEstimator;
  double pPattern[36421];
  double pScanAngles[72842];
  phased_SteeringVector cSteeringVector;
} phased_MUSICEstimator2D;

#endif

//
// File trailer for music2D_types.h
//
// [EOF]
//
