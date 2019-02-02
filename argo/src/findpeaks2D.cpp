//
// File: findpeaks2D.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
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
// Arguments    : const double X[36421]
//                double peakmatrix[36421]
// Return Type  : void
//
void findpeaks2D(const double X[36421], double peakmatrix[36421])
{
  int i9;
  int i10;
  static boolean_T connectmatrix[284648];
  boolean_T bv0[35581];
  static double b_connectmatrix[284648];
  int connectposs_tmp;
  double b_tmp;
  int connectmatrix_tmp;
  static double multipeakmatrix[36421];
  int xOffset;
  static double possmatrix[36421];
  static double finishtestmax[35581];
  int idx;
  double dv11[301];
  double b_possmatrix;
  static double possmatrixsave[36421];
  static signed char connectposs[284648];
  boolean_T c_possmatrix[36421];
  double dv12[301];
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T c_AllAdjacentPositiveAreNotEqua;
  boolean_T PositiveValues_flag;
  emxArray_real_T *nextInfRows;
  emxArray_int16_T *nextInfCols;
  emxArray_uint16_T *r0;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_int32_T *r7;
  emxArray_int16_T *j;
  emxArray_real_T *r8;
  boolean_T guard1 = false;
  static double b_connectposs[320229];
  static double finishtestmin_tmp[35581];
  static double finishtestmin[35581];
  double dv13[301];
  double dv14[301];
  memset(&peakmatrix[0], 0, 36421U * sizeof(double));
  for (i9 = 0; i9 < 299; i9++) {
    for (i10 = 0; i10 < 119; i10++) {
      connectposs_tmp = i10 + 121 * (1 + i9);
      b_tmp = X[connectposs_tmp + 1];
      connectmatrix_tmp = i10 + 119 * i9;
      xOffset = i10 + 121 * i9;
      b_connectmatrix[connectmatrix_tmp] = b_tmp - X[xOffset];
      b_connectmatrix[35581 + connectmatrix_tmp] = b_tmp - X[connectposs_tmp];
      idx = i10 + 121 * (2 + i9);
      b_connectmatrix[71162 + connectmatrix_tmp] = b_tmp - X[idx];
      b_connectmatrix[106743 + connectmatrix_tmp] = b_tmp - X[xOffset + 1];
      b_connectmatrix[142324 + connectmatrix_tmp] = b_tmp - X[idx + 1];
      b_connectmatrix[177905 + connectmatrix_tmp] = b_tmp - X[xOffset + 2];
      b_connectmatrix[213486 + connectmatrix_tmp] = b_tmp - X[connectposs_tmp +
        2];
      b_connectmatrix[249067 + connectmatrix_tmp] = b_tmp - X[idx + 2];
    }
  }

  for (i9 = 0; i9 < 284648; i9++) {
    connectmatrix[i9] = (b_connectmatrix[i9] > 0.0);
  }

  all(connectmatrix, bv0);
  for (i9 = 0; i9 < 299; i9++) {
    for (i10 = 0; i10 < 119; i10++) {
      peakmatrix[(i10 + 121 * (1 + i9)) + 1] = bv0[i10 + 119 * i9];
    }
  }

  memset(&multipeakmatrix[0], 0, 36421U * sizeof(double));
  memset(&possmatrix[0], 0, 36421U * sizeof(double));
  memcpy(&finishtestmax[0], &b_connectmatrix[0], 35581U * sizeof(double));
  for (connectmatrix_tmp = 0; connectmatrix_tmp < 7; connectmatrix_tmp++) {
    xOffset = (connectmatrix_tmp + 1) * 35581;
    for (idx = 0; idx < 35581; idx++) {
      b_tmp = b_connectmatrix[xOffset + idx];
      if ((!rtIsNaN(b_tmp)) && (rtIsNaN(finishtestmax[idx]) ||
           (finishtestmax[idx] > b_tmp))) {
        finishtestmax[idx] = b_tmp;
      }
    }
  }

  for (i9 = 0; i9 < 299; i9++) {
    for (i10 = 0; i10 < 119; i10++) {
      possmatrix[(i10 + 121 * (1 + i9)) + 1] = (finishtestmax[i10 + 119 * i9] ==
        0.0);
    }
  }

  for (connectmatrix_tmp = 0; connectmatrix_tmp < 36421; connectmatrix_tmp++) {
    b_possmatrix = possmatrix[connectmatrix_tmp];
    if (X[connectmatrix_tmp] == rtMinusInf) {
      b_possmatrix = 0.0;
    }

    possmatrixsave[connectmatrix_tmp] = b_possmatrix;
    possmatrix[connectmatrix_tmp] = b_possmatrix;
  }

  b_sum(possmatrix, dv11);
  if (c_sum(dv11) > 0.0) {
    for (i9 = 0; i9 < 299; i9++) {
      for (i10 = 0; i10 < 119; i10++) {
        xOffset = i10 + 119 * i9;
        idx = i10 + 121 * i9;
        connectposs[xOffset] = (signed char)possmatrix[idx];
        connectmatrix_tmp = i10 + 121 * (1 + i9);
        connectposs[35581 + xOffset] = (signed char)possmatrix[connectmatrix_tmp];
        connectposs_tmp = i10 + 121 * (2 + i9);
        connectposs[71162 + xOffset] = (signed char)possmatrix[connectposs_tmp];
        connectposs[106743 + xOffset] = (signed char)possmatrix[idx + 1];
        connectposs[142324 + xOffset] = (signed char)possmatrix[connectposs_tmp
          + 1];
        connectposs[177905 + xOffset] = (signed char)possmatrix[idx + 2];
        connectposs[213486 + xOffset] = (signed char)
          possmatrix[connectmatrix_tmp + 2];
        connectposs[249067 + xOffset] = (signed char)possmatrix[connectposs_tmp
          + 2];
      }
    }

    for (connectmatrix_tmp = 0; connectmatrix_tmp < 284648; connectmatrix_tmp++)
    {
      b_tmp = b_connectmatrix[connectmatrix_tmp];
      if (connectposs[connectmatrix_tmp] == 1) {
        b_tmp = 1.0;
      }

      connectmatrix[connectmatrix_tmp] = (b_tmp > 0.0);
      b_connectmatrix[connectmatrix_tmp] = b_tmp;
    }

    all(connectmatrix, bv0);
    for (i9 = 0; i9 < 299; i9++) {
      for (i10 = 0; i10 < 119; i10++) {
        connectmatrix_tmp = (i10 + 121 * (1 + i9)) + 1;
        possmatrix[connectmatrix_tmp] = -possmatrix[connectmatrix_tmp] + 2.0 *
          (double)bv0[i10 + 119 * i9];
      }
    }

    for (i9 = 0; i9 < 36421; i9++) {
      b_possmatrix = possmatrix[i9] * possmatrixsave[i9];
      c_possmatrix[i9] = (b_possmatrix > 0.0);
      possmatrix[i9] = b_possmatrix;
    }

    d_sum(c_possmatrix, dv12);
    if (c_sum(dv12) > 0.0) {
      emxInit_int32_T(&ii, 1);
      idx = 0;
      i9 = ii->size[0];
      ii->size[0] = 36421;
      emxEnsureCapacity_int32_T(ii, i9);
      connectmatrix_tmp = 0;
      exitg1 = false;
      while ((!exitg1) && (connectmatrix_tmp < 36421)) {
        if (possmatrix[connectmatrix_tmp] == 1.0) {
          idx++;
          ii->data[idx - 1] = connectmatrix_tmp + 1;
          if (idx >= 36421) {
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
        i9 = ii->size[0];
        ii->size[0] = idx;
        emxEnsureCapacity_int32_T(ii, i9);
      }

      connectmatrix_tmp = ii->size[0];
      for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
        possmatrix[ii->data[i9] - 1] = ii->data[i9];
      }

      c_AllAdjacentPositiveAreNotEqua = true;
      PositiveValues_flag = true;
      for (i9 = 0; i9 < 36421; i9++) {
        possmatrixsave[i9] = possmatrix[i9];
        multipeakmatrix[i9] = 0.0;
      }

      emxInit_real_T(&nextInfRows, 1);
      emxInit_int16_T(&nextInfCols, 1);
      emxInit_uint16_T(&r0, 2);
      emxInit_int32_T(&r1, 2);
      emxInit_int32_T(&r2, 2);
      emxInit_int32_T(&r3, 2);
      emxInit_int32_T(&r4, 2);
      emxInit_int32_T(&r5, 2);
      emxInit_int32_T(&r6, 2);
      emxInit_int32_T(&r7, 2);
      emxInit_int16_T(&j, 1);
      emxInit_real_T(&r8, 1);
      while (PositiveValues_flag && c_AllAdjacentPositiveAreNotEqua) {
        idx = 0;
        i9 = ii->size[0];
        ii->size[0] = 36421;
        emxEnsureCapacity_int32_T(ii, i9);
        i9 = j->size[0];
        j->size[0] = 36421;
        emxEnsureCapacity_int16_T(j, i9);
        connectmatrix_tmp = 1;
        xOffset = 1;
        exitg1 = false;
        while ((!exitg1) && (xOffset <= 301)) {
          guard1 = false;
          if (possmatrix[(connectmatrix_tmp + 121 * (xOffset - 1)) - 1] == -1.0)
          {
            idx++;
            ii->data[idx - 1] = connectmatrix_tmp;
            j->data[idx - 1] = (short)xOffset;
            if (idx >= 36421) {
              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            connectmatrix_tmp++;
            if (connectmatrix_tmp > 121) {
              connectmatrix_tmp = 1;
              xOffset++;
            }
          }
        }

        if (1 > idx) {
          ii->size[0] = 0;
          j->size[0] = 0;
        } else {
          i9 = ii->size[0];
          ii->size[0] = idx;
          emxEnsureCapacity_int32_T(ii, i9);
          i9 = j->size[0];
          j->size[0] = idx;
          emxEnsureCapacity_int16_T(j, i9);
        }

        i9 = nextInfRows->size[0];
        nextInfRows->size[0] = ii->size[0] << 3;
        emxEnsureCapacity_real_T(nextInfRows, i9);
        connectmatrix_tmp = ii->size[0] << 3;
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[i9] = 0.0;
        }

        i9 = nextInfCols->size[0];
        nextInfCols->size[0] = ii->size[0] << 3;
        emxEnsureCapacity_int16_T(nextInfCols, i9);
        connectmatrix_tmp = ii->size[0] << 3;
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[i9] = 0;
        }

        if (1 > ii->size[0]) {
          i9 = 0;
        } else {
          i9 = ii->size[0];
        }

        i10 = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = (unsigned short)i9;
        emxEnsureCapacity_uint16_T(r0, i10);
        connectmatrix_tmp = (unsigned short)i9 - 1;
        for (i9 = 0; i9 <= connectmatrix_tmp; i9++) {
          r0->data[i9] = (unsigned short)i9;
        }

        connectmatrix_tmp = r0->size[0] * r0->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r0->data[i9]] = (double)ii->data[i9] - 1.0;
        }

        if (1 > ii->size[0]) {
          i9 = 0;
        } else {
          i9 = ii->size[0];
        }

        i10 = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = (unsigned short)i9;
        emxEnsureCapacity_uint16_T(r0, i10);
        connectmatrix_tmp = (unsigned short)i9 - 1;
        for (i9 = 0; i9 <= connectmatrix_tmp; i9++) {
          r0->data[i9] = (unsigned short)i9;
        }

        connectmatrix_tmp = r0->size[0] * r0->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r0->data[i9]] = (short)(j->data[i9] - 1);
        }

        i9 = ii->size[0] << 1;
        if (ii->size[0] + 1 > i9) {
          i10 = 1;
          i9 = 0;
        } else {
          i10 = ii->size[0] + 1;
        }

        connectposs_tmp = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        connectmatrix_tmp = (i9 - i10) + 1;
        r1->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r1, connectposs_tmp);
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          r1->data[i9] = (i10 + i9) - 1;
        }

        connectmatrix_tmp = r1->size[0] * r1->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r1->data[i9]] = (double)ii->data[i9] - 1.0;
        }

        i9 = ii->size[0] << 1;
        if (ii->size[0] + 1 > i9) {
          i10 = 1;
          i9 = 0;
        } else {
          i10 = ii->size[0] + 1;
        }

        connectposs_tmp = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        connectmatrix_tmp = (i9 - i10) + 1;
        r1->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r1, connectposs_tmp);
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          r1->data[i9] = (i10 + i9) - 1;
        }

        connectmatrix_tmp = r1->size[0] * r1->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r1->data[i9]] = j->data[i9];
        }

        i9 = (ii->size[0] << 1) + 1;
        i10 = 3 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r2->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r2, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r2->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r2->size[0] * r2->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r2->data[i9]] = (double)ii->data[i9] - 1.0;
        }

        i9 = (ii->size[0] << 1) + 1;
        i10 = 3 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r2->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r2, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r2->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r2->size[0] * r2->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r2->data[i9]] = (short)(j->data[i9] + 1);
        }

        i9 = 3 * ii->size[0] + 1;
        i10 = ii->size[0] << 2;
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r3->size[0] * r3->size[1];
        r3->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r3->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r3, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r3->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r3->size[0] * r3->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r3->data[i9]] = ii->data[i9];
        }

        i9 = 3 * ii->size[0] + 1;
        i10 = ii->size[0] << 2;
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r3->size[0] * r3->size[1];
        r3->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r3->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r3, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r3->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r3->size[0] * r3->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r3->data[i9]] = (short)(j->data[i9] - 1);
        }

        i9 = (ii->size[0] << 2) + 1;
        i10 = 5 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r4->size[0] * r4->size[1];
        r4->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r4->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r4, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r4->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r4->size[0] * r4->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r4->data[i9]] = ii->data[i9];
        }

        i9 = (ii->size[0] << 2) + 1;
        i10 = 5 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r4->size[0] * r4->size[1];
        r4->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r4->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r4, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r4->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r4->size[0] * r4->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r4->data[i9]] = (short)(j->data[i9] + 1);
        }

        i9 = 5 * ii->size[0] + 1;
        i10 = 6 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r5->size[0] * r5->size[1];
        r5->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r5->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r5, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r5->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r5->size[0] * r5->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r5->data[i9]] = (double)ii->data[i9] + 1.0;
        }

        i9 = 5 * ii->size[0] + 1;
        i10 = 6 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r5->size[0] * r5->size[1];
        r5->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r5->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r5, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r5->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r5->size[0] * r5->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r5->data[i9]] = (short)(j->data[i9] - 1);
        }

        i9 = 6 * ii->size[0] + 1;
        i10 = 7 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r6->size[0] * r6->size[1];
        r6->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r6->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r6, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r6->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r6->size[0] * r6->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r6->data[i9]] = (double)ii->data[i9] + 1.0;
        }

        i9 = 6 * ii->size[0] + 1;
        i10 = 7 * ii->size[0];
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r6->size[0] * r6->size[1];
        r6->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r6->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r6, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r6->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r6->size[0] * r6->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r6->data[i9]] = j->data[i9];
        }

        i9 = 7 * ii->size[0] + 1;
        i10 = ii->size[0] << 3;
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r7->size[0] * r7->size[1];
        r7->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r7->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r7, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r7->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r7->size[0] * r7->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[r7->data[i9]] = (double)ii->data[i9] + 1.0;
        }

        i9 = 7 * ii->size[0] + 1;
        i10 = ii->size[0] << 3;
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        connectposs_tmp = r7->size[0] * r7->size[1];
        r7->size[0] = 1;
        connectmatrix_tmp = i10 - i9;
        r7->size[1] = connectmatrix_tmp;
        emxEnsureCapacity_int32_T(r7, connectposs_tmp);
        for (i10 = 0; i10 < connectmatrix_tmp; i10++) {
          r7->data[i10] = i9 + i10;
        }

        connectmatrix_tmp = r7->size[0] * r7->size[1];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfCols->data[r7->data[i9]] = (short)(j->data[i9] + 1);
        }

        i9 = nextInfRows->size[0];
        emxEnsureCapacity_real_T(nextInfRows, i9);
        connectmatrix_tmp = nextInfRows->size[0];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          nextInfRows->data[i9] = (int)nextInfRows->data[i9] + 121 *
            (nextInfCols->data[i9] - 1);
        }

        i9 = r8->size[0];
        r8->size[0] = nextInfRows->size[0];
        emxEnsureCapacity_real_T(r8, i9);
        connectmatrix_tmp = nextInfRows->size[0];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          r8->data[i9] = -(double)(possmatrix[(int)nextInfRows->data[i9] - 1] >
            0.0);
        }

        connectmatrix_tmp = r8->size[0];
        for (i9 = 0; i9 < connectmatrix_tmp; i9++) {
          possmatrix[(int)nextInfRows->data[i9] - 1] = r8->data[i9];
        }

        for (i9 = 0; i9 < 299; i9++) {
          for (i10 = 0; i10 < 119; i10++) {
            xOffset = i10 + 119 * i9;
            idx = i10 + 121 * i9;
            b_connectposs[xOffset] = possmatrix[idx];
            connectmatrix_tmp = i10 + 121 * (1 + i9);
            b_connectposs[35581 + xOffset] = possmatrix[connectmatrix_tmp];
            connectposs_tmp = i10 + 121 * (2 + i9);
            b_connectposs[71162 + xOffset] = possmatrix[connectposs_tmp];
            b_connectposs[106743 + xOffset] = possmatrix[idx + 1];
            b_connectposs[142324 + xOffset] = possmatrix[connectposs_tmp + 1];
            b_connectposs[177905 + xOffset] = possmatrix[idx + 2];
            b_connectposs[213486 + xOffset] = possmatrix[connectmatrix_tmp + 2];
            b_connectposs[249067 + xOffset] = possmatrix[connectposs_tmp + 2];
            b_connectposs[284648 + xOffset] = possmatrix[connectmatrix_tmp + 1];
          }
        }

        memcpy(&finishtestmax[0], &b_connectposs[0], 35581U * sizeof(double));
        for (connectmatrix_tmp = 0; connectmatrix_tmp < 8; connectmatrix_tmp++)
        {
          xOffset = (connectmatrix_tmp + 1) * 35581;
          for (idx = 0; idx < 35581; idx++) {
            b_tmp = b_connectposs[xOffset + idx];
            if (finishtestmax[idx] < b_tmp) {
              finishtestmax[idx] = b_tmp;
            }
          }
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 320229;
             connectmatrix_tmp++) {
          b_tmp = b_connectposs[connectmatrix_tmp];
          if (b_connectposs[connectmatrix_tmp] <= 0.0) {
            b_tmp = rtInf;
          }

          b_connectposs[connectmatrix_tmp] = b_tmp;
        }

        memcpy(&finishtestmin_tmp[0], &b_connectposs[0], 35581U * sizeof(double));
        for (connectmatrix_tmp = 0; connectmatrix_tmp < 8; connectmatrix_tmp++)
        {
          xOffset = (connectmatrix_tmp + 1) * 35581;
          for (idx = 0; idx < 35581; idx++) {
            b_tmp = b_connectposs[xOffset + idx];
            if (finishtestmin_tmp[idx] > b_tmp) {
              finishtestmin_tmp[idx] = b_tmp;
            }
          }
        }

        memcpy(&finishtestmin[0], &finishtestmin_tmp[0], 35581U * sizeof(double));
        for (i9 = 0; i9 < 299; i9++) {
          for (i10 = 0; i10 < 119; i10++) {
            bv0[i10 + 119 * i9] = (possmatrix[(i10 + 121 * (1 + i9)) + 1] <= 0.0);
          }
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 35581; connectmatrix_tmp
             ++) {
          if (bv0[connectmatrix_tmp]) {
            finishtestmax[connectmatrix_tmp] = 0.0;
          }
        }

        for (i9 = 0; i9 < 299; i9++) {
          for (i10 = 0; i10 < 119; i10++) {
            bv0[i10 + 119 * i9] = (possmatrix[(i10 + 121 * (1 + i9)) + 1] <= 0.0);
          }
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 35581; connectmatrix_tmp
             ++) {
          if (bv0[connectmatrix_tmp]) {
            finishtestmin[connectmatrix_tmp] = 0.0;
          }
        }

        if (isequal(finishtestmin, finishtestmax)) {
          for (i9 = 0; i9 < 36421; i9++) {
            c_possmatrix[i9] = (possmatrix[i9] < 0.0);
          }

          d_sum(c_possmatrix, dv13);
          if (c_sum(dv13) == 0.0) {
            c_AllAdjacentPositiveAreNotEqua = false;
          }
        }

        for (i9 = 0; i9 < 299; i9++) {
          memcpy(&multipeakmatrix[i9 * 121 + 122], &finishtestmin_tmp[i9 * 119],
                 119U * sizeof(double));
        }

        for (connectmatrix_tmp = 0; connectmatrix_tmp < 36421; connectmatrix_tmp
             ++) {
          b_possmatrix = possmatrix[connectmatrix_tmp];
          b_tmp = possmatrix[connectmatrix_tmp];
          if (possmatrix[connectmatrix_tmp] > 0.0) {
            b_tmp = multipeakmatrix[connectmatrix_tmp];
            b_possmatrix = multipeakmatrix[connectmatrix_tmp];
          }

          c_possmatrix[connectmatrix_tmp] = (b_tmp > 0.0);
          possmatrix[connectmatrix_tmp] = b_possmatrix;
        }

        d_sum(c_possmatrix, dv14);
        if (c_sum(dv14) == 0.0) {
          PositiveValues_flag = false;
        }
      }

      emxFree_real_T(&r8);
      emxFree_int16_T(&j);
      emxFree_int32_T(&ii);
      emxFree_int32_T(&r7);
      emxFree_int32_T(&r6);
      emxFree_int32_T(&r5);
      emxFree_int32_T(&r4);
      emxFree_int32_T(&r3);
      emxFree_int32_T(&r2);
      emxFree_int32_T(&r1);
      emxFree_uint16_T(&r0);
      emxFree_int16_T(&nextInfCols);
      emxFree_real_T(&nextInfRows);
      for (connectmatrix_tmp = 0; connectmatrix_tmp < 36421; connectmatrix_tmp++)
      {
        b_possmatrix = possmatrix[connectmatrix_tmp];
        if (possmatrix[connectmatrix_tmp] < 1.0) {
          b_possmatrix = rtMinusInf;
        }

        possmatrix[connectmatrix_tmp] = b_possmatrix;
      }

      local_ismember(possmatrixsave, possmatrix, c_possmatrix);
      for (i9 = 0; i9 < 36421; i9++) {
        multipeakmatrix[i9] = c_possmatrix[i9];
      }
    }
  }

  for (i9 = 0; i9 < 36421; i9++) {
    peakmatrix[i9] += multipeakmatrix[i9];
  }
}

//
// File trailer for findpeaks2D.cpp
//
// [EOF]
//
