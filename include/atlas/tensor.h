#ifndef ATLAS_TENSOR_H
#define ATLAS_TENSOR_H

#include <stdint.h>
#include <stdbool.h> 
#include <stddef.h>

typedef struct Context Context;

typedef struct Backward Backward;

typedef struct Tensor Tensor;

uint8_t get(Tensor* tensor, size_t* indices);

static inline size_t size(const Tensor* a)
{
	size_t size = 1;
	for (size_t i = 0; i < a->ndim; i++) { size *= a->shape[i]; }
	return size;
}

Tensor tensor_like(const Tensor* a);
Tensor zeros_like(const Tensor* a);
Tensor ones_like(const Tensor* a);

#endif
