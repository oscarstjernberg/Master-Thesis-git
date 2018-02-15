/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: serialRunOnArduino_data.c
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

#include "serialRunOnArduino.h"
#include "serialRunOnArduino_private.h"

/* Block parameters (auto storage) */
P_serialRunOnArduino_T serialRunOnArduino_P = {
  /* Variable: Kp
   * Referenced by: '<S1>/Gain'
   */
  0.01,

  /* Expression: 10000000
   * Referenced by: '<S1>/Constant'
   */
  1.0E+7,

  /* Expression: 10000000
   * Referenced by: '<S2>/Constant2'
   */
  1.0E+7,

  /* Expression: 1/100000
   * Referenced by: '<S2>/Gain2'
   */
  1.0E-5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 100000
   * Referenced by: '<S1>/Gain1'
   */
  100000.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
