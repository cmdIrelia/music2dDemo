//
// File: elemdelay.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Feb-2019 02:46:35
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
//                const double ang[322]
//                double tau[644]
// Return Type  : void
//
void elemdelay(const double pos[12], const double ang[322], double tau[644])
{
  int i8;
  double incidentdir_tmp[161];
  double dv7[161];
  double dv8[161];
  double dv9[161];
  double b_incidentdir_tmp[483];
  int i9;
  for (i8 = 0; i8 < 161; i8++) {
    incidentdir_tmp[i8] = ang[1 + (i8 << 1)];
  }

  b_cosd(incidentdir_tmp);
  for (i8 = 0; i8 < 161; i8++) {
    dv7[i8] = ang[i8 << 1];
    incidentdir_tmp[i8] = -incidentdir_tmp[i8];
  }

  b_cosd(dv7);
  for (i8 = 0; i8 < 161; i8++) {
    dv8[i8] = ang[i8 << 1];
  }

  b_sind(dv8);
  for (i8 = 0; i8 < 161; i8++) {
    dv9[i8] = ang[1 + (i8 << 1)];
  }

  b_sind(dv9);
  for (i8 = 0; i8 < 161; i8++) {
    b_incidentdir_tmp[3 * i8] = incidentdir_tmp[i8] * dv7[i8];
    b_incidentdir_tmp[1 + 3 * i8] = incidentdir_tmp[i8] * dv8[i8];
    b_incidentdir_tmp[2 + 3 * i8] = -dv9[i8];
  }

  for (i8 = 0; i8 < 4; i8++) {
    for (i9 = 0; i9 < 161; i9++) {
      tau[i8 + (i9 << 2)] = ((pos[3 * i8] * b_incidentdir_tmp[3 * i9] + pos[1 +
        3 * i8] * b_incidentdir_tmp[1 + 3 * i9]) + pos[2 + 3 * i8] *
        b_incidentdir_tmp[2 + 3 * i9]) / 2.99792458E+8;
    }
  }
}

//
// File trailer for elemdelay.cpp
//
// [EOF]
//
