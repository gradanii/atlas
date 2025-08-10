#include "atlas/engine.h"

uint8_t popcount(uint8_t byte)
{
  byte -= (byte >> 1) & 0b01010101;
  byte = (byte & 0b00110011) + ((byte >> 2) & 0b00110011);
  byte = (byte + (byte >> 4)) & 0b00001111;
  return byte;
}

uint8_t xnor_dot(uint8_t byte1, uint8_t byte2)
{
	uint8_t xnor = ~(byte1 ^ byte2);
	return popcount(xnor);
}

uint8_t xnor_dot_vector(uint8_t vec1[], size_t len1, uint8_t vec2[], size_t len2)
{
	uint8_t *arr;
	size_t size = len1 < len2 ? len1 : len2;

	arr = (uint8_t*)calloc(size, sizeof(uint8_t));

	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = ~(vec1[i] ^ vec2[i]);
	}

	uint8_t final_popcount = 0;
	for (size_t i = 0; i < size; ++i)
	{
		final_popcount += popcount(arr[i]);
	}

	return final_popcount;
}

bool threshold(uint8_t byte, uint8_t threshold_byte, uint8_t threshold_distance)
{
	uint8_t distance = popcount(byte ^ threshold_byte);
	if (distance <= threshold_distance) { return true; } else { return false; }
}

bool activation(uint8_t byte, uint8_t threshold)
{
	if (popcount(byte) >= threshold) { return true; } else { return false; }
}
