/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: serialRunOnArduino_types.h
 *
 * Code generated for Simulink model 'serialRunOnArduino'.
 *
 * Model version                  : 1.54
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Feb 15 09:38:38 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_serialRunOnArduino_types_h_
#define RTW_HEADER_serialRunOnArduino_types_h_
#include "rtwtypes.h"
#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  int32_T isInitialized;
  uint16_T DataSizeInBytes;
  uint16_T DataTypeWidth;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_cell_wrap_serialRunOnArduino_T
#define typedef_cell_wrap_serialRunOnArduino_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_serialRunOnArduino_T;

#endif                                 /*typedef_cell_wrap_serialRunOnArduino_T*/

#ifndef typedef_codertarget_arduinobase_int_i_T
#define typedef_codertarget_arduinobase_int_i_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_serialRunOnArduino_T inputVarSize;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
} codertarget_arduinobase_int_i_T;

#endif                                 /*typedef_codertarget_arduinobase_int_i_T*/

/* Parameters (auto storage) */
typedef struct P_serialRunOnArduino_T_ P_serialRunOnArduino_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_serialRunOnArduino_T RT_MODEL_serialRunOnArduino_T;

#endif                                 /* RTW_HEADER_serialRunOnArduino_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
