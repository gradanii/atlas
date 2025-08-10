#include "atlas/tensor.h"
#include <stdint.h>
#include <stddef.h>

typedef struct Tensor
{
	uint8_t* data;
	size_t* shape;
	size_t* strides;
	size_t ndim;
} Tensor;

/* A 2D-array: [[1, 2, 3], [4, 5, 6]]
	 The struct takes this, and flattens it: [1, 2, 3, 4, 5, 6]
	 In order to index properly, it takes the shape [2, 3] (2 sub-arrays, 3 elements in each array)
	 Strides means how many bytes it needs to skip to get to the next sub-array.
	 Lets take our example, first we get the size of an element, we're using uint8_ts so the size is 1 byte.
	 A strides attribute can look like: [3, 1]. This means one sub-array is 3 * 1 bytes.
	 We can infer this from our shapes attribute, by taking the sizeof(elem) and the second element of our shape.
	 Note: This example is for a 2D Tensor.

	 So if i want to access the element '4', with 2D indexing we can do array[1][0] (0th element of 1st array).
	 We can achieve this by taking the same indexes, (1, 0) but this time, to access the first one, it does (i * stride + j).
*/
