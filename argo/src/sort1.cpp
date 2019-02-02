//
// File: sort1.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "sort1.h"
#include "music2D_emxutil.h"
#include "sortIdx.h"
#include "nonSingletonDim.h"

// Function Definitions

//
// Arguments    : double x[36421]
//                int idx[36421]
// Return Type  : void
//
void b_sort(double x[36421], int idx[36421])
{
  double x4[4];
  unsigned short idx4[4];
  static double xwork[36421];
  int nNaNs;
  int ib;
  int k;
  signed char perm[4];
  int i2;
  int quartetOffset;
  int i3;
  static int iwork[36421];
  int i4;
  double d5;
  double d6;
  memset(&idx[0], 0, 36421U * sizeof(int));
  x4[0] = 0.0;
  idx4[0] = 0U;
  x4[1] = 0.0;
  idx4[1] = 0U;
  x4[2] = 0.0;
  idx4[2] = 0U;
  x4[3] = 0.0;
  idx4[3] = 0U;
  memset(&xwork[0], 0, 36421U * sizeof(double));
  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 36421; k++) {
    if (rtIsNaN(x[k])) {
      idx[36420 - nNaNs] = k + 1;
      xwork[36420 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (unsigned short)(k + 1);
      x4[ib - 1] = x[k];
      if (ib == 4) {
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          ib = 1;
          i2 = 2;
        } else {
          ib = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        d5 = x4[ib - 1];
        d6 = x4[i3 - 1];
        if (d5 <= d6) {
          if (x4[i2 - 1] <= d6) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i2;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (x4[i2 - 1] <= x4[i4 - 1]) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          d6 = x4[i4 - 1];
          if (d5 <= d6) {
            if (x4[i2 - 1] <= d6) {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i2;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)i2;
            }
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i4;
            perm[2] = (signed char)ib;
            perm[3] = (signed char)i2;
          }
        }

        i3 = perm[0] - 1;
        idx[quartetOffset - 3] = idx4[i3];
        i4 = perm[1] - 1;
        idx[quartetOffset - 2] = idx4[i4];
        ib = perm[2] - 1;
        idx[quartetOffset - 1] = idx4[ib];
        i2 = perm[3] - 1;
        idx[quartetOffset] = idx4[i2];
        x[quartetOffset - 3] = x4[i3];
        x[quartetOffset - 2] = x4[i4];
        x[quartetOffset - 1] = x4[ib];
        x[quartetOffset] = x4[i2];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 0; k < ib; k++) {
      i3 = perm[k] - 1;
      i4 = ((k - nNaNs) - ib) + 36421;
      idx[i4] = idx4[i3];
      x[i4] = x4[i3];
    }
  }

  i2 = (nNaNs >> 1) + 36421;
  for (k = 0; k <= i2 - 36422; k++) {
    ib = (k - nNaNs) + 36421;
    i3 = idx[ib];
    idx[ib] = idx[36420 - k];
    idx[36420 - k] = i3;
    x[ib] = xwork[36420 - k];
    x[36420 - k] = xwork[ib];
  }

  if ((nNaNs & 1) != 0) {
    ib = i2 - nNaNs;
    x[ib] = xwork[ib];
  }

  memset(&iwork[0], 0, 36421U * sizeof(int));
  ib = 2;
  if (36421 - nNaNs > 1) {
    i2 = (36421 - nNaNs) >> 8;
    if (i2 > 0) {
      for (ib = 0; ib < i2; ib++) {
        merge_pow2_block(idx, x, ib << 8);
      }

      ib = i2 << 8;
      i2 = 36421 - (nNaNs + ib);
      if (i2 > 0) {
        merge_block(idx, x, ib, i2, 2, iwork, xwork);
      }

      ib = 8;
    }

    merge_block(idx, x, 0, 36421 - nNaNs, ib, iwork, xwork);
  }
}

//
// Arguments    : emxArray_real_T *x
//                emxArray_int32_T *idx
// Return Type  : void
//
void c_sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i20;
  emxArray_real_T *vwork;
  int vlen;
  int j;
  unsigned short x_idx_0;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = nonSingletonDim(x);
  if (dim <= 1) {
    i20 = x->size[0];
  } else {
    i20 = 1;
  }

  emxInit_real_T(&vwork, 1);
  vlen = i20 - 1;
  j = vwork->size[0];
  vwork->size[0] = (unsigned short)i20;
  emxEnsureCapacity_real_T(vwork, j);
  x_idx_0 = (unsigned short)x->size[0];
  i20 = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T(idx, i20);
  vstride = 1;
  for (k = 0; k <= dim - 2; k++) {
    vstride *= x->size[0];
  }

  emxInit_int32_T(&iidx, 1);
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i20 = j + k * vstride;
      x->data[i20] = vwork->data[k];
      idx->data[i20] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

//
// Arguments    : double x[4]
//                int idx[4]
// Return Type  : void
//
void sort(double x[4], int idx[4])
{
  double x4[4];
  int idx4[4];
  double xwork[4];
  int nNaNs;
  int ib;
  int quartetOffset;
  signed char perm[4];
  int i2;
  int i3;
  int i4;
  double d3;
  double d4;
  idx[0] = 0;
  x4[0] = 0.0;
  idx4[0] = 0;
  xwork[0] = 0.0;
  idx[1] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  xwork[1] = 0.0;
  idx[2] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  xwork[2] = 0.0;
  idx[3] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  xwork[3] = 0.0;
  nNaNs = 0;
  ib = 0;
  if (rtIsNaN(x[0])) {
    idx[3] = 1;
    xwork[3] = x[0];
    nNaNs = 1;
  } else {
    ib = 1;
    idx4[0] = 1;
    x4[0] = x[0];
  }

  if (rtIsNaN(x[1])) {
    idx[3 - nNaNs] = 2;
    xwork[3 - nNaNs] = x[1];
    nNaNs++;
  } else {
    ib++;
    idx4[ib - 1] = 2;
    x4[ib - 1] = x[1];
  }

  if (rtIsNaN(x[2])) {
    idx[3 - nNaNs] = 3;
    xwork[3 - nNaNs] = x[2];
    nNaNs++;
  } else {
    ib++;
    idx4[ib - 1] = 3;
    x4[ib - 1] = x[2];
  }

  if (rtIsNaN(x[3])) {
    idx[3 - nNaNs] = 4;
    xwork[3 - nNaNs] = x[3];
    nNaNs++;
  } else {
    ib++;
    idx4[ib - 1] = 4;
    x4[ib - 1] = x[3];
    if (ib == 4) {
      quartetOffset = 3 - nNaNs;
      if (x4[0] >= x4[1]) {
        ib = 1;
        i2 = 2;
      } else {
        ib = 2;
        i2 = 1;
      }

      if (x4[2] >= x4[3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      d3 = x4[ib - 1];
      d4 = x4[i3 - 1];
      if (d3 >= d4) {
        if (x4[i2 - 1] >= d4) {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (x4[i2 - 1] >= x4[i4 - 1]) {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i2;
          perm[3] = (signed char)i4;
        } else {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i4;
          perm[3] = (signed char)i2;
        }
      } else {
        d4 = x4[i4 - 1];
        if (d3 >= d4) {
          if (x4[i2 - 1] >= d4) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)ib;
          perm[3] = (signed char)i2;
        }
      }

      i3 = perm[0] - 1;
      idx[quartetOffset - 3] = idx4[i3];
      i4 = perm[1] - 1;
      idx[quartetOffset - 2] = idx4[i4];
      ib = perm[2] - 1;
      idx[quartetOffset - 1] = idx4[ib];
      i2 = perm[3] - 1;
      idx[quartetOffset] = idx4[i2];
      x[quartetOffset - 3] = x4[i3];
      x[quartetOffset - 2] = x4[i4];
      x[quartetOffset - 1] = x4[ib];
      x[quartetOffset] = x4[i2];
      ib = 0;
    }
  }

  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      i3 = perm[quartetOffset] - 1;
      i4 = ((quartetOffset - nNaNs) - ib) + 4;
      idx[i4] = idx4[i3];
      x[i4] = x4[i3];
    }
  }

  ib = (nNaNs >> 1) + 4;
  for (quartetOffset = 0; quartetOffset <= ib - 5; quartetOffset++) {
    i3 = (quartetOffset - nNaNs) + 4;
    i2 = idx[i3];
    idx[i3] = idx[3 - quartetOffset];
    idx[3 - quartetOffset] = i2;
    x[i3] = xwork[3 - quartetOffset];
    x[3 - quartetOffset] = xwork[i3];
  }

  if ((nNaNs & 1) != 0) {
    ib -= nNaNs;
    x[ib] = xwork[ib];
  }

  idx4[0] = 0;
  idx4[1] = 0;
  idx4[2] = 0;
  idx4[3] = 0;
  i3 = 4 - nNaNs;
  if ((nNaNs > 0) && (4 - nNaNs > 0)) {
    for (quartetOffset = 0; quartetOffset < nNaNs; quartetOffset++) {
      ib = (quartetOffset - nNaNs) + 4;
      xwork[quartetOffset] = x[ib];
      idx4[quartetOffset] = idx[ib];
    }

    for (quartetOffset = i3; quartetOffset >= 1; quartetOffset--) {
      ib = (nNaNs + quartetOffset) - 1;
      x[ib] = x[quartetOffset - 1];
      idx[ib] = idx[quartetOffset - 1];
    }

    memcpy(&x[0], &xwork[0], (unsigned int)(nNaNs * (int)sizeof(double)));
    memcpy(&idx[0], &idx4[0], (unsigned int)(nNaNs * (int)sizeof(int)));
  }
}

//
// File trailer for sort1.cpp
//
// [EOF]
//
