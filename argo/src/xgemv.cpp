//
// File: xgemv.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xgemv.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                const creal_T A[16]
//                int ia0
//                const creal_T x[16]
//                int ix0
//                creal_T y[4]
// Return Type  : void
//
void xgemv(int m, int n, const creal_T A[16], int ia0, const creal_T x[16], int
           ix0, creal_T y[4])
{
  int iy;
  int i11;
  int iac;
  int ix;
  double c_re;
  double c_im;
  int i12;
  int ia;
  if (n != 0) {
    for (iy = 0; iy < n; iy++) {
      y[iy].re = 0.0;
      y[iy].im = 0.0;
    }

    iy = 0;
    i11 = ia0 + ((n - 1) << 2);
    for (iac = ia0; iac <= i11; iac += 4) {
      ix = ix0 - 1;
      c_re = 0.0;
      c_im = 0.0;
      i12 = (iac + m) - 1;
      for (ia = iac; ia <= i12; ia++) {
        c_re += A[ia - 1].re * x[ix].re + A[ia - 1].im * x[ix].im;
        c_im += A[ia - 1].re * x[ix].im - A[ia - 1].im * x[ix].re;
        ix++;
      }

      y[iy].re += c_re - 0.0 * c_im;
      y[iy].im += c_im + 0.0 * c_re;
      iy++;
    }
  }
}

//
// File trailer for xgemv.cpp
//
// [EOF]
//
