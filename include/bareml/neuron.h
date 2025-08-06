#ifndef BAREML_NEURON_H
#define BAREML_NEURON_H

#include "engine.h"

bool neuron(uint8_t byte, uint8_t weight, uint8_t threshold)
{
	uint8_t dot_product = xnor_dot(byte, weight);
	return activation(dot_product, threshold);
}

bool* layer(uint8_t input, uint8_t* weights, uint8_t* thresholds, uint8_t n_neurons)
{
	bool *arr;
	arr = (bool*)calloc(n_neurons, sizeof(bool));

	for (int i = 0; i < n_neurons; ++i)
	{
		arr[i] = neuron(input, weights[i], thresholds[i]);
	}

	return arr;
}

bool** forward
(uint8_t* inputs, uint8_t n_neurons, uint8_t n_layers, uint8_t** weights, uint8_t** thresholds)
{
	bool **arr = (bool**)calloc(n_layers, sizeof(bool*));
	for (int i = 0; i < n_layers; ++i)
	{
		arr[i] = (bool*)calloc(n_neurons, sizeof(bool));
	}

	for (int i = 0; i < n_layers; ++i)
	{
		arr[i] = layer(inputs[i], weights[i], thresholds[i], n_neurons);
	}

	return arr;
}

bool* predict(bool** inputs, uint8_t n_layers, uint8_t n_neurons)
{
	uint8_t *arr = (uint8_t*)calloc(n_layers, sizeof(uint8_t));

	uint8_t max_activation = arr[0];
	bool* output = inputs[0];
	for (int i = 0; i < n_layers; ++i)
	{
		arr[i] = 0;
		for (int j = 0; j < n_neurons; ++j)
		{
			arr[i] += inputs[i][j];
		}
		if (arr[i] > max_activation) { max_activation = arr[i]; output = inputs[i]; }
	}

	free(arr);
	return output;
}

#endif
