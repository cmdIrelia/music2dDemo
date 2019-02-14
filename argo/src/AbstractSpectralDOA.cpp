//
// File: AbstractSpectralDOA.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "AbstractSpectralDOA.h"
#include "music2D_emxutil.h"
#include "sort1.h"
#include "findpeaks2D.h"
#include "meshgrid.h"

// Function Definitions

//
// Arguments    : phased_MUSICEstimator2D *obj
// Return Type  : void
//
void AbstractSpectralDOA_setupImpl(phased_MUSICEstimator2D *obj)
{
  phased_URA *varargin_2;
  int i;
  double dv0[161];
  double dv1[161];
  static double ScanAz[25921];
  static double ScanEl[25921];
  obj->cCovEstimator.isInitialized = 0;
  obj->cCovEstimator.matlabCodegenIsDeleted = false;
  varargin_2 = obj->SensorArray;
  obj->cSteeringVector.isInitialized = 0;
  obj->cSteeringVector.SensorArray = varargin_2;
  obj->cSteeringVector.matlabCodegenIsDeleted = false;
  for (i = 0; i < 161; i++) {
    dv0[i] = -80.0 + (double)i;
    dv1[i] = -80.0 + (double)i;
  }

  meshgrid(dv0, dv1, ScanAz, ScanEl);
  for (i = 0; i < 25921; i++) {
    obj->pScanAngles[i << 1] = ScanAz[i];
  }

  for (i = 0; i < 25921; i++) {
    obj->pScanAngles[1 + (i << 1)] = ScanEl[i];
  }

  for (i = 0; i < 25921; i++) {
    obj->pPattern[i] = 0.0;
  }
}

//
// Arguments    : const double X[25921]
//                double RowIndex_data[]
//                int RowIndex_size[1]
//                double ColIndex_data[]
//                int ColIndex_size[1]
// Return Type  : void
//
void c_AbstractSpectralDOA_privFindP(const double X[25921], double
  RowIndex_data[], int RowIndex_size[1], double ColIndex_data[], int
  ColIndex_size[1])
{
  emxArray_int32_T *locs;
  static double xbk[25921];
  int idx;
  int jj;
  int ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *rows;
  unsigned char j_data[25921];
  emxArray_int32_T *b_idx;
  emxArray_real_T *x;
  emxInit_int32_T(&locs, 1);
  findpeaks2D(X, xbk);
  idx = 0;
  jj = locs->size[0];
  locs->size[0] = 25921;
  emxEnsureCapacity_int32_T(locs, jj);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 161)) {
    guard1 = false;
    if (xbk[(ii + 161 * (jj - 1)) - 1] != 0.0) {
      idx++;
      locs->data[idx - 1] = ii;
      j_data[idx - 1] = (unsigned char)jj;
      if (idx >= 25921) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 161) {
        ii = 1;
        jj++;
      }
    }
  }

  if (1 > idx) {
    locs->size[0] = 0;
  } else {
    jj = locs->size[0];
    locs->size[0] = idx;
    emxEnsureCapacity_int32_T(locs, jj);
  }

  emxInit_int32_T(&rows, 1);
  jj = rows->size[0];
  rows->size[0] = locs->size[0];
  emxEnsureCapacity_int32_T(rows, jj);
  ii = locs->size[0];
  for (jj = 0; jj < ii; jj++) {
    rows->data[jj] = locs->data[jj];
  }

  emxInit_int32_T(&b_idx, 1);
  jj = b_idx->size[0];
  b_idx->size[0] = rows->size[0];
  emxEnsureCapacity_int32_T(b_idx, jj);
  ii = rows->size[0];
  for (jj = 0; jj < ii; jj++) {
    b_idx->data[jj] = rows->data[jj] + 161 * (j_data[jj] - 1);
  }

  emxInit_real_T(&x, 1);
  jj = x->size[0];
  x->size[0] = b_idx->size[0];
  emxEnsureCapacity_real_T(x, jj);
  ii = b_idx->size[0];
  for (jj = 0; jj < ii; jj++) {
    x->data[jj] = X[b_idx->data[jj] - 1];
  }

  emxFree_int32_T(&b_idx);
  c_sort(x, locs);
  jj = x->size[0];
  x->size[0] = locs->size[0];
  emxEnsureCapacity_real_T(x, jj);
  ii = locs->size[0];
  for (jj = 0; jj < ii; jj++) {
    x->data[jj] = locs->data[jj];
  }

  ii = (int)fmin(1.0, (double)x->size[0]);
  if (1 > ii) {
    ii = -1;
  } else {
    ii = 0;
  }

  jj = locs->size[0];
  locs->size[0] = ii + 1;
  emxEnsureCapacity_int32_T(locs, jj);
  for (jj = 0; jj <= ii; jj++) {
    locs->data[0] = (int)x->data[0];
  }

  emxFree_real_T(&x);
  RowIndex_size[0] = locs->size[0];
  ii = locs->size[0];
  for (jj = 0; jj < ii; jj++) {
    RowIndex_data[jj] = rows->data[locs->data[jj] - 1];
  }

  emxFree_int32_T(&rows);
  ColIndex_size[0] = locs->size[0];
  ii = locs->size[0];
  for (jj = 0; jj < ii; jj++) {
    ColIndex_data[jj] = j_data[locs->data[jj] - 1];
  }

  emxFree_int32_T(&locs);
}

//
// File trailer for AbstractSpectralDOA.cpp
//
// [EOF]
//
