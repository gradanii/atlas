#ifndef ATLAS_NEURON_H
#define ATLAS_NEURON_H

#include "atlas/engine.h"

bool neuron(uint8_t byte, uint8_t weight, uint8_t threshold);

bool* layer(uint8_t input, uint8_t* weights, uint8_t* thresholds, uint8_t n_neurons);

bool** forward
(uint8_t* inputs, uint8_t n_neurons, uint8_t n_layers, uint8_t** weights, uint8_t** thresholds);

bool* predict(bool** inputs, uint8_t n_layers, uint8_t n_neurons);

#endif
