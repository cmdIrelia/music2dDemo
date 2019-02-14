//
// File: ismember.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
//

// Include Files
#include "rt_nonfinite.h"
#include <string.h>
#include "music2D.h"
#include "ismember.h"
#include "music2D_rtwutil.h"
#include "sort1.h"
#include "issorted.h"

// Function Declarations
static int bsearchni(int k, const double x[25921], const double s[25921]);

// Function Definitions

//
// Arguments    : int k
//                const double x[25921]
//                const double s[25921]
// Return Type  : int
//
static int bsearchni(int k, const double x[25921], const double s[25921])
{
  int idx;
  double b_x;
  int ilo;
  int ihi;
  boolean_T exitg1;
  int imid;
  boolean_T b0;
  b_x = x[k - 1];
  idx = 0;
  ilo = 1;
  ihi = 25921;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    imid = ((ilo >> 1) + (ihi >> 1)) - 1;
    if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
      imid++;
    }

    if (b_x == s[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else {
      if (rtIsNaN(s[imid])) {
        b0 = !rtIsNaN(b_x);
      } else {
        b0 = ((!rtIsNaN(b_x)) && (b_x < s[imid]));
      }

      if (b0) {
        ihi = imid;
      } else {
        ilo = imid + 2;
      }
    }
  }

  if (idx > 0) {
    idx--;
    while ((idx > 0) && (b_x == s[idx - 1])) {
      idx--;
    }

    idx++;
  }

  return idx;
}

//
// Arguments    : const double a[25921]
//                const double s[25921]
//                boolean_T tf[25921]
// Return Type  : void
//
void local_ismember(const double a[25921], const double s[25921], boolean_T tf
                    [25921])
{
  int k;
  static double ss[25921];
  int n;
  music2DTLS *music2DTLSThread;
  music2DTLSThread = emlrtGetThreadStackData();
  memset(&tf[0], 0, 25921U * sizeof(boolean_T));
  if (!issorted(s)) {
    memcpy(&ss[0], &s[0], 25921U * sizeof(double));
    b_sort(ss, music2DTLSThread->f0.unusedExpr);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(n)

    for (k = 0; k < 25921; k++) {
      n = bsearchni(1 + k, a, ss);
      if (n > 0) {
        tf[k] = true;
      }
    }
  } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(n)

    for (k = 0; k < 25921; k++) {
      n = bsearchni(1 + k, a, s);
      if (n > 0) {
        tf[k] = true;
      }
    }
  }
}

//
// File trailer for ismember.cpp
//
// [EOF]
//
