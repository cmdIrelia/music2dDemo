//
// File: xzlarf.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xzlarf.h"
#include "xgerc.h"
#include "xgemv.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                int iv0
//                const creal_T tau
//                creal_T C[16]
//                int ic0
//                creal_T work[4]
// Return Type  : void
//
void xzlarf(int m, int n, int iv0, const creal_T tau, creal_T C[16], int ic0,
            creal_T work[4])
{
  int lastv;
  int lastc;
  creal_T b_tau;
  boolean_T exitg2;
  int coltop;
  int ia;
  int exitg1;
  if ((tau.re != 0.0) || (tau.im != 0.0)) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && ((C[lastc - 2].re == 0.0) && (C[lastc - 2].im == 0.0)))
    {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = ic0 + ((lastc - 1) << 2);
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= (coltop + lastv) - 1) {
          if ((C[ia - 1].re != 0.0) || (C[ia - 1].im != 0.0)) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    xgemv(lastv, lastc, C, ic0, C, iv0, work);
    b_tau.re = -tau.re;
    b_tau.im = -tau.im;
    xgerc(lastv, lastc, b_tau, iv0, work, C, ic0);
  }
}

//
// File trailer for xzlarf.cpp
//
// [EOF]
//
