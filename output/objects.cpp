
#include "objects.h"
#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>
#include<iostream>
#include<fstream>

namespace brian {

std::vector< rk_state* > _mersenne_twister_states;

//////////////// networks /////////////////
Network magicnetwork;

//////////////// arrays ///////////////////
double * _array_defaultclock_dt;
const int _num__array_defaultclock_dt = 1;
double * _array_defaultclock_t;
const int _num__array_defaultclock_t = 1;
int64_t * _array_defaultclock_timestep;
const int _num__array_defaultclock_timestep = 1;
int32_t * _array_neurongroup__spikespace;
const int _num__array_neurongroup__spikespace = 4001;
double * _array_neurongroup_g_ampa;
const int _num__array_neurongroup_g_ampa = 4000;
double * _array_neurongroup_g_gaba;
const int _num__array_neurongroup_g_gaba = 4000;
int32_t * _array_neurongroup_i;
const int _num__array_neurongroup_i = 4000;
double * _array_neurongroup_lastspike;
const int _num__array_neurongroup_lastspike = 4000;
char * _array_neurongroup_not_refractory;
const int _num__array_neurongroup_not_refractory = 4000;
int32_t * _array_neurongroup_subgroup_1__sub_idx;
const int _num__array_neurongroup_subgroup_1__sub_idx = 800;
int32_t * _array_neurongroup_subgroup_2__sub_idx;
const int _num__array_neurongroup_subgroup_2__sub_idx = 100;
int32_t * _array_neurongroup_subgroup__sub_idx;
const int _num__array_neurongroup_subgroup__sub_idx = 3200;
double * _array_neurongroup_v;
const int _num__array_neurongroup_v = 4000;
int32_t * _array_poissongroup__spikespace;
const int _num__array_poissongroup__spikespace = 101;
int32_t * _array_poissongroup_i;
const int _num__array_poissongroup_i = 100;
double * _array_poissongroup_rates;
const int _num__array_poissongroup_rates = 100;
int32_t * _array_spikemonitor__source_idx;
const int _num__array_spikemonitor__source_idx = 3200;
int32_t * _array_spikemonitor_count;
const int _num__array_spikemonitor_count = 3200;
int32_t * _array_spikemonitor_N;
const int _num__array_spikemonitor_N = 1;
int32_t * _array_statemonitor__indices;
const int _num__array_statemonitor__indices = 1;
int32_t * _array_statemonitor_N;
const int _num__array_statemonitor_N = 1;
double * _array_statemonitor_v;
const int _num__array_statemonitor_v = (0, 1);
int32_t * _array_synapses_1_N;
const int _num__array_synapses_1_N = 1;
int32_t * _array_synapses_1_sources;
const int _num__array_synapses_1_sources = 204490;
int32_t * _array_synapses_1_targets;
const int _num__array_synapses_1_targets = 204490;
int32_t * _array_synapses_2_N;
const int _num__array_synapses_2_N = 1;
int32_t * _array_synapses_2_sources;
const int _num__array_synapses_2_sources = 51197;
int32_t * _array_synapses_2_targets;
const int _num__array_synapses_2_targets = 51197;
int32_t * _array_synapses_3_N;
const int _num__array_synapses_3_N = 1;
int32_t * _array_synapses_3_sources;
const int _num__array_synapses_3_sources = 51120;
int32_t * _array_synapses_3_targets;
const int _num__array_synapses_3_targets = 51120;
int32_t * _array_synapses_4_N;
const int _num__array_synapses_4_N = 1;
int32_t * _array_synapses_4_sources;
const int _num__array_synapses_4_sources = 12788;
int32_t * _array_synapses_4_targets;
const int _num__array_synapses_4_targets = 12788;
int32_t * _array_synapses_N;
const int _num__array_synapses_N = 1;

//////////////// dynamic arrays 1d /////////
std::vector<int32_t> _dynamic_array_spikemonitor_i;
std::vector<double> _dynamic_array_spikemonitor_t;
std::vector<double> _dynamic_array_statemonitor_t;
std::vector<int32_t> _dynamic_array_synapses_1__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_1__synaptic_pre;
std::vector<double> _dynamic_array_synapses_1_delay;
std::vector<int32_t> _dynamic_array_synapses_1_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_1_N_outgoing;
std::vector<double> _dynamic_array_synapses_1_w;
std::vector<int32_t> _dynamic_array_synapses_2__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_2__synaptic_pre;
std::vector<double> _dynamic_array_synapses_2_delay;
std::vector<int32_t> _dynamic_array_synapses_2_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_2_N_outgoing;
std::vector<double> _dynamic_array_synapses_2_w;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
std::vector<double> _dynamic_array_synapses_3_delay;
std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
std::vector<double> _dynamic_array_synapses_3_w;
std::vector<int32_t> _dynamic_array_synapses_4__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_4__synaptic_pre;
std::vector<double> _dynamic_array_synapses_4_delay;
std::vector<int32_t> _dynamic_array_synapses_4_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_4_N_outgoing;
std::vector<double> _dynamic_array_synapses_4_w;
std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
std::vector<double> _dynamic_array_synapses_delay;
std::vector<int32_t> _dynamic_array_synapses_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_N_outgoing;

//////////////// dynamic arrays 2d /////////
DynamicArray2D<double> _dynamic_array_statemonitor_v;

/////////////// static arrays /////////////
double * _static_array__array_poissongroup_rates;
const int _num__static_array__array_poissongroup_rates = 100;
int32_t * _static_array__array_synapses_1_sources;
const int _num__static_array__array_synapses_1_sources = 204490;
int32_t * _static_array__array_synapses_1_targets;
const int _num__static_array__array_synapses_1_targets = 204490;
int32_t * _static_array__array_synapses_2_sources;
const int _num__static_array__array_synapses_2_sources = 51197;
int32_t * _static_array__array_synapses_2_targets;
const int _num__static_array__array_synapses_2_targets = 51197;
int32_t * _static_array__array_synapses_3_sources;
const int _num__static_array__array_synapses_3_sources = 51120;
int32_t * _static_array__array_synapses_3_targets;
const int _num__static_array__array_synapses_3_targets = 51120;
int32_t * _static_array__array_synapses_4_sources;
const int _num__static_array__array_synapses_4_sources = 12788;
int32_t * _static_array__array_synapses_4_targets;
const int _num__static_array__array_synapses_4_targets = 12788;

//////////////// synapses /////////////////
// synapses
SynapticPathway synapses_pre(
		_dynamic_array_synapses__synaptic_pre,
		0, 100);
// synapses_1
SynapticPathway synapses_1_pre(
		_dynamic_array_synapses_1__synaptic_pre,
		0, 3200);
// synapses_2
SynapticPathway synapses_2_pre(
		_dynamic_array_synapses_2__synaptic_pre,
		0, 3200);
// synapses_3
SynapticPathway synapses_3_pre(
		_dynamic_array_synapses_3__synaptic_pre,
		3200, 4000);
// synapses_4
SynapticPathway synapses_4_pre(
		_dynamic_array_synapses_4__synaptic_pre,
		3200, 4000);

//////////////// clocks ///////////////////
Clock defaultclock;  // attributes will be set in run.cpp

// Profiling information for each code object
}

void _init_arrays()
{
	using namespace brian;

    // Arrays initialized to 0
	_array_defaultclock_dt = new double[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_dt[i] = 0;

	_array_defaultclock_t = new double[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_t[i] = 0;

	_array_defaultclock_timestep = new int64_t[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_timestep[i] = 0;

	_array_neurongroup__spikespace = new int32_t[4001];
    
	for(int i=0; i<4001; i++) _array_neurongroup__spikespace[i] = 0;

	_array_neurongroup_g_ampa = new double[4000];
    
	for(int i=0; i<4000; i++) _array_neurongroup_g_ampa[i] = 0;

	_array_neurongroup_g_gaba = new double[4000];
    
	for(int i=0; i<4000; i++) _array_neurongroup_g_gaba[i] = 0;

	_array_neurongroup_i = new int32_t[4000];
    
	for(int i=0; i<4000; i++) _array_neurongroup_i[i] = 0;

	_array_neurongroup_lastspike = new double[4000];
    
	for(int i=0; i<4000; i++) _array_neurongroup_lastspike[i] = 0;

	_array_neurongroup_not_refractory = new char[4000];
    
	for(int i=0; i<4000; i++) _array_neurongroup_not_refractory[i] = 0;

	_array_neurongroup_subgroup_1__sub_idx = new int32_t[800];
    
	for(int i=0; i<800; i++) _array_neurongroup_subgroup_1__sub_idx[i] = 0;

	_array_neurongroup_subgroup_2__sub_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_subgroup_2__sub_idx[i] = 0;

	_array_neurongroup_subgroup__sub_idx = new int32_t[3200];
    
	for(int i=0; i<3200; i++) _array_neurongroup_subgroup__sub_idx[i] = 0;

	_array_neurongroup_v = new double[4000];
    
	for(int i=0; i<4000; i++) _array_neurongroup_v[i] = 0;

	_array_poissongroup__spikespace = new int32_t[101];
    
	for(int i=0; i<101; i++) _array_poissongroup__spikespace[i] = 0;

	_array_poissongroup_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_poissongroup_i[i] = 0;

	_array_poissongroup_rates = new double[100];
    
	for(int i=0; i<100; i++) _array_poissongroup_rates[i] = 0;

	_array_spikemonitor__source_idx = new int32_t[3200];
    
	for(int i=0; i<3200; i++) _array_spikemonitor__source_idx[i] = 0;

	_array_spikemonitor_count = new int32_t[3200];
    
	for(int i=0; i<3200; i++) _array_spikemonitor_count[i] = 0;

	_array_spikemonitor_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_N[i] = 0;

	_array_statemonitor__indices = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_statemonitor__indices[i] = 0;

	_array_statemonitor_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_statemonitor_N[i] = 0;

	_array_synapses_1_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_1_N[i] = 0;

	_array_synapses_1_sources = new int32_t[204490];
    
	for(int i=0; i<204490; i++) _array_synapses_1_sources[i] = 0;

	_array_synapses_1_targets = new int32_t[204490];
    
	for(int i=0; i<204490; i++) _array_synapses_1_targets[i] = 0;

	_array_synapses_2_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_2_N[i] = 0;

	_array_synapses_2_sources = new int32_t[51197];
    
	for(int i=0; i<51197; i++) _array_synapses_2_sources[i] = 0;

	_array_synapses_2_targets = new int32_t[51197];
    
	for(int i=0; i<51197; i++) _array_synapses_2_targets[i] = 0;

	_array_synapses_3_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_3_N[i] = 0;

	_array_synapses_3_sources = new int32_t[51120];
    
	for(int i=0; i<51120; i++) _array_synapses_3_sources[i] = 0;

	_array_synapses_3_targets = new int32_t[51120];
    
	for(int i=0; i<51120; i++) _array_synapses_3_targets[i] = 0;

	_array_synapses_4_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_4_N[i] = 0;

	_array_synapses_4_sources = new int32_t[12788];
    
	for(int i=0; i<12788; i++) _array_synapses_4_sources[i] = 0;

	_array_synapses_4_targets = new int32_t[12788];
    
	for(int i=0; i<12788; i++) _array_synapses_4_targets[i] = 0;

	_array_synapses_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_N[i] = 0;


	// Arrays initialized to an "arange"
	_array_neurongroup_i = new int32_t[4000];
    
	for(int i=0; i<4000; i++) _array_neurongroup_i[i] = 0 + i;

	_array_neurongroup_subgroup_1__sub_idx = new int32_t[800];
    
	for(int i=0; i<800; i++) _array_neurongroup_subgroup_1__sub_idx[i] = 3200 + i;

	_array_neurongroup_subgroup_2__sub_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_subgroup_2__sub_idx[i] = 0 + i;

	_array_neurongroup_subgroup__sub_idx = new int32_t[3200];
    
	for(int i=0; i<3200; i++) _array_neurongroup_subgroup__sub_idx[i] = 0 + i;

	_array_poissongroup_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_poissongroup_i[i] = 0 + i;

	_array_spikemonitor__source_idx = new int32_t[3200];
    
	for(int i=0; i<3200; i++) _array_spikemonitor__source_idx[i] = 0 + i;


	// static arrays
	_static_array__array_poissongroup_rates = new double[100];
	_static_array__array_synapses_1_sources = new int32_t[204490];
	_static_array__array_synapses_1_targets = new int32_t[204490];
	_static_array__array_synapses_2_sources = new int32_t[51197];
	_static_array__array_synapses_2_targets = new int32_t[51197];
	_static_array__array_synapses_3_sources = new int32_t[51120];
	_static_array__array_synapses_3_targets = new int32_t[51120];
	_static_array__array_synapses_4_sources = new int32_t[12788];
	_static_array__array_synapses_4_targets = new int32_t[12788];

	// Random number generator states
	for (int i=0; i<1; i++)
	    _mersenne_twister_states.push_back(new rk_state());
}

void _load_arrays()
{
	using namespace brian;

	ifstream f_static_array__array_poissongroup_rates;
	f_static_array__array_poissongroup_rates.open("static_arrays/_static_array__array_poissongroup_rates", ios::in | ios::binary);
	if(f_static_array__array_poissongroup_rates.is_open())
	{
		f_static_array__array_poissongroup_rates.read(reinterpret_cast<char*>(_static_array__array_poissongroup_rates), 100*sizeof(double));
	} else
	{
		std::cout << "Error opening static array _static_array__array_poissongroup_rates." << endl;
	}
	ifstream f_static_array__array_synapses_1_sources;
	f_static_array__array_synapses_1_sources.open("static_arrays/_static_array__array_synapses_1_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_1_sources.is_open())
	{
		f_static_array__array_synapses_1_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_1_sources), 204490*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_1_sources." << endl;
	}
	ifstream f_static_array__array_synapses_1_targets;
	f_static_array__array_synapses_1_targets.open("static_arrays/_static_array__array_synapses_1_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_1_targets.is_open())
	{
		f_static_array__array_synapses_1_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_1_targets), 204490*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_1_targets." << endl;
	}
	ifstream f_static_array__array_synapses_2_sources;
	f_static_array__array_synapses_2_sources.open("static_arrays/_static_array__array_synapses_2_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_2_sources.is_open())
	{
		f_static_array__array_synapses_2_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_2_sources), 51197*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_2_sources." << endl;
	}
	ifstream f_static_array__array_synapses_2_targets;
	f_static_array__array_synapses_2_targets.open("static_arrays/_static_array__array_synapses_2_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_2_targets.is_open())
	{
		f_static_array__array_synapses_2_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_2_targets), 51197*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_2_targets." << endl;
	}
	ifstream f_static_array__array_synapses_3_sources;
	f_static_array__array_synapses_3_sources.open("static_arrays/_static_array__array_synapses_3_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_3_sources.is_open())
	{
		f_static_array__array_synapses_3_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_3_sources), 51120*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_3_sources." << endl;
	}
	ifstream f_static_array__array_synapses_3_targets;
	f_static_array__array_synapses_3_targets.open("static_arrays/_static_array__array_synapses_3_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_3_targets.is_open())
	{
		f_static_array__array_synapses_3_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_3_targets), 51120*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_3_targets." << endl;
	}
	ifstream f_static_array__array_synapses_4_sources;
	f_static_array__array_synapses_4_sources.open("static_arrays/_static_array__array_synapses_4_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_4_sources.is_open())
	{
		f_static_array__array_synapses_4_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_4_sources), 12788*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_4_sources." << endl;
	}
	ifstream f_static_array__array_synapses_4_targets;
	f_static_array__array_synapses_4_targets.open("static_arrays/_static_array__array_synapses_4_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_4_targets.is_open())
	{
		f_static_array__array_synapses_4_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_4_targets), 12788*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_4_targets." << endl;
	}
}

void _write_arrays()
{
	using namespace brian;

	ofstream outfile__array_defaultclock_dt;
	outfile__array_defaultclock_dt.open("results\\_array_defaultclock_dt_1978099143", ios::binary | ios::out);
	if(outfile__array_defaultclock_dt.is_open())
	{
		outfile__array_defaultclock_dt.write(reinterpret_cast<char*>(_array_defaultclock_dt), 1*sizeof(_array_defaultclock_dt[0]));
		outfile__array_defaultclock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_dt." << endl;
	}
	ofstream outfile__array_defaultclock_t;
	outfile__array_defaultclock_t.open("results\\_array_defaultclock_t_2669362164", ios::binary | ios::out);
	if(outfile__array_defaultclock_t.is_open())
	{
		outfile__array_defaultclock_t.write(reinterpret_cast<char*>(_array_defaultclock_t), 1*sizeof(_array_defaultclock_t[0]));
		outfile__array_defaultclock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_t." << endl;
	}
	ofstream outfile__array_defaultclock_timestep;
	outfile__array_defaultclock_timestep.open("results\\_array_defaultclock_timestep_144223508", ios::binary | ios::out);
	if(outfile__array_defaultclock_timestep.is_open())
	{
		outfile__array_defaultclock_timestep.write(reinterpret_cast<char*>(_array_defaultclock_timestep), 1*sizeof(_array_defaultclock_timestep[0]));
		outfile__array_defaultclock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_timestep." << endl;
	}
	ofstream outfile__array_neurongroup__spikespace;
	outfile__array_neurongroup__spikespace.open("results\\_array_neurongroup__spikespace_3522821529", ios::binary | ios::out);
	if(outfile__array_neurongroup__spikespace.is_open())
	{
		outfile__array_neurongroup__spikespace.write(reinterpret_cast<char*>(_array_neurongroup__spikespace), 4001*sizeof(_array_neurongroup__spikespace[0]));
		outfile__array_neurongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_g_ampa;
	outfile__array_neurongroup_g_ampa.open("results\\_array_neurongroup_g_ampa_1967940385", ios::binary | ios::out);
	if(outfile__array_neurongroup_g_ampa.is_open())
	{
		outfile__array_neurongroup_g_ampa.write(reinterpret_cast<char*>(_array_neurongroup_g_ampa), 4000*sizeof(_array_neurongroup_g_ampa[0]));
		outfile__array_neurongroup_g_ampa.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_g_ampa." << endl;
	}
	ofstream outfile__array_neurongroup_g_gaba;
	outfile__array_neurongroup_g_gaba.open("results\\_array_neurongroup_g_gaba_566867274", ios::binary | ios::out);
	if(outfile__array_neurongroup_g_gaba.is_open())
	{
		outfile__array_neurongroup_g_gaba.write(reinterpret_cast<char*>(_array_neurongroup_g_gaba), 4000*sizeof(_array_neurongroup_g_gaba[0]));
		outfile__array_neurongroup_g_gaba.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_g_gaba." << endl;
	}
	ofstream outfile__array_neurongroup_i;
	outfile__array_neurongroup_i.open("results\\_array_neurongroup_i_2649026944", ios::binary | ios::out);
	if(outfile__array_neurongroup_i.is_open())
	{
		outfile__array_neurongroup_i.write(reinterpret_cast<char*>(_array_neurongroup_i), 4000*sizeof(_array_neurongroup_i[0]));
		outfile__array_neurongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_i." << endl;
	}
	ofstream outfile__array_neurongroup_lastspike;
	outfile__array_neurongroup_lastspike.open("results\\_array_neurongroup_lastspike_1647074423", ios::binary | ios::out);
	if(outfile__array_neurongroup_lastspike.is_open())
	{
		outfile__array_neurongroup_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_lastspike), 4000*sizeof(_array_neurongroup_lastspike[0]));
		outfile__array_neurongroup_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_not_refractory;
	outfile__array_neurongroup_not_refractory.open("results\\_array_neurongroup_not_refractory_1422681464", ios::binary | ios::out);
	if(outfile__array_neurongroup_not_refractory.is_open())
	{
		outfile__array_neurongroup_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_not_refractory), 4000*sizeof(_array_neurongroup_not_refractory[0]));
		outfile__array_neurongroup_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_subgroup_1__sub_idx;
	outfile__array_neurongroup_subgroup_1__sub_idx.open("results\\_array_neurongroup_subgroup_1__sub_idx_2735655493", ios::binary | ios::out);
	if(outfile__array_neurongroup_subgroup_1__sub_idx.is_open())
	{
		outfile__array_neurongroup_subgroup_1__sub_idx.write(reinterpret_cast<char*>(_array_neurongroup_subgroup_1__sub_idx), 800*sizeof(_array_neurongroup_subgroup_1__sub_idx[0]));
		outfile__array_neurongroup_subgroup_1__sub_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_subgroup_1__sub_idx." << endl;
	}
	ofstream outfile__array_neurongroup_subgroup_2__sub_idx;
	outfile__array_neurongroup_subgroup_2__sub_idx.open("results\\_array_neurongroup_subgroup_2__sub_idx_1211724102", ios::binary | ios::out);
	if(outfile__array_neurongroup_subgroup_2__sub_idx.is_open())
	{
		outfile__array_neurongroup_subgroup_2__sub_idx.write(reinterpret_cast<char*>(_array_neurongroup_subgroup_2__sub_idx), 100*sizeof(_array_neurongroup_subgroup_2__sub_idx[0]));
		outfile__array_neurongroup_subgroup_2__sub_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_subgroup_2__sub_idx." << endl;
	}
	ofstream outfile__array_neurongroup_subgroup__sub_idx;
	outfile__array_neurongroup_subgroup__sub_idx.open("results\\_array_neurongroup_subgroup__sub_idx_2982823616", ios::binary | ios::out);
	if(outfile__array_neurongroup_subgroup__sub_idx.is_open())
	{
		outfile__array_neurongroup_subgroup__sub_idx.write(reinterpret_cast<char*>(_array_neurongroup_subgroup__sub_idx), 3200*sizeof(_array_neurongroup_subgroup__sub_idx[0]));
		outfile__array_neurongroup_subgroup__sub_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_subgroup__sub_idx." << endl;
	}
	ofstream outfile__array_neurongroup_v;
	outfile__array_neurongroup_v.open("results\\_array_neurongroup_v_283966581", ios::binary | ios::out);
	if(outfile__array_neurongroup_v.is_open())
	{
		outfile__array_neurongroup_v.write(reinterpret_cast<char*>(_array_neurongroup_v), 4000*sizeof(_array_neurongroup_v[0]));
		outfile__array_neurongroup_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_v." << endl;
	}
	ofstream outfile__array_poissongroup__spikespace;
	outfile__array_poissongroup__spikespace.open("results\\_array_poissongroup__spikespace_1019000416", ios::binary | ios::out);
	if(outfile__array_poissongroup__spikespace.is_open())
	{
		outfile__array_poissongroup__spikespace.write(reinterpret_cast<char*>(_array_poissongroup__spikespace), 101*sizeof(_array_poissongroup__spikespace[0]));
		outfile__array_poissongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup__spikespace." << endl;
	}
	ofstream outfile__array_poissongroup_i;
	outfile__array_poissongroup_i.open("results\\_array_poissongroup_i_1277690444", ios::binary | ios::out);
	if(outfile__array_poissongroup_i.is_open())
	{
		outfile__array_poissongroup_i.write(reinterpret_cast<char*>(_array_poissongroup_i), 100*sizeof(_array_poissongroup_i[0]));
		outfile__array_poissongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_i." << endl;
	}
	ofstream outfile__array_poissongroup_rates;
	outfile__array_poissongroup_rates.open("results\\_array_poissongroup_rates_3353413371", ios::binary | ios::out);
	if(outfile__array_poissongroup_rates.is_open())
	{
		outfile__array_poissongroup_rates.write(reinterpret_cast<char*>(_array_poissongroup_rates), 100*sizeof(_array_poissongroup_rates[0]));
		outfile__array_poissongroup_rates.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_rates." << endl;
	}
	ofstream outfile__array_spikemonitor__source_idx;
	outfile__array_spikemonitor__source_idx.open("results\\_array_spikemonitor__source_idx_1477951789", ios::binary | ios::out);
	if(outfile__array_spikemonitor__source_idx.is_open())
	{
		outfile__array_spikemonitor__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor__source_idx), 3200*sizeof(_array_spikemonitor__source_idx[0]));
		outfile__array_spikemonitor__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_count;
	outfile__array_spikemonitor_count.open("results\\_array_spikemonitor_count_598337445", ios::binary | ios::out);
	if(outfile__array_spikemonitor_count.is_open())
	{
		outfile__array_spikemonitor_count.write(reinterpret_cast<char*>(_array_spikemonitor_count), 3200*sizeof(_array_spikemonitor_count[0]));
		outfile__array_spikemonitor_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_count." << endl;
	}
	ofstream outfile__array_spikemonitor_N;
	outfile__array_spikemonitor_N.open("results\\_array_spikemonitor_N_225734567", ios::binary | ios::out);
	if(outfile__array_spikemonitor_N.is_open())
	{
		outfile__array_spikemonitor_N.write(reinterpret_cast<char*>(_array_spikemonitor_N), 1*sizeof(_array_spikemonitor_N[0]));
		outfile__array_spikemonitor_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_N." << endl;
	}
	ofstream outfile__array_statemonitor__indices;
	outfile__array_statemonitor__indices.open("results\\_array_statemonitor__indices_2854283999", ios::binary | ios::out);
	if(outfile__array_statemonitor__indices.is_open())
	{
		outfile__array_statemonitor__indices.write(reinterpret_cast<char*>(_array_statemonitor__indices), 1*sizeof(_array_statemonitor__indices[0]));
		outfile__array_statemonitor__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor__indices." << endl;
	}
	ofstream outfile__array_statemonitor_N;
	outfile__array_statemonitor_N.open("results\\_array_statemonitor_N_4140778434", ios::binary | ios::out);
	if(outfile__array_statemonitor_N.is_open())
	{
		outfile__array_statemonitor_N.write(reinterpret_cast<char*>(_array_statemonitor_N), 1*sizeof(_array_statemonitor_N[0]));
		outfile__array_statemonitor_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_N." << endl;
	}
	ofstream outfile__array_synapses_1_N;
	outfile__array_synapses_1_N.open("results\\_array_synapses_1_N_1771729519", ios::binary | ios::out);
	if(outfile__array_synapses_1_N.is_open())
	{
		outfile__array_synapses_1_N.write(reinterpret_cast<char*>(_array_synapses_1_N), 1*sizeof(_array_synapses_1_N[0]));
		outfile__array_synapses_1_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_N." << endl;
	}
	ofstream outfile__array_synapses_1_sources;
	outfile__array_synapses_1_sources.open("results\\_array_synapses_1_sources_93121092", ios::binary | ios::out);
	if(outfile__array_synapses_1_sources.is_open())
	{
		outfile__array_synapses_1_sources.write(reinterpret_cast<char*>(_array_synapses_1_sources), 204490*sizeof(_array_synapses_1_sources[0]));
		outfile__array_synapses_1_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_sources." << endl;
	}
	ofstream outfile__array_synapses_1_targets;
	outfile__array_synapses_1_targets.open("results\\_array_synapses_1_targets_2022871461", ios::binary | ios::out);
	if(outfile__array_synapses_1_targets.is_open())
	{
		outfile__array_synapses_1_targets.write(reinterpret_cast<char*>(_array_synapses_1_targets), 204490*sizeof(_array_synapses_1_targets[0]));
		outfile__array_synapses_1_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_targets." << endl;
	}
	ofstream outfile__array_synapses_2_N;
	outfile__array_synapses_2_N.open("results\\_array_synapses_2_N_1809632310", ios::binary | ios::out);
	if(outfile__array_synapses_2_N.is_open())
	{
		outfile__array_synapses_2_N.write(reinterpret_cast<char*>(_array_synapses_2_N), 1*sizeof(_array_synapses_2_N[0]));
		outfile__array_synapses_2_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_N." << endl;
	}
	ofstream outfile__array_synapses_2_sources;
	outfile__array_synapses_2_sources.open("results\\_array_synapses_2_sources_1006753409", ios::binary | ios::out);
	if(outfile__array_synapses_2_sources.is_open())
	{
		outfile__array_synapses_2_sources.write(reinterpret_cast<char*>(_array_synapses_2_sources), 51197*sizeof(_array_synapses_2_sources[0]));
		outfile__array_synapses_2_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_sources." << endl;
	}
	ofstream outfile__array_synapses_2_targets;
	outfile__array_synapses_2_targets.open("results\\_array_synapses_2_targets_1092595040", ios::binary | ios::out);
	if(outfile__array_synapses_2_targets.is_open())
	{
		outfile__array_synapses_2_targets.write(reinterpret_cast<char*>(_array_synapses_2_targets), 51197*sizeof(_array_synapses_2_targets[0]));
		outfile__array_synapses_2_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_targets." << endl;
	}
	ofstream outfile__array_synapses_3_N;
	outfile__array_synapses_3_N.open("results\\_array_synapses_3_N_1780393473", ios::binary | ios::out);
	if(outfile__array_synapses_3_N.is_open())
	{
		outfile__array_synapses_3_N.write(reinterpret_cast<char*>(_array_synapses_3_N), 1*sizeof(_array_synapses_3_N[0]));
		outfile__array_synapses_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_N." << endl;
	}
	ofstream outfile__array_synapses_3_sources;
	outfile__array_synapses_3_sources.open("results\\_array_synapses_3_sources_729465538", ios::binary | ios::out);
	if(outfile__array_synapses_3_sources.is_open())
	{
		outfile__array_synapses_3_sources.write(reinterpret_cast<char*>(_array_synapses_3_sources), 51120*sizeof(_array_synapses_3_sources[0]));
		outfile__array_synapses_3_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_sources." << endl;
	}
	ofstream outfile__array_synapses_3_targets;
	outfile__array_synapses_3_targets.open("results\\_array_synapses_3_targets_1449441571", ios::binary | ios::out);
	if(outfile__array_synapses_3_targets.is_open())
	{
		outfile__array_synapses_3_targets.write(reinterpret_cast<char*>(_array_synapses_3_targets), 51120*sizeof(_array_synapses_3_targets[0]));
		outfile__array_synapses_3_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_targets." << endl;
	}
	ofstream outfile__array_synapses_4_N;
	outfile__array_synapses_4_N.open("results\\_array_synapses_4_N_1867624580", ios::binary | ios::out);
	if(outfile__array_synapses_4_N.is_open())
	{
		outfile__array_synapses_4_N.write(reinterpret_cast<char*>(_array_synapses_4_N), 1*sizeof(_array_synapses_4_N[0]));
		outfile__array_synapses_4_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_4_N." << endl;
	}
	ofstream outfile__array_synapses_4_sources;
	outfile__array_synapses_4_sources.open("results\\_array_synapses_4_sources_1327214347", ios::binary | ios::out);
	if(outfile__array_synapses_4_sources.is_open())
	{
		outfile__array_synapses_4_sources.write(reinterpret_cast<char*>(_array_synapses_4_sources), 12788*sizeof(_array_synapses_4_sources[0]));
		outfile__array_synapses_4_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_4_sources." << endl;
	}
	ofstream outfile__array_synapses_4_targets;
	outfile__array_synapses_4_targets.open("results\\_array_synapses_4_targets_839242986", ios::binary | ios::out);
	if(outfile__array_synapses_4_targets.is_open())
	{
		outfile__array_synapses_4_targets.write(reinterpret_cast<char*>(_array_synapses_4_targets), 12788*sizeof(_array_synapses_4_targets[0]));
		outfile__array_synapses_4_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_4_targets." << endl;
	}
	ofstream outfile__array_synapses_N;
	outfile__array_synapses_N.open("results\\_array_synapses_N_483293785", ios::binary | ios::out);
	if(outfile__array_synapses_N.is_open())
	{
		outfile__array_synapses_N.write(reinterpret_cast<char*>(_array_synapses_N), 1*sizeof(_array_synapses_N[0]));
		outfile__array_synapses_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_N." << endl;
	}

	ofstream outfile__dynamic_array_spikemonitor_i;
	outfile__dynamic_array_spikemonitor_i.open("results\\_dynamic_array_spikemonitor_i_1976709050", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_i[0]), _dynamic_array_spikemonitor_i.size()*sizeof(_dynamic_array_spikemonitor_i[0]));
		    outfile__dynamic_array_spikemonitor_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_t;
	outfile__dynamic_array_spikemonitor_t.open("results\\_dynamic_array_spikemonitor_t_383009635", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_t[0]), _dynamic_array_spikemonitor_t.size()*sizeof(_dynamic_array_spikemonitor_t[0]));
		    outfile__dynamic_array_spikemonitor_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_t;
	outfile__dynamic_array_statemonitor_t.open("results\\_dynamic_array_statemonitor_t_3983503110", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_t.is_open())
	{
        if (! _dynamic_array_statemonitor_t.empty() )
        {
			outfile__dynamic_array_statemonitor_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_t[0]), _dynamic_array_statemonitor_t.size()*sizeof(_dynamic_array_statemonitor_t[0]));
		    outfile__dynamic_array_statemonitor_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_t." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1__synaptic_post;
	outfile__dynamic_array_synapses_1__synaptic_post.open("results\\_dynamic_array_synapses_1__synaptic_post_1999337987", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_1__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_1__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1__synaptic_post[0]), _dynamic_array_synapses_1__synaptic_post.size()*sizeof(_dynamic_array_synapses_1__synaptic_post[0]));
		    outfile__dynamic_array_synapses_1__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1__synaptic_pre;
	outfile__dynamic_array_synapses_1__synaptic_pre.open("results\\_dynamic_array_synapses_1__synaptic_pre_681065502", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_1__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_1__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1__synaptic_pre[0]), _dynamic_array_synapses_1__synaptic_pre.size()*sizeof(_dynamic_array_synapses_1__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_1__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_delay;
	outfile__dynamic_array_synapses_1_delay.open("results\\_dynamic_array_synapses_1_delay_2373823482", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_delay.is_open())
	{
        if (! _dynamic_array_synapses_1_delay.empty() )
        {
			outfile__dynamic_array_synapses_1_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_delay[0]), _dynamic_array_synapses_1_delay.size()*sizeof(_dynamic_array_synapses_1_delay[0]));
		    outfile__dynamic_array_synapses_1_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_N_incoming;
	outfile__dynamic_array_synapses_1_N_incoming.open("results\\_dynamic_array_synapses_1_N_incoming_3469555706", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_1_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_1_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_N_incoming[0]), _dynamic_array_synapses_1_N_incoming.size()*sizeof(_dynamic_array_synapses_1_N_incoming[0]));
		    outfile__dynamic_array_synapses_1_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_N_outgoing;
	outfile__dynamic_array_synapses_1_N_outgoing.open("results\\_dynamic_array_synapses_1_N_outgoing_3922806560", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_1_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_1_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_N_outgoing[0]), _dynamic_array_synapses_1_N_outgoing.size()*sizeof(_dynamic_array_synapses_1_N_outgoing[0]));
		    outfile__dynamic_array_synapses_1_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_w;
	outfile__dynamic_array_synapses_1_w.open("results\\_dynamic_array_synapses_1_w_1857285062", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_w.is_open())
	{
        if (! _dynamic_array_synapses_1_w.empty() )
        {
			outfile__dynamic_array_synapses_1_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_w[0]), _dynamic_array_synapses_1_w.size()*sizeof(_dynamic_array_synapses_1_w[0]));
		    outfile__dynamic_array_synapses_1_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2__synaptic_post;
	outfile__dynamic_array_synapses_2__synaptic_post.open("results\\_dynamic_array_synapses_2__synaptic_post_1591987953", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_2__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_2__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2__synaptic_post[0]), _dynamic_array_synapses_2__synaptic_post.size()*sizeof(_dynamic_array_synapses_2__synaptic_post[0]));
		    outfile__dynamic_array_synapses_2__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2__synaptic_pre;
	outfile__dynamic_array_synapses_2__synaptic_pre.open("results\\_dynamic_array_synapses_2__synaptic_pre_971331175", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_2__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_2__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2__synaptic_pre[0]), _dynamic_array_synapses_2__synaptic_pre.size()*sizeof(_dynamic_array_synapses_2__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_2__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_delay;
	outfile__dynamic_array_synapses_2_delay.open("results\\_dynamic_array_synapses_2_delay_3163926887", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_delay.is_open())
	{
        if (! _dynamic_array_synapses_2_delay.empty() )
        {
			outfile__dynamic_array_synapses_2_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_delay[0]), _dynamic_array_synapses_2_delay.size()*sizeof(_dynamic_array_synapses_2_delay[0]));
		    outfile__dynamic_array_synapses_2_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_N_incoming;
	outfile__dynamic_array_synapses_2_N_incoming.open("results\\_dynamic_array_synapses_2_N_incoming_3109283082", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_2_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_2_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_N_incoming[0]), _dynamic_array_synapses_2_N_incoming.size()*sizeof(_dynamic_array_synapses_2_N_incoming[0]));
		    outfile__dynamic_array_synapses_2_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_N_outgoing;
	outfile__dynamic_array_synapses_2_N_outgoing.open("results\\_dynamic_array_synapses_2_N_outgoing_2656015824", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_2_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_2_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_N_outgoing[0]), _dynamic_array_synapses_2_N_outgoing.size()*sizeof(_dynamic_array_synapses_2_N_outgoing[0]));
		    outfile__dynamic_array_synapses_2_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_w;
	outfile__dynamic_array_synapses_2_w.open("results\\_dynamic_array_synapses_2_w_1828017567", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_w.is_open())
	{
        if (! _dynamic_array_synapses_2_w.empty() )
        {
			outfile__dynamic_array_synapses_2_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_w[0]), _dynamic_array_synapses_2_w.size()*sizeof(_dynamic_array_synapses_2_w[0]));
		    outfile__dynamic_array_synapses_2_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3__synaptic_post;
	outfile__dynamic_array_synapses_3__synaptic_post.open("results\\_dynamic_array_synapses_3__synaptic_post_4035665760", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_3__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_3__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3__synaptic_post[0]), _dynamic_array_synapses_3__synaptic_post.size()*sizeof(_dynamic_array_synapses_3__synaptic_post[0]));
		    outfile__dynamic_array_synapses_3__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3__synaptic_pre;
	outfile__dynamic_array_synapses_3__synaptic_pre.open("results\\_dynamic_array_synapses_3__synaptic_pre_2149485967", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_3__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_3__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3__synaptic_pre[0]), _dynamic_array_synapses_3__synaptic_pre.size()*sizeof(_dynamic_array_synapses_3__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_3__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_delay;
	outfile__dynamic_array_synapses_3_delay.open("results\\_dynamic_array_synapses_3_delay_451066579", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_delay.is_open())
	{
        if (! _dynamic_array_synapses_3_delay.empty() )
        {
			outfile__dynamic_array_synapses_3_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_delay[0]), _dynamic_array_synapses_3_delay.size()*sizeof(_dynamic_array_synapses_3_delay[0]));
		    outfile__dynamic_array_synapses_3_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_N_incoming;
	outfile__dynamic_array_synapses_3_N_incoming.open("results\\_dynamic_array_synapses_3_N_incoming_586590565", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_3_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_3_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_N_incoming[0]), _dynamic_array_synapses_3_N_incoming.size()*sizeof(_dynamic_array_synapses_3_N_incoming[0]));
		    outfile__dynamic_array_synapses_3_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_N_outgoing;
	outfile__dynamic_array_synapses_3_N_outgoing.open("results\\_dynamic_array_synapses_3_N_outgoing_99277247", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_3_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_3_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_N_outgoing[0]), _dynamic_array_synapses_3_N_outgoing.size()*sizeof(_dynamic_array_synapses_3_N_outgoing[0]));
		    outfile__dynamic_array_synapses_3_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_w;
	outfile__dynamic_array_synapses_3_w.open("results\\_dynamic_array_synapses_3_w_1832337320", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_w.is_open())
	{
        if (! _dynamic_array_synapses_3_w.empty() )
        {
			outfile__dynamic_array_synapses_3_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_w[0]), _dynamic_array_synapses_3_w.size()*sizeof(_dynamic_array_synapses_3_w[0]));
		    outfile__dynamic_array_synapses_3_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4__synaptic_post;
	outfile__dynamic_array_synapses_4__synaptic_post.open("results\\_dynamic_array_synapses_4__synaptic_post_225617685", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_4__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_4__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4__synaptic_post[0]), _dynamic_array_synapses_4__synaptic_post.size()*sizeof(_dynamic_array_synapses_4__synaptic_post[0]));
		    outfile__dynamic_array_synapses_4__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4__synaptic_pre;
	outfile__dynamic_array_synapses_4__synaptic_pre.open("results\\_dynamic_array_synapses_4__synaptic_pre_455049877", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_4__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_4__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4__synaptic_pre[0]), _dynamic_array_synapses_4__synaptic_pre.size()*sizeof(_dynamic_array_synapses_4__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_4__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_delay;
	outfile__dynamic_array_synapses_4_delay.open("results\\_dynamic_array_synapses_4_delay_3745875037", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_delay.is_open())
	{
        if (! _dynamic_array_synapses_4_delay.empty() )
        {
			outfile__dynamic_array_synapses_4_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_delay[0]), _dynamic_array_synapses_4_delay.size()*sizeof(_dynamic_array_synapses_4_delay[0]));
		    outfile__dynamic_array_synapses_4_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_N_incoming;
	outfile__dynamic_array_synapses_4_N_incoming.open("results\\_dynamic_array_synapses_4_N_incoming_1450066154", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_4_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_4_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_N_incoming[0]), _dynamic_array_synapses_4_N_incoming.size()*sizeof(_dynamic_array_synapses_4_N_incoming[0]));
		    outfile__dynamic_array_synapses_4_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_N_outgoing;
	outfile__dynamic_array_synapses_4_N_outgoing.open("results\\_dynamic_array_synapses_4_N_outgoing_1903308848", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_4_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_4_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_N_outgoing[0]), _dynamic_array_synapses_4_N_outgoing.size()*sizeof(_dynamic_array_synapses_4_N_outgoing[0]));
		    outfile__dynamic_array_synapses_4_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_w;
	outfile__dynamic_array_synapses_4_w.open("results\\_dynamic_array_synapses_4_w_1752705325", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_w.is_open())
	{
        if (! _dynamic_array_synapses_4_w.empty() )
        {
			outfile__dynamic_array_synapses_4_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_w[0]), _dynamic_array_synapses_4_w.size()*sizeof(_dynamic_array_synapses_4_w[0]));
		    outfile__dynamic_array_synapses_4_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses__synaptic_post;
	outfile__dynamic_array_synapses__synaptic_post.open("results\\_dynamic_array_synapses__synaptic_post_1801389495", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses__synaptic_post[0]), _dynamic_array_synapses__synaptic_post.size()*sizeof(_dynamic_array_synapses__synaptic_post[0]));
		    outfile__dynamic_array_synapses__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses__synaptic_pre;
	outfile__dynamic_array_synapses__synaptic_pre.open("results\\_dynamic_array_synapses__synaptic_pre_814148175", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses__synaptic_pre[0]), _dynamic_array_synapses__synaptic_pre.size()*sizeof(_dynamic_array_synapses__synaptic_pre[0]));
		    outfile__dynamic_array_synapses__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_delay;
	outfile__dynamic_array_synapses_delay.open("results\\_dynamic_array_synapses_delay_3246960869", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_delay.is_open())
	{
        if (! _dynamic_array_synapses_delay.empty() )
        {
			outfile__dynamic_array_synapses_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_delay[0]), _dynamic_array_synapses_delay.size()*sizeof(_dynamic_array_synapses_delay[0]));
		    outfile__dynamic_array_synapses_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_N_incoming;
	outfile__dynamic_array_synapses_N_incoming.open("results\\_dynamic_array_synapses_N_incoming_1151751685", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_N_incoming[0]), _dynamic_array_synapses_N_incoming.size()*sizeof(_dynamic_array_synapses_N_incoming[0]));
		    outfile__dynamic_array_synapses_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_N_outgoing;
	outfile__dynamic_array_synapses_N_outgoing.open("results\\_dynamic_array_synapses_N_outgoing_1673144031", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_N_outgoing[0]), _dynamic_array_synapses_N_outgoing.size()*sizeof(_dynamic_array_synapses_N_outgoing[0]));
		    outfile__dynamic_array_synapses_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_N_outgoing." << endl;
	}

	ofstream outfile__dynamic_array_statemonitor_v;
	outfile__dynamic_array_statemonitor_v.open("results\\_dynamic_array_statemonitor_v_56692266", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_v.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_v.n; n++)
        {
            if (! _dynamic_array_statemonitor_v(n).empty())
            {
                outfile__dynamic_array_statemonitor_v.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_v(n, 0)), _dynamic_array_statemonitor_v.m*sizeof(_dynamic_array_statemonitor_v(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_v.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_v." << endl;
	}
	// Write last run info to disk
	ofstream outfile_last_run_info;
	outfile_last_run_info.open("results/last_run_info.txt", ios::out);
	if(outfile_last_run_info.is_open())
	{
		outfile_last_run_info << (Network::_last_run_time) << " " << (Network::_last_run_completed_fraction) << std::endl;
		outfile_last_run_info.close();
	} else
	{
	    std::cout << "Error writing last run info to file." << std::endl;
	}
}

void _dealloc_arrays()
{
	using namespace brian;


	// static arrays
	if(_static_array__array_poissongroup_rates!=0)
	{
		delete [] _static_array__array_poissongroup_rates;
		_static_array__array_poissongroup_rates = 0;
	}
	if(_static_array__array_synapses_1_sources!=0)
	{
		delete [] _static_array__array_synapses_1_sources;
		_static_array__array_synapses_1_sources = 0;
	}
	if(_static_array__array_synapses_1_targets!=0)
	{
		delete [] _static_array__array_synapses_1_targets;
		_static_array__array_synapses_1_targets = 0;
	}
	if(_static_array__array_synapses_2_sources!=0)
	{
		delete [] _static_array__array_synapses_2_sources;
		_static_array__array_synapses_2_sources = 0;
	}
	if(_static_array__array_synapses_2_targets!=0)
	{
		delete [] _static_array__array_synapses_2_targets;
		_static_array__array_synapses_2_targets = 0;
	}
	if(_static_array__array_synapses_3_sources!=0)
	{
		delete [] _static_array__array_synapses_3_sources;
		_static_array__array_synapses_3_sources = 0;
	}
	if(_static_array__array_synapses_3_targets!=0)
	{
		delete [] _static_array__array_synapses_3_targets;
		_static_array__array_synapses_3_targets = 0;
	}
	if(_static_array__array_synapses_4_sources!=0)
	{
		delete [] _static_array__array_synapses_4_sources;
		_static_array__array_synapses_4_sources = 0;
	}
	if(_static_array__array_synapses_4_targets!=0)
	{
		delete [] _static_array__array_synapses_4_targets;
		_static_array__array_synapses_4_targets = 0;
	}
}

