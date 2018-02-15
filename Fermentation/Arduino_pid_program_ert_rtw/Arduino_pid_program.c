/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program.c
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
  real_T data;
  uint8_T sts;
  real_T rtb_Add;
  real_T rtb_Gain3;

  /* MATLABSystem: '<Root>/Serial Receive' */
  MW_Serial_read(0U, Arduino_pid_program_DW.obj_p.DataSizeInBytes, &data, &sts);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (sts > 0) {
    if (!Arduino_pid_program_DW.EnabledSubsystem_MODE) {
      Arduino_pid_program_DW.EnabledSubsystem_MODE = true;
    }

    /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    Arduino_pid_program_B.DiscreteTimeIntegrator =
      Arduino_pid_program_DW.DiscreteTimeIntegrator_DSTATE;

    /* Gain: '<S1>/Gain3' incorporates:
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
     *  Gain: '<S1>/Gain2'
     *  Sum: '<S1>/Sum'
     */
    rtb_Gain3 = (Arduino_pid_program_P.Kd * data -
                 Arduino_pid_program_DW.DiscreteTimeIntegrator1_DSTATE) *
      Arduino_pid_program_P.N;

    /* Sum: '<S1>/Add' incorporates:
     *  Gain: '<S1>/Gain'
     */
    rtb_Add = (Arduino_pid_program_P.Kp * data +
               Arduino_pid_program_B.DiscreteTimeIntegrator) + rtb_Gain3;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Add > Arduino_pid_program_P.Saturation_UpperSat) {
      Arduino_pid_program_B.Saturation =
        Arduino_pid_program_P.Saturation_UpperSat;
    } else if (rtb_Add < Arduino_pid_program_P.Saturation_LowerSat) {
      Arduino_pid_program_B.Saturation =
        Arduino_pid_program_P.Saturation_LowerSat;
    } else {
      Arduino_pid_program_B.Saturation = rtb_Add;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S1>/Gain1'
     *  Gain: '<S1>/Gain4'
     *  Sum: '<S1>/Sum1'
     *  Sum: '<S1>/Sum2'
     */
    Arduino_pid_program_DW.DiscreteTimeIntegrator_DSTATE +=
      ((Arduino_pid_program_B.Saturation - rtb_Add) * Arduino_pid_program_P.Kb +
       Arduino_pid_program_P.Ki * data) *
      Arduino_pid_program_P.DiscreteTimeIntegrator_gainval;

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
    Arduino_pid_program_DW.DiscreteTimeIntegrator1_DSTATE +=
      Arduino_pid_program_P.DiscreteTimeIntegrator1_gainval * rtb_Gain3;
  } else {
    if (Arduino_pid_program_DW.EnabledSubsystem_MODE) {
      /* Disable for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
      Arduino_pid_program_DW.DiscreteTimeIntegrator_DSTATE =
        Arduino_pid_program_B.DiscreteTimeIntegrator;
      Arduino_pid_program_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of MATLABSystem: '<Root>/Serial Receive' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* MATLABSystem: '<Root>/Serial Transmit' */
  data = Arduino_pid_program_B.Saturation;
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
  Arduino_pid_program_DW.obj_p.isInitialized = 0L;
  Arduino_pid_program_DW.obj_p.isInitialized = 1L;
  Arduino_pid_program_DW.obj_p.DataTypeWidth = 4U;
  Arduino_pid_program_DW.obj_p.DataSizeInBytes =
    Arduino_pid_program_DW.obj_p.DataTypeWidth;

  /* Start for MATLABSystem: '<Root>/Serial Transmit' */
  Arduino_pid_program_DW.obj.isInitialized = 0L;
  Arduino_pid_program_DW.obj.isInitialized = 1L;
  Arduino_pid_program_DW.obj.port = 0.0;
  Arduino_pid_program_DW.obj.dataSizeInBytes = 8.0;
  Arduino_pid_program_DW.obj.dataType = 6.0;
  Arduino_pid_program_DW.obj.sendModeEnum = 0.0;
  Arduino_pid_program_DW.obj.sendFormatEnum = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Arduino_pid_program_DW.DiscreteTimeIntegrator_DSTATE =
    Arduino_pid_program_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  Arduino_pid_program_DW.DiscreteTimeIntegrator1_DSTATE =
    Arduino_pid_program_P.DiscreteTimeIntegrator1_IC;

  /* SystemInitialize for Outport: '<S1>/Out1' */
  Arduino_pid_program_B.Saturation = Arduino_pid_program_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */
}

/* Model terminate function */
void Arduino_pid_program_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (Arduino_pid_program_DW.obj_p.isInitialized == 1L) {
    Arduino_pid_program_DW.obj_p.isInitialized = 2L;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (Arduino_pid_program_DW.obj.isInitialized == 1L) {
    Arduino_pid_program_DW.obj.isInitialized = 2L;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
