#ifndef GLOBALS_H
#define GLOBALS_H

/**
 * Globals.h
 * Stores const global variables.
 * ( since they are const int, they will be replaces with preprocessor macro )
*/

// Sharp:
const int SHARPENSIZE = 3;

// Blurs:
// 3x3
const int GAUSSIAN_BLUR_3x3_DIVIDER = 16;
const int GAUSSIAN_BLUR_3x3_SIZE = 3;
//5x5
const int GAUSSIAN_BLUR_5x5_DIVIDER = 256;
const int GAUSSIAN_BLUR_5x5_SIZE = 5;

#endif // GLOBALS_H
