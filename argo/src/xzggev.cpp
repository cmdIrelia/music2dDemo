//
// File: xzggev.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xzggev.h"
#include "xzlartg.h"
#include "xztgevc.h"
#include "xzhgeqz.h"
#include "abs.h"
#include "music2D_rtwutil.h"

// Function Definitions

//
// Arguments    : creal_T A[16]
//                int *info
//                creal_T alpha1[4]
//                creal_T beta1[4]
//                creal_T V[16]
// Return Type  : void
//
void xzggev(creal_T A[16], int *info, creal_T alpha1[4], creal_T beta1[4],
            creal_T V[16])
{
  double anrm;
  int jcol;
  boolean_T exitg1;
  double absxk;
  boolean_T ilascl;
  double anrmto;
  int rscale[4];
  double ctoc;
  boolean_T notdone;
  int ilo;
  double cfrom1;
  int ihi;
  double stemp_re;
  int exitg3;
  double stemp_im;
  int i;
  int jcolp1;
  int j;
  int ii;
  int nzcount;
  creal_T atmp;
  boolean_T exitg4;
  int exitg2;
  signed char b_I[16];
  int jrow;
  *info = 0;
  anrm = 0.0;
  jcol = 0;
  exitg1 = false;
  while ((!exitg1) && (jcol < 16)) {
    absxk = rt_hypotd_snf(A[jcol].re, A[jcol].im);
    if (rtIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      jcol++;
    }
  }

  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
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
    for (jcolp1 = 0; jcolp1 < 16; jcolp1++) {
      V[jcolp1].re = rtNaN;
      V[jcolp1].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      absxk = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        cfrom1 = absxk * 2.0041683600089728E-292;
        stemp_re = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          stemp_im = 2.0041683600089728E-292;
          absxk = cfrom1;
        } else if (stemp_re > absxk) {
          stemp_im = 4.9896007738368E+291;
          ctoc = stemp_re;
        } else {
          stemp_im = ctoc / absxk;
          notdone = false;
        }

        for (jcolp1 = 0; jcolp1 < 16; jcolp1++) {
          A[jcolp1].re *= stemp_im;
          A[jcolp1].im *= stemp_im;
        }
      }
    }

    rscale[0] = 1;
    rscale[1] = 1;
    rscale[2] = 1;
    rscale[3] = 1;
    ilo = 1;
    ihi = 4;
    do {
      exitg3 = 0;
      i = 0;
      j = -1;
      notdone = false;
      ii = ihi;
      exitg1 = false;
      while ((!exitg1) && (ii > 0)) {
        nzcount = 0;
        i = ii;
        j = ihi - 1;
        jcol = 0;
        exitg4 = false;
        while ((!exitg4) && (jcol <= ihi - 1)) {
          if ((A[(ii + (jcol << 2)) - 1].re != 0.0) || (A[(ii + (jcol << 2)) - 1]
               .im != 0.0) || (ii == jcol + 1)) {
            if (nzcount == 0) {
              j = jcol;
              nzcount = 1;
              jcol++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            jcol++;
          }
        }

        if (nzcount < 2) {
          notdone = true;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (!notdone) {
        exitg3 = 2;
      } else {
        if (i != ihi) {
          atmp = A[i - 1];
          A[i - 1] = A[ihi - 1];
          A[ihi - 1] = atmp;
          atmp = A[i + 3];
          A[i + 3] = A[ihi + 3];
          A[ihi + 3] = atmp;
          atmp = A[i + 7];
          A[i + 7] = A[ihi + 7];
          A[ihi + 7] = atmp;
          atmp = A[i + 11];
          A[i + 11] = A[ihi + 11];
          A[ihi + 11] = atmp;
        }

        if (j + 1 != ihi) {
          for (jcol = 0; jcol < ihi; jcol++) {
            ii = jcol + (j << 2);
            atmp = A[ii];
            jcolp1 = jcol + ((ihi - 1) << 2);
            A[ii] = A[jcolp1];
            A[jcolp1] = atmp;
          }
        }

        rscale[ihi - 1] = j + 1;
        ihi--;
        if (ihi == 1) {
          rscale[0] = 1;
          exitg3 = 1;
        }
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
    } else {
      do {
        exitg2 = 0;
        i = 0;
        j = 0;
        notdone = false;
        jcol = ilo;
        exitg1 = false;
        while ((!exitg1) && (jcol <= ihi)) {
          nzcount = 0;
          i = ihi;
          j = jcol;
          ii = ilo;
          exitg4 = false;
          while ((!exitg4) && (ii <= ihi)) {
            if ((A[(ii + ((jcol - 1) << 2)) - 1].re != 0.0) || (A[(ii + ((jcol -
                    1) << 2)) - 1].im != 0.0) || (ii == jcol)) {
              if (nzcount == 0) {
                i = ii;
                nzcount = 1;
                ii++;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              ii++;
            }
          }

          if (nzcount < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            jcol++;
          }
        }

        if (!notdone) {
          exitg2 = 1;
        } else {
          if (i != ilo) {
            for (jcol = ilo; jcol < 5; jcol++) {
              ii = (jcol - 1) << 2;
              nzcount = (i + ii) - 1;
              atmp = A[nzcount];
              jcolp1 = (ilo + ii) - 1;
              A[nzcount] = A[jcolp1];
              A[jcolp1] = atmp;
            }
          }

          if (j != ilo) {
            for (jcol = 0; jcol < ihi; jcol++) {
              ii = jcol + ((j - 1) << 2);
              atmp = A[ii];
              jcolp1 = jcol + ((ilo - 1) << 2);
              A[ii] = A[jcolp1];
              A[jcolp1] = atmp;
            }
          }

          rscale[ilo - 1] = j;
          ilo++;
          if (ilo == ihi) {
            rscale[ilo - 1] = ilo;
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);
    }

    for (jcolp1 = 0; jcolp1 < 16; jcolp1++) {
      b_I[jcolp1] = 0;
    }

    b_I[0] = 1;
    b_I[5] = 1;
    b_I[10] = 1;
    b_I[15] = 1;
    for (jcolp1 = 0; jcolp1 < 16; jcolp1++) {
      V[jcolp1].re = b_I[jcolp1];
      V[jcolp1].im = 0.0;
    }

    if (ihi >= ilo + 2) {
      for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
        jcolp1 = jcol + 2;
        for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
          nzcount = jrow + (jcol << 2);
          xzlartg(A[nzcount - 1], A[nzcount], &cfrom1, &atmp, &A[(jrow + (jcol <<
                    2)) - 1]);
          A[nzcount].re = 0.0;
          A[nzcount].im = 0.0;
          for (j = jcolp1; j < 5; j++) {
            ii = jrow + ((j - 1) << 2);
            nzcount = ii - 1;
            stemp_re = cfrom1 * A[nzcount].re + (atmp.re * A[ii].re - atmp.im *
              A[jrow + ((j - 1) << 2)].im);
            stemp_im = cfrom1 * A[(jrow + ((j - 1) << 2)) - 1].im + (atmp.re *
              A[jrow + ((j - 1) << 2)].im + atmp.im * A[jrow + ((j - 1) << 2)].
              re);
            absxk = A[(jrow + ((j - 1) << 2)) - 1].im;
            ctoc = A[(jrow + ((j - 1) << 2)) - 1].re;
            A[ii].re = cfrom1 * A[jrow + ((j - 1) << 2)].re - (atmp.re * A[(jrow
              + ((j - 1) << 2)) - 1].re + atmp.im * A[(jrow + ((j - 1) << 2)) -
              1].im);
            A[ii].im = cfrom1 * A[jrow + ((j - 1) << 2)].im - (atmp.re * absxk -
              atmp.im * ctoc);
            A[nzcount].re = stemp_re;
            A[nzcount].im = stemp_im;
          }

          atmp.re = -atmp.re;
          atmp.im = -atmp.im;
          for (i = 1; i <= ihi; i++) {
            ii = (i + ((jrow - 1) << 2)) - 1;
            nzcount = (i + (jrow << 2)) - 1;
            stemp_re = cfrom1 * A[nzcount].re + (atmp.re * A[ii].re - atmp.im *
              A[(i + ((jrow - 1) << 2)) - 1].im);
            stemp_im = cfrom1 * A[(i + (jrow << 2)) - 1].im + (atmp.re * A[(i +
              ((jrow - 1) << 2)) - 1].im + atmp.im * A[(i + ((jrow - 1) << 2)) -
              1].re);
            absxk = A[(i + (jrow << 2)) - 1].im;
            ctoc = A[(i + (jrow << 2)) - 1].re;
            A[ii].re = cfrom1 * A[(i + ((jrow - 1) << 2)) - 1].re - (atmp.re *
              A[(i + (jrow << 2)) - 1].re + atmp.im * A[(i + (jrow << 2)) - 1].
              im);
            A[ii].im = cfrom1 * A[(i + ((jrow - 1) << 2)) - 1].im - (atmp.re *
              absxk - atmp.im * ctoc);
            A[nzcount].re = stemp_re;
            A[nzcount].im = stemp_im;
          }

          stemp_re = cfrom1 * V[jrow << 2].re + (atmp.re * V[(jrow - 1) << 2].re
            - atmp.im * V[(jrow - 1) << 2].im);
          stemp_im = cfrom1 * V[jrow << 2].im + (atmp.re * V[(jrow - 1) << 2].im
            + atmp.im * V[(jrow - 1) << 2].re);
          absxk = V[jrow << 2].re;
          V[(jrow - 1) << 2].re = cfrom1 * V[(jrow - 1) << 2].re - (atmp.re *
            V[jrow << 2].re + atmp.im * V[jrow << 2].im);
          V[(jrow - 1) << 2].im = cfrom1 * V[(jrow - 1) << 2].im - (atmp.re *
            V[jrow << 2].im - atmp.im * absxk);
          V[jrow << 2].re = stemp_re;
          V[jrow << 2].im = stemp_im;
          ii = 1 + ((jrow - 1) << 2);
          nzcount = 1 + (jrow << 2);
          stemp_re = cfrom1 * V[nzcount].re + (atmp.re * V[ii].re - atmp.im * V
            [1 + ((jrow - 1) << 2)].im);
          stemp_im = cfrom1 * V[1 + (jrow << 2)].im + (atmp.re * V[1 + ((jrow -
            1) << 2)].im + atmp.im * V[1 + ((jrow - 1) << 2)].re);
          absxk = V[1 + (jrow << 2)].re;
          V[ii].re = cfrom1 * V[1 + ((jrow - 1) << 2)].re - (atmp.re * V[1 +
            (jrow << 2)].re + atmp.im * V[1 + (jrow << 2)].im);
          V[ii].im = cfrom1 * V[ii].im - (atmp.re * V[1 + (jrow << 2)].im -
            atmp.im * absxk);
          V[nzcount].re = stemp_re;
          V[nzcount].im = stemp_im;
          ii = 2 + ((jrow - 1) << 2);
          nzcount = 2 + (jrow << 2);
          stemp_re = cfrom1 * V[nzcount].re + (atmp.re * V[ii].re - atmp.im * V
            [2 + ((jrow - 1) << 2)].im);
          stemp_im = cfrom1 * V[2 + (jrow << 2)].im + (atmp.re * V[2 + ((jrow -
            1) << 2)].im + atmp.im * V[2 + ((jrow - 1) << 2)].re);
          absxk = V[2 + (jrow << 2)].re;
          V[ii].re = cfrom1 * V[2 + ((jrow - 1) << 2)].re - (atmp.re * V[2 +
            (jrow << 2)].re + atmp.im * V[2 + (jrow << 2)].im);
          V[ii].im = cfrom1 * V[ii].im - (atmp.re * V[2 + (jrow << 2)].im -
            atmp.im * absxk);
          V[nzcount].re = stemp_re;
          V[nzcount].im = stemp_im;
          ii = 3 + ((jrow - 1) << 2);
          nzcount = 3 + (jrow << 2);
          stemp_re = cfrom1 * V[nzcount].re + (atmp.re * V[ii].re - atmp.im * V
            [3 + ((jrow - 1) << 2)].im);
          stemp_im = cfrom1 * V[3 + (jrow << 2)].im + (atmp.re * V[3 + ((jrow -
            1) << 2)].im + atmp.im * V[3 + ((jrow - 1) << 2)].re);
          absxk = V[3 + (jrow << 2)].re;
          V[ii].re = cfrom1 * V[3 + ((jrow - 1) << 2)].re - (atmp.re * V[3 +
            (jrow << 2)].re + atmp.im * V[3 + (jrow << 2)].im);
          V[ii].im = cfrom1 * V[ii].im - (atmp.re * V[3 + (jrow << 2)].im -
            atmp.im * absxk);
          V[nzcount].re = stemp_re;
          V[nzcount].im = stemp_im;
        }
      }
    }

    xzhgeqz(A, ilo, ihi, V, info, alpha1, beta1);
    if (*info == 0) {
      xztgevc(A, V);
      if (ilo > 1) {
        for (i = ilo - 2; i + 1 >= 1; i--) {
          jcol = rscale[i] - 1;
          if (rscale[i] != i + 1) {
            atmp = V[i];
            V[i] = V[jcol];
            V[jcol] = atmp;
            atmp = V[i + 4];
            V[i + 4] = V[jcol + 4];
            V[jcol + 4] = atmp;
            atmp = V[i + 8];
            V[i + 8] = V[jcol + 8];
            V[jcol + 8] = atmp;
            atmp = V[i + 12];
            V[i + 12] = V[jcol + 12];
            V[jcol + 12] = atmp;
          }
        }
      }

      if (ihi < 4) {
        jcolp1 = ihi + 1;
        for (i = jcolp1; i < 5; i++) {
          nzcount = rscale[i - 1];
          if (nzcount != i) {
            atmp = V[i - 1];
            V[i - 1] = V[nzcount - 1];
            V[nzcount - 1] = atmp;
            atmp = V[i + 3];
            V[i + 3] = V[nzcount + 3];
            V[nzcount + 3] = atmp;
            atmp = V[i + 7];
            V[i + 7] = V[nzcount + 7];
            V[nzcount + 7] = atmp;
            atmp = V[i + 11];
            V[i + 11] = V[nzcount + 11];
            V[nzcount + 11] = atmp;
          }
        }
      }

      for (nzcount = 0; nzcount < 4; nzcount++) {
        ii = nzcount << 2;
        absxk = fabs(V[ii].re) + fabs(V[nzcount << 2].im);
        ctoc = fabs(V[ii + 1].re) + fabs(V[(nzcount << 2) + 1].im);
        if (ctoc > absxk) {
          absxk = ctoc;
        }

        ctoc = fabs(V[ii + 2].re) + fabs(V[(nzcount << 2) + 2].im);
        if (ctoc > absxk) {
          absxk = ctoc;
        }

        ctoc = fabs(V[ii + 3].re) + fabs(V[(nzcount << 2) + 3].im);
        if (ctoc > absxk) {
          absxk = ctoc;
        }

        if (absxk >= 6.7178761075670888E-139) {
          absxk = 1.0 / absxk;
          V[ii].re = absxk * V[nzcount << 2].re;
          V[ii].im *= absxk;
          jcolp1 = 1 + ii;
          V[jcolp1].re *= absxk;
          V[jcolp1].im *= absxk;
          jcolp1 = 2 + ii;
          V[jcolp1].re *= absxk;
          V[jcolp1].im *= absxk;
          jcolp1 = 3 + ii;
          V[jcolp1].re *= absxk;
          V[jcolp1].im *= absxk;
        }
      }

      if (ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          stemp_re = anrm / 4.9896007738368E+291;
          if ((cfrom1 > anrm) && (anrm != 0.0)) {
            stemp_im = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (stemp_re > anrmto) {
            stemp_im = 4.9896007738368E+291;
            anrm = stemp_re;
          } else {
            stemp_im = anrm / anrmto;
            notdone = false;
          }

          alpha1[0].re *= stemp_im;
          alpha1[0].im *= stemp_im;
          alpha1[1].re *= stemp_im;
          alpha1[1].im *= stemp_im;
          alpha1[2].re *= stemp_im;
          alpha1[2].im *= stemp_im;
          alpha1[3].re *= stemp_im;
          alpha1[3].im *= stemp_im;
        }
      }
    }
  }
}

//
// File trailer for xzggev.cpp
//
// [EOF]
//
