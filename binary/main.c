#include "src/neuron.c"

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
	
	bool* prediction = predict(arr, n_layers, n_neurons);
	
	for (int i = 0; i < n_neurons; ++i)
	{
		printf("%hhu", prediction[i]);
	}
	printf("\n");
}
