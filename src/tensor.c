#include "atlas/tensor.h"
#include <assert.h>

struct Tensor
{
	uint8_t* data;
	size_t* shape;
	size_t* strides;
	size_t ndim;
	size_t nbit;
};

Tensor create(size_t ndim, size_t* shape, size_t nbit)
{
	Tensor out;
	out.ndim = ndim;
	out.nbit = nbit;

	out.shape = malloc(ndim * sizeof(size_t));
	memcpy(out.shape, shape, ndim * sizeof(size_t));

	out.data = malloc(packed_size(size(out), nbit) * sizeof(uint8_t));

	out.strides = malloc(ndim * sizeof(size_t));
	out.strides[ndim - 1] = 1;
	for (ssize_t i = ndim - 2; i >= 0; --i)
	{
		out.strides[i] = out.strides[i + 1] * out.shape[i + 1];
	}
	
	return out;
}

void free(Tensor* in)
{	
	free(in->data); 
	free(in->shape);
	free(in->strides);
}

Tensor* copy(const Tensor* src, Tensor* dest)
{
	assert(src->nbit == dest->nbit);
	assert(src->ndim == dest->ndim);
	for (size_t i = 0; i < dest->ndim; i++)
	{
		assert(src->shape[i] == dest->shape[i]);
	}

	memcpy(dest->data, src->data, size(dest) * sizeof(uint8_t));

	return dest;
}

Tensor* reshape(Tensor* in, size_t* shape, size_t ndim)
{
	in->ndim = ndim;

	in->shape = realloc(in->shape, ndim * sizeof(size_t));
	memcpy(in->shape, shape, ndim * sizeof(size_t));

	in->strides = realloc(in->strides, ndim * sizeof(size_t));
	in->strides[ndim - 1] = 1;
	for (ssize_t i = ndim - 2; i >= 0; --i)
	{
		in->strides[i] = in->strides[i + 1] * in->shape[i + 1];
	}

	return in;
}

uint8_t pack(uint8_t value)
{
	size_t nbit = 1;
	while (value >>= 1) {nbit++;}
	size_t size = (int)floor(8.0 / nbit);

	for (size_t i = 0; i < size; i++)
	{
		value |= value << (nbit * i);
	}

	return value;
}

Tensor* fill(Tensor* in, uint8_t value)
{
	for (size_t i = 0; i < size(in); i++)
	{
		in->data[i] = pack(value);	
	}

	return in;
}

Tensor tensor_like(const Tensor* in)
{
	Tensor out;

	out.data = malloc(size(in) * sizeof(uint8_t));
	out.ndim = a->ndim;
	out.nbit = a->nbit;

	out.shape = malloc(out.ndim * sizeof(size_t));
	memcpy(out.shape, a->shape, out.ndim * sizeof(size_t));
	
	out.strides = malloc(out.ndim * sizeof(size_t));
	memcpy(out.strides, a->strides, out.ndim * sizeof(size_t));

	return out;
}

Tensor zeros_like(const Tensor* in)
{
	Tensor out = tensor_like(in);
	memset(out.data, 0, size(out) * sizeof(uint8_t));
	return out;
}

Tensor ones_like(const Tensor* in)
{
	Tensor out = tensor_like(in);
	memset(out.data, 1, size(out) * sizeof(uint8_t));
	return out; 
}
