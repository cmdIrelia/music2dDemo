//
// File: xhseqr.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include <math.h>
#include "rt_nonfinite.h"
#include "music2D.h"
#include "xhseqr.h"
#include "abs.h"
#include "recip.h"
#include "xdlapy3.h"
#include "sqrt.h"
#include "music2D_rtwutil.h"

// Function Definitions

//
// Arguments    : creal_T h[16]
//                creal_T z[16]
// Return Type  : int
//
int xhseqr(creal_T h[16], creal_T z[16])
{
  int info;
  int i;
  int i15;
  boolean_T exitg1;
  double tst;
  double ab;
  int L;
  double br;
  boolean_T goto140;
  int its;
  creal_T sc;
  boolean_T exitg2;
  int k;
  boolean_T exitg3;
  double ba;
  int ix0_tmp;
  int knt;
  double t_re;
  double t_im;
  boolean_T goto70;
  creal_T v;
  int m;
  int i16;
  double u_re;
  double u_im;
  int b_k;
  double s;
  double aa;
  creal_T b_v[2];
  int j;
  int c_k;
  info = 0;
  h[2].re = 0.0;
  h[2].im = 0.0;
  h[3].re = 0.0;
  h[3].im = 0.0;
  h[7].re = 0.0;
  h[7].im = 0.0;
  for (i = 0; i < 3; i++) {
    i15 = (i + (i << 2)) + 1;
    if (h[i15].im != 0.0) {
      tst = h[(i + (i << 2)) + 1].re;
      ab = h[(i + (i << 2)) + 1].im;
      br = fabs(h[(i + (i << 2)) + 1].re) + fabs(h[(i + (i << 2)) + 1].im);
      if (ab == 0.0) {
        sc.re = tst / br;
        sc.im = 0.0;
      } else if (tst == 0.0) {
        sc.re = 0.0;
        sc.im = ab / br;
      } else {
        sc.re = tst / br;
        sc.im = ab / br;
      }

      br = rt_hypotd_snf(sc.re, sc.im);
      if (-sc.im == 0.0) {
        sc.re /= br;
        sc.im = 0.0;
      } else if (sc.re == 0.0) {
        sc.re = 0.0;
        sc.im = -sc.im / br;
      } else {
        sc.re /= br;
        sc.im = -sc.im / br;
      }

      h[i15].re = rt_hypotd_snf(h[(i + (i << 2)) + 1].re, h[(i + (i << 2)) + 1].
        im);
      h[i15].im = 0.0;
      ix0_tmp = (i + 1) << 2;
      knt = (i + ix0_tmp) + 2;
      i15 = knt + ((2 - i) << 2);
      for (k = knt; k <= i15; k += 4) {
        ab = h[k - 1].re;
        tst = h[k - 1].im;
        h[k - 1].re = sc.re * ab - sc.im * tst;
        h[k - 1].im = sc.re * tst + sc.im * ab;
      }

      knt = ix0_tmp + 1;
      t_re = sc.re;
      t_im = -sc.im;
      if (4 < i + 3) {
        i16 = 1;
      } else {
        i16 = i;
      }

      i15 = ix0_tmp + i16;
      for (k = knt; k <= i15 + 3; k++) {
        ab = h[k - 1].re;
        tst = h[k - 1].im;
        h[k - 1].re = t_re * ab - t_im * tst;
        h[k - 1].im = t_re * tst + t_im * ab;
      }

      t_re = sc.re;
      t_im = -sc.im;
      i15 = ix0_tmp + 4;
      for (k = knt; k <= i15; k++) {
        ab = z[k - 1].re;
        tst = z[k - 1].im;
        z[k - 1].re = t_re * ab - t_im * tst;
        z[k - 1].im = t_re * tst + t_im * ab;
      }
    }
  }

  i = 3;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    L = -1;
    goto140 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L + 2)) {
        i15 = k + ((k - 1) << 2);
        ab = fabs(h[i15].re);
        ba = ab + fabs(h[k + ((k - 1) << 2)].im);
        if (ba <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          knt = k + (k << 2);
          t_im = fabs(h[knt].re) + fabs(h[k + (k << 2)].im);
          tst = (fabs(h[i15 - 1].re) + fabs(h[(k + ((k - 1) << 2)) - 1].im)) +
            t_im;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = fabs(h[(k + ((k - 2) << 2)) - 1].re);
            }

            if (k + 2 <= 4) {
              tst += fabs(h[knt + 1].re);
            }
          }

          if (ab <= 2.2204460492503131E-16 * tst) {
            tst = fabs(h[knt - 1].re) + fabs(h[(k + (k << 2)) - 1].im);
            if (ba > tst) {
              ab = ba;
              ba = tst;
            } else {
              ab = tst;
            }

            tst = fabs(h[(k + ((k - 1) << 2)) - 1].re - h[k + (k << 2)].re) +
              fabs(h[(k + ((k - 1) << 2)) - 1].im - h[k + (k << 2)].im);
            if (t_im > tst) {
              aa = t_im;
              t_im = tst;
            } else {
              aa = tst;
            }

            s = aa + ab;
            if (ba * (ab / s) <= fmax(4.0083367200179456E-292,
                 2.2204460492503131E-16 * (t_im * (aa / s)))) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k - 1;
      if (k + 1 > 1) {
        h[k + ((k - 1) << 2)].re = 0.0;
        h[k + ((k - 1) << 2)].im = 0.0;
      }

      if (k + 1 >= i + 1) {
        goto140 = true;
        exitg2 = true;
      } else {
        if (its == 10) {
          t_re = 0.75 * fabs(h[(k + (k << 2)) + 1].re) + h[k + (k << 2)].re;
          t_im = h[k + (k << 2)].im;
        } else if (its == 20) {
          t_re = 0.75 * fabs(h[i + ((i - 1) << 2)].re) + h[i + (i << 2)].re;
          t_im = h[i + (i << 2)].im;
        } else {
          ix0_tmp = i + (i << 2);
          t_re = h[ix0_tmp].re;
          t_im = h[i + (i << 2)].im;
          v = h[ix0_tmp - 1];
          b_sqrt(&v);
          knt = i + ((i - 1) << 2);
          sc = h[knt];
          b_sqrt(&sc);
          u_re = v.re * sc.re - v.im * sc.im;
          u_im = v.re * sc.im + v.im * sc.re;
          s = fabs(u_re) + fabs(u_im);
          if (s != 0.0) {
            aa = 0.5 * (h[knt - 1].re - h[i + (i << 2)].re);
            ba = 0.5 * (h[(i + ((i - 1) << 2)) - 1].im - h[i + (i << 2)].im);
            tst = fabs(aa) + fabs(ba);
            s = fmax(s, tst);
            if (ba == 0.0) {
              t_re = aa / s;
              t_im = 0.0;
            } else if (aa == 0.0) {
              t_re = 0.0;
              t_im = ba / s;
            } else {
              t_re = aa / s;
              t_im = ba / s;
            }

            ab = t_re;
            t_re = t_re * t_re - t_im * t_im;
            t_im = ab * t_im + t_im * ab;
            if (u_im == 0.0) {
              sc.re = u_re / s;
              sc.im = 0.0;
            } else if (u_re == 0.0) {
              sc.re = 0.0;
              sc.im = u_im / s;
            } else {
              sc.re = u_re / s;
              sc.im = u_im / s;
            }

            v.re = t_re + (sc.re * sc.re - sc.im * sc.im);
            v.im = t_im + (sc.re * sc.im + sc.im * sc.re);
            b_sqrt(&v);
            sc.re = s * v.re;
            sc.im = s * v.im;
            if (tst > 0.0) {
              if (ba == 0.0) {
                t_re = aa / tst;
                t_im = 0.0;
              } else if (aa == 0.0) {
                t_re = 0.0;
                t_im = ba / tst;
              } else {
                t_re = aa / tst;
                t_im = ba / tst;
              }

              if (t_re * sc.re + t_im * sc.im < 0.0) {
                sc.re = -sc.re;
                sc.im = -sc.im;
              }
            }

            br = aa + sc.re;
            aa = ba + sc.im;
            if (aa == 0.0) {
              if (u_im == 0.0) {
                t_im = u_re / br;
                tst = 0.0;
              } else if (u_re == 0.0) {
                t_im = 0.0;
                tst = u_im / br;
              } else {
                t_im = u_re / br;
                tst = u_im / br;
              }
            } else if (br == 0.0) {
              if (u_re == 0.0) {
                t_im = u_im / aa;
                tst = 0.0;
              } else if (u_im == 0.0) {
                t_im = 0.0;
                tst = -(u_re / aa);
              } else {
                t_im = u_im / aa;
                tst = -(u_re / aa);
              }
            } else {
              ba = fabs(br);
              tst = fabs(aa);
              if (ba > tst) {
                s = aa / br;
                tst = br + s * aa;
                t_im = (u_re + s * u_im) / tst;
                tst = (u_im - s * u_re) / tst;
              } else if (tst == ba) {
                if (br > 0.0) {
                  ab = 0.5;
                } else {
                  ab = -0.5;
                }

                if (aa > 0.0) {
                  tst = 0.5;
                } else {
                  tst = -0.5;
                }

                t_im = (u_re * ab + u_im * tst) / ba;
                tst = (u_im * ab - u_re * tst) / ba;
              } else {
                s = br / aa;
                tst = aa + s * br;
                t_im = (s * u_re + u_im) / tst;
                tst = (s * u_im - u_re) / tst;
              }
            }

            t_re = h[i + (i << 2)].re - (u_re * t_im - u_im * tst);
            t_im = h[i + (i << 2)].im - (u_re * tst + u_im * t_im);
          }
        }

        goto70 = false;
        m = i;
        exitg3 = false;
        while ((!exitg3) && (m > k + 1)) {
          knt = m + ((m - 1) << 2);
          sc.re = h[knt - 1].re - t_re;
          sc.im = h[(m + ((m - 1) << 2)) - 1].im - t_im;
          ab = h[knt].re;
          s = (fabs(sc.re) + fabs(sc.im)) + fabs(ab);
          if (sc.im == 0.0) {
            sc.re /= s;
            sc.im = 0.0;
          } else if (sc.re == 0.0) {
            sc.re = 0.0;
            sc.im /= s;
          } else {
            sc.re /= s;
            sc.im /= s;
          }

          ab /= s;
          b_v[0] = sc;
          b_v[1].re = ab;
          b_v[1].im = 0.0;
          if (fabs(h[(m + ((m - 2) << 2)) - 1].re) * fabs(ab) <=
              2.2204460492503131E-16 * ((fabs(sc.re) + fabs(sc.im)) * ((fabs(h
                  [(m + ((m - 1) << 2)) - 1].re) + fabs(h[(m + ((m - 1) << 2)) -
                  1].im)) + (fabs(h[m + (m << 2)].re) + fabs(h[m + (m << 2)].im)))))
          {
            goto70 = true;
            exitg3 = true;
          } else {
            m--;
          }
        }

        if (!goto70) {
          sc.re = h[k + (k << 2)].re - t_re;
          sc.im = h[k + (k << 2)].im - t_im;
          ab = h[(k + (k << 2)) + 1].re;
          s = (fabs(sc.re) + fabs(sc.im)) + fabs(ab);
          if (sc.im == 0.0) {
            b_v[0].re = sc.re / s;
            b_v[0].im = 0.0;
          } else if (sc.re == 0.0) {
            b_v[0].re = 0.0;
            b_v[0].im = sc.im / s;
          } else {
            b_v[0].re = sc.re / s;
            b_v[0].im = sc.im / s;
          }

          ab /= s;
          b_v[1].re = ab;
          b_v[1].im = 0.0;
        }

        for (b_k = m; b_k <= i; b_k++) {
          if (b_k > m) {
            knt = b_k + ((b_k - 2) << 2);
            b_v[0] = h[knt - 1];
            b_v[1] = h[knt];
          }

          sc = b_v[0];
          aa = b_v[1].re;
          ba = b_v[1].im;
          t_re = 0.0;
          t_im = 0.0;
          tst = rt_hypotd_snf(b_v[1].re, b_v[1].im);
          if ((tst != 0.0) || (b_v[0].im != 0.0)) {
            ab = xdlapy3(b_v[0].re, b_v[0].im, tst);
            if (b_v[0].re >= 0.0) {
              ab = -ab;
            }

            if (fabs(ab) < 1.0020841800044864E-292) {
              knt = -1;
              do {
                knt++;
                aa *= 9.9792015476736E+291;
                ba *= 9.9792015476736E+291;
                ab *= 9.9792015476736E+291;
                sc.re *= 9.9792015476736E+291;
                sc.im *= 9.9792015476736E+291;
              } while (!(fabs(ab) >= 1.0020841800044864E-292));

              ab = xdlapy3(sc.re, sc.im, rt_hypotd_snf(aa, ba));
              if (sc.re >= 0.0) {
                ab = -ab;
              }

              tst = ab - sc.re;
              if (0.0 - sc.im == 0.0) {
                t_re = tst / ab;
                t_im = 0.0;
              } else if (tst == 0.0) {
                t_re = 0.0;
                t_im = (0.0 - sc.im) / ab;
              } else {
                t_re = tst / ab;
                t_im = (0.0 - sc.im) / ab;
              }

              v.re = sc.re - ab;
              v.im = sc.im;
              sc = recip(v);
              tst = aa;
              aa = sc.re * aa - sc.im * ba;
              ba = sc.re * ba + sc.im * tst;
              for (c_k = 0; c_k <= knt; c_k++) {
                ab *= 1.0020841800044864E-292;
              }

              sc.re = ab;
              sc.im = 0.0;
            } else {
              tst = ab - b_v[0].re;
              if (0.0 - b_v[0].im == 0.0) {
                t_re = tst / ab;
                t_im = 0.0;
              } else if (tst == 0.0) {
                t_re = 0.0;
                t_im = (0.0 - b_v[0].im) / ab;
              } else {
                t_re = tst / ab;
                t_im = (0.0 - b_v[0].im) / ab;
              }

              v.re = b_v[0].re - ab;
              v.im = b_v[0].im;
              v = recip(v);
              aa = v.re * b_v[1].re - v.im * b_v[1].im;
              ba = v.re * b_v[1].im + v.im * b_v[1].re;
              sc.re = ab;
              sc.im = 0.0;
            }
          }

          b_v[0] = sc;
          b_v[1].re = aa;
          b_v[1].im = ba;
          if (b_k > m) {
            h[(b_k + ((b_k - 2) << 2)) - 1] = sc;
            h[b_k + ((b_k - 2) << 2)].re = 0.0;
            h[b_k + ((b_k - 2) << 2)].im = 0.0;
          }

          ab = t_re * aa - t_im * ba;
          for (j = b_k; j < 5; j++) {
            ix0_tmp = b_k + ((j - 1) << 2);
            knt = ix0_tmp - 1;
            sc.re = (t_re * h[knt].re - -t_im * h[(b_k + ((j - 1) << 2)) - 1].im)
              + ab * h[ix0_tmp].re;
            sc.im = (t_re * h[(b_k + ((j - 1) << 2)) - 1].im + -t_im * h[(b_k +
                      ((j - 1) << 2)) - 1].re) + ab * h[b_k + ((j - 1) << 2)].im;
            h[knt].re = h[(b_k + ((j - 1) << 2)) - 1].re - sc.re;
            h[knt].im = h[(b_k + ((j - 1) << 2)) - 1].im - sc.im;
            h[ix0_tmp].re = h[b_k + ((j - 1) << 2)].re - (sc.re * aa - sc.im *
              ba);
            h[ix0_tmp].im = h[b_k + ((j - 1) << 2)].im - (sc.re * ba + sc.im *
              aa);
          }

          if (b_k + 2 < i + 1) {
            i15 = b_k + 1;
          } else {
            i15 = i;
          }

          for (j = 0; j <= i15; j++) {
            ix0_tmp = j + ((b_k - 1) << 2);
            knt = j + (b_k << 2);
            sc.re = (t_re * h[ix0_tmp].re - t_im * h[j + ((b_k - 1) << 2)].im) +
              ab * h[knt].re;
            sc.im = (t_re * h[j + ((b_k - 1) << 2)].im + t_im * h[j + ((b_k - 1)
                      << 2)].re) + ab * h[j + (b_k << 2)].im;
            h[ix0_tmp].re = h[j + ((b_k - 1) << 2)].re - sc.re;
            h[ix0_tmp].im = h[j + ((b_k - 1) << 2)].im - sc.im;
            h[knt].re = h[j + (b_k << 2)].re - (sc.re * aa - sc.im * -ba);
            h[knt].im = h[j + (b_k << 2)].im - (sc.re * -ba + sc.im * aa);
          }

          sc.re = (t_re * z[(b_k - 1) << 2].re - t_im * z[(b_k - 1) << 2].im) +
            ab * z[b_k << 2].re;
          sc.im = (t_re * z[(b_k - 1) << 2].im + t_im * z[(b_k - 1) << 2].re) +
            ab * z[b_k << 2].im;
          z[(b_k - 1) << 2].re -= sc.re;
          z[(b_k - 1) << 2].im -= sc.im;
          z[b_k << 2].re -= sc.re * aa - sc.im * -ba;
          z[b_k << 2].im -= sc.re * -ba + sc.im * aa;
          ix0_tmp = 1 + ((b_k - 1) << 2);
          knt = 1 + (b_k << 2);
          sc.re = (t_re * z[ix0_tmp].re - t_im * z[1 + ((b_k - 1) << 2)].im) +
            ab * z[knt].re;
          sc.im = (t_re * z[1 + ((b_k - 1) << 2)].im + t_im * z[1 + ((b_k - 1) <<
                    2)].re) + ab * z[1 + (b_k << 2)].im;
          z[ix0_tmp].re = z[1 + ((b_k - 1) << 2)].re - sc.re;
          z[ix0_tmp].im = z[1 + ((b_k - 1) << 2)].im - sc.im;
          z[knt].re = z[1 + (b_k << 2)].re - (sc.re * aa - sc.im * -ba);
          z[knt].im = z[1 + (b_k << 2)].im - (sc.re * -ba + sc.im * aa);
          ix0_tmp = 2 + ((b_k - 1) << 2);
          knt = 2 + (b_k << 2);
          sc.re = (t_re * z[ix0_tmp].re - t_im * z[2 + ((b_k - 1) << 2)].im) +
            ab * z[knt].re;
          sc.im = (t_re * z[2 + ((b_k - 1) << 2)].im + t_im * z[2 + ((b_k - 1) <<
                    2)].re) + ab * z[2 + (b_k << 2)].im;
          z[ix0_tmp].re = z[2 + ((b_k - 1) << 2)].re - sc.re;
          z[ix0_tmp].im = z[2 + ((b_k - 1) << 2)].im - sc.im;
          z[knt].re = z[2 + (b_k << 2)].re - (sc.re * aa - sc.im * -ba);
          z[knt].im = z[2 + (b_k << 2)].im - (sc.re * -ba + sc.im * aa);
          ix0_tmp = 3 + ((b_k - 1) << 2);
          knt = 3 + (b_k << 2);
          sc.re = (t_re * z[ix0_tmp].re - t_im * z[3 + ((b_k - 1) << 2)].im) +
            ab * z[knt].re;
          sc.im = (t_re * z[3 + ((b_k - 1) << 2)].im + t_im * z[3 + ((b_k - 1) <<
                    2)].re) + ab * z[3 + (b_k << 2)].im;
          z[ix0_tmp].re = z[3 + ((b_k - 1) << 2)].re - sc.re;
          z[ix0_tmp].im = z[3 + ((b_k - 1) << 2)].im - sc.im;
          z[knt].re = z[3 + (b_k << 2)].re - (sc.re * aa - sc.im * -ba);
          z[knt].im = z[3 + (b_k << 2)].im - (sc.re * -ba + sc.im * aa);
          if ((b_k == m) && (m > k + 1)) {
            br = rt_hypotd_snf(1.0 - t_re, 0.0 - t_im);
            if (0.0 - t_im == 0.0) {
              sc.re = (1.0 - t_re) / br;
              sc.im = 0.0;
            } else if (1.0 - t_re == 0.0) {
              sc.re = 0.0;
              sc.im = (0.0 - t_im) / br;
            } else {
              sc.re = (1.0 - t_re) / br;
              sc.im = (0.0 - t_im) / br;
            }

            ab = h[m + ((m - 1) << 2)].re;
            tst = h[m + ((m - 1) << 2)].im;
            h[m + ((m - 1) << 2)].re = ab * sc.re - tst * -sc.im;
            h[m + ((m - 1) << 2)].im = ab * -sc.im + tst * sc.re;
            if (m + 2 <= i + 1) {
              knt = 3 + (m << 2);
              ab = h[knt].re;
              tst = h[3 + (m << 2)].im;
              h[knt].re = ab * sc.re - tst * sc.im;
              h[knt].im = ab * sc.im + tst * sc.re;
            }

            for (j = m; j <= i + 1; j++) {
              if (j != m + 1) {
                if (4 > j) {
                  knt = j + (j << 2);
                  i15 = knt + ((3 - j) << 2);
                  for (c_k = knt; c_k <= i15; c_k += 4) {
                    ab = h[c_k - 1].re;
                    tst = h[c_k - 1].im;
                    h[c_k - 1].re = sc.re * ab - sc.im * tst;
                    h[c_k - 1].im = sc.re * tst + sc.im * ab;
                  }
                }

                ix0_tmp = (j - 1) << 2;
                knt = ix0_tmp + 1;
                t_re = sc.re;
                t_im = -sc.im;
                i15 = (ix0_tmp + j) - 1;
                for (c_k = knt; c_k <= i15; c_k++) {
                  ab = h[c_k - 1].re;
                  tst = h[c_k - 1].im;
                  h[c_k - 1].re = t_re * ab - t_im * tst;
                  h[c_k - 1].im = t_re * tst + t_im * ab;
                }

                t_re = sc.re;
                t_im = -sc.im;
                i15 = ix0_tmp + 4;
                for (c_k = knt; c_k <= i15; c_k++) {
                  ab = z[c_k - 1].re;
                  tst = z[c_k - 1].im;
                  z[c_k - 1].re = t_re * ab - t_im * tst;
                  z[c_k - 1].im = t_re * tst + t_im * ab;
                }
              }
            }
          }
        }

        sc = h[i + ((i - 1) << 2)];
        if (h[i + ((i - 1) << 2)].im != 0.0) {
          ab = rt_hypotd_snf(h[i + ((i - 1) << 2)].re, h[i + ((i - 1) << 2)].im);
          h[i + ((i - 1) << 2)].re = ab;
          h[i + ((i - 1) << 2)].im = 0.0;
          if (sc.im == 0.0) {
            sc.re /= ab;
            sc.im = 0.0;
          } else if (sc.re == 0.0) {
            sc.re = 0.0;
            sc.im /= ab;
          } else {
            sc.re /= ab;
            sc.im /= ab;
          }

          if (4 > i + 1) {
            knt = (i + ((i + 1) << 2)) + 1;
            t_re = sc.re;
            t_im = -sc.im;
            i15 = knt + ((2 - i) << 2);
            for (k = knt; k <= i15; k += 4) {
              ab = h[k - 1].re;
              tst = h[k - 1].im;
              h[k - 1].re = t_re * ab - t_im * tst;
              h[k - 1].im = t_re * tst + t_im * ab;
            }
          }

          ix0_tmp = (i << 2) + 1;
          i15 = (i << 2) + i;
          for (k = ix0_tmp; k <= i15; k++) {
            ab = h[k - 1].re;
            tst = h[k - 1].im;
            h[k - 1].re = sc.re * ab - sc.im * tst;
            h[k - 1].im = sc.re * tst + sc.im * ab;
          }

          i15 = (i << 2) + 4;
          for (k = ix0_tmp; k <= i15; k++) {
            ab = z[k - 1].re;
            tst = z[k - 1].im;
            z[k - 1].re = sc.re * ab - sc.im * tst;
            z[k - 1].im = sc.re * tst + sc.im * ab;
          }
        }

        its++;
      }
    }

    if (!goto140) {
      info = i + 1;
      exitg1 = true;
    } else {
      i = L;
    }
  }

  h[3].re = 0.0;
  h[3].im = 0.0;
  return info;
}

//
// File trailer for xhseqr.cpp
//
// [EOF]
//
