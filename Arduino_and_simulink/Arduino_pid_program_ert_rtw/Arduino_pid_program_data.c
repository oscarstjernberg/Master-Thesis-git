/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program_data.c
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

#include "Arduino_pid_program.h"
#include "Arduino_pid_program_private.h"

/* Block parameters (auto storage) */
P_Arduino_pid_program_T Arduino_pid_program_P = {
  /* Variable: N
   * Referenced by: '<S1>/Gain3'
   */
  { { 0UL, 0UL } },

  /* Variable: Kb
   * Referenced by: '<S1>/Gain4'
   */
  { { 0xB851EC00UL, 0x51EB851EUL } },

  /* Variable: Kp
   * Referenced by: '<S1>/Gain'
   */
  1717986918,

  /* Variable: Ki
   * Referenced by: '<S1>/Gain1'
   */
  1374389535,

  /* Variable: Kd
   * Referenced by: '<S1>/Gain2'
   */
  0,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S1>/Saturation'
   */
  100000,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S1>/Saturation'
   */
  -100000,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0,

  /* Computed Parameter: DiscreteTimeIntegrator1_IC
   * Referenced by: '<S1>/Discrete-Time Integrator1'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
