#ifndef BAREML_TYPING_BINARY_H
#define BAREML_TYPING_BINARY_H

uint8_t* binary_1d(uint8_t size, bool* inputs);

uint8_t* random_binary_1d(uint8_t size, unsigned int seed);

uint8_t** binary_2d(uint8_t rows, uint8_t cols, bool inputs[rows][cols]);

uint8_t** random_binary_2d(uint8_t rows, uint8_t cols, unsigned int seed);

#endif
