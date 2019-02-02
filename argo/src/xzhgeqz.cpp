//
// File: xzhgeqz.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "sqrt.h"

// Function Definitions

//
// Arguments    : creal_T A[16]
//                int ilo
//                int ihi
//                creal_T Z[16]
//                int *info
//                creal_T alpha1[4]
//                creal_T beta1[4]
// Return Type  : void
//
void xzhgeqz(creal_T A[16], int ilo, int ihi, creal_T Z[16], int *info, creal_T
             alpha1[4], creal_T beta1[4])
{
  double eshift_re;
  double eshift_im;
  creal_T ctemp;
  double anorm;
  double scale;
  double reAij;
  double sumsq;
  double b_atol;
  boolean_T firstNonZero;
  int j;
  int jp1;
  double ascale;
  int i;
  double imAij;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int ifirst;
  double temp2;
  int istart;
  int ilast;
  int ilastm1;
  int iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int jiter;
  int exitg1;
  boolean_T b_guard1 = false;
  boolean_T guard3 = false;
  boolean_T exitg2;
  creal_T b_ascale;
  creal_T shift;
  double ascale_re;
  double ad22_re;
  int shift_re_tmp;
  double ad22_im;
  int ad22_re_tmp;
  *info = 0;
  alpha1[0].re = 0.0;
  alpha1[0].im = 0.0;
  beta1[0].re = 1.0;
  beta1[0].im = 0.0;
  alpha1[1].re = 0.0;
  alpha1[1].im = 0.0;
  beta1[1].re = 1.0;
  beta1[1].im = 0.0;
  alpha1[2].re = 0.0;
  alpha1[2].im = 0.0;
  beta1[2].re = 1.0;
  beta1[2].im = 0.0;
  alpha1[3].re = 0.0;
  alpha1[3].im = 0.0;
  beta1[3].re = 1.0;
  beta1[3].im = 0.0;
  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = 0.0;
  if (ilo <= ihi) {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    for (j = ilo; j <= ihi; j++) {
      jp1 = j + 1;
      if (ihi < j + 1) {
        jp1 = ihi;
      }

      for (i = ilo; i <= jp1; i++) {
        reAij = A[(i + ((j - 1) << 2)) - 1].re;
        imAij = A[(i + ((j - 1) << 2)) - 1].im;
        if (reAij != 0.0) {
          anorm = fabs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = anorm;
            firstNonZero = false;
          } else if (scale < anorm) {
            temp2 = scale / anorm;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = anorm;
          } else {
            temp2 = anorm / scale;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0) {
          anorm = fabs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = anorm;
            firstNonZero = false;
          } else if (scale < anorm) {
            temp2 = scale / anorm;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = anorm;
          } else {
            temp2 = anorm / scale;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    anorm = scale * sqrt(sumsq);
  }

  reAij = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (reAij > 2.2250738585072014E-308) {
    b_atol = reAij;
  }

  reAij = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    reAij = anorm;
  }

  ascale = 1.0 / reAij;
  firstNonZero = true;
  jp1 = ihi + 1;
  for (j = jp1; j < 5; j++) {
    alpha1[j - 1] = A[(j + ((j - 1) << 2)) - 1];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
        b_guard1 = false;
        if (ilast + 1 == ilo) {
          goto60 = true;
          b_guard1 = true;
        } else {
          jp1 = ilast + (ilastm1 << 2);
          if (fabs(A[jp1].re) + fabs(A[ilast + (ilastm1 << 2)].im) <= b_atol) {
            A[jp1].re = 0.0;
            A[jp1].im = 0.0;
            goto60 = true;
            b_guard1 = true;
          } else {
            j = ilastm1;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (j + 1 >= ilo)) {
              if (j + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                jp1 = j + ((j - 1) << 2);
                if (fabs(A[jp1].re) + fabs(A[j + ((j - 1) << 2)].im) <= b_atol)
                {
                  A[jp1].re = 0.0;
                  A[jp1].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  j--;
                  guard3 = false;
                }
              }
            }

            if (guard3) {
              ifirst = j + 1;
              goto70 = true;
            }

            if (goto70) {
              b_guard1 = true;
            } else {
              alpha1[0].re = rtNaN;
              alpha1[0].im = 0.0;
              beta1[0].re = rtNaN;
              beta1[0].im = 0.0;
              alpha1[1].re = rtNaN;
              alpha1[1].im = 0.0;
              beta1[1].re = rtNaN;
              beta1[1].im = 0.0;
              alpha1[2].re = rtNaN;
              alpha1[2].im = 0.0;
              beta1[2].re = rtNaN;
              beta1[2].im = 0.0;
              alpha1[3].re = rtNaN;
              alpha1[3].im = 0.0;
              beta1[3].re = rtNaN;
              beta1[3].im = 0.0;
              for (jp1 = 0; jp1 < 16; jp1++) {
                Z[jp1].re = rtNaN;
                Z[jp1].im = 0.0;
              }

              *info = 1;
              exitg1 = 1;
            }
          }
        }

        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = A[ilast + (ilast << 2)];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              firstNonZero = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              jiter++;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (iiter - iiter / 10 * 10 != 0) {
                anorm = ascale * A[ilastm1 + (ilastm1 << 2)].re;
                reAij = ascale * A[ilastm1 + (ilastm1 << 2)].im;
                if (reAij == 0.0) {
                  shift.re = anorm / 0.5;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = reAij / 0.5;
                } else {
                  shift.re = anorm / 0.5;
                  shift.im = reAij / 0.5;
                }

                jp1 = ilast << 2;
                anorm = ascale * A[ilast + jp1].re;
                reAij = ascale * A[ilast + (ilast << 2)].im;
                if (reAij == 0.0) {
                  ad22_re = anorm / 0.5;
                  ad22_im = 0.0;
                } else if (anorm == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = reAij / 0.5;
                } else {
                  ad22_re = anorm / 0.5;
                  ad22_im = reAij / 0.5;
                }

                imAij = 0.5 * (shift.re + ad22_re);
                temp2 = 0.5 * (shift.im + ad22_im);
                anorm = ascale * A[ilastm1 + jp1].re;
                reAij = ascale * A[ilastm1 + (ilast << 2)].im;
                if (reAij == 0.0) {
                  ascale_re = anorm / 0.5;
                  sumsq = 0.0;
                } else if (anorm == 0.0) {
                  ascale_re = 0.0;
                  sumsq = reAij / 0.5;
                } else {
                  ascale_re = anorm / 0.5;
                  sumsq = reAij / 0.5;
                }

                anorm = ascale * A[ilast + (ilastm1 << 2)].re;
                reAij = ascale * A[ilast + (ilastm1 << 2)].im;
                if (reAij == 0.0) {
                  scale = anorm / 0.5;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  scale = 0.0;
                  anorm = reAij / 0.5;
                } else {
                  scale = anorm / 0.5;
                  anorm = reAij / 0.5;
                }

                reAij = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((imAij * imAij - temp2 * temp2) + (ascale_re * scale
                  - sumsq * anorm)) - (shift.re * ad22_re - shift.im * ad22_im);
                shift.im = ((imAij * temp2 + temp2 * imAij) + (ascale_re * anorm
                  + sumsq * scale)) - reAij;
                b_sqrt(&shift);
                if ((imAij - ad22_re) * shift.re + (temp2 - ad22_im) * shift.im <=
                    0.0) {
                  shift.re += imAij;
                  shift.im += temp2;
                } else {
                  shift.re = imAij - shift.re;
                  shift.im = temp2 - shift.im;
                }
              } else {
                anorm = ascale * A[ilast + (ilastm1 << 2)].re;
                reAij = ascale * A[ilast + (ilastm1 << 2)].im;
                if (reAij == 0.0) {
                  ascale_re = anorm / 0.5;
                  sumsq = 0.0;
                } else if (anorm == 0.0) {
                  ascale_re = 0.0;
                  sumsq = reAij / 0.5;
                } else {
                  ascale_re = anorm / 0.5;
                  sumsq = reAij / 0.5;
                }

                eshift_re += ascale_re;
                eshift_im += sumsq;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                i = j << 2;
                ctemp.re = ascale * A[j + i].re - shift.re * 0.5;
                ctemp.im = ascale * A[j + (j << 2)].im - shift.im * 0.5;
                anorm = fabs(ctemp.re) + fabs(ctemp.im);
                temp2 = ascale * (fabs(A[jp1 + i].re) + fabs(A[jp1 + (j << 2)].
                  im));
                reAij = anorm;
                if (temp2 > anorm) {
                  reAij = temp2;
                }

                if ((reAij < 1.0) && (reAij != 0.0)) {
                  anorm /= reAij;
                  temp2 /= reAij;
                }

                if ((fabs(A[j + ((j - 1) << 2)].re) + fabs(A[j + ((j - 1) << 2)]
                      .im)) * temp2 <= anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                ctemp.re = ascale * A[(ifirst + ((ifirst - 1) << 2)) - 1].re -
                  shift.re * 0.5;
                ctemp.im = ascale * A[(ifirst + ((ifirst - 1) << 2)) - 1].im -
                  shift.im * 0.5;
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              b_ascale.re = ascale * A[istart + ((istart - 1) << 2)].re;
              b_ascale.im = ascale * A[istart + ((istart - 1) << 2)].im;
              b_xzlartg(ctemp, b_ascale, &scale, &shift);
              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  i = j + (jp1 << 2);
                  xzlartg(A[i - 1], A[i], &scale, &shift, &A[(j + (jp1 << 2)) -
                          1]);
                  A[i].re = 0.0;
                  A[i].im = 0.0;
                }

                for (jp1 = j; jp1 < 5; jp1++) {
                  shift_re_tmp = j + ((jp1 - 1) << 2);
                  ad22_re_tmp = shift_re_tmp - 1;
                  ad22_re = scale * A[ad22_re_tmp].re + (shift.re *
                    A[shift_re_tmp].re - shift.im * A[j + ((jp1 - 1) << 2)].im);
                  ad22_im = scale * A[(j + ((jp1 - 1) << 2)) - 1].im + (shift.re
                    * A[j + ((jp1 - 1) << 2)].im + shift.im * A[j + ((jp1 - 1) <<
                    2)].re);
                  anorm = A[(j + ((jp1 - 1) << 2)) - 1].im;
                  reAij = A[(j + ((jp1 - 1) << 2)) - 1].re;
                  A[shift_re_tmp].re = scale * A[j + ((jp1 - 1) << 2)].re -
                    (shift.re * A[(j + ((jp1 - 1) << 2)) - 1].re + shift.im * A
                     [(j + ((jp1 - 1) << 2)) - 1].im);
                  A[shift_re_tmp].im = scale * A[j + ((jp1 - 1) << 2)].im -
                    (shift.re * anorm - shift.im * reAij);
                  A[ad22_re_tmp].re = ad22_re;
                  A[ad22_re_tmp].im = ad22_im;
                }

                shift.re = -shift.re;
                shift.im = -shift.im;
                jp1 = j;
                if (ilast + 1 < j + 2) {
                  jp1 = ilast - 1;
                }

                for (i = 1; i <= jp1 + 2; i++) {
                  shift_re_tmp = (i + ((j - 1) << 2)) - 1;
                  ad22_re_tmp = (i + (j << 2)) - 1;
                  ad22_re = scale * A[ad22_re_tmp].re + (shift.re *
                    A[shift_re_tmp].re - shift.im * A[(i + ((j - 1) << 2)) - 1].
                    im);
                  ad22_im = scale * A[(i + (j << 2)) - 1].im + (shift.re * A[(i
                    + ((j - 1) << 2)) - 1].im + shift.im * A[(i + ((j - 1) << 2))
                    - 1].re);
                  anorm = A[(i + (j << 2)) - 1].im;
                  reAij = A[(i + (j << 2)) - 1].re;
                  A[shift_re_tmp].re = scale * A[(i + ((j - 1) << 2)) - 1].re -
                    (shift.re * A[(i + (j << 2)) - 1].re + shift.im * A[(i + (j <<
                       2)) - 1].im);
                  A[shift_re_tmp].im = scale * A[(i + ((j - 1) << 2)) - 1].im -
                    (shift.re * anorm - shift.im * reAij);
                  A[ad22_re_tmp].re = ad22_re;
                  A[ad22_re_tmp].im = ad22_im;
                }

                ad22_re = scale * Z[j << 2].re + (shift.re * Z[(j - 1) << 2].re
                  - shift.im * Z[(j - 1) << 2].im);
                ad22_im = scale * Z[j << 2].im + (shift.re * Z[(j - 1) << 2].im
                  + shift.im * Z[(j - 1) << 2].re);
                anorm = Z[j << 2].im;
                reAij = Z[j << 2].re;
                Z[(j - 1) << 2].re = scale * Z[(j - 1) << 2].re - (shift.re *
                  Z[j << 2].re + shift.im * Z[j << 2].im);
                Z[(j - 1) << 2].im = scale * Z[(j - 1) << 2].im - (shift.re *
                  anorm - shift.im * reAij);
                Z[j << 2].re = ad22_re;
                Z[j << 2].im = ad22_im;
                shift_re_tmp = 1 + ((j - 1) << 2);
                ad22_re_tmp = 1 + (j << 2);
                ad22_re = scale * Z[ad22_re_tmp].re + (shift.re * Z[shift_re_tmp]
                  .re - shift.im * Z[1 + ((j - 1) << 2)].im);
                ad22_im = scale * Z[1 + (j << 2)].im + (shift.re * Z[1 + ((j - 1)
                  << 2)].im + shift.im * Z[1 + ((j - 1) << 2)].re);
                anorm = Z[1 + (j << 2)].im;
                reAij = Z[1 + (j << 2)].re;
                Z[shift_re_tmp].re = scale * Z[1 + ((j - 1) << 2)].re -
                  (shift.re * Z[1 + (j << 2)].re + shift.im * Z[1 + (j << 2)].im);
                Z[shift_re_tmp].im = scale * Z[1 + ((j - 1) << 2)].im -
                  (shift.re * anorm - shift.im * reAij);
                Z[ad22_re_tmp].re = ad22_re;
                Z[ad22_re_tmp].im = ad22_im;
                shift_re_tmp = 2 + ((j - 1) << 2);
                ad22_re_tmp = 2 + (j << 2);
                ad22_re = scale * Z[ad22_re_tmp].re + (shift.re * Z[shift_re_tmp]
                  .re - shift.im * Z[2 + ((j - 1) << 2)].im);
                ad22_im = scale * Z[2 + (j << 2)].im + (shift.re * Z[2 + ((j - 1)
                  << 2)].im + shift.im * Z[2 + ((j - 1) << 2)].re);
                anorm = Z[2 + (j << 2)].im;
                reAij = Z[2 + (j << 2)].re;
                Z[shift_re_tmp].re = scale * Z[2 + ((j - 1) << 2)].re -
                  (shift.re * Z[2 + (j << 2)].re + shift.im * Z[2 + (j << 2)].im);
                Z[shift_re_tmp].im = scale * Z[2 + ((j - 1) << 2)].im -
                  (shift.re * anorm - shift.im * reAij);
                Z[ad22_re_tmp].re = ad22_re;
                Z[ad22_re_tmp].im = ad22_im;
                shift_re_tmp = 3 + ((j - 1) << 2);
                ad22_re_tmp = 3 + (j << 2);
                ad22_re = scale * Z[ad22_re_tmp].re + (shift.re * Z[shift_re_tmp]
                  .re - shift.im * Z[3 + ((j - 1) << 2)].im);
                ad22_im = scale * Z[3 + (j << 2)].im + (shift.re * Z[3 + ((j - 1)
                  << 2)].im + shift.im * Z[3 + ((j - 1) << 2)].re);
                anorm = Z[3 + (j << 2)].im;
                reAij = Z[3 + (j << 2)].re;
                Z[shift_re_tmp].re = scale * Z[3 + ((j - 1) << 2)].re -
                  (shift.re * Z[3 + (j << 2)].re + shift.im * Z[3 + (j << 2)].im);
                Z[shift_re_tmp].im = scale * Z[3 + ((j - 1) << 2)].im -
                  (shift.re * anorm - shift.im * reAij);
                Z[ad22_re_tmp].re = ad22_re;
                Z[ad22_re_tmp].im = ad22_im;
                jp1 = j - 1;
                j++;
              }
            }

            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (firstNonZero) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 <= ilast; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }

      for (jp1 = 0; jp1 < 16; jp1++) {
        Z[jp1].re = rtNaN;
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (j = 0; j <= ilo - 2; j++) {
      alpha1[j] = A[j + (j << 2)];
    }
  }
}

//
// File trailer for xzhgeqz.cpp
//
// [EOF]
//
