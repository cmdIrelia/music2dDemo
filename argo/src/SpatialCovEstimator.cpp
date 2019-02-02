//
// File: SpatialCovEstimator.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "SpatialCovEstimator.h"

// Function Definitions

//
// Arguments    : const creal_T X[4000]
//                creal_T Sx[16]
// Return Type  : void
//
void SpatialCovEstimator_stepImpl(const creal_T X[4000], creal_T Sx[16])
{
  int i2;
  int subOut_tmp;
  creal_T subOut[4000];
  int i3;
  double re;
  double im;
  int i4;
  int subOut_re_tmp;
  double subOut_re;
  double subOut_im;
  for (i2 = 0; i2 < 1000; i2++) {
    subOut_tmp = i2 << 2;
    subOut[subOut_tmp] = X[i2];
    subOut[1 + subOut_tmp] = X[i2 + 1000];
    subOut[2 + subOut_tmp] = X[i2 + 2000];
    subOut[3 + subOut_tmp] = X[i2 + 3000];
  }

  for (i2 = 0; i2 < 4; i2++) {
    for (subOut_tmp = 0; subOut_tmp < 4; subOut_tmp++) {
      i3 = i2 + (subOut_tmp << 2);
      Sx[i3].re = 0.0;
      Sx[i3].im = 0.0;
      re = 0.0;
      im = 0.0;
      for (i4 = 0; i4 < 1000; i4++) {
        subOut_re_tmp = i4 << 2;
        subOut_re = subOut[subOut_tmp + subOut_re_tmp].re;
        subOut_im = -subOut[subOut_tmp + (i4 << 2)].im;
        re += subOut[i2 + subOut_re_tmp].re * subOut_re - subOut[i2 + (i4 << 2)]
          .im * subOut_im;
        im += subOut[i2 + (i4 << 2)].re * subOut_im + subOut[i2 + (i4 << 2)].im *
          subOut_re;
      }

      Sx[i3].re = re;
      Sx[i3].im = im;
    }
  }

  for (i2 = 0; i2 < 16; i2++) {
    Sx[i2].re *= 0.001;
    Sx[i2].im *= 0.001;
  }
}

//
// File trailer for SpatialCovEstimator.cpp
//
// [EOF]
//
