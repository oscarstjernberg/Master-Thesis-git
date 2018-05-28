#include "Warning.h"

void WarningClass::warning(double temp)
{
	if (temp > 26)		// If the output temperature exceeds this value, the warning led light up.
	{
		digitalWrite(warningLED, HIGH);
	}
	else
	{
		digitalWrite(warningLED, LOW);
	}
}