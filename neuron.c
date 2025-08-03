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
(uint8_t* inputs, uint8_t n_neurons, uint8_t n_layers, uint8_t weights[n_neurons][n_layers], uint8_t thresholds[n_neurons][n_layers])
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

int main()
{
	uint8_t inputs[] = {1, 0, 1}; 

	uint8_t weights[2][3] = {
	  {1, 0, 1}, 
		{0, 1, 1} 
	};

	uint8_t thresholds[2][3] = {
		{1, 1, 2}, 
		{1, 0, 0} 
	};

	uint8_t n_neurons = 3;

	uint8_t n_layers = 2;

	bool** arr = forward(inputs, n_neurons, n_layers, weights, thresholds);

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j) { printf("%d ", arr[i][j]); }
		printf("\n");
	}
}
