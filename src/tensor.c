#include "atlas/tensor.h"

struct Context
{
	
}

struct Backward
{
	Context ctx;
	void (*backward)(Context* ctx, const Tensor* grad_output);
}

struct Tensor
{
	uint8_t* data;
	size_t* shape;
	size_t* strides;
	size_t ndim;
	bool requires_grad;
	Backward* grad_fn;
};

uint8_t get(Tensor* tensor, size_t* indices)
{
	size_t* strides = tensor->strides;
	size_t ndim = tensor->ndim;

	size_t idx = 0;
	for (size_t i = 0; i < ndim; ++i)
	{
		idx += indices[i] * strides[i];
	}

	return tensor->data[idx];
}

