
#ifndef _BRIAN_OBJECTS_H
#define _BRIAN_OBJECTS_H

#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>


namespace brian {

// In OpenMP we need one state per thread
extern std::vector< rk_state* > _mersenne_twister_states;

//////////////// clocks ///////////////////
extern Clock defaultclock;

//////////////// networks /////////////////
extern Network magicnetwork;

//////////////// dynamic arrays ///////////
extern std::vector<int32_t> _dynamic_array_spikegeneratorgroup__timebins;
extern std::vector<int32_t> _dynamic_array_spikegeneratorgroup_neuron_index;
extern std::vector<int32_t> _dynamic_array_spikegeneratorgroup_spike_number;
extern std::vector<double> _dynamic_array_spikegeneratorgroup_spike_time;
extern std::vector<int32_t> _dynamic_array_spikemonitor_i;
extern std::vector<double> _dynamic_array_spikemonitor_t;
extern std::vector<int32_t> _dynamic_array_synapses_1__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_1__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_1_delay;
extern std::vector<int32_t> _dynamic_array_synapses_1_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_1_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_2__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_2__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_2_delay;
extern std::vector<int32_t> _dynamic_array_synapses_2_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_2_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_3_delay;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_delay;
extern std::vector<int32_t> _dynamic_array_synapses_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_N_outgoing;

//////////////// arrays ///////////////////
extern double *_array_defaultclock_dt;
extern const int _num__array_defaultclock_dt;
extern double *_array_defaultclock_t;
extern const int _num__array_defaultclock_t;
extern int64_t *_array_defaultclock_timestep;
extern const int _num__array_defaultclock_timestep;
extern int32_t *_array_neurongroup_1__spikespace;
extern const int _num__array_neurongroup_1__spikespace;
extern int32_t *_array_neurongroup_1_i;
extern const int _num__array_neurongroup_1_i;
extern double *_array_neurongroup_1_lastspike;
extern const int _num__array_neurongroup_1_lastspike;
extern char *_array_neurongroup_1_not_refractory;
extern const int _num__array_neurongroup_1_not_refractory;
extern double *_array_neurongroup_1_v;
extern const int _num__array_neurongroup_1_v;
extern int32_t *_array_neurongroup__spikespace;
extern const int _num__array_neurongroup__spikespace;
extern int32_t *_array_neurongroup_i;
extern const int _num__array_neurongroup_i;
extern double *_array_neurongroup_I;
extern const int _num__array_neurongroup_I;
extern double *_array_neurongroup_lastspike;
extern const int _num__array_neurongroup_lastspike;
extern char *_array_neurongroup_not_refractory;
extern const int _num__array_neurongroup_not_refractory;
extern double *_array_neurongroup_v;
extern const int _num__array_neurongroup_v;
extern int32_t *_array_spikegeneratorgroup__lastindex;
extern const int _num__array_spikegeneratorgroup__lastindex;
extern int32_t *_array_spikegeneratorgroup__period_bins;
extern const int _num__array_spikegeneratorgroup__period_bins;
extern int32_t *_array_spikegeneratorgroup__spikespace;
extern const int _num__array_spikegeneratorgroup__spikespace;
extern int32_t *_array_spikegeneratorgroup_i;
extern const int _num__array_spikegeneratorgroup_i;
extern double *_array_spikegeneratorgroup_period;
extern const int _num__array_spikegeneratorgroup_period;
extern int32_t *_array_spikemonitor__source_idx;
extern const int _num__array_spikemonitor__source_idx;
extern int32_t *_array_spikemonitor_count;
extern const int _num__array_spikemonitor_count;
extern int32_t *_array_spikemonitor_N;
extern const int _num__array_spikemonitor_N;
extern int32_t *_array_synapses_1_N;
extern const int _num__array_synapses_1_N;
extern int32_t *_array_synapses_1_sources;
extern const int _num__array_synapses_1_sources;
extern int32_t *_array_synapses_1_targets;
extern const int _num__array_synapses_1_targets;
extern int32_t *_array_synapses_2_N;
extern const int _num__array_synapses_2_N;
extern int32_t *_array_synapses_2_sources;
extern const int _num__array_synapses_2_sources;
extern int32_t *_array_synapses_2_targets;
extern const int _num__array_synapses_2_targets;
extern int32_t *_array_synapses_3_N;
extern const int _num__array_synapses_3_N;
extern int32_t *_array_synapses_3_sources;
extern const int _num__array_synapses_3_sources;
extern int32_t *_array_synapses_3_targets;
extern const int _num__array_synapses_3_targets;
extern int32_t *_array_synapses_N;
extern const int _num__array_synapses_N;
extern int32_t *_array_synapses_sources;
extern const int _num__array_synapses_sources;
extern int32_t *_array_synapses_targets;
extern const int _num__array_synapses_targets;

//////////////// dynamic arrays 2d /////////

/////////////// static arrays /////////////
extern int32_t *_static_array__array_synapses_1_sources;
extern const int _num__static_array__array_synapses_1_sources;
extern int32_t *_static_array__array_synapses_1_targets;
extern const int _num__static_array__array_synapses_1_targets;
extern int32_t *_static_array__array_synapses_2_sources;
extern const int _num__static_array__array_synapses_2_sources;
extern int32_t *_static_array__array_synapses_2_targets;
extern const int _num__static_array__array_synapses_2_targets;
extern int32_t *_static_array__array_synapses_3_sources;
extern const int _num__static_array__array_synapses_3_sources;
extern int32_t *_static_array__array_synapses_3_targets;
extern const int _num__static_array__array_synapses_3_targets;
extern int32_t *_static_array__array_synapses_sources;
extern const int _num__static_array__array_synapses_sources;
extern int32_t *_static_array__array_synapses_targets;
extern const int _num__static_array__array_synapses_targets;
extern int32_t *_static_array__dynamic_array_spikegeneratorgroup__timebins;
extern const int _num__static_array__dynamic_array_spikegeneratorgroup__timebins;
extern double *_static_array__dynamic_array_spikegeneratorgroup_neuron_index;
extern const int _num__static_array__dynamic_array_spikegeneratorgroup_neuron_index;
extern int32_t *_static_array__dynamic_array_spikegeneratorgroup_spike_number;
extern const int _num__static_array__dynamic_array_spikegeneratorgroup_spike_number;
extern double *_static_array__dynamic_array_spikegeneratorgroup_spike_time;
extern const int _num__static_array__dynamic_array_spikegeneratorgroup_spike_time;

//////////////// synapses /////////////////
// synapses
extern SynapticPathway synapses_pre;
// synapses_1
extern SynapticPathway synapses_1_pre;
// synapses_2
extern SynapticPathway synapses_2_pre;
// synapses_3
extern SynapticPathway synapses_3_pre;

// Profiling information for each code object
}

void _init_arrays();
void _load_arrays();
void _write_arrays();
void _dealloc_arrays();

#endif


