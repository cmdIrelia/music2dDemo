//src conv shincky

// Include Files
//#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include "rt_nonfinite.h"
#include "music2D.h"
#include "main.h"
#include "music2D_terminate.h"
#include "music2D_initialize.h"

using namespace std;

// Function Declarations
static void argInit_1000x4_creal_T(creal_T result[4000]);
static creal_T argInit_creal_T();
static void main_music2D();


static void argInit_1000x4_creal_T(creal_T result[4000])
{
	int idx0;
	creal_T result_tmp;

	const int Nsamp = 1000;
	double time_line[Nsamp];
	for (int i = 0; i < Nsamp; i++) {
		time_line[i] = (1.f*M_PI - 0.f) / Nsamp*i;
	}

	creal_T signal[3][Nsamp];
	const double freq = 1;
	for (int i = 0; i < Nsamp; i++) {
		signal[0][i].re = sin(freq * time_line[i]);
		signal[0][i].im = cos(freq * time_line[i]);

		signal[1][i].re = sin(freq * time_line[i] + 1.5);
		signal[1][i].im = cos(freq * time_line[i] + 1.5);

		signal[2][i].re = sin(freq * time_line[i] - 1.5);
		signal[2][i].im = cos(freq * time_line[i] - 1.5);
	}


	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < 1000; idx0++) {
		result[idx0] = 	      signal[1][idx0];
		result[idx0 + 1000] = signal[0][idx0];
		result[idx0 + 2000] = signal[1][idx0];
		result[idx0 + 3000] = signal[0][idx0];
	}
}

//
// Arguments    : void
// Return Type  : void
//
static void main_music2D()
{
	creal_T dcv0[4000];
	double rtn[2];

	// Initialize function 'music2D' input arguments.
	// Initialize function input argument 'signal'.
	// Call the entry-point 'music2D'.
	argInit_1000x4_creal_T(dcv0);
	cout << "go music2D" << endl;
	music2D(dcv0, rtn);
	cout << "rtn = " << rtn[0] << "  " << rtn[1] << endl;
	cout << "out music2D" << endl;
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const[])
{
	// Initialize the application.
	// You do not need to do this more than one time.
	music2D_initialize();

	// Invoke the entry-point functions.
	// You can call entry-point functions multiple times.
	main_music2D();

	// Terminate the application.
	// You do not need to do this more than one time.
	music2D_terminate();

	//system("pause");
	return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
