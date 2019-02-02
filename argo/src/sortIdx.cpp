//
// File: sortIdx.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "sortIdx.h"
#include "music2D_emxutil.h"

// Function Declarations
static void b_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void b_merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void b_merge_pow2_block(emxArray_int32_T *idx, emxArray_real_T *x, int
  offset);
static void merge(int idx[25921], double x[25921], int offset, int np, int nq,
                  int iwork[25921], double xwork[25921]);

// Function Definitions

//
// Arguments    : emxArray_int32_T *idx
//                emxArray_real_T *x
//                int offset
//                int np
//                int nq
//                emxArray_int32_T *iwork
//                emxArray_real_T *xwork
// Return Type  : void
//
static void b_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i23;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i23 = offset + iout;
      iwork->data[iout] = idx->data[i23];
      xwork->data[iout] = x->data[i23];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] >= xwork->data[q]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[q];
        x->data[iout] = xwork->data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i23 = q + iout;
            idx->data[i23] = iwork->data[iout - 1];
            x->data[i23] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : emxArray_int32_T *idx
//                emxArray_real_T *x
//                int offset
//                int n
//                int preSortLevel
//                emxArray_int32_T *iwork
//                emxArray_real_T *xwork
// Return Type  : void
//
static void b_merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        b_merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      b_merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    b_merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

//
// Arguments    : emxArray_int32_T *idx
//                emxArray_real_T *x
//                int offset
// Return Type  : void
//
static void b_merge_pow2_block(emxArray_int32_T *idx, emxArray_real_T *x, int
  offset)
{
  int b;
  int bLen;
  int bLen2;
  int nPairs;
  int k;
  int blockOffset;
  int j;
  int p;
  int iout;
  int q;
  int iwork[256];
  double xwork[256];
  int exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 0; k < nPairs; k++) {
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx->data[iout];
        xwork[j] = x->data[iout];
      }

      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] >= xwork[q]) {
          idx->data[iout] = iwork[p];
          x->data[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx->data[iout] = iwork[q];
          x->data[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx->data[q] = iwork[j - 1];
              x->data[q] = xwork[j - 1];
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

//
// Arguments    : int idx[25921]
//                double x[25921]
//                int offset
//                int np
//                int nq
//                int iwork[25921]
//                double xwork[25921]
// Return Type  : void
//
static void merge(int idx[25921], double x[25921], int offset, int np, int nq,
                  int iwork[25921], double xwork[25921])
{
  int n_tmp;
  int iout;
  int p;
  int i20;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i20 = offset + iout;
      iwork[iout] = idx[i20];
      xwork[iout] = x[i20];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i20 = q + iout;
            idx[i20] = iwork[iout - 1];
            x[i20] = xwork[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : int idx[25921]
//                double x[25921]
//                int offset
//                int n
//                int preSortLevel
//                int iwork[25921]
//                double xwork[25921]
// Return Type  : void
//
void merge_block(int idx[25921], double x[25921], int offset, int n, int
                 preSortLevel, int iwork[25921], double xwork[25921])
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

//
// Arguments    : int idx[25921]
//                double x[25921]
//                int offset
// Return Type  : void
//
void merge_pow2_block(int idx[25921], double x[25921], int offset)
{
  int b;
  int bLen;
  int bLen2;
  int nPairs;
  int k;
  int blockOffset;
  int j;
  int p;
  int iout;
  int q;
  int iwork[256];
  double xwork[256];
  int exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 0; k < nPairs; k++) {
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx[iout];
        xwork[j] = x[iout];
      }

      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] <= xwork[q]) {
          idx[iout] = iwork[p];
          x[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[iout] = iwork[q];
          x[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx[q] = iwork[j - 1];
              x[q] = xwork[j - 1];
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

//
// Arguments    : emxArray_real_T *x
//                emxArray_int32_T *idx
// Return Type  : void
//
void sortIdx(emxArray_real_T *x, emxArray_int32_T *idx)
{
  short x_idx_0;
  int i22;
  int ib;
  int n;
  int b_n;
  double x4[4];
  short idx4[4];
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  int nNaNs;
  int k;
  signed char perm[4];
  int quartetOffset;
  int i1;
  int i3;
  int i4;
  double d8;
  double d9;
  x_idx_0 = (short)x->size[0];
  i22 = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T(idx, i22);
  ib = x_idx_0;
  for (i22 = 0; i22 < ib; i22++) {
    idx->data[i22] = 0;
  }

  if (x->size[0] != 0) {
    n = x->size[0];
    b_n = x->size[0];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    emxInit_int32_T(&iwork, 1);
    i22 = iwork->size[0];
    iwork->size[0] = x_idx_0;
    emxEnsureCapacity_int32_T(iwork, i22);
    ib = x_idx_0;
    for (i22 = 0; i22 < ib; i22++) {
      iwork->data[i22] = 0;
    }

    emxInit_real_T(&xwork, 1);
    x_idx_0 = (short)x->size[0];
    i22 = xwork->size[0];
    xwork->size[0] = x_idx_0;
    emxEnsureCapacity_real_T(xwork, i22);
    ib = x_idx_0;
    for (i22 = 0; i22 < ib; i22++) {
      xwork->data[i22] = 0.0;
    }

    nNaNs = 0;
    ib = -1;
    for (k = 0; k < b_n; k++) {
      if (rtIsNaN(x->data[k])) {
        i22 = (b_n - nNaNs) - 1;
        idx->data[i22] = k + 1;
        xwork->data[i22] = x->data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = (short)(k + 1);
        x4[ib] = x->data[k];
        if (ib + 1 == 4) {
          quartetOffset = k - nNaNs;
          if (x4[0] >= x4[1]) {
            i1 = 1;
            ib = 2;
          } else {
            i1 = 2;
            ib = 1;
          }

          if (x4[2] >= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }

          d8 = x4[i1 - 1];
          d9 = x4[i3 - 1];
          if (d8 >= d9) {
            if (x4[ib - 1] >= d9) {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i3;
              perm[3] = (signed char)i4;
            } else if (x4[ib - 1] >= x4[i4 - 1]) {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)ib;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)ib;
            }
          } else {
            d9 = x4[i4 - 1];
            if (d8 >= d9) {
              if (x4[ib - 1] >= d9) {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)i1;
                perm[2] = (signed char)ib;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)i1;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)ib;
              }
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)i4;
              perm[2] = (signed char)i1;
              perm[3] = (signed char)ib;
            }
          }

          i22 = perm[0] - 1;
          idx->data[quartetOffset - 3] = idx4[i22];
          i4 = perm[1] - 1;
          idx->data[quartetOffset - 2] = idx4[i4];
          i1 = perm[2] - 1;
          idx->data[quartetOffset - 1] = idx4[i1];
          ib = perm[3] - 1;
          idx->data[quartetOffset] = idx4[ib];
          x->data[quartetOffset - 3] = x4[i22];
          x->data[quartetOffset - 2] = x4[i4];
          x->data[quartetOffset - 1] = x4[i1];
          x->data[quartetOffset] = x4[ib];
          ib = -1;
        }
      }
    }

    i22 = (b_n - nNaNs) - 1;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
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

      for (k = 0; k <= ib; k++) {
        i4 = perm[k] - 1;
        i1 = (i22 - ib) + k;
        idx->data[i1] = idx4[i4];
        x->data[i1] = x4[i4];
      }
    }

    ib = (nNaNs >> 1) + 1;
    for (k = 0; k <= ib - 2; k++) {
      i1 = (i22 + k) + 1;
      i3 = idx->data[i1];
      i4 = (b_n - k) - 1;
      idx->data[i1] = idx->data[i4];
      idx->data[i4] = i3;
      x->data[i1] = xwork->data[i4];
      x->data[i4] = xwork->data[i1];
    }

    if ((nNaNs & 1) != 0) {
      i22 += ib;
      x->data[i22] = xwork->data[i22];
    }

    i3 = n - nNaNs;
    ib = 2;
    if (i3 > 1) {
      if (n >= 256) {
        i1 = i3 >> 8;
        if (i1 > 0) {
          for (ib = 0; ib < i1; ib++) {
            b_merge_pow2_block(idx, x, ib << 8);
          }

          ib = i1 << 8;
          i1 = i3 - ib;
          if (i1 > 0) {
            b_merge_block(idx, x, ib, i1, 2, iwork, xwork);
          }

          ib = 8;
        }
      }

      b_merge_block(idx, x, 0, i3, ib, iwork, xwork);
    }

    if ((nNaNs > 0) && (i3 > 0)) {
      for (k = 0; k < nNaNs; k++) {
        i22 = i3 + k;
        xwork->data[k] = x->data[i22];
        iwork->data[k] = idx->data[i22];
      }

      for (k = i3; k >= 1; k--) {
        i22 = (nNaNs + k) - 1;
        x->data[i22] = x->data[k - 1];
        idx->data[i22] = idx->data[k - 1];
      }

      for (k = 0; k < nNaNs; k++) {
        x->data[k] = xwork->data[k];
        idx->data[k] = iwork->data[k];
      }
    }

    emxFree_real_T(&xwork);
    emxFree_int32_T(&iwork);
  }
}

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
