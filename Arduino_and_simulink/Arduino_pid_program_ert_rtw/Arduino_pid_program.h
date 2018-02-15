/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program.h
 *
 * Code generated for Simulink model 'Arduino_pid_program'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Feb 15 11:22:06 2018
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
#include "MW_SerialWrite.h"
#include "MW_SerialRead.h"
#endif                                 /* Arduino_pid_program_COMMON_INCLUDES_ */

#include "Arduino_pid_program_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  int128m_T r0;
  int128m_T r1;
  int128m_T r2;
  int128m_T r3;
  int64m_T Add;                        /* '<S1>/Add' */
  int64m_T r4;
  int64m_T r5;
  int64m_T r6;
  int32_T Saturation;                  /* '<S1>/Saturation' */
} B_Arduino_pid_program_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_d_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_m;/* '<Root>/Serial Receive' */
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator1_DSTATE;/* '<S1>/Discrete-Time Integrator1' */
} DW_Arduino_pid_program_T;

/* Parameters (auto storage) */
struct P_Arduino_pid_program_T_ {
  int64m_T N;                          /* Variable: N
                                        * Referenced by: '<S1>/Gain3'
                                        */
  int64m_T Kb;                         /* Variable: Kb
                                        * Referenced by: '<S1>/Gain4'
                                        */
  int32_T Kp;                          /* Variable: Kp
                                        * Referenced by: '<S1>/Gain'
                                        */
  int32_T Ki;                          /* Variable: Ki
                                        * Referenced by: '<S1>/Gain1'
                                        */
  int32_T Kd;                          /* Variable: Kd
                                        * Referenced by: '<S1>/Gain2'
                                        */
  int32_T Saturation_UpperSat;         /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S1>/Saturation'
                                        */
  int32_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S1>/Saturation'
                                        */
  int32_T DiscreteTimeIntegrator_IC;   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  int32_T DiscreteTimeIntegrator1_IC;  /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                        * Referenced by: '<S1>/Discrete-Time Integrator1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Arduino_pid_program_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_Arduino_pid_program_T Arduino_pid_program_P;

/* Block signals (auto storage) */
extern B_Arduino_pid_program_T Arduino_pid_program_B;

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
 * '<S1>'   : 'Arduino_pid_program/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_Arduino_pid_program_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
