//
// File: xztgevc.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xztgevc.h"

// Function Definitions

//
// Arguments    : const creal_T A[16]
//                creal_T V[16]
// Return Type  : void
//
void xztgevc(const creal_T A[16], creal_T V[16])
{
  double rworka[4];
  double anorm;
  int j;
  double xmx;
  int i;
  double d_re;
  double ascale;
  int je;
  int x_tmp;
  double temp;
  double salpha_re;
  double salpha_im;
  double acoeff;
  boolean_T lscalea;
  double z;
  boolean_T lscaleb;
  double scale;
  double acoefa;
  creal_T work1[4];
  double dmin;
  int i17;
  creal_T work2[4];
  int b_j;
  int d_re_tmp;
  double d_im;
  int i18;
  rworka[0] = 0.0;
  rworka[1] = 0.0;
  rworka[2] = 0.0;
  rworka[3] = 0.0;
  anorm = fabs(A[0].re) + fabs(A[0].im);
  for (j = 0; j < 3; j++) {
    for (i = 0; i <= j; i++) {
      rworka[j + 1] += fabs(A[i + ((j + 1) << 2)].re) + fabs(A[i + ((j + 1) << 2)]
        .im);
    }

    d_re = rworka[j + 1] + (fabs(A[(j + ((j + 1) << 2)) + 1].re) + fabs(A[(j +
      ((j + 1) << 2)) + 1].im));
    if (d_re > anorm) {
      anorm = d_re;
    }
  }

  xmx = anorm;
  if (2.2250738585072014E-308 > anorm) {
    xmx = 2.2250738585072014E-308;
  }

  ascale = 1.0 / xmx;
  for (je = 0; je < 4; je++) {
    x_tmp = (3 - je) << 2;
    xmx = (fabs(A[(x_tmp - je) + 3].re) + fabs(A[(((3 - je) << 2) - je) + 3].im))
      * ascale;
    if (1.0 > xmx) {
      xmx = 1.0;
    }

    temp = 1.0 / xmx;
    salpha_re = ascale * (temp * A[(((3 - je) << 2) - je) + 3].re);
    salpha_im = ascale * (temp * A[(((3 - je) << 2) - je) + 3].im);
    acoeff = temp * ascale;
    if ((temp >= 2.2250738585072014E-308) && (fabs(acoeff) <
         4.0083367200179456E-292)) {
      lscalea = true;
    } else {
      lscalea = false;
    }

    z = fabs(salpha_re) + fabs(salpha_im);
    if ((z >= 2.2250738585072014E-308) && (z < 4.0083367200179456E-292)) {
      lscaleb = true;
    } else {
      lscaleb = false;
    }

    scale = 1.0;
    if (lscalea) {
      xmx = anorm;
      if (2.4948003869184E+291 < anorm) {
        xmx = 2.4948003869184E+291;
      }

      scale = 4.0083367200179456E-292 / temp * xmx;
    }

    if (lscaleb) {
      d_re = 4.0083367200179456E-292 / z;
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (lscalea || lscaleb) {
      xmx = fabs(acoeff);
      if (1.0 > xmx) {
        xmx = 1.0;
      }

      if (z > xmx) {
        xmx = z;
      }

      d_re = 1.0 / (2.2250738585072014E-308 * xmx);
      if (d_re < scale) {
        scale = d_re;
      }

      if (lscalea) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }

      salpha_re *= scale;
      salpha_im *= scale;
    }

    acoefa = fabs(acoeff);
    work1[0].re = 0.0;
    work1[0].im = 0.0;
    work1[1].re = 0.0;
    work1[1].im = 0.0;
    work1[2].re = 0.0;
    work1[2].im = 0.0;
    work1[3].re = 0.0;
    work1[3].im = 0.0;
    work1[3 - je].re = 1.0;
    work1[3 - je].im = 0.0;
    dmin = 2.2204460492503131E-16 * acoefa * anorm;
    d_re = 2.2204460492503131E-16 * (fabs(salpha_re) + fabs(salpha_im));
    if (d_re > dmin) {
      dmin = d_re;
    }

    if (2.2250738585072014E-308 > dmin) {
      dmin = 2.2250738585072014E-308;
    }

    i17 = 2 - je;
    for (i = 0; i <= i17; i++) {
      work1[i].re = acoeff * A[i + x_tmp].re;
      work1[i].im = acoeff * A[i + ((3 - je) << 2)].im;
    }

    work1[3 - je].re = 1.0;
    work1[3 - je].im = 0.0;
    i17 = (int)((1.0 + (-1.0 - ((4.0 + -(double)je) - 1.0))) / -1.0);
    for (j = 0; j < i17; j++) {
      b_j = 2 - (je + j);
      d_re_tmp = b_j << 2;
      d_re = acoeff * A[b_j + d_re_tmp].re - salpha_re;
      d_im = acoeff * A[b_j + (b_j << 2)].im - salpha_im;
      if (fabs(d_re) + fabs(d_im) <= dmin) {
        d_re = dmin;
        d_im = 0.0;
      }

      xmx = fabs(d_re) + fabs(d_im);
      if (xmx < 1.0) {
        z = fabs(work1[b_j].re) + fabs(work1[b_j].im);
        if (z >= 1.1235582092889474E+307 * xmx) {
          temp = 1.0 / z;
          i18 = 3 - je;
          for (i = 0; i <= i18; i++) {
            work1[i].re *= temp;
            work1[i].im *= temp;
          }
        }
      }

      temp = -work1[b_j].re;
      if (d_im == 0.0) {
        if (-work1[b_j].im == 0.0) {
          work1[b_j].re = -work1[b_j].re / d_re;
          work1[b_j].im = 0.0;
        } else if (-work1[b_j].re == 0.0) {
          work1[b_j].re = 0.0;
          work1[b_j].im = -work1[b_j].im / d_re;
        } else {
          work1[b_j].re = -work1[b_j].re / d_re;
          work1[b_j].im = -work1[b_j].im / d_re;
        }
      } else if (d_re == 0.0) {
        if (-work1[b_j].re == 0.0) {
          work1[b_j].re = -work1[b_j].im / d_im;
          work1[b_j].im = 0.0;
        } else if (-work1[b_j].im == 0.0) {
          work1[b_j].re = 0.0;
          work1[b_j].im = -(temp / d_im);
        } else {
          work1[b_j].re = -work1[b_j].im / d_im;
          work1[b_j].im = -(temp / d_im);
        }
      } else {
        scale = fabs(d_re);
        xmx = fabs(d_im);
        if (scale > xmx) {
          z = d_im / d_re;
          xmx = d_re + z * d_im;
          work1[b_j].re = (-work1[b_j].re + z * -work1[b_j].im) / xmx;
          work1[b_j].im = (-work1[b_j].im - z * temp) / xmx;
        } else if (xmx == scale) {
          if (d_re > 0.0) {
            z = 0.5;
          } else {
            z = -0.5;
          }

          if (d_im > 0.0) {
            xmx = 0.5;
          } else {
            xmx = -0.5;
          }

          work1[b_j].re = (-work1[b_j].re * z + -work1[b_j].im * xmx) / scale;
          work1[b_j].im = (-work1[b_j].im * z - temp * xmx) / scale;
        } else {
          z = d_re / d_im;
          xmx = d_im + z * d_re;
          work1[b_j].re = (z * -work1[b_j].re + -work1[b_j].im) / xmx;
          work1[b_j].im = (z * -work1[b_j].im - temp) / xmx;
        }
      }

      if (b_j + 1 > 1) {
        xmx = fabs(work1[b_j].re) + fabs(work1[b_j].im);
        if (xmx > 1.0) {
          temp = 1.0 / xmx;
          if (acoefa * rworka[b_j] >= 1.1235582092889474E+307 * temp) {
            i18 = 3 - je;
            for (i = 0; i <= i18; i++) {
              work1[i].re *= temp;
              work1[i].im *= temp;
            }
          }
        }

        d_re = acoeff * work1[b_j].re;
        d_im = acoeff * work1[b_j].im;
        for (i = 0; i < b_j; i++) {
          work1[i].re += d_re * A[i + d_re_tmp].re - d_im * A[i + (b_j << 2)].im;
          work1[i].im += d_re * A[i + (b_j << 2)].im + d_im * A[i + (b_j << 2)].
            re;
        }
      }
    }

    work2[0].re = 0.0;
    work2[0].im = 0.0;
    work2[1].re = 0.0;
    work2[1].im = 0.0;
    work2[2].re = 0.0;
    work2[2].im = 0.0;
    work2[3].re = 0.0;
    work2[3].im = 0.0;
    i17 = 3 - je;
    for (i = 0; i <= i17; i++) {
      b_j = i << 2;
      work2[0].re += V[b_j].re * work1[i].re - V[i << 2].im * work1[i].im;
      work2[0].im += V[i << 2].re * work1[i].im + V[i << 2].im * work1[i].re;
      work2[1].re += V[1 + b_j].re * work1[i].re - V[1 + (i << 2)].im * work1[i]
        .im;
      work2[1].im += V[1 + (i << 2)].re * work1[i].im + V[1 + (i << 2)].im *
        work1[i].re;
      work2[2].re += V[2 + b_j].re * work1[i].re - V[2 + (i << 2)].im * work1[i]
        .im;
      work2[2].im += V[2 + (i << 2)].re * work1[i].im + V[2 + (i << 2)].im *
        work1[i].re;
      work2[3].re += V[3 + b_j].re * work1[i].re - V[3 + (i << 2)].im * work1[i]
        .im;
      work2[3].im += V[3 + (i << 2)].re * work1[i].im + V[3 + (i << 2)].im *
        work1[i].re;
    }

    xmx = fabs(work2[0].re) + fabs(work2[0].im);
    d_re = fabs(work2[1].re) + fabs(work2[1].im);
    if (d_re > xmx) {
      xmx = d_re;
    }

    d_re = fabs(work2[2].re) + fabs(work2[2].im);
    if (d_re > xmx) {
      xmx = d_re;
    }

    d_re = fabs(work2[3].re) + fabs(work2[3].im);
    if (d_re > xmx) {
      xmx = d_re;
    }

    if (xmx > 2.2250738585072014E-308) {
      temp = 1.0 / xmx;
      V[x_tmp].re = temp * work2[0].re;
      V[x_tmp].im = temp * work2[0].im;
      V[1 + ((3 - je) << 2)].re = temp * work2[1].re;
      V[1 + ((3 - je) << 2)].im = temp * work2[1].im;
      V[2 + ((3 - je) << 2)].re = temp * work2[2].re;
      V[2 + ((3 - je) << 2)].im = temp * work2[2].im;
      V[3 + ((3 - je) << 2)].re = temp * work2[3].re;
      V[3 + ((3 - je) << 2)].im = temp * work2[3].im;
    } else {
      V[x_tmp].re = 0.0;
      V[x_tmp].im = 0.0;
      i17 = 1 + x_tmp;
      V[i17].re = 0.0;
      V[i17].im = 0.0;
      i17 = 2 + x_tmp;
      V[i17].re = 0.0;
      V[i17].im = 0.0;
      i17 = 3 + x_tmp;
      V[i17].re = 0.0;
      V[i17].im = 0.0;
    }
  }
}

//
// File trailer for xztgevc.cpp
//
// [EOF]
//
