#include <stdbool.h>

char* categorizeBox(int length, int width, int height, int mass) {
    bool isHeavy = false;
	bool isBulky = false;
	long vol = (long)length * (long)width * (long)height;
	if (mass >= 100)
		isHeavy = true;
	if ((vol >= 1000000000) || (length >= 10000 || width >= 10000 || height >= 10000))
		isBulky = true;

	if (isBulky && isHeavy)
		return "Both";
	if (isBulky)
		return "Bulky";
	if (isHeavy)
		return "Heavy";
	return "Neither";
}
