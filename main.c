#include "atlas/neuron.h"
#include "atlas/types/binary.h"

int main()
{
	uint8_t n_neurons = 3;
	uint8_t n_layers = 2;

	size_t wt_shape = {2, 3};
	size_t i_shape = {3};

	uint8_t* inputs = random(i_shape, 42);
	uint8_t** weights = random(wt_shape, 21);
	uint8_t** thresholds = random_binary_2d(n_layers, n_neurons, 20);

	bool** arr = forward(inputs, n_neurons, n_layers, weights, thresholds);
	
	bool* prediction = predict(arr, n_layers, n_neurons);
	
	for (int i = 0; i < n_neurons; ++i)
	{
		printf("%hhu ", prediction[i]);
	}
	printf("\n");

	bool ins[] = {1, 0, 1};

	uint8_t* packed = binary_1d(n_neurons, ins);

	for (int i = 0; i < 1; ++i) printf("%hhu\n", packed[i]);
}
