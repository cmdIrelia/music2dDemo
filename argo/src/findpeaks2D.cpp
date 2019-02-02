//
// File: findpeaks2D.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "findpeaks2D.h"
#include "sum.h"
#include "isequal.h"
#include "music2D_emxutil.h"
#include "ismember.h"
#include "all1.h"

// Function Definitions

//
// Arguments    : const double X[25921]
//                double peakmatrix[25921]
// Return Type  : void
//
void findpeaks2D(const double X[25921], double peakmatrix[25921])
{
  int i10;
  unsigned char a_tmp[159];
  int i11;
  static double a[25281];
  static boolean_T connectmatrix[202248];
  boolean_T bv0[25281];
  static double b_connectmatrix[202248];
  int connectposs_tmp;
  int connectmatrix_tmp;
  static double multipeakmatrix[25921];
  static double possmatrix[25921];
  int xOffset;
  int idx;
  double b_tmp;
  double dv11[161];
  static double possmatrixsave[25921];
  static signed char connectposs[202248];
  boolean_T b_possmatrix[25921];
  double dv12[161];
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T c_AllAdjacentPositiveAreNotEqua;
  boolean_T PositiveValues_flag;
  emxArray_real_T *nextInfRows;
  emxArray_uint8_T *nextInfCols;
  emxArray_uint16_T *r0;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_real_T *r7;
  boolean_T guard1 = false;
  unsigned char j_data[25921];
  short tmp_data[25921];
  static double b_connectposs[227529];
  static double finishtestmin_tmp[25281];
  double d0;
  static double finishtestmin[25281];
  double dv13[161];
  double dv14[161];
  memset(&peakmatrix[0], 0, 25921U * sizeof(double));
  for (i10 = 0; i10 < 159; i10++) {
    a_tmp[i10] = (unsigned char)(2U + i10);
  }

  for (i10 = 0; i10 < 159; i10++) {
    for (i11 = 0; i11 < 159; i11++) {
      a[i11 + 159 * i10] = X[(a_tmp[i11] + 161 * (a_tmp[i10] - 1)) - 1];
    }
  }

  for (i10 = 0; i10 < 159; i10++) {
    a_tmp[i10] = (unsigned char)(1U + i10);
  }

  for (i10 = 0; i10 < 159; i10++) {
    for (i11 = 0; i11 < 159; i11++) {
      connectposs_tmp = i11 + 159 * i10;
      b_connectmatrix[connectposs_tmp] = a[connectposs_tmp] - X[(a_tmp[i11] +
        161 * (a_tmp[i10] - 1)) - 1];
      connectmatrix_tmp = i11 + 161 * (1 + i10);
      b_connectmatrix[25281 + connectposs_tmp] = a[connectposs_tmp] -
        X[connectmatrix_tmp];
      xOffset = i11 + 161 * (2 + i10);
      b_connectmatrix[50562 + connectposs_tmp] = a[connectposs_tmp] - X[xOffset];
      idx = i11 + 161 * i10;
      b_connectmatrix[75843 + connectposs_tmp] = a[connectposs_tmp] - X[idx + 1];
      b_connectmatrix[101124 + connectposs_tmp] = a[connectposs_tmp] - X[xOffset
        + 1];
      b_connectmatrix[126405 + connectposs_tmp] = a[connectposs_tmp] - X[idx + 2];
      b_connectmatrix[151686 + connectposs_tmp] = a[connectposs_tmp] -
        X[connectmatrix_tmp + 2];
      b_connectmatrix[176967 + connectposs_tmp] = a[connectposs_tmp] - X[xOffset
        + 2];
    }
  }

  for (i10 = 0; i10 < 202248; i10++) {
    connectmatrix[i10] = (b_connectmatrix[i10] > 0.0);
  }

  all(connectmatrix, bv0);
  for (i10 = 0; i10 < 159; i10++) {
    for (i11 = 0; i11 < 159; i11++) {
      peakmatrix[(i11 + 161 * (1 + i10)) + 1] = bv0[i11 + 159 * i10];
    }
  }

  memset(&multipeakmatrix[0], 0, 25921U * sizeof(double));
  memset(&possmatrix[0], 0, 25921U * sizeof(double));
  memcpy(&a[0], &b_connectmatrix[0], 25281U * sizeof(double));
  for (connectmatrix_tmp = 0; connectmatrix_tmp < 7; connectmatrix_tmp++) {
    xOffset = (connectmatrix_tmp + 1) * 25281;
    for (idx = 0; idx < 25281; idx++) {
      b_tmp = b_connectmatrix[xOffset + idx];
      if ((!rtIsNaN(b_tmp)) && (rtIsNaN(a[idx]) || (a[idx] > b_tmp))) {
        a[idx] = b_tmp;
      }
    }
  }

  for (i10 = 0; i10 < 159; i10++) {
    for (i11 = 0; i11 < 159; i11++) {
      possmatrix[(i11 + 161 * (1 + i10)) + 1] = (a[i11 + 159 * i10] == 0.0);
    }
  }

  for (connectmatrix_tmp = 0; connectmatrix_tmp < 25921; connectmatrix_tmp++) {
    b_tmp = possmatrix[connectmatrix_tmp];
    if (X[connectmatrix_tmp] == rtMinusInf) {
      b_tmp = 0.0;
    }

    possmatrixsave[connectmatrix_tmp] = b_tmp;
    possmatrix[connectmatrix_tmp] = b_tmp;
  }

  b_sum(possmatrix, dv11);
  if (c_sum(dv11) > 0.0) {
    for (i10 = 0; i10 < 159; i10++) {
      for (i11 = 0; i11 < 159; i11++) {
        xOffset = i11 + 159 * i10;
        idx = i11 + 161 * i10;
        connectposs[xOffset] = (signed char)possmatrix[idx];
        connectmatrix_tmp = i11 + 161 * (1 + i10);
        connectposs[25281 + xOffset] = (signed char)possmatrix[connectmatrix_tmp];
        connectposs_tmp = i11 + 161 * (2 + i10);
        connectposs[50562 + xOffset] = (signed char)possmatrix[connectposs_tmp];
        connectposs[75843 + xOffset] = (signed char)possmatrix[idx + 1];
        connectposs[101124 + xOffset] = (signed char)possmatrix[connectposs_tmp
          + 1];
        connectposs[126405 + xOffset] = (signed char)possmatrix[idx + 2];
        connectposs[151686 + xOffset] = (signed char)
          possmatrix[connectmatrix_tmp + 2];
        connectposs[176967 + xOffset] = (signed char)possmatrix[connectposs_tmp
          + 2];
      }
    }

    for (connectmatrix_tmp = 0; connectmatrix_tmp < 202248; connectmatrix_tmp++)
    {
      b_tmp = b_connectmatrix[connectmatrix_tmp];
      if (connectposs[connectmatrix_tmp] == 1) {
        b_tmp = 1.0;
      }

      connectmatrix[connectmatrix_tmp] = (b_tmp > 0.0);
      b_connectmatrix[connectmatrix_tmp] = b_tmp;
    }

    all(connectmatrix, bv0);
    for (i10 = 0; i10 < 159; i10++) {
      for (i11 = 0; i11 < 159; i11++) {
        connectmatrix_tmp = (i11 + 161 * (1 + i10)) + 1;
        possmatrix[connectmatrix_tmp] = -possmatrix[connectmatrix_tmp] + 2.0 *
          (double)bv0[i11 + 159 * i10];
      }
    }

    for (i10 = 0; i10 < 25921; i10++) {
      b_tmp = possmatrix[i10] * possmatrixsave[i10];
      b_possmatrix[i10] = (b_tmp > 0.0);
      possmatrix[i10] = b_tmp;
    }

    d_sum(b_possmatrix, dv12);
    if (c_sum(dv12) > 0.0) {
      emxInit_int32_T(&ii, 1);
      idx = 0;
      i10 = ii->size[0];
      ii->size[0] = 25921;
      emxEnsureCapacity_int32_T(ii, i10);
      connectmatrix_tmp = 0;
      exitg1 = false;
      while ((!exitg1) && (connectmatrix_tmp < 25921)) {
        if (possmatrix[connectmatrix_tmp] == 1.0) {
          idx++;
          ii->data[idx - 1] = connectmatrix_tmp + 1;
          if (idx >= 25921) {
            exitg1 = true;
          } else {
            connectmatrix_tmp++;
          }
        } else {
          connectmatrix_tmp++;
        }
      }

      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        i10 = ii->size[0];
        ii->size[0] = idx;
        emxEnsureCapacity_int32_T(ii, i10);
      }

      connectmatrix_tmp = ii->size[0];
      for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
        possmatrix[ii->data[i10] - 1] = ii->data[i10];
      }

      c_AllAdjacentPositiveAreNotEqua = true;
      PositiveValues_flag = true;
      for (i10 = 0; i10 < 25921; i10++) {
        possmatrixsave[i10] = possmatrix[i10];
        multipeakmatrix[i10] = 0.0;
      }

      emxInit_real_T(&nextInfRows, 1);
      emxInit_uint8_T(&nextInfCols, 1);
      emxInit_uint16_T(&r0, 2);
      emxInit_int32_T(&r1, 2);
      emxInit_int32_T(&r2, 2);
      emxInit_int32_T(&r3, 2);
      emxInit_int32_T(&r4, 2);
      emxInit_int32_T(&r5, 2);
      emxInit_int32_T(&r6, 2);
      emxInit_real_T(&r7, 1);
      while (PositiveValues_flag && c_AllAdjacentPositiveAreNotEqua) {
        idx = 0;
        i10 = ii->size[0];
        ii->size[0] = 25921;
        emxEnsureCapacity_int32_T(ii, i10);
        connectmatrix_tmp = 1;
        xOffset = 1;
        exitg1 = false;
        while ((!exitg1) && (xOffset <= 161)) {
          guard1 = false;
          if (possmatrix[(connectmatrix_tmp + 161 * (xOffset - 1)) - 1] == -1.0)
          {
            idx++;
            ii->data[idx - 1] = connectmatrix_tmp;
            j_data[idx - 1] = (unsigned char)xOffset;
            if (idx >= 25921) {
              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            connectmatrix_tmp++;
            if (connectmatrix_tmp > 161) {
              connectmatrix_tmp = 1;
              xOffset++;
            }
          }
        }

        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          i10 = ii->size[0];
          ii->size[0] = idx;
          emxEnsureCapacity_int32_T(ii, i10);
        }

        i10 = nextInfRows->size[0];
        nextInfRows->size[0] = ii->size[0] << 3;
        emxEnsureCapacity_real_T(nextInfRows, i10);
        connectmatrix_tmp = ii->size[0] << 3;
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[i10] = 0.0;
        }

        i10 = nextInfCols->size[0];
        nextInfCols->size[0] = ii->size[0] << 3;
        emxEnsureCapacity_uint8_T(nextInfCols, i10);
        connectmatrix_tmp = ii->size[0] << 3;
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[i10] = 0U;
        }

        if (1 > ii->size[0]) {
          i10 = 0;
        } else {
          i10 = ii->size[0];
        }

        connectmatrix_tmp = (short)i10 - 1;
        for (i11 = 0; i11 <= connectmatrix_tmp; i11++) {
          tmp_data[i11] = (short)i11;
        }

        connectmatrix_tmp = (short)i10;
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[tmp_data[i10]] = (double)ii->data[i10] - 1.0;
        }

        if (1 > ii->size[0]) {
          i10 = 0;
        } else {
          i10 = ii->size[0];
        }

        connectmatrix_tmp = (short)i10 - 1;
        for (i11 = 0; i11 <= connectmatrix_tmp; i11++) {
          tmp_data[i11] = (short)i11;
        }

        connectmatrix_tmp = (short)i10;
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[tmp_data[i10]] = (unsigned char)(j_data[i10] - 1U);
        }

        i10 = ii->size[0] << 1;
        if (ii->size[0] + 1 > i10) {
          i11 = 1;
          i10 = 0;
        } else {
          i11 = ii->size[0] + 1;
        }

        connectposs_tmp = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        connectmatrix_tmp = (unsigned short)i10 - (unsigned short)i11;
        r0->size[1] = connectmatrix_tmp + 1;
        emxEnsureCapacity_uint16_T(r0, connectposs_tmp);
        for (i10 = 0; i10 <= connectmatrix_tmp; i10++) {
          r0->data[i10] = (unsigned short)((unsigned short)((unsigned int)
            (unsigned short)i11 + i10) - 1U);
        }

        connectmatrix_tmp = r0->size[0] * r0->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[r0->data[i10]] = (double)ii->data[i10] - 1.0;
        }

        i10 = ii->size[0] << 1;
        if (ii->size[0] + 1 > i10) {
          i11 = 1;
          i10 = 0;
        } else {
          i11 = ii->size[0] + 1;
        }

        connectposs_tmp = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        connectmatrix_tmp = (unsigned short)i10 - (unsigned short)i11;
        r0->size[1] = connectmatrix_tmp + 1;
        emxEnsureCapacity_uint16_T(r0, connectposs_tmp);
        for (i10 = 0; i10 <= connectmatrix_tmp; i10++) {
          r0->data[i10] = (unsigned short)((unsigned short)((unsigned int)
            (unsigned short)i11 + i10) - 1U);
        }

        connectmatrix_tmp = r0->size[0] * r0->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[r0->data[i10]] = j_data[i10];
        }

        i10 = (ii->size[0] << 1) + 1;
        i11 = 3 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r1->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r1, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r1->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r1->size[0] * r1->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[r1->data[i10]] = (double)ii->data[i10] - 1.0;
        }

        i10 = (ii->size[0] << 1) + 1;
        i11 = 3 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r1->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r1, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r1->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r1->size[0] * r1->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[r1->data[i10]] = (unsigned char)(j_data[i10] + 1U);
        }

        i10 = 3 * ii->size[0] + 1;
        i11 = ii->size[0] << 2;
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r2->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r2, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r2->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r2->size[0] * r2->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[r2->data[i10]] = ii->data[i10];
        }

        i10 = 3 * ii->size[0] + 1;
        i11 = ii->size[0] << 2;
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r2->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r2, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r2->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r2->size[0] * r2->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[r2->data[i10]] = (unsigned char)(j_data[i10] - 1U);
        }

        i10 = (ii->size[0] << 2) + 1;
        i11 = 5 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r3->size[0] * r3->size[1];
        r3->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r3->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r3, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r3->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r3->size[0] * r3->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[r3->data[i10]] = ii->data[i10];
        }

        i10 = (ii->size[0] << 2) + 1;
        i11 = 5 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r3->size[0] * r3->size[1];
        r3->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r3->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r3, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r3->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r3->size[0] * r3->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[r3->data[i10]] = (unsigned char)(j_data[i10] + 1U);
        }

        i10 = 5 * ii->size[0] + 1;
        i11 = 6 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r4->size[0] * r4->size[1];
        r4->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r4->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r4, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r4->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r4->size[0] * r4->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[r4->data[i10]] = (double)ii->data[i10] + 1.0;
        }

        i10 = 5 * ii->size[0] + 1;
        i11 = 6 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r4->size[0] * r4->size[1];
        r4->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r4->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r4, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r4->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r4->size[0] * r4->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[r4->data[i10]] = (unsigned char)(j_data[i10] - 1U);
        }

        i10 = 6 * ii->size[0] + 1;
        i11 = 7 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r5->size[0] * r5->size[1];
        r5->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r5->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r5, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r5->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r5->size[0] * r5->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[r5->data[i10]] = (double)ii->data[i10] + 1.0;
        }

        i10 = 6 * ii->size[0] + 1;
        i11 = 7 * ii->size[0];
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r5->size[0] * r5->size[1];
        r5->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r5->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r5, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r5->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r5->size[0] * r5->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[r5->data[i10]] = j_data[i10];
        }

        i10 = 7 * ii->size[0] + 1;
        i11 = ii->size[0] << 3;
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r6->size[0] * r6->size[1];
        r6->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r6->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r6, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r6->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r6->size[0] * r6->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[r6->data[i10]] = (double)ii->data[i10] + 1.0;
        }

        i10 = 7 * ii->size[0] + 1;
        i11 = ii->size[0] << 3;
        if (i10 > i11) {
          i10 = 0;
          i11 = 0;
        } else {
          i10--;
        }

        connectposs_tmp = r6->size[0] * r6->size[1];
        r6->size[0] = 1;
        connectmatrix_tmp = i11 - i10;
        r6->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r6, connectposs_tmp);
        for (i11 = 0; i11 < connectmatrix_tmp; i11++) {
          r6->data[i11] = i10 + i11;
        }

        connectmatrix_tmp = r6->size[0] * r6->size[1];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfCols->data[r6->data[i10]] = (unsigned char)(j_data[i10] + 1U);
        }

        i10 = nextInfRows->size[0];
        emxEnsureCapacity_real_T(nextInfRows, i10);
        connectmatrix_tmp = nextInfRows->size[0];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          nextInfRows->data[i10] = (int)nextInfRows->data[i10] + 161 *
            (nextInfCols->data[i10] - 1);
        }

        i10 = r7->size[0];
        r7->size[0] = nextInfRows->size[0];
        emxEnsureCapacity_real_T(r7, i10);
        connectmatrix_tmp = nextInfRows->size[0];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r7->data[i10] = -(double)(possmatrix[(int)nextInfRows->data[i10] - 1] >
            0.0);
        }

        connectmatrix_tmp = r7->size[0];
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          possmatrix[(int)nextInfRows->data[i10] - 1] = r7->data[i10];
        }

        for (i10 = 0; i10 < 159; i10++) {
          for (i11 = 0; i11 < 159; i11++) {
            xOffset = i11 + 159 * i10;
            idx = i11 + 161 * i10;
            b_connectposs[xOffset] = possmatrix[idx];
            connectmatrix_tmp = i11 + 161 * (1 + i10);
            b_connectposs[25281 + xOffset] = possmatrix[connectmatrix_tmp];
            connectposs_tmp = i11 + 161 * (2 + i10);
            b_connectposs[50562 + xOffset] = possmatrix[connectposs_tmp];
            b_connectposs[75843 + xOffset] = possmatrix[idx + 1];
            b_connectposs[101124 + xOffset] = possmatrix[connectposs_tmp + 1];
            b_connectposs[126405 + xOffset] = possmatrix[idx + 2];
            b_connectposs[151686 + xOffset] = possmatrix[connectmatrix_tmp + 2];
            b_connectposs[176967 + xOffset] = possmatrix[connectposs_tmp + 2];
            b_connectposs[202248 + xOffset] = possmatrix[connectmatrix_tmp + 1];
          }
        }

        memcpy(&a[0], &b_connectposs[0], 25281U * sizeof(double));
        for (connectmatrix_tmp = 0; connectmatrix_tmp < 8; connectmatrix_tmp++)
        {
          xOffset = (connectmatrix_tmp + 1) * 25281;
          for (idx = 0; idx < 25281; idx++) {
            d0 = b_connectposs[xOffset + idx];
            if (a[idx] < d0) {
              a[idx] = d0;
            }
          }
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 227529;
             connectmatrix_tmp++) {
          b_tmp = b_connectposs[connectmatrix_tmp];
          if (b_connectposs[connectmatrix_tmp] <= 0.0) {
            b_tmp = rtInf;
          }

          b_connectposs[connectmatrix_tmp] = b_tmp;
        }

        memcpy(&finishtestmin_tmp[0], &b_connectposs[0], 25281U * sizeof(double));
        for (connectmatrix_tmp = 0; connectmatrix_tmp < 8; connectmatrix_tmp++)
        {
          xOffset = (connectmatrix_tmp + 1) * 25281;
          for (idx = 0; idx < 25281; idx++) {
            d0 = b_connectposs[xOffset + idx];
            if (finishtestmin_tmp[idx] > d0) {
              finishtestmin_tmp[idx] = d0;
            }
          }
        }

        memcpy(&finishtestmin[0], &finishtestmin_tmp[0], 25281U * sizeof(double));
        for (i10 = 0; i10 < 159; i10++) {
          for (i11 = 0; i11 < 159; i11++) {
            bv0[i11 + 159 * i10] = (possmatrix[(i11 + 161 * (1 + i10)) + 1] <=
              0.0);
          }
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 25281; connectmatrix_tmp
             ++) {
          if (bv0[connectmatrix_tmp]) {
            a[connectmatrix_tmp] = 0.0;
          }
        }

        for (i10 = 0; i10 < 159; i10++) {
          for (i11 = 0; i11 < 159; i11++) {
            bv0[i11 + 159 * i10] = (possmatrix[(i11 + 161 * (1 + i10)) + 1] <=
              0.0);
          }
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 25281; connectmatrix_tmp
             ++) {
          if (bv0[connectmatrix_tmp]) {
            finishtestmin[connectmatrix_tmp] = 0.0;
          }
        }

        if (isequal(finishtestmin, a)) {
          for (i10 = 0; i10 < 25921; i10++) {
            b_possmatrix[i10] = (possmatrix[i10] < 0.0);
          }

          d_sum(b_possmatrix, dv13);
          if (c_sum(dv13) == 0.0) {
            c_AllAdjacentPositiveAreNotEqua = false;
          }
        }

        for (i10 = 0; i10 < 159; i10++) {
          memcpy(&multipeakmatrix[i10 * 161 + 162], &finishtestmin_tmp[i10 * 159],
                 159U * sizeof(double));
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 25921; connectmatrix_tmp
             ++) {
          b_tmp = possmatrix[connectmatrix_tmp];
          d0 = possmatrix[connectmatrix_tmp];
          if (possmatrix[connectmatrix_tmp] > 0.0) {
            d0 = multipeakmatrix[connectmatrix_tmp];
            b_tmp = multipeakmatrix[connectmatrix_tmp];
          }

          b_possmatrix[connectmatrix_tmp] = (d0 > 0.0);
          possmatrix[connectmatrix_tmp] = b_tmp;
        }

        d_sum(b_possmatrix, dv14);
        if (c_sum(dv14) == 0.0) {
          PositiveValues_flag = false;
        }
      }

      emxFree_real_T(&r7);
      emxFree_int32_T(&ii);
      emxFree_int32_T(&r6);
      emxFree_int32_T(&r5);
      emxFree_int32_T(&r4);
      emxFree_int32_T(&r3);
      emxFree_int32_T(&r2);
      emxFree_int32_T(&r1);
      emxFree_uint16_T(&r0);
      emxFree_uint8_T(&nextInfCols);
      emxFree_real_T(&nextInfRows);
      for (connectmatrix_tmp = 0; connectmatrix_tmp < 25921; connectmatrix_tmp++)
      {
        b_tmp = possmatrix[connectmatrix_tmp];
        if (possmatrix[connectmatrix_tmp] < 1.0) {
          b_tmp = rtMinusInf;
        }

        possmatrix[connectmatrix_tmp] = b_tmp;
      }

      local_ismember(possmatrixsave, possmatrix, b_possmatrix);
      for (i10 = 0; i10 < 25921; i10++) {
        multipeakmatrix[i10] = b_possmatrix[i10];
      }
    }
  }

  for (i10 = 0; i10 < 25921; i10++) {
    peakmatrix[i10] += multipeakmatrix[i10];
  }
}

//
// File trailer for findpeaks2D.cpp
//
// [EOF]
//
