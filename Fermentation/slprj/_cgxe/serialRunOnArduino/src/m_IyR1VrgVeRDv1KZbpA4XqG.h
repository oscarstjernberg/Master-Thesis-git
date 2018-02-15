#ifndef __IyR1VrgVeRDv1KZbpA4XqG_h__
#define __IyR1VrgVeRDv1KZbpA4XqG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"

/* Type Definitions */
#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct {
  uint32_T f1[8];
} cell_wrap;

#endif                                 /*typedef_cell_wrap*/

#ifndef typedef_codertarget_arduinobase_internal_arduino_SerialWrite
#define typedef_codertarget_arduinobase_internal_arduino_SerialWrite

typedef struct {
  int32_T isInitialized;
  cell_wrap inputVarSize[1];
} codertarget_arduinobase_internal_arduino_SerialWrite;

#endif                                 /*typedef_codertarget_arduinobase_internal_arduino_SerialWrite*/

#ifndef typedef_InstanceStruct_IyR1VrgVeRDv1KZbpA4XqG
#define typedef_InstanceStruct_IyR1VrgVeRDv1KZbpA4XqG

typedef struct {
  SimStruct *S;
  codertarget_arduinobase_internal_arduino_SerialWrite sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  uint16_T *u0;
} InstanceStruct_IyR1VrgVeRDv1KZbpA4XqG;

#endif                                 /*typedef_InstanceStruct_IyR1VrgVeRDv1KZbpA4XqG*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_IyR1VrgVeRDv1KZbpA4XqG(SimStruct *S, int_T method,
  void* data);

#endif
