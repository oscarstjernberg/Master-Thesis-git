// ReadToTable.h

#ifndef _READTOTABLE_h
#define _READTOTABLE_h

#ifndef __SD_H__
#include <SD.h>
#endif // !__SD_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ReadToTableClass
{

public:

	int Time_ref[32];
	int Temp_ref[32];
	int array = 0;
	int ROW_DIM;

	void init(int CS_PIN, File &file);
	void read(File &file);
	int	 currentIndex(int millis);

protected:
	const int COL_DIM = 2;

	double MillisToHour = 3600000;
	int i = 0;        // First array index.
	int j = 0;        // Second array index
	int n;         // Length of returned field with delimiter.
	char str[20];     // Must hold longest field with delimiter and zero byte.
	char *ptr;        // Test for valid field.
	char delim = 0;   // Delimiter from previous line. Start with no delimiter.
	int Index;


	int readField(File* file, char* str, size_t size, char* delim);
};

extern ReadToTableClass ReadToTable;

#endif

