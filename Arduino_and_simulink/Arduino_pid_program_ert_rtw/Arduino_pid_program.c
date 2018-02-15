/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_pid_program.c
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
#define Arduino_pid_prog_floatprecision (2.0)

/* Block signals (auto storage) */
B_Arduino_pid_program_T Arduino_pid_program_B;

/* Block states (auto storage) */
DW_Arduino_pid_program_T Arduino_pid_program_DW;

/* Real-time model */
RT_MODEL_Arduino_pid_program_T Arduino_pid_program_M_;
RT_MODEL_Arduino_pid_program_T *const Arduino_pid_program_M =
  &Arduino_pid_program_M_;
int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  int16_T nb;
  int16_T i;
  uint32_T ys;
  uint32_T yi;
  uint32_T u1i;
  int16_T nc;
  uint16_T nr;
  uint16_T nl;
  int16_T i1;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      nl = 32U - nr;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << nl | yi;
        i++;
      }

      yi = u1i >> nr;
      u1i = nc < n1 ? u1[nc] : ys;
      y[i] = u1i << nl | yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int16_T n)
{
  uint32_T yi;
  uint32_T u1i;
  uint32_T borrow = 0UL;
  int16_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i - u2[i]) - borrow;
    y[i] = yi;
    borrow = borrow != 0UL ? (uint32_T)(yi >= u1i) : (uint32_T)(yi > u1i);
  }
}

void sMultiWord2MultiWord(const uint32_T u1[], int16_T n1, uint32_T y[], int16_T
  n)
{
  uint32_T u1i;
  int16_T nm;
  int16_T i;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    u1i = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
    for (i = nm; i < n; i++) {
      y[i] = u1i;
    }
  }
}

void sMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  int16_T nb;
  int16_T nc;
  int16_T i;
  uint32_T ys;
  uint32_T u1i;
  uint32_T yi;
  uint16_T nr;
  uint16_T nl;
  nb = (int16_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  nc = nb > n ? n : nb;
  u1i = 0UL;
  for (i = 0; i < nc; i++) {
    y[i] = 0UL;
  }

  if (nb < n) {
    nl = n2 - ((uint16_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      nr = 32U - nl;
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> nr;
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> nr | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int16_T n)
{
  uint32_T yi;
  int16_T i;
  y[0] = (uint32_T)u;
  yi = u < 0L ? MAX_uint32_T : 0UL;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int16_T n)
{
  uint32_T yi;
  uint32_T u1i;
  uint32_T carry = 0UL;
  int16_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0UL ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0;
}

int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  int16_T y;
  uint32_T su1;
  uint32_T su2;
  int16_T i;
  su1 = u1[n - 1] & 2147483648UL;
  su2 = u2[n - 1] & 2147483648UL;
  if ((su1 ^ su2) != 0UL) {
    y = su1 != 0UL ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      su2 = u2[i];
      if (su1 != su2) {
        y = su1 > su2 ? 1 : -1;
      }
    }
  }

  return y;
}

boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) <= 0;
}

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0L ? ~(uint32_T)in0 + 1UL : (uint32_T)in0;
  absIn1 = in1 < 0L ? ~(uint32_T)in1 + 1UL : (uint32_T)in1;
  in0Hi = absIn0 >> 16UL;
  in0Lo = absIn0 & 65535UL;
  in1Hi = absIn1 >> 16UL;
  absIn0 = absIn1 & 65535UL;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0UL;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16UL) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1UL;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16UL;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16UL) + (productHiLo >> 16UL)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0L) || ((in1 == 0L) || ((in0 > 0L) == (in1 > 0L))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0UL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32UL - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

/* Model step function */
void Arduino_pid_program_step(void)
{
  int32_T data;
  uint8_T sts;
  int32_T rtb_Gain3;
  int64m_T tmp;
  uint32_T tmp_0;
  uint32_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  int64m_T tmp_4;
  int64m_T tmp_5;
  static int64m_T tmp_6 = { { 25UL, 0UL }/* chunks */
  };

  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  MW_Serial_read(0U, Arduino_pid_program_DW.obj_m.DataSizeInBytes, &data, &sts);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (sts > 0) {
    /* Gain: '<S1>/Gain3' */
    Arduino_pid_program_B.r4 = Arduino_pid_program_P.N;

    /* Gain: '<S1>/Gain2' */
    tmp_0 = (uint32_T)Arduino_pid_program_P.Kd;
    tmp_1 = (uint32_T)data;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

    /* Sum: '<S1>/Sum' incorporates:
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
     */
    tmp_2 = tmp_6;
    sMultiWordMul(&tmp.chunks[0U], 2, &tmp_2.chunks[0U], 2,
                  &Arduino_pid_program_B.r3.chunks[0U], 4);
    sMultiWordShr(&Arduino_pid_program_B.r3.chunks[0U], 4, 966U,
                  &Arduino_pid_program_B.r2.chunks[0U], 4);
    sMultiWord2MultiWord(&Arduino_pid_program_B.r2.chunks[0U], 4,
                         &Arduino_pid_program_B.r6.chunks[0U], 2);
    sLong2MultiWord(Arduino_pid_program_DW.DiscreteTimeIntegrator1_DSTATE,
                    &tmp_2.chunks[0U], 2);
    sMultiWordShl(&tmp_2.chunks[0U], 2, 32U, &tmp.chunks[0U], 2);
    MultiWordSub(&Arduino_pid_program_B.r6.chunks[0U], &tmp.chunks[0U],
                 &Arduino_pid_program_B.r5.chunks[0U], 2);

    /* Gain: '<S1>/Gain3' */
    sMultiWordMul(&Arduino_pid_program_B.r4.chunks[0U], 2,
                  &Arduino_pid_program_B.r5.chunks[0U], 2,
                  &Arduino_pid_program_B.r1.chunks[0U], 4);
    sMultiWordShr(&Arduino_pid_program_B.r1.chunks[0U], 4, 1039U,
                  &Arduino_pid_program_B.r0.chunks[0U], 4);
    rtb_Gain3 = mul_s32_loSR(MultiWord2sLong(&Arduino_pid_program_B.r0.chunks[0U]),
      1374389535L, 30UL);

    /* Gain: '<S1>/Gain' */
    tmp_0 = (uint32_T)Arduino_pid_program_P.Kp;
    tmp_1 = (uint32_T)data;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &Arduino_pid_program_B.r6.chunks[0U], 2);

    /* Sum: '<S1>/Add' incorporates:
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
     */
    sMultiWordShr(&Arduino_pid_program_B.r6.chunks[0U], 2, 2U,
                  &Arduino_pid_program_B.r5.chunks[0U], 2);
    tmp_0 = (uint32_T)Arduino_pid_program_DW.DiscreteTimeIntegrator_DSTATE;
    tmp_1 = 1374389535UL;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);
    sMultiWordShr(&tmp.chunks[0U], 2, 5U, &Arduino_pid_program_B.r6.chunks[0U],
                  2);
    MultiWordAdd(&Arduino_pid_program_B.r5.chunks[0U],
                 &Arduino_pid_program_B.r6.chunks[0U],
                 &Arduino_pid_program_B.r4.chunks[0U], 2);
    sLong2MultiWord(rtb_Gain3, &Arduino_pid_program_B.r6.chunks[0U], 2);
    sMultiWordShl(&Arduino_pid_program_B.r6.chunks[0U], 2, 32U,
                  &Arduino_pid_program_B.r5.chunks[0U], 2);
    MultiWordAdd(&Arduino_pid_program_B.r4.chunks[0U],
                 &Arduino_pid_program_B.r5.chunks[0U],
                 &Arduino_pid_program_B.Add.chunks[0U], 2);

    /* Saturate: '<S1>/Saturation' */
    sLong2MultiWord(Arduino_pid_program_P.Saturation_UpperSat,
                    &Arduino_pid_program_B.r5.chunks[0U], 2);
    sMultiWordShl(&Arduino_pid_program_B.r5.chunks[0U], 2, 32U,
                  &Arduino_pid_program_B.r4.chunks[0U], 2);
    if (sMultiWordGe(&Arduino_pid_program_B.Add.chunks[0U],
                     &Arduino_pid_program_B.r4.chunks[0U], 2)) {
      Arduino_pid_program_B.Saturation =
        Arduino_pid_program_P.Saturation_UpperSat;
    } else {
      sLong2MultiWord(Arduino_pid_program_P.Saturation_LowerSat,
                      &Arduino_pid_program_B.r6.chunks[0U], 2);
      sMultiWordShl(&Arduino_pid_program_B.r6.chunks[0U], 2, 32U,
                    &Arduino_pid_program_B.r5.chunks[0U], 2);
      if (sMultiWordLe(&Arduino_pid_program_B.Add.chunks[0U],
                       &Arduino_pid_program_B.r5.chunks[0U], 2)) {
        Arduino_pid_program_B.Saturation =
          Arduino_pid_program_P.Saturation_LowerSat;
      } else {
        sMultiWordShr(&Arduino_pid_program_B.Add.chunks[0U], 2, 32U,
                      &Arduino_pid_program_B.r6.chunks[0U], 2);
        Arduino_pid_program_B.Saturation = MultiWord2sLong
          (&Arduino_pid_program_B.r6.chunks[0U]);
      }
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Gain: '<S1>/Gain1' */
    tmp_0 = (uint32_T)Arduino_pid_program_P.Ki;
    tmp_1 = (uint32_T)data;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp_2.chunks[0U], 2);

    /* Sum: '<S1>/Sum1' */
    sMultiWordShr(&tmp_2.chunks[0U], 2, 33U, &tmp.chunks[0U], 2);

    /* Gain: '<S1>/Gain4' */
    tmp_2 = Arduino_pid_program_P.Kb;

    /* Sum: '<S1>/Sum2' */
    sLong2MultiWord(Arduino_pid_program_B.Saturation, &tmp_5.chunks[0U], 2);
    sMultiWordShl(&tmp_5.chunks[0U], 2, 32U, &tmp_4.chunks[0U], 2);
    MultiWordSub(&tmp_4.chunks[0U], &Arduino_pid_program_B.Add.chunks[0U],
                 &tmp_3.chunks[0U], 2);

    /* Gain: '<S1>/Gain4' */
    sMultiWordMul(&tmp_2.chunks[0U], 2, &tmp_3.chunks[0U], 2,
                  &Arduino_pid_program_B.r2.chunks[0U], 4);

    /* Sum: '<S1>/Sum1' */
    sMultiWordShr(&Arduino_pid_program_B.r2.chunks[0U], 4, 97U,
                  &Arduino_pid_program_B.r1.chunks[0U], 4);

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
     *  Sum: '<S1>/Sum1'
     */
    Arduino_pid_program_DW.DiscreteTimeIntegrator_DSTATE += (MultiWord2sLong
      (&tmp.chunks[0U]) + MultiWord2sLong(&Arduino_pid_program_B.r1.chunks[0U]))
      >> 4;

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
    Arduino_pid_program_DW.DiscreteTimeIntegrator1_DSTATE += rtb_Gain3;
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Receive' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Start for MATLABSystem: '<Root>/Serial Transmit' */
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

  /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Arduino_pid_program_DW.DiscreteTimeIntegrator_DSTATE =
    Arduino_pid_program_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  Arduino_pid_program_DW.DiscreteTimeIntegrator1_DSTATE =
    Arduino_pid_program_P.DiscreteTimeIntegrator1_IC;

  /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */
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
