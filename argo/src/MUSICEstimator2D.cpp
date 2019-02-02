//
// File: MUSICEstimator2D.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "MUSICEstimator2D.h"
#include "AbstractSpectralDOA.h"
#include "sqrt.h"
#include "sum.h"
#include "power.h"
#include "abs.h"
#include "eps.h"
#include "SystemCore.h"
#include "sort1.h"
#include "schur.h"
#include "xzggev.h"
#include "anyNonFinite.h"

// Function Declarations
static void MUSICEstimator2D_privEig(const creal_T Sx[16], double eigenvals[4],
  creal_T eigenvects[16]);
static void c_MUSICEstimator2D_privDOASpect(phased_MUSICEstimator2D *obj, const
  creal_T X[4000], phased_URA *iobj_0, phased_IsotropicAntennaElement *iobj_1);

// Function Definitions

//
// Arguments    : const creal_T Sx[16]
//                double eigenvals[4]
//                creal_T eigenvects[16]
// Return Type  : void
//
static void MUSICEstimator2D_privEig(const creal_T Sx[16], double eigenvals[4],
  creal_T eigenvects[16])
{
  boolean_T p;
  int info;
  int j;
  boolean_T exitg2;
  creal_T At[16];
  creal_T V[16];
  int i;
  creal_T alpha1[4];
  creal_T beta1[4];
  int exitg1;
  double colnorm;
  double scale;
  int At_re_tmp_tmp;
  double absxk;
  double d[4];
  double b_eigenvals[16];
  double t;
  int iidx[4];
  if (anyNonFinite(Sx)) {
    for (info = 0; info < 16; info++) {
      V[info].re = rtNaN;
      V[info].im = 0.0;
      At[info].re = 0.0;
      At[info].im = 0.0;
    }

    At[0].re = rtNaN;
    At[0].im = 0.0;
    At[5].re = rtNaN;
    At[5].im = 0.0;
    At[10].re = rtNaN;
    At[10].im = 0.0;
    At[15].re = rtNaN;
    At[15].im = 0.0;
  } else {
    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 4)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= j) {
          if ((!(Sx[i + (j << 2)].re == Sx[j + (i << 2)].re)) || (!(Sx[i + (j <<
                 2)].im == -Sx[j + (i << 2)].im))) {
            p = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (p) {
      schur(Sx, V, At);
      At[0].im = 0.0;
      for (j = 0; j < 3; j++) {
        At_re_tmp_tmp = (j + 1) << 2;
        info = (j + At_re_tmp_tmp) + 1;
        At[info].im = 0.0;
        info = (j + (j << 2)) + 1;
        At[info].re = 0.0;
        At[info].im = 0.0;
        for (i = 0; i <= j; i++) {
          info = i + At_re_tmp_tmp;
          At[info].re = 0.0;
          At[info].im = 0.0;
        }
      }
    } else {
      memcpy(&At[0], &Sx[0], sizeof(creal_T) << 4);
      xzggev(At, &info, alpha1, beta1, V);
      colnorm = 0.0;
      scale = 3.3121686421112381E-170;
      for (info = 1; info < 5; info++) {
        absxk = fabs(V[info - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }

        absxk = fabs(V[info - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }
      }

      colnorm = scale * sqrt(colnorm);
      for (j = 1; j < 5; j++) {
        scale = V[j - 1].re;
        absxk = V[j - 1].im;
        if (absxk == 0.0) {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = 0.0;
        } else if (scale == 0.0) {
          V[j - 1].re = 0.0;
          V[j - 1].im = absxk / colnorm;
        } else {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = absxk / colnorm;
        }
      }

      colnorm = 0.0;
      scale = 3.3121686421112381E-170;
      for (info = 5; info < 9; info++) {
        absxk = fabs(V[info - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }

        absxk = fabs(V[info - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }
      }

      colnorm = scale * sqrt(colnorm);
      for (j = 5; j < 9; j++) {
        scale = V[j - 1].re;
        absxk = V[j - 1].im;
        if (absxk == 0.0) {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = 0.0;
        } else if (scale == 0.0) {
          V[j - 1].re = 0.0;
          V[j - 1].im = absxk / colnorm;
        } else {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = absxk / colnorm;
        }
      }

      colnorm = 0.0;
      scale = 3.3121686421112381E-170;
      for (info = 9; info < 13; info++) {
        absxk = fabs(V[info - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }

        absxk = fabs(V[info - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }
      }

      colnorm = scale * sqrt(colnorm);
      for (j = 9; j < 13; j++) {
        scale = V[j - 1].re;
        absxk = V[j - 1].im;
        if (absxk == 0.0) {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = 0.0;
        } else if (scale == 0.0) {
          V[j - 1].re = 0.0;
          V[j - 1].im = absxk / colnorm;
        } else {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = absxk / colnorm;
        }
      }

      colnorm = 0.0;
      scale = 3.3121686421112381E-170;
      for (info = 13; info < 17; info++) {
        absxk = fabs(V[info - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }

        absxk = fabs(V[info - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          colnorm = 1.0 + colnorm * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          colnorm += t * t;
        }
      }

      colnorm = scale * sqrt(colnorm);
      for (j = 13; j < 17; j++) {
        scale = V[j - 1].re;
        absxk = V[j - 1].im;
        if (absxk == 0.0) {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = 0.0;
        } else if (scale == 0.0) {
          V[j - 1].re = 0.0;
          V[j - 1].im = absxk / colnorm;
        } else {
          V[j - 1].re = scale / colnorm;
          V[j - 1].im = absxk / colnorm;
        }
      }

      for (info = 0; info < 16; info++) {
        At[info].re = 0.0;
        At[info].im = 0.0;
      }

      if (beta1[0].im == 0.0) {
        if (alpha1[0].im == 0.0) {
          At[0].re = alpha1[0].re / beta1[0].re;
          At[0].im = 0.0;
        } else if (alpha1[0].re == 0.0) {
          At[0].re = 0.0;
          At[0].im = alpha1[0].im / beta1[0].re;
        } else {
          At[0].re = alpha1[0].re / beta1[0].re;
          At[0].im = alpha1[0].im / beta1[0].re;
        }
      } else if (beta1[0].re == 0.0) {
        if (alpha1[0].re == 0.0) {
          At[0].re = alpha1[0].im / beta1[0].im;
          At[0].im = 0.0;
        } else if (alpha1[0].im == 0.0) {
          At[0].re = 0.0;
          At[0].im = -(alpha1[0].re / beta1[0].im);
        } else {
          At[0].re = alpha1[0].im / beta1[0].im;
          At[0].im = -(alpha1[0].re / beta1[0].im);
        }
      } else {
        t = fabs(beta1[0].re);
        scale = fabs(beta1[0].im);
        if (t > scale) {
          scale = beta1[0].im / beta1[0].re;
          absxk = beta1[0].re + scale * beta1[0].im;
          At[0].re = (alpha1[0].re + scale * alpha1[0].im) / absxk;
          At[0].im = (alpha1[0].im - scale * alpha1[0].re) / absxk;
        } else if (scale == t) {
          if (beta1[0].re > 0.0) {
            scale = 0.5;
          } else {
            scale = -0.5;
          }

          if (beta1[0].im > 0.0) {
            absxk = 0.5;
          } else {
            absxk = -0.5;
          }

          At[0].re = (alpha1[0].re * scale + alpha1[0].im * absxk) / t;
          At[0].im = (alpha1[0].im * scale - alpha1[0].re * absxk) / t;
        } else {
          scale = beta1[0].re / beta1[0].im;
          absxk = beta1[0].im + scale * beta1[0].re;
          At[0].re = (scale * alpha1[0].re + alpha1[0].im) / absxk;
          At[0].im = (scale * alpha1[0].im - alpha1[0].re) / absxk;
        }
      }

      if (beta1[1].im == 0.0) {
        if (alpha1[1].im == 0.0) {
          At[5].re = alpha1[1].re / beta1[1].re;
          At[5].im = 0.0;
        } else if (alpha1[1].re == 0.0) {
          At[5].re = 0.0;
          At[5].im = alpha1[1].im / beta1[1].re;
        } else {
          At[5].re = alpha1[1].re / beta1[1].re;
          At[5].im = alpha1[1].im / beta1[1].re;
        }
      } else if (beta1[1].re == 0.0) {
        if (alpha1[1].re == 0.0) {
          At[5].re = alpha1[1].im / beta1[1].im;
          At[5].im = 0.0;
        } else if (alpha1[1].im == 0.0) {
          At[5].re = 0.0;
          At[5].im = -(alpha1[1].re / beta1[1].im);
        } else {
          At[5].re = alpha1[1].im / beta1[1].im;
          At[5].im = -(alpha1[1].re / beta1[1].im);
        }
      } else {
        t = fabs(beta1[1].re);
        scale = fabs(beta1[1].im);
        if (t > scale) {
          scale = beta1[1].im / beta1[1].re;
          absxk = beta1[1].re + scale * beta1[1].im;
          At[5].re = (alpha1[1].re + scale * alpha1[1].im) / absxk;
          At[5].im = (alpha1[1].im - scale * alpha1[1].re) / absxk;
        } else if (scale == t) {
          if (beta1[1].re > 0.0) {
            scale = 0.5;
          } else {
            scale = -0.5;
          }

          if (beta1[1].im > 0.0) {
            absxk = 0.5;
          } else {
            absxk = -0.5;
          }

          At[5].re = (alpha1[1].re * scale + alpha1[1].im * absxk) / t;
          At[5].im = (alpha1[1].im * scale - alpha1[1].re * absxk) / t;
        } else {
          scale = beta1[1].re / beta1[1].im;
          absxk = beta1[1].im + scale * beta1[1].re;
          At[5].re = (scale * alpha1[1].re + alpha1[1].im) / absxk;
          At[5].im = (scale * alpha1[1].im - alpha1[1].re) / absxk;
        }
      }

      if (beta1[2].im == 0.0) {
        if (alpha1[2].im == 0.0) {
          At[10].re = alpha1[2].re / beta1[2].re;
          At[10].im = 0.0;
        } else if (alpha1[2].re == 0.0) {
          At[10].re = 0.0;
          At[10].im = alpha1[2].im / beta1[2].re;
        } else {
          At[10].re = alpha1[2].re / beta1[2].re;
          At[10].im = alpha1[2].im / beta1[2].re;
        }
      } else if (beta1[2].re == 0.0) {
        if (alpha1[2].re == 0.0) {
          At[10].re = alpha1[2].im / beta1[2].im;
          At[10].im = 0.0;
        } else if (alpha1[2].im == 0.0) {
          At[10].re = 0.0;
          At[10].im = -(alpha1[2].re / beta1[2].im);
        } else {
          At[10].re = alpha1[2].im / beta1[2].im;
          At[10].im = -(alpha1[2].re / beta1[2].im);
        }
      } else {
        t = fabs(beta1[2].re);
        scale = fabs(beta1[2].im);
        if (t > scale) {
          scale = beta1[2].im / beta1[2].re;
          absxk = beta1[2].re + scale * beta1[2].im;
          At[10].re = (alpha1[2].re + scale * alpha1[2].im) / absxk;
          At[10].im = (alpha1[2].im - scale * alpha1[2].re) / absxk;
        } else if (scale == t) {
          if (beta1[2].re > 0.0) {
            scale = 0.5;
          } else {
            scale = -0.5;
          }

          if (beta1[2].im > 0.0) {
            absxk = 0.5;
          } else {
            absxk = -0.5;
          }

          At[10].re = (alpha1[2].re * scale + alpha1[2].im * absxk) / t;
          At[10].im = (alpha1[2].im * scale - alpha1[2].re * absxk) / t;
        } else {
          scale = beta1[2].re / beta1[2].im;
          absxk = beta1[2].im + scale * beta1[2].re;
          At[10].re = (scale * alpha1[2].re + alpha1[2].im) / absxk;
          At[10].im = (scale * alpha1[2].im - alpha1[2].re) / absxk;
        }
      }

      if (beta1[3].im == 0.0) {
        if (alpha1[3].im == 0.0) {
          At[15].re = alpha1[3].re / beta1[3].re;
          At[15].im = 0.0;
        } else if (alpha1[3].re == 0.0) {
          At[15].re = 0.0;
          At[15].im = alpha1[3].im / beta1[3].re;
        } else {
          At[15].re = alpha1[3].re / beta1[3].re;
          At[15].im = alpha1[3].im / beta1[3].re;
        }
      } else if (beta1[3].re == 0.0) {
        if (alpha1[3].re == 0.0) {
          At[15].re = alpha1[3].im / beta1[3].im;
          At[15].im = 0.0;
        } else if (alpha1[3].im == 0.0) {
          At[15].re = 0.0;
          At[15].im = -(alpha1[3].re / beta1[3].im);
        } else {
          At[15].re = alpha1[3].im / beta1[3].im;
          At[15].im = -(alpha1[3].re / beta1[3].im);
        }
      } else {
        t = fabs(beta1[3].re);
        scale = fabs(beta1[3].im);
        if (t > scale) {
          scale = beta1[3].im / beta1[3].re;
          absxk = beta1[3].re + scale * beta1[3].im;
          At[15].re = (alpha1[3].re + scale * alpha1[3].im) / absxk;
          At[15].im = (alpha1[3].im - scale * alpha1[3].re) / absxk;
        } else if (scale == t) {
          if (beta1[3].re > 0.0) {
            scale = 0.5;
          } else {
            scale = -0.5;
          }

          if (beta1[3].im > 0.0) {
            absxk = 0.5;
          } else {
            absxk = -0.5;
          }

          At[15].re = (alpha1[3].re * scale + alpha1[3].im * absxk) / t;
          At[15].im = (alpha1[3].im * scale - alpha1[3].re * absxk) / t;
        } else {
          scale = beta1[3].re / beta1[3].im;
          absxk = beta1[3].im + scale * beta1[3].re;
          At[15].re = (scale * alpha1[3].re + alpha1[3].im) / absxk;
          At[15].im = (scale * alpha1[3].im - alpha1[3].re) / absxk;
        }
      }
    }
  }

  for (info = 0; info < 16; info++) {
    b_eigenvals[info] = At[info].re;
  }

  d[0] = b_eigenvals[0];
  d[1] = b_eigenvals[5];
  d[2] = b_eigenvals[10];
  d[3] = b_eigenvals[15];
  sort(d, iidx);
  for (i = 0; i < 4; i++) {
    eigenvals[i] = d[i];
    info = i << 2;
    eigenvects[info] = V[(iidx[i] - 1) << 2];
    eigenvects[1 + info] = V[1 + ((iidx[i] - 1) << 2)];
    eigenvects[2 + info] = V[2 + ((iidx[i] - 1) << 2)];
    eigenvects[3 + info] = V[3 + ((iidx[i] - 1) << 2)];
    if (d[i] < 0.0) {
      eigenvals[i] = 0.0;
    }
  }
}

//
// Arguments    : phased_MUSICEstimator2D *obj
//                const creal_T X[4000]
//                phased_URA *iobj_0
//                phased_IsotropicAntennaElement *iobj_1
// Return Type  : void
//
static void c_MUSICEstimator2D_privDOASpect(phased_MUSICEstimator2D *obj, const
  creal_T X[4000], phased_URA *iobj_0, phased_IsotropicAntennaElement *iobj_1)
{
  creal_T Cx[16];
  double eigenvals[4];
  creal_T eigenvects[16];
  phased_SteeringVector *hsv;
  int m;
  unsigned short u0;
  int i1;
  unsigned short tempidx[301];
  double tempangle[602];
  creal_T sv[1204];
  int tempangle_tmp;
  int b_tempangle_tmp;
  creal_T b_sv[903];
  double dv3[903];
  double dv4[903];
  double dv5[301];
  int sv_re_tmp;
  int b_sv_re_tmp;
  int c_sv_re_tmp;
  int d_sv_re_tmp;
  int e_sv_re_tmp;
  double re;
  double im;
  SystemCore_step(&obj->cCovEstimator, X, Cx);
  MUSICEstimator2D_privEig(Cx, eigenvals, eigenvects);
  hsv = &obj->cSteeringVector;
  for (m = 0; m < 121; m++) {
    u0 = (unsigned short)(301U * m + 1U);
    for (i1 = 0; i1 < 301; i1++) {
      tempidx[i1] = (unsigned short)((unsigned int)i1 + u0);
    }

    for (i1 = 0; i1 < 301; i1++) {
      tempangle_tmp = (tempidx[i1] - 1) << 1;
      b_tempangle_tmp = i1 << 1;
      tempangle[b_tempangle_tmp] = obj->pScanAngles[tempangle_tmp];
      tempangle[1 + b_tempangle_tmp] = obj->pScanAngles[1 + tempangle_tmp];
    }

    b_SystemCore_step(hsv, tempangle, iobj_0, iobj_1, sv);
    eps();
    for (i1 = 0; i1 < 301; i1++) {
      for (tempangle_tmp = 0; tempangle_tmp < 3; tempangle_tmp++) {
        b_tempangle_tmp = i1 + 301 * tempangle_tmp;
        b_sv[b_tempangle_tmp].re = 0.0;
        b_sv[b_tempangle_tmp].im = 0.0;
        sv_re_tmp = i1 << 2;
        b_sv_re_tmp = (1 + tempangle_tmp) << 2;
        c_sv_re_tmp = 1 + sv_re_tmp;
        d_sv_re_tmp = 2 + sv_re_tmp;
        e_sv_re_tmp = 3 + sv_re_tmp;
        re = (((sv[sv_re_tmp].re * eigenvects[b_sv_re_tmp].re - -sv[sv_re_tmp].
                im * eigenvects[(1 + tempangle_tmp) << 2].im) + (sv[c_sv_re_tmp]
                .re * eigenvects[1 + b_sv_re_tmp].re - -sv[c_sv_re_tmp].im *
                eigenvects[1 + ((1 + tempangle_tmp) << 2)].im)) +
              (sv[d_sv_re_tmp].re * eigenvects[2 + b_sv_re_tmp].re -
               -sv[d_sv_re_tmp].im * eigenvects[2 + ((1 + tempangle_tmp) << 2)].
               im)) + (sv[e_sv_re_tmp].re * eigenvects[3 + b_sv_re_tmp].re -
                       -sv[e_sv_re_tmp].im * eigenvects[3 + ((1 + tempangle_tmp)
          << 2)].im);
        im = (((sv[sv_re_tmp].re * eigenvects[(1 + tempangle_tmp) << 2].im +
                -sv[sv_re_tmp].im * eigenvects[(1 + tempangle_tmp) << 2].re) +
               (sv[c_sv_re_tmp].re * eigenvects[1 + ((1 + tempangle_tmp) << 2)].
                im + -sv[c_sv_re_tmp].im * eigenvects[1 + ((1 + tempangle_tmp) <<
                 2)].re)) + (sv[d_sv_re_tmp].re * eigenvects[2 + ((1 +
                 tempangle_tmp) << 2)].im + -sv[d_sv_re_tmp].im * eigenvects[2 +
                             ((1 + tempangle_tmp) << 2)].re)) + (sv[e_sv_re_tmp]
          .re * eigenvects[3 + ((1 + tempangle_tmp) << 2)].im + -sv[e_sv_re_tmp]
          .im * eigenvects[3 + ((1 + tempangle_tmp) << 2)].re);
        b_sv[b_tempangle_tmp].re = re;
        b_sv[b_tempangle_tmp].im = im;
      }
    }

    b_abs(b_sv, dv3);
    power(dv3, dv4);
    sum(dv4, dv5);
    for (i1 = 0; i1 < 301; i1++) {
      obj->pPattern[tempidx[i1] - 1] = 1.0 / (dv5[i1] + 2.2204460492503131E-16);
    }
  }
}

//
// Arguments    : phased_MUSICEstimator2D *obj
//                const creal_T X[4000]
//                phased_URA *iobj_0
//                phased_IsotropicAntennaElement *iobj_1
//                double scanpattern[36421]
//                double doasOut[2]
// Return Type  : void
//
void MUSICEstimator2D_stepImpl(phased_MUSICEstimator2D *obj, const creal_T X
  [4000], phased_URA *iobj_0, phased_IsotropicAntennaElement *iobj_1, double
  scanpattern[36421], double doasOut[2])
{
  int i;
  static double dv2[36421];
  double rowIndex_data[1];
  int rowIndex_size[1];
  double colIndex_data[1];
  int colIndex_size[1];
  int i0;
  c_MUSICEstimator2D_privDOASpect(obj, X, iobj_0, iobj_1);
  for (i = 0; i < 36421; i++) {
    dv2[i] = obj->pPattern[i];
  }

  c_sqrt(dv2);
  memcpy(&scanpattern[0], &dv2[0], 36421U * sizeof(double));
  c_AbstractSpectralDOA_privFindP(dv2, rowIndex_data, rowIndex_size,
    colIndex_data, colIndex_size);
  if (rowIndex_size[0] > 0) {
    doasOut[0] = rtNaN;
    doasOut[1] = rtNaN;
    i = colIndex_size[0];
    for (i0 = 0; i0 < i; i0++) {
      doasOut[0] = (short)((short)((int)colIndex_data[i0] - 1) - 150);
    }

    i = rowIndex_size[0];
    for (i0 = 0; i0 < i; i0++) {
      doasOut[1] = (signed char)((signed char)((int)rowIndex_data[i0] - 1) - 60);
    }
  } else {
    doasOut[0] = rtNaN;
    doasOut[1] = rtNaN;
  }
}

//
// File trailer for MUSICEstimator2D.cpp
//
// [EOF]
//
