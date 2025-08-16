#ifndef ATLAS_TENSOR_H
#define ATLAS_TENSOR_H

#include <stdint.h>
#include <stdbool.h> 
#include <stddef.h>

typedef struct Context Context;

typedef struct Backward Backward;

typedef struct Tensor Tensor;

uint8_t get(Tensor* tensor, size_t* indices);

#endif
