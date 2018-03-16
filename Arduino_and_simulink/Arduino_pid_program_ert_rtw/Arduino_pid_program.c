/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program.c
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

#include "Arduino_pid_program.h"
#include "Arduino_pid_program_private.h"
#define Arduino_pid_prog_floatprecision (2.0)

/* Block signals (auto storage) */
B_Arduino_pid_program_T Arduino_pid_program_B;

/* Block states (auto storage) */
DW_Arduino_pid_program_T Arduino_pid_program_DW;

/* Real-time model */
RT_MODEL_Arduino_pid_program_T Arduino_pid_program_M_;
RT_MODEL_Arduino_pid_program_T *const Arduino_pid_program_M =
  &Arduino_pid_program_M_;

/* Model step function */
void Arduino_pid_program_step(void)
{
  int32_T data;
  uint8_T sts;

  /* Start for MATLABSystem: '<Root>/Serial Receive' incorporates:
   *  Inport: '<S1>/In1'
   */
  MW_Serial_read(0U, Arduino_pid_program_DW.obj_m.DataSizeInBytes, &data, &sts);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (sts > 0) {
    Arduino_pid_program_B.In1 = data;
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Receive' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Start for MATLABSystem: '<Root>/Serial Transmit' */
  data = Arduino_pid_program_B.In1;
  MW_Serial_write(Arduino_pid_program_DW.obj.port, &data, 1.0,
                  Arduino_pid_program_DW.obj.dataSizeInBytes,
                  Arduino_pid_program_DW.obj.sendModeEnum,
                  Arduino_pid_program_DW.obj.dataType,
                  Arduino_pid_program_DW.obj.sendFormatEnum,
                  Arduino_pid_prog_floatprecision, '\x00');
}

/* Model initialize function */
void Arduino_pid_program_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Arduino_pid_program_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Arduino_pid_program_B), 0,
                sizeof(B_Arduino_pid_program_T));

  /* states (dwork) */
  (void) memset((void *)&Arduino_pid_program_DW, 0,
                sizeof(DW_Arduino_pid_program_T));

  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  Arduino_pid_program_DW.obj_m.isInitialized = 0L;
  Arduino_pid_program_DW.obj_m.isInitialized = 1L;
  Arduino_pid_program_DW.obj_m.DataTypeWidth = 4U;
  Arduino_pid_program_DW.obj_m.DataSizeInBytes =
    Arduino_pid_program_DW.obj_m.DataTypeWidth;

  /* Start for MATLABSystem: '<Root>/Serial Transmit' */
  Arduino_pid_program_DW.obj.isInitialized = 0L;
  Arduino_pid_program_DW.obj.isInitialized = 1L;
  Arduino_pid_program_DW.obj.port = 0.0;
  Arduino_pid_program_DW.obj.dataSizeInBytes = 4.0;
  Arduino_pid_program_DW.obj.dataType = 5.0;
  Arduino_pid_program_DW.obj.sendModeEnum = 0.0;
  Arduino_pid_program_DW.obj.sendFormatEnum = 0.0;
}

/* Model terminate function */
void Arduino_pid_program_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  if (Arduino_pid_program_DW.obj_m.isInitialized == 1L) {
    Arduino_pid_program_DW.obj_m.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Receive' */

  /* Start for MATLABSystem: '<Root>/Serial Transmit' */
  if (Arduino_pid_program_DW.obj.isInitialized == 1L) {
    Arduino_pid_program_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
