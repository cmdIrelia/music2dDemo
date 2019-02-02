//
// File: music2D.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 02-Feb-2019 23:40:29
//

// Include Files
#include "rt_nonfinite.h"
#include "music2D.h"
#include "matlabCodegenHandle.h"
#include "SystemCore.h"

// Function Definitions

//
// function rtn=music2D(signal)
// Beamscan DOA Estimation with a URA
//  Next, we illustrate DOA estimation using a 10-by-5 uniform rectangular
//  array (URA). A URA can estimate both azimuth and elevation angles. The
//  element spacing is 0.3 meters between each row, and 0.5 meters between
//  each column.
// Arguments    : const creal_T b_signal[4000]
//                double rtn[2]
// Return Type  : void
//
void music2D(const creal_T b_signal[4000], double rtn[2])
{
  phased_URA lobj_3;
  static phased_MUSICEstimator2D musicazelspectrum;
  phased_URA ura;
  phased_IsotropicAntennaElement lobj_2;
  phased_IsotropicAntennaElement lobj_4;
  static double unusedU0[36421];
  lobj_3.matlabCodegenIsDeleted = true;
  musicazelspectrum.cSteeringVector.matlabCodegenIsDeleted = true;
  musicazelspectrum.cCovEstimator.matlabCodegenIsDeleted = true;
  ura.matlabCodegenIsDeleted = true;
  musicazelspectrum.matlabCodegenIsDeleted = true;

  // 'music2D:7' ura = phased.URA('Size',[2 2],'ElementSpacing',[0.5 0.5]);
  ura.Element = &lobj_2;
  ura.matlabCodegenIsDeleted = false;

  // 'music2D:9' fc = 300e6;
  //  Operating frequency
  // ura_position = getElementPosition(ura);
  //  plot element position
  // x=ura_position(1,:);
  // y=ura_position(2,:);
  // z=ura_position(3,:);
  // scatter3(x,y,z)
  // ura_elements = ura.Size(1)*ura.Size(2);
  // s=string(linspace(1,ura_elements,ura_elements));
  // text(x,y,z, s, 'fontsize', 10);
  //  MUSIC DOA Estimation with a URA
  // 'music2D:21' musicazelspectrum = phased.MUSICEstimator2D('SensorArray',ura,... 
  // 'music2D:22'         'OperatingFrequency',fc,...
  // 'music2D:23'         'AzimuthScanAngles',-150:150,'ElevationScanAngles',-60:60,... 
  // 'music2D:24'         'DOAOutputPort',true,'NumSignalsSource','Property','NumSignals',1); 
  musicazelspectrum.isInitialized = 0;
  musicazelspectrum.SensorArray = &ura;
  musicazelspectrum.matlabCodegenIsDeleted = false;

  //
  //  To compare MVDR and MUSIC estimators, let's consider sources located even
  //  closer together. Using MVDR and MUSIC, compute the spatial spectrum
  //  of two sources located at 10&deg; in azimuth and separated by 3&deg;
  //  in elevation.
  // 'music2D:32' [~,angmusic] = musicazelspectrum(signal);
  SystemCore_parenReference(&musicazelspectrum, b_signal, &lobj_3, &lobj_4,
    unusedU0, rtn);

  // 'music2D:32' ~
  // 'music2D:34' rtn = angmusic;
  //
  //  In this case, only MUSIC correctly estimates to directions of arrival for
  //  the two sources. To see why, plot an elevation cut of each spatial
  //  spectrum at 10&deg; azimuth.
  // figure;
  // plotSpectrum(musicazelspectrum);
  d_matlabCodegenHandle_matlabCod(&musicazelspectrum);
  c_matlabCodegenHandle_matlabCod(&ura);
  e_matlabCodegenHandle_matlabCod(&musicazelspectrum.cCovEstimator);
  f_matlabCodegenHandle_matlabCod(&musicazelspectrum.cSteeringVector);
  c_matlabCodegenHandle_matlabCod(&lobj_3);
}

//
// File trailer for music2D.cpp
//
// [EOF]
//
