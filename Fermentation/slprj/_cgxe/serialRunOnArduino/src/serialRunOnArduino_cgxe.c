/* Include files */

#include "serialRunOnArduino_cgxe.h"
#include "m_IyR1VrgVeRDv1KZbpA4XqG.h"

unsigned int cgxe_serialRunOnArduino_method_dispatcher(SimStruct* S, int_T
  method, void* data)
{
  if (ssGetChecksum0(S) == 2853339978 &&
      ssGetChecksum1(S) == 1913475607 &&
      ssGetChecksum2(S) == 587192514 &&
      ssGetChecksum3(S) == 238541843) {
    method_dispatcher_IyR1VrgVeRDv1KZbpA4XqG(S, method, data);
    return 1;
  }

  return 0;
}
