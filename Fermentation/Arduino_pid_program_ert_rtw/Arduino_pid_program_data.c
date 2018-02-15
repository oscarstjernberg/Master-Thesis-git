/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program_data.c
 *
 * Code generated for Simulink model 'Arduino_pid_program'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Feb 14 15:11:07 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Arduino_pid_program.h"
#include "Arduino_pid_program_private.h"

/* Block parameters (auto storage) */
P_Arduino_pid_program_T Arduino_pid_program_P = {
  /* Variable: Kb
   * Referenced by: '<S1>/Gain4'
   */
  1.0,

  /* Variable: Kd
   * Referenced by: '<S1>/Gain2'
   */
  0.0,

  /* Variable: Ki
   * Referenced by: '<S1>/Gain1'
   */
  0.0001,

  /* Variable: Kp
   * Referenced by: '<S1>/Gain'
   */
  0.01,

  /* Variable: N
   * Referenced by: '<S1>/Gain3'
   */
  1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S1>/Out1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator1'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Saturation'
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<S1>/Saturation'
   */
  -100.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
