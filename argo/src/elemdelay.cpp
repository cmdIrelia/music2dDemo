//
// File: elemdelay.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "elemdelay.h"
#include "sind.h"
#include "cosd.h"

// Function Definitions

//
// Arguments    : const double pos[12]
//                const double ang[602]
//                double tau[1204]
// Return Type  : void
//
void elemdelay(const double pos[12], const double ang[602], double tau[1204])
{
  int i7;
  double incidentdir_tmp[301];
  double dv7[301];
  double dv8[301];
  double dv9[301];
  double b_incidentdir_tmp[903];
  int i8;
  for (i7 = 0; i7 < 301; i7++) {
    incidentdir_tmp[i7] = ang[1 + (i7 << 1)];
  }

  b_cosd(incidentdir_tmp);
  for (i7 = 0; i7 < 301; i7++) {
    dv7[i7] = ang[i7 << 1];
    incidentdir_tmp[i7] = -incidentdir_tmp[i7];
  }

  b_cosd(dv7);
  for (i7 = 0; i7 < 301; i7++) {
    dv8[i7] = ang[i7 << 1];
  }

  b_sind(dv8);
  for (i7 = 0; i7 < 301; i7++) {
    dv9[i7] = ang[1 + (i7 << 1)];
  }

  b_sind(dv9);
  for (i7 = 0; i7 < 301; i7++) {
    b_incidentdir_tmp[3 * i7] = incidentdir_tmp[i7] * dv7[i7];
    b_incidentdir_tmp[1 + 3 * i7] = incidentdir_tmp[i7] * dv8[i7];
    b_incidentdir_tmp[2 + 3 * i7] = -dv9[i7];
  }

  for (i7 = 0; i7 < 4; i7++) {
    for (i8 = 0; i8 < 301; i8++) {
      tau[i7 + (i8 << 2)] = ((pos[3 * i7] * b_incidentdir_tmp[3 * i8] + pos[1 +
        3 * i7] * b_incidentdir_tmp[1 + 3 * i8]) + pos[2 + 3 * i7] *
        b_incidentdir_tmp[2 + 3 * i8]) / 2.99792458E+8;
    }
  }
}

//
// File trailer for elemdelay.cpp
//
// [EOF]
//
