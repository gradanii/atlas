#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool popcount(bool byte)
{
  byte -= (byte >> 1) & 0b01010101;
  byte = (byte & 0b00110011) + ((byte >> 2) & 0b00110011);
  byte = (byte + (byte >> 4)) & 0b00001111;
  return byte;
}

bool xnor_dot(bool byte1, bool byte2)
{
	bool xnor = ~(byte1 ^ byte2);
	return popcount(xnor);
}

bool xnor_dot_vector(bool vec1[], size_t len1, bool vec2[], size_t len2)
{
	bool *arr;
	size_t size = len1 < len2 ? len1 : len2;

	arr = (bool*)calloc(size, sizeof(bool));

	for (int i = 0; i < size; ++i)
	{
		arr[i] = ~(vec1[i] ^ vec2[i]);
	}

	bool final_popcount;
	for (int i = 0; i < size; ++i)
	{
		final_popcount += popcount(arr[i]);
	}

	return final_popcount;
}

bool threshold(bool byte, bool threshold_byte, bool threshold_distance)
{
	uint8_t distance = popcount(byte ^ threshold_byte);
	if (distance <= threshold_distance) { return true; } else { return false; }
}

bool activation(bool byte, bool threshold)
{
	if (popcount(byte) >= threshold) { return true; } else { return false; }
}
