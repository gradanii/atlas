#include "bareml/engine.h"

uint8_t cross_entropy(bool** inputs, bool** targets, uint8_t n_neurons, uint8_t n_layers)
{
	uint8_t xnor_sum = 0;
	for (int i = 0; i < n_layers; ++i)
	{
		for (int j = 0; j < n_neurons; ++j)
		{
			xnor_sum += ~(inputs[i][j] ^ targets[i][j]) & 0x1;
		}
	}

	return xnor_sum / (n_neurons * n_layers);
}
