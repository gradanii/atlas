#include "atlas/types/binary.h"
#include "atlas/engine.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define index(x) (int)floor(x / 8.0)

uint8_t* binary_1d(uint8_t size, bool* inputs)
{
	int arr_size = (int)ceil(size / 8.0);
	uint8_t* arr = calloc(arr_size, sizeof(uint8_t));

	for (int i = 0; i < size; ++i)
	{
		arr[index(i)] = (arr[index(i)] << 1) ^ inputs[i];
	}

	return arr;
}

Tensor random(size_t* shape, size_t ndim)
{
	srand(time(NULL));

	Tensor tensor;
	tensor.ndim = ndim;
	tensor.shape = calloc(ndim, sizeof(size_t));
	memcpy(tensor.shape, shape, ndim * sizeof(size_t));

	size_t size = 1;
	for (size_t i = 0; i < ndim; ++i)
	{
		size *= shape[i];
	}

	bool* data = calloc(size, sizeof(bool));
	for (size_t i = 0; i < size; ++i)
	{
		data[i] = rand() % 2;
	}

	tensor.data = binary_1d(size, data);
	tensor.strides = calloc(ndim, sizeof(size_t));
	tensor.strides[ndim - 1] = 1;
	for (ssize_t i = ndim - 2; i >= 0; --i)
	{
		tensor.strides[i] = tensor.strides[i + 1] * tensor.shape[i + 1];
	}

	return tensor;
}
