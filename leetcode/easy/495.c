#include <string.h>


int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
	if (timeSeriesSize <= 0 || duration <= 0)
		return 0;
	
	int result = 0;
	for (int i = 0; i < timeSeriesSize; i++)
	{
		if (i == timeSeriesSize - 1)
			result += duration;
		else if (timeSeries[i + 1] - timeSeries[i] < duration)
			result += timeSeries[i + 1] - timeSeries[i];
		else
			result += duration;
	}
	return result;
}
