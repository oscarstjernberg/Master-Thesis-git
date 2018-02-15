/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program.h
 *
 * Code generated for Simulink model 'Arduino_pid_program'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Feb 15 13:20:57 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Arduino_pid_program_h_
#define RTW_HEADER_Arduino_pid_program_h_
#include <stddef.h>
#include <string.h>
#ifndef Arduino_pid_program_COMMON_INCLUDES_
# define Arduino_pid_program_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalio.h"
#include "arduino_analoginput_lct.h"
#endif                                 /* Arduino_pid_program_COMMON_INCLUDES_ */

#include "Arduino_pid_program_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S1>/Digital Output' */
} DW_Arduino_pid_program_T;

/* Parameters (auto storage) */
struct P_Arduino_pid_program_T_ {
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Arduino_pid_program_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_Arduino_pid_program_T Arduino_pid_program_P;

/* Block states (auto storage) */
extern DW_Arduino_pid_program_T Arduino_pid_program_DW;

/* Model entry point functions */
extern void Arduino_pid_program_initialize(void);
extern void Arduino_pid_program_step(void);
extern void Arduino_pid_program_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Arduino_pid_program_T *const Arduino_pid_program_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Arduino_pid_program'
 * '<S1>'   : 'Arduino_pid_program/Digital Output'
 * '<S2>'   : 'Arduino_pid_program/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_Arduino_pid_program_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
