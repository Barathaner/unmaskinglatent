
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
extern std::vector<int32_t> _dynamic_array_spikemonitor_i;
extern std::vector<double> _dynamic_array_spikemonitor_t;
extern std::vector<double> _dynamic_array_statemonitor_t;
extern std::vector<int32_t> _dynamic_array_synapses_1__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_1__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_1_delay;
extern std::vector<int32_t> _dynamic_array_synapses_1_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_1_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_1_w;
extern std::vector<int32_t> _dynamic_array_synapses_2__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_2__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_2_delay;
extern std::vector<int32_t> _dynamic_array_synapses_2_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_2_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_2_w;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_3_delay;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_3_w;
extern std::vector<int32_t> _dynamic_array_synapses_4__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_4__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_4_delay;
extern std::vector<int32_t> _dynamic_array_synapses_4_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_4_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_4_w;
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
extern int32_t *_array_neurongroup__spikespace;
extern const int _num__array_neurongroup__spikespace;
extern double *_array_neurongroup_g_ampa;
extern const int _num__array_neurongroup_g_ampa;
extern double *_array_neurongroup_g_gaba;
extern const int _num__array_neurongroup_g_gaba;
extern int32_t *_array_neurongroup_i;
extern const int _num__array_neurongroup_i;
extern double *_array_neurongroup_lastspike;
extern const int _num__array_neurongroup_lastspike;
extern char *_array_neurongroup_not_refractory;
extern const int _num__array_neurongroup_not_refractory;
extern int32_t *_array_neurongroup_subgroup_1__sub_idx;
extern const int _num__array_neurongroup_subgroup_1__sub_idx;
extern int32_t *_array_neurongroup_subgroup_2__sub_idx;
extern const int _num__array_neurongroup_subgroup_2__sub_idx;
extern int32_t *_array_neurongroup_subgroup__sub_idx;
extern const int _num__array_neurongroup_subgroup__sub_idx;
extern double *_array_neurongroup_v;
extern const int _num__array_neurongroup_v;
extern int32_t *_array_poissongroup__spikespace;
extern const int _num__array_poissongroup__spikespace;
extern int32_t *_array_poissongroup_i;
extern const int _num__array_poissongroup_i;
extern double *_array_poissongroup_rates;
extern const int _num__array_poissongroup_rates;
extern int32_t *_array_spikemonitor__source_idx;
extern const int _num__array_spikemonitor__source_idx;
extern int32_t *_array_spikemonitor_count;
extern const int _num__array_spikemonitor_count;
extern int32_t *_array_spikemonitor_N;
extern const int _num__array_spikemonitor_N;
extern int32_t *_array_statemonitor__indices;
extern const int _num__array_statemonitor__indices;
extern int32_t *_array_statemonitor_N;
extern const int _num__array_statemonitor_N;
extern double *_array_statemonitor_v;
extern const int _num__array_statemonitor_v;
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
extern int32_t *_array_synapses_4_N;
extern const int _num__array_synapses_4_N;
extern int32_t *_array_synapses_4_sources;
extern const int _num__array_synapses_4_sources;
extern int32_t *_array_synapses_4_targets;
extern const int _num__array_synapses_4_targets;
extern int32_t *_array_synapses_N;
extern const int _num__array_synapses_N;

//////////////// dynamic arrays 2d /////////
extern DynamicArray2D<double> _dynamic_array_statemonitor_v;

/////////////// static arrays /////////////
extern double *_static_array__array_poissongroup_rates;
extern const int _num__static_array__array_poissongroup_rates;
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
extern int32_t *_static_array__array_synapses_4_sources;
extern const int _num__static_array__array_synapses_4_sources;
extern int32_t *_static_array__array_synapses_4_targets;
extern const int _num__static_array__array_synapses_4_targets;

//////////////// synapses /////////////////
// synapses
extern SynapticPathway synapses_pre;
// synapses_1
extern SynapticPathway synapses_1_pre;
// synapses_2
extern SynapticPathway synapses_2_pre;
// synapses_3
extern SynapticPathway synapses_3_pre;
// synapses_4
extern SynapticPathway synapses_4_pre;

// Profiling information for each code object
}

void _init_arrays();
void _load_arrays();
void _write_arrays();
void _dealloc_arrays();

#endif


