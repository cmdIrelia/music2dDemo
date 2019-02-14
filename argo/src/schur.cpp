//
// File: schur.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "schur.h"
#include "xhseqr.h"
#include "xzlarf.h"
#include "recip.h"
#include "xdlapy3.h"
#include "xnrm2.h"
#include "anyNonFinite.h"

// Function Definitions

//
// Arguments    : const creal_T A[16]
//                creal_T V[16]
//                creal_T T[16]
// Return Type  : void
//
void schur(const creal_T A[16], creal_T V[16], creal_T T[16])
{
  int i6;
  creal_T work[4];
  int knt;
  int k;
  int i;
  int b_i;
  int im1n;
  int in;
  int jA;
  int alpha1_tmp;
  creal_T alpha1;
  creal_T tau[3];
  double xnorm;
  double beta1;
  int iv0;
  double temp_im;
  int lastv;
  int lastc;
  creal_T b_T;
  boolean_T exitg2;
  double c_im;
  int ix;
  int exitg1;
  int i7;
  if (anyNonFinite(A)) {
    for (i6 = 0; i6 < 16; i6++) {
      V[i6].re = rtNaN;
      V[i6].im = 0.0;
    }

    knt = 2;
    for (k = 0; k < 3; k++) {
      for (i = knt; i < 5; i++) {
        i6 = (i + (k << 2)) - 1;
        V[i6].re = 0.0;
        V[i6].im = 0.0;
      }

      knt++;
    }

    for (i6 = 0; i6 < 16; i6++) {
      T[i6].re = rtNaN;
      T[i6].im = 0.0;
    }
  } else {
    memcpy(&T[0], &A[0], sizeof(creal_T) << 4);
    work[0].re = 0.0;
    work[0].im = 0.0;
    work[1].re = 0.0;
    work[1].im = 0.0;
    work[2].re = 0.0;
    work[2].im = 0.0;
    work[3].re = 0.0;
    work[3].im = 0.0;
    for (i = 0; i < 3; i++) {
      b_i = i << 2;
      im1n = b_i + 2;
      in = (i + 1) << 2;
      alpha1_tmp = (i + b_i) + 1;
      alpha1 = T[alpha1_tmp];
      knt = i + 3;
      if (knt < 4) {
        knt = 3;
      } else {
        knt = 4;
      }

      jA = knt + b_i;
      tau[i].re = 0.0;
      tau[i].im = 0.0;
      xnorm = xnrm2(2 - i, T, jA);
      if ((xnorm != 0.0) || (T[(i + (i << 2)) + 1].im != 0.0)) {
        beta1 = xdlapy3(T[(i + (i << 2)) + 1].re, T[(i + (i << 2)) + 1].im,
                        xnorm);
        if (T[(i + (i << 2)) + 1].re >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = -1;
          i6 = (jA - i) + 1;
          do {
            knt++;
            for (k = jA; k <= i6; k++) {
              xnorm = T[k - 1].re;
              temp_im = T[k - 1].im;
              T[k - 1].re = 9.9792015476736E+291 * xnorm - 0.0 * temp_im;
              T[k - 1].im = 9.9792015476736E+291 * temp_im + 0.0 * xnorm;
            }

            beta1 *= 9.9792015476736E+291;
            alpha1.re *= 9.9792015476736E+291;
            alpha1.im *= 9.9792015476736E+291;
          } while (!(fabs(beta1) >= 1.0020841800044864E-292));

          beta1 = xdlapy3(alpha1.re, alpha1.im, xnrm2(2 - i, T, jA));
          if (alpha1.re >= 0.0) {
            beta1 = -beta1;
          }

          xnorm = beta1 - alpha1.re;
          if (0.0 - alpha1.im == 0.0) {
            tau[i].re = xnorm / beta1;
            tau[i].im = 0.0;
          } else if (xnorm == 0.0) {
            tau[i].re = 0.0;
            tau[i].im = (0.0 - alpha1.im) / beta1;
          } else {
            tau[i].re = xnorm / beta1;
            tau[i].im = (0.0 - alpha1.im) / beta1;
          }

          b_T.re = alpha1.re - beta1;
          b_T.im = alpha1.im;
          alpha1 = recip(b_T);
          i6 = (jA - i) + 1;
          for (k = jA; k <= i6; k++) {
            xnorm = T[k - 1].re;
            temp_im = T[k - 1].im;
            T[k - 1].re = alpha1.re * xnorm - alpha1.im * temp_im;
            T[k - 1].im = alpha1.re * temp_im + alpha1.im * xnorm;
          }

          for (k = 0; k <= knt; k++) {
            beta1 *= 1.0020841800044864E-292;
          }

          alpha1.re = beta1;
          alpha1.im = 0.0;
        } else {
          xnorm = beta1 - T[(i + (i << 2)) + 1].re;
          temp_im = 0.0 - T[(i + (i << 2)) + 1].im;
          if (temp_im == 0.0) {
            tau[i].re = xnorm / beta1;
            tau[i].im = 0.0;
          } else if (xnorm == 0.0) {
            tau[i].re = 0.0;
            tau[i].im = temp_im / beta1;
          } else {
            tau[i].re = xnorm / beta1;
            tau[i].im = temp_im / beta1;
          }

          b_T.re = T[(i + (i << 2)) + 1].re - beta1;
          b_T.im = T[(i + (i << 2)) + 1].im;
          alpha1 = recip(b_T);
          i6 = (jA - i) + 1;
          for (k = jA; k <= i6; k++) {
            xnorm = T[k - 1].re;
            temp_im = T[k - 1].im;
            T[k - 1].re = alpha1.re * xnorm - alpha1.im * temp_im;
            T[k - 1].im = alpha1.re * temp_im + alpha1.im * xnorm;
          }

          alpha1.re = beta1;
          alpha1.im = 0.0;
        }
      }

      T[alpha1_tmp].re = 1.0;
      T[alpha1_tmp].im = 0.0;
      iv0 = i + im1n;
      k = in + 1;
      if ((tau[i].re != 0.0) || (tau[i].im != 0.0)) {
        lastv = 2 - i;
        b_i = (iv0 - i) + 1;
        while ((lastv + 1 > 0) && ((T[b_i].re == 0.0) && (T[b_i].im == 0.0))) {
          lastv--;
          b_i--;
        }

        lastc = 4;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          knt = in + lastc;
          jA = knt;
          do {
            exitg1 = 0;
            if (jA <= knt + (lastv << 2)) {
              if ((T[jA - 1].re != 0.0) || (T[jA - 1].im != 0.0)) {
                exitg1 = 1;
              } else {
                jA += 4;
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
        lastv = -1;
        lastc = 0;
      }

      if (lastv + 1 > 0) {
        if (lastc != 0) {
          for (knt = 0; knt < lastc; knt++) {
            work[knt].re = 0.0;
            work[knt].im = 0.0;
          }

          ix = iv0;
          i6 = (in + (lastv << 2)) + 1;
          for (b_i = k; b_i <= i6; b_i += 4) {
            beta1 = T[ix - 1].re - 0.0 * T[ix - 1].im;
            c_im = T[ix - 1].im + 0.0 * T[ix - 1].re;
            knt = 0;
            i7 = (b_i + lastc) - 1;
            for (jA = b_i; jA <= i7; jA++) {
              work[knt].re += T[jA - 1].re * beta1 - T[jA - 1].im * c_im;
              work[knt].im += T[jA - 1].re * c_im + T[jA - 1].im * beta1;
              knt++;
            }

            ix++;
          }
        }

        beta1 = -tau[i].re;
        c_im = -tau[i].im;
        if ((!(-tau[i].re == 0.0)) || (!(-tau[i].im == 0.0))) {
          jA = in;
          knt = iv0 - 1;
          for (k = 0; k <= lastv; k++) {
            if ((T[knt].re != 0.0) || (T[knt].im != 0.0)) {
              xnorm = T[knt].re * beta1 + T[knt].im * c_im;
              temp_im = T[knt].re * c_im - T[knt].im * beta1;
              ix = 0;
              i6 = jA + 1;
              i7 = lastc + jA;
              for (b_i = i6; b_i <= i7; b_i++) {
                T[b_i - 1].re += work[ix].re * xnorm - work[ix].im * temp_im;
                T[b_i - 1].im += work[ix].re * temp_im + work[ix].im * xnorm;
                ix++;
              }
            }

            knt++;
            jA += 4;
          }
        }
      }

      b_T.re = tau[i].re;
      b_T.im = -tau[i].im;
      xzlarf(3 - i, 3 - i, i + im1n, b_T, T, (i + in) + 2, work);
      T[alpha1_tmp] = alpha1;
    }

    memcpy(&V[0], &T[0], sizeof(creal_T) << 4);
    for (k = 2; k >= 0; k--) {
      jA = (k + 1) << 2;
      for (i = 0; i <= k; i++) {
        i6 = jA + i;
        V[i6].re = 0.0;
        V[i6].im = 0.0;
      }

      i6 = k + 3;
      for (i = i6; i < 5; i++) {
        knt = jA + i;
        V[knt - 1] = V[knt - 5];
      }
    }

    V[1].re = 0.0;
    V[1].im = 0.0;
    V[2].re = 0.0;
    V[2].im = 0.0;
    V[3].re = 0.0;
    V[3].im = 0.0;
    V[0].re = 1.0;
    V[0].im = 0.0;
    knt = 2;
    work[0].re = 0.0;
    work[0].im = 0.0;
    work[1].re = 0.0;
    work[1].im = 0.0;
    work[2].re = 0.0;
    work[2].im = 0.0;
    work[3].re = 0.0;
    work[3].im = 0.0;
    for (i = 2; i >= 0; i--) {
      b_i = (i + (i << 2)) + 5;
      if (i + 1 < 3) {
        V[b_i].re = 1.0;
        V[b_i].im = 0.0;
        xzlarf(3 - i, 2 - i, b_i + 1, tau[knt], V, b_i + 5, work);
        jA = b_i + 2;
        beta1 = -tau[knt].re;
        c_im = -tau[knt].im;
        i6 = (b_i - i) + 3;
        for (k = jA; k <= i6; k++) {
          xnorm = V[k - 1].re;
          temp_im = V[k - 1].im;
          V[k - 1].re = beta1 * xnorm - c_im * temp_im;
          V[k - 1].im = beta1 * temp_im + c_im * xnorm;
        }
      }

      V[b_i].re = 1.0 - tau[knt].re;
      V[b_i].im = 0.0 - tau[knt].im;
      for (k = 0; k < i; k++) {
        i6 = (b_i - k) - 1;
        V[i6].re = 0.0;
        V[i6].im = 0.0;
      }

      knt--;
    }

    xhseqr(T, V);
  }
}

//
// File trailer for schur.cpp
//
// [EOF]
//
