//
// File: xgerc.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xgerc.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                const creal_T alpha1
//                int ix0
//                const creal_T y[4]
//                creal_T A[16]
//                int ia0
// Return Type  : void
//
void xgerc(int m, int n, const creal_T alpha1, int ix0, const creal_T y[4],
           creal_T A[16], int ia0)
{
  int jA;
  int jy;
  int j;
  double temp_re;
  double temp_im;
  int ix;
  int i13;
  int i14;
  int ijA;
  double A_im;
  if ((!(alpha1.re == 0.0)) || (!(alpha1.im == 0.0))) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if ((y[jy].re != 0.0) || (y[jy].im != 0.0)) {
        temp_re = y[jy].re * alpha1.re + y[jy].im * alpha1.im;
        temp_im = y[jy].re * alpha1.im - y[jy].im * alpha1.re;
        ix = ix0;
        i13 = jA + 1;
        i14 = m + jA;
        for (ijA = i13; ijA <= i14; ijA++) {
          A_im = A[ix - 1].re * temp_im + A[ix - 1].im * temp_re;
          A[ijA - 1].re += A[ix - 1].re * temp_re - A[ix - 1].im * temp_im;
          A[ijA - 1].im += A_im;
          ix++;
        }
      }

      jy++;
      jA += 4;
    }
  }
}

//
// File trailer for xgerc.cpp
//
// [EOF]
//
