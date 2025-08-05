#ifndef BAREML_TYPING_BINARY_H
#define BAREML_TYPING_BINARY_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define index(x) (int)floor(x / 8.0)

uint8_t* tensor_1d(bool* inputs, uint8_t size)
{
	int arr_size = (int)ceil(size / 8.0);
	uint8_t* arr = (uint8_t*)calloc(arr_size, sizeof(uint8_t));

	for (int i = 0; i < size; ++i)
	{
		arr[index(i)] = (arr[index(i)] << 1) ^ inputs[i];
	}

	return arr;
}

#endif
