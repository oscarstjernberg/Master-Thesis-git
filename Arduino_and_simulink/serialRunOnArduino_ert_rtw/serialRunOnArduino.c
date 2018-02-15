/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: serialRunOnArduino.c
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
#define serialRunOnArdui_floatprecision (2.0)

/* Block signals (auto storage) */
B_serialRunOnArduino_T serialRunOnArduino_B;

/* Block states (auto storage) */
DW_serialRunOnArduino_T serialRunOnArduino_DW;

/* Real-time model */
RT_MODEL_serialRunOnArduino_T serialRunOnArduino_M_;
RT_MODEL_serialRunOnArduino_T *const serialRunOnArduino_M =
  &serialRunOnArduino_M_;

/* Model step function */
void serialRunOnArduino_step(void)
{
  uint32_T data;
  uint8_T sts;
  real_T rtb_Gain2;
  real_T tmp;

  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  MW_Serial_read(0U, serialRunOnArduino_DW.obj_m.DataSizeInBytes, &data, &sts);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (sts > 0) {
    /* Gain: '<S2>/Gain2' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Sum: '<S2>/Subtract'
     */
    rtb_Gain2 = ((real_T)data - serialRunOnArduino_P.Constant2_Value) *
      serialRunOnArduino_P.Gain2_Gain;

    /* Gain: '<S1>/Gain' */
    tmp = floor(serialRunOnArduino_P.Kp * rtb_Gain2);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* Sum: '<S1>/Add' incorporates:
     *  Constant: '<S1>/Constant'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain1'
     *  Sum: '<S1>/Sum'
     */
    serialRunOnArduino_B.Add = ((real_T)(tmp < 0.0 ? (uint32_T)-(int32_T)
      (uint32_T)-tmp : (uint32_T)tmp) +
      serialRunOnArduino_DW.DiscreteTimeIntegrator_DSTATE) *
      serialRunOnArduino_P.Gain1_Gain + serialRunOnArduino_P.Constant_Value;

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    serialRunOnArduino_DW.DiscreteTimeIntegrator_DSTATE +=
      serialRunOnArduino_P.DiscreteTimeIntegrator_gainval * rtb_Gain2;
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Receive' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* MATLABSystem: '<Root>/Serial Transmit' */
  rtb_Gain2 = serialRunOnArduino_B.Add;
  MW_Serial_write(serialRunOnArduino_DW.obj.port, &rtb_Gain2, 1.0,
                  serialRunOnArduino_DW.obj.dataSizeInBytes,
                  serialRunOnArduino_DW.obj.sendModeEnum,
                  serialRunOnArduino_DW.obj.dataType,
                  serialRunOnArduino_DW.obj.sendFormatEnum,
                  serialRunOnArdui_floatprecision, '\x00');
}

/* Model initialize function */
void serialRunOnArduino_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(serialRunOnArduino_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &serialRunOnArduino_B), 0,
                sizeof(B_serialRunOnArduino_T));

  /* states (dwork) */
  (void) memset((void *)&serialRunOnArduino_DW, 0,
                sizeof(DW_serialRunOnArduino_T));

  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  serialRunOnArduino_DW.obj_m.isInitialized = 0L;
  serialRunOnArduino_DW.obj_m.isInitialized = 1L;
  serialRunOnArduino_DW.obj_m.DataTypeWidth = 4U;
  serialRunOnArduino_DW.obj_m.DataSizeInBytes =
    serialRunOnArduino_DW.obj_m.DataTypeWidth;

  /* Start for MATLABSystem: '<Root>/Serial Transmit' */
  serialRunOnArduino_DW.obj.isInitialized = 0L;
  serialRunOnArduino_DW.obj.isInitialized = 1L;
  serialRunOnArduino_DW.obj.port = 0.0;
  serialRunOnArduino_DW.obj.dataSizeInBytes = 8.0;
  serialRunOnArduino_DW.obj.dataType = 6.0;
  serialRunOnArduino_DW.obj.sendModeEnum = 0.0;
  serialRunOnArduino_DW.obj.sendFormatEnum = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  serialRunOnArduino_DW.DiscreteTimeIntegrator_DSTATE =
    serialRunOnArduino_P.DiscreteTimeIntegrator_IC;

  /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */
}

/* Model terminate function */
void serialRunOnArduino_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  if (serialRunOnArduino_DW.obj_m.isInitialized == 1L) {
    serialRunOnArduino_DW.obj_m.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (serialRunOnArduino_DW.obj.isInitialized == 1L) {
    serialRunOnArduino_DW.obj.isInitialized = 2L;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
