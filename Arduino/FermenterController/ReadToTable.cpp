// 
// 
// 
//------------------------------------------------------------------------------
#define errorHalt(msg) {Serial.println(F(msg)); while(1);}
//------------------------------------------------------------------------------

#include "ReadToTable.h"

void ReadToTableClass::init(int CS_PIN, File &file)
{
	// Initialize the SD.
	if (!SD.begin(CS_PIN)) {
		errorHalt("begin failed");
	}
	// Create or open the file.
	file = SD.open("file.txt", FILE_WRITE);
	if (!file) {
		errorHalt("open failed");
	}
	file.close();
}

void ReadToTableClass::read(File &file)
{
	file = SD.open("file.txt",FILE_READ);
	// Find number of lines in file.
	if (file) {
		while (file.available()) {
			file.readStringUntil('\n');
			ROW_DIM++;
		}
		Serial.println("Number of lines in file:");
		Serial.println(ROW_DIM);

		file.close();
	}
	else
	{
		errorHalt(":(");
	}

	// Array for data.
	int** array = new int*[ROW_DIM];
	for (int a = 0; a < ROW_DIM; a++)
	{
		array[a] = new int[COL_DIM];
	}

	// Read the file and store the data.
	file = SD.open("file.txt", FILE_READ);
	file.seek(0);
	while (true) {
		n = readField(&file, str, sizeof(str), ",\n");
		// Read error or at EOF.
		if (n == 0) {
			Serial.println("BREAK");
			break;
		}
		// Advance indices based on previous delimiter.
		if (delim == '\n') {
			// previous delimiter was endl so start a new row.
			if (++i >= ROW_DIM) {
				errorHalt("too many lines");
			}
			j = 0;
		}
		else if (delim == ',') {
			// previous delimiter was comma so advance column.
			if (++j >= COL_DIM) {
				errorHalt("too many fields");
			}
		}
		array[i][j] = strtol(str, &ptr, 10);

		if (j == 0)
		{
			Temp_ref[i] = array[i][j];
		}
		if (j == 1)
		{
			Time_ref[i] = array[i][j];
		}
		// Skip any blanks after number.
		while (*ptr == ' ') {
			ptr++;
		}
		// Save delimiter.
		delim = *ptr;
	}
	// Print the array.
	for (i = 0; i < ROW_DIM; i++) {	
		for (j = 0; j < COL_DIM; j++) {
			if (j) {
				Serial.print(' ');
			}
			 Serial.print(array[i][j]);
		}
		Serial.println();
	}
	Serial.println("Done");
	file.close();
}

int	 ReadToTableClass::currentIndex(int millis)
{	
	int hour = millis / MillisToHour;

		if (hour > Time_ref[Index] && Index < ROW_DIM)
		{
			return ++Index;
		}
		else
		{
			return Index;
		}
}

int ReadToTableClass::readField(File* file, char* str, size_t size, char* delim) {
	char ch;
	int n = 0;
	while ((n + 1) < size && file->read(&ch, 1) == 1) {
		// Delete CR.
		if (ch == '\r') {
			continue;
		}
		str[n++] = ch;
		if (strchr(delim, ch)) {
			break;
		}
	}
	str[n] = '\0';
	return n;
}

ReadToTableClass ReadToTable;