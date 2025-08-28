#ifndef ATLAS_TENSOR_H
#define ATLAS_TENSOR_H

#include <stdint.h>
#include <stdbool.h> 
#include <stddef.h>

typedef struct Tensor Tensor;

static inline size_t size(const Tensor* a)
{
	size_t size = 1;
	for (size_t i = 0; i < a->ndim; i++) { size *= a->shape[i]; }
	return size;
}

static inline size_t packed_size(size_t size, size_t nbit)
{
	return (int)ceil(size / (int)floor(8.0 / nbit));
}

Tensor create(size_t ndim, size_t* shape, size_t nbit);
void free(Tensor* in);
Tensor* copy(const Tensor* src, Tensor* dest);
Tensor* reshape(Tensor* in, size_t* shape, size_t ndim);
uint8_t pack(uint8_t value);
Tensor* fill(Tensor* in, uint8_t value)

#endif
