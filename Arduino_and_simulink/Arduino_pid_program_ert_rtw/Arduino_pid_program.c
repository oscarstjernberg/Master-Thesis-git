/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program.c
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

#include "Arduino_pid_program.h"
#include "Arduino_pid_program_private.h"
#define Arduino_pid_program_PinNumber  (9.0)

/* Block states (auto storage) */
DW_Arduino_pid_program_T Arduino_pid_program_DW;

/* Real-time model */
RT_MODEL_Arduino_pid_program_T Arduino_pid_program_M_;
RT_MODEL_Arduino_pid_program_T *const Arduino_pid_program_M =
  &Arduino_pid_program_M_;

/* Model step function */
void Arduino_pid_program_step(void)
{
  uint16_T rtb_AnalogInput_0;

  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  rtb_AnalogInput_0 = MW_analogRead(Arduino_pid_program_P.AnalogInput_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input'
   */
  if (rtb_AnalogInput_0 > 255U) {
    rtb_AnalogInput_0 = 255U;
  }

  /* MATLABSystem: '<S1>/Digital Output' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  writeDigitalPin((uint8_T)Arduino_pid_program_PinNumber, (uint8_T)
                  rtb_AnalogInput_0);
}

/* Model initialize function */
void Arduino_pid_program_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Arduino_pid_program_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Arduino_pid_program_DW, 0,
                sizeof(DW_Arduino_pid_program_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  MW_pinModeAnalogInput(Arduino_pid_program_P.AnalogInput_p1);

  /* Start for MATLABSystem: '<S1>/Digital Output' */
  Arduino_pid_program_DW.obj.isInitialized = 0L;
  Arduino_pid_program_DW.obj.isInitialized = 1L;
  digitalIOSetup((uint8_T)Arduino_pid_program_PinNumber, true);
}

/* Model terminate function */
void Arduino_pid_program_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (Arduino_pid_program_DW.obj.isInitialized == 1L) {
    Arduino_pid_program_DW.obj.isInitialized = 2L;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
