
void dupeElement(int *arr, int index, int arrSize)
{
	if (index < arrSize - 1)
		for (int i = arrSize - 1; i > index; i--)
			arr[i] = arr[i - 1];
}

void duplicateZeros(int* arr, int arrSize)
{
    for (int i = arrSize - 1; i >= 0; i--)
		if ( arr[i] == 0)
			dupeElement(arr, i, arrSize);
}