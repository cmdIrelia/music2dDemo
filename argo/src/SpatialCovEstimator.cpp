//
// File: SpatialCovEstimator.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
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
  int i3;
  int subOut_tmp;
  creal_T subOut[4000];
  int i4;
  double re;
  double im;
  int i5;
  int subOut_re_tmp;
  double subOut_re;
  double subOut_im;
  for (i3 = 0; i3 < 1000; i3++) {
    subOut_tmp = i3 << 2;
    subOut[subOut_tmp] = X[i3];
    subOut[1 + subOut_tmp] = X[i3 + 1000];
    subOut[2 + subOut_tmp] = X[i3 + 2000];
    subOut[3 + subOut_tmp] = X[i3 + 3000];
  }

  for (i3 = 0; i3 < 4; i3++) {
    for (subOut_tmp = 0; subOut_tmp < 4; subOut_tmp++) {
      i4 = i3 + (subOut_tmp << 2);
      Sx[i4].re = 0.0;
      Sx[i4].im = 0.0;
      re = 0.0;
      im = 0.0;
      for (i5 = 0; i5 < 1000; i5++) {
        subOut_re_tmp = i5 << 2;
        subOut_re = subOut[subOut_tmp + subOut_re_tmp].re;
        subOut_im = -subOut[subOut_tmp + (i5 << 2)].im;
        re += subOut[i3 + subOut_re_tmp].re * subOut_re - subOut[i3 + (i5 << 2)]
          .im * subOut_im;
        im += subOut[i3 + (i5 << 2)].re * subOut_im + subOut[i3 + (i5 << 2)].im *
          subOut_re;
      }

      Sx[i4].re = re;
      Sx[i4].im = im;
    }
  }

  for (i3 = 0; i3 < 16; i3++) {
    Sx[i3].re *= 0.001;
    Sx[i3].im *= 0.001;
  }
}

//
// File trailer for SpatialCovEstimator.cpp
//
// [EOF]
//
