/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program_types.h
 *
 * Code generated for Simulink model 'Arduino_pid_program'.
 *
 * Model version                  : 1.58
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Mar 16 11:06:09 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Arduino_pid_program_types_h_
#define RTW_HEADER_Arduino_pid_program_types_h_
#include "rtwtypes.h"
#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  int32_T isInitialized;
  uint16_T DataSizeInBytes;
  uint16_T DataTypeWidth;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_cell_wrap_Arduino_pid_program_T
#define typedef_cell_wrap_Arduino_pid_program_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_Arduino_pid_program_T;

#endif                                 /*typedef_cell_wrap_Arduino_pid_program_T*/

#ifndef typedef_codertarget_arduinobase_int_d_T
#define typedef_codertarget_arduinobase_int_d_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_Arduino_pid_program_T inputVarSize;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
} codertarget_arduinobase_int_d_T;

#endif                                 /*typedef_codertarget_arduinobase_int_d_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_Arduino_pid_program_T RT_MODEL_Arduino_pid_program_T;

#endif                                 /* RTW_HEADER_Arduino_pid_program_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
