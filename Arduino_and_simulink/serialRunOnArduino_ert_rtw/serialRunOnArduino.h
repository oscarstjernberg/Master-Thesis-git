/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: serialRunOnArduino.h
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

#ifndef RTW_HEADER_serialRunOnArduino_h_
#define RTW_HEADER_serialRunOnArduino_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef serialRunOnArduino_COMMON_INCLUDES_
# define serialRunOnArduino_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialWrite.h"
#include "MW_SerialRead.h"
#endif                                 /* serialRunOnArduino_COMMON_INCLUDES_ */

#include "serialRunOnArduino_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Add;                          /* '<S1>/Add' */
} B_serialRunOnArduino_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_i_T obj; /* '<Root>/Serial Transmit' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  codertarget_arduinobase_inter_T obj_m;/* '<Root>/Serial Receive' */
} DW_serialRunOnArduino_T;

/* Parameters (auto storage) */
struct P_serialRunOnArduino_T_ {
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 10000000
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 10000000
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/100000
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S1>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100000
                                        * Referenced by: '<S1>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_serialRunOnArduino_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_serialRunOnArduino_T serialRunOnArduino_P;

/* Block signals (auto storage) */
extern B_serialRunOnArduino_T serialRunOnArduino_B;

/* Block states (auto storage) */
extern DW_serialRunOnArduino_T serialRunOnArduino_DW;

/* Model entry point functions */
extern void serialRunOnArduino_initialize(void);
extern void serialRunOnArduino_step(void);
extern void serialRunOnArduino_terminate(void);

/* Real-time Model object */
extern RT_MODEL_serialRunOnArduino_T *const serialRunOnArduino_M;

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
 * '<Root>' : 'serialRunOnArduino'
 * '<S1>'   : 'serialRunOnArduino/Enabled Subsystem'
 * '<S2>'   : 'serialRunOnArduino/Enabled Subsystem/Subsystem'
 */
#endif                                 /* RTW_HEADER_serialRunOnArduino_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
