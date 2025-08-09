#ifndef BAREML_ENGINE_H
#define BAREML_ENGINE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t popcount(uint8_t byte);

uint8_t xnor_dot(uint8_t byte1, uint8_t byte2);

uint8_t xnor_dot_vector(uint8_t vec1[], size_t len1, uint8_t vec2[], size_t len2);

bool threshold(uint8_t byte, uint8_t threshold_byte, uint8_t threshold_distance);

bool activation(uint8_t byte, uint8_t threshold);

#endif
