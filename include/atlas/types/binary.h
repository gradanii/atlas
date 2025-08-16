#ifndef ATLAS_TYPING_BINARY_H
#define ATLAS_TYPING_BINARY_H

#include "atlas/tensor.h"
#include <stdint.h>
#include <stdbool.h>

uint8_t* binary_1d(uint8_t size, bool* inputs);

Tensor random(size_t* shape, size_t ndim); 

#endif
