#include "atlas/tensor.h"

struct Context
{
	uint8_t* ctx_data;
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
static inline size_t size(const Tensor* a)
{
	size_t size = 1;
	for (size_t i = 0; i < a->ndim; i++) { size *= a->shape[i]; }
	return size;
}

Tensor tensor_like(const Tensor* a)
{
	Tensor out;

	out.data = malloc(size(a) * sizeof(uint8_t));
	out.ndim = a->ndim;

	out.shape = malloc(out.ndim * sizeof(size_t));
	memcpy(out.shape, a->shape, out.ndim * sizeof(size_t));

	out.strides = malloc(out.ndim * sizeof(size_t));
	memcpy(out.strides, a->strides, out.ndim * sizeof(size_t));

	out.requires_grad = a->requires_grad;
	out.grad_fn = NULL;
	return out;
}

Tensor zeros_like(const Tensor* a)
{
	Tensor out;

	out.data = calloc(size(a), sizeof(uint8_t));
	out.ndim = a->ndim;

	out.shape = malloc(out.ndim * sizeof(size_t));
	memcpy(out.shape, a->shape, out.ndim * sizeof(size_t));

	out.strides = malloc(out.ndim * sizeof(size_t));
	memcpy(out.strides, a->strides, out.ndim * sizeof(size_t));

	out.requires_grad = a->requires_grad;
	out.grad_fn = NULL;
	return out;
}

Tensor ones_like(const Tensor* a)
{
	Tensor out = tensor_like(a);
	for (size_t i = 0; i < size(a); i++) { out.data[i] = 1; }
	return out;
}
