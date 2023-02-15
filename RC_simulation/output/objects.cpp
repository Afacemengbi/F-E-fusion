
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
int32_t * _array_neurongroup_1__spikespace;
const int _num__array_neurongroup_1__spikespace = 2;
int32_t * _array_neurongroup_1_i;
const int _num__array_neurongroup_1_i = 1;
double * _array_neurongroup_1_lastspike;
const int _num__array_neurongroup_1_lastspike = 1;
char * _array_neurongroup_1_not_refractory;
const int _num__array_neurongroup_1_not_refractory = 1;
double * _array_neurongroup_1_v;
const int _num__array_neurongroup_1_v = 1;
int32_t * _array_neurongroup__spikespace;
const int _num__array_neurongroup__spikespace = 32401;
int32_t * _array_neurongroup_i;
const int _num__array_neurongroup_i = 32400;
double * _array_neurongroup_I;
const int _num__array_neurongroup_I = 32400;
double * _array_neurongroup_lastspike;
const int _num__array_neurongroup_lastspike = 32400;
char * _array_neurongroup_not_refractory;
const int _num__array_neurongroup_not_refractory = 32400;
double * _array_neurongroup_v;
const int _num__array_neurongroup_v = 32400;
int32_t * _array_spikegeneratorgroup__lastindex;
const int _num__array_spikegeneratorgroup__lastindex = 1;
int32_t * _array_spikegeneratorgroup__period_bins;
const int _num__array_spikegeneratorgroup__period_bins = 1;
int32_t * _array_spikegeneratorgroup__spikespace;
const int _num__array_spikegeneratorgroup__spikespace = 129601;
int32_t * _array_spikegeneratorgroup_i;
const int _num__array_spikegeneratorgroup_i = 129600;
double * _array_spikegeneratorgroup_period;
const int _num__array_spikegeneratorgroup_period = 1;
int32_t * _array_spikemonitor__source_idx;
const int _num__array_spikemonitor__source_idx = 32400;
int32_t * _array_spikemonitor_count;
const int _num__array_spikemonitor_count = 32400;
int32_t * _array_spikemonitor_N;
const int _num__array_spikemonitor_N = 1;
int32_t * _array_synapses_1_N;
const int _num__array_synapses_1_N = 1;
int32_t * _array_synapses_1_sources;
const int _num__array_synapses_1_sources = 128850;
int32_t * _array_synapses_1_targets;
const int _num__array_synapses_1_targets = 128850;
int32_t * _array_synapses_2_N;
const int _num__array_synapses_2_N = 1;
int32_t * _array_synapses_2_sources;
const int _num__array_synapses_2_sources = 32400;
int32_t * _array_synapses_2_targets;
const int _num__array_synapses_2_targets = 32400;
int32_t * _array_synapses_3_N;
const int _num__array_synapses_3_N = 1;
int32_t * _array_synapses_3_sources;
const int _num__array_synapses_3_sources = 32400;
int32_t * _array_synapses_3_targets;
const int _num__array_synapses_3_targets = 32400;
int32_t * _array_synapses_N;
const int _num__array_synapses_N = 1;
int32_t * _array_synapses_sources;
const int _num__array_synapses_sources = 645000;
int32_t * _array_synapses_targets;
const int _num__array_synapses_targets = 645000;

//////////////// dynamic arrays 1d /////////
std::vector<int32_t> _dynamic_array_spikegeneratorgroup__timebins;
std::vector<int32_t> _dynamic_array_spikegeneratorgroup_neuron_index;
std::vector<int32_t> _dynamic_array_spikegeneratorgroup_spike_number;
std::vector<double> _dynamic_array_spikegeneratorgroup_spike_time;
std::vector<int32_t> _dynamic_array_spikemonitor_i;
std::vector<double> _dynamic_array_spikemonitor_t;
std::vector<int32_t> _dynamic_array_synapses_1__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_1__synaptic_pre;
std::vector<double> _dynamic_array_synapses_1_delay;
std::vector<int32_t> _dynamic_array_synapses_1_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_1_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_2__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_2__synaptic_pre;
std::vector<double> _dynamic_array_synapses_2_delay;
std::vector<int32_t> _dynamic_array_synapses_2_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_2_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
std::vector<double> _dynamic_array_synapses_3_delay;
std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
std::vector<double> _dynamic_array_synapses_delay;
std::vector<int32_t> _dynamic_array_synapses_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_N_outgoing;

//////////////// dynamic arrays 2d /////////

/////////////// static arrays /////////////
int32_t * _static_array__array_synapses_1_sources;
const int _num__static_array__array_synapses_1_sources = 128850;
int32_t * _static_array__array_synapses_1_targets;
const int _num__static_array__array_synapses_1_targets = 128850;
int32_t * _static_array__array_synapses_2_sources;
const int _num__static_array__array_synapses_2_sources = 32400;
int32_t * _static_array__array_synapses_2_targets;
const int _num__static_array__array_synapses_2_targets = 32400;
int32_t * _static_array__array_synapses_3_sources;
const int _num__static_array__array_synapses_3_sources = 32400;
int32_t * _static_array__array_synapses_3_targets;
const int _num__static_array__array_synapses_3_targets = 32400;
int32_t * _static_array__array_synapses_sources;
const int _num__static_array__array_synapses_sources = 645000;
int32_t * _static_array__array_synapses_targets;
const int _num__static_array__array_synapses_targets = 645000;
int32_t * _static_array__dynamic_array_spikegeneratorgroup__timebins;
const int _num__static_array__dynamic_array_spikegeneratorgroup__timebins = 5820222;
double * _static_array__dynamic_array_spikegeneratorgroup_neuron_index;
const int _num__static_array__dynamic_array_spikegeneratorgroup_neuron_index = 5820222;
int32_t * _static_array__dynamic_array_spikegeneratorgroup_spike_number;
const int _num__static_array__dynamic_array_spikegeneratorgroup_spike_number = 5820222;
double * _static_array__dynamic_array_spikegeneratorgroup_spike_time;
const int _num__static_array__dynamic_array_spikegeneratorgroup_spike_time = 5820222;

//////////////// synapses /////////////////
// synapses
SynapticPathway synapses_pre(
		_dynamic_array_synapses__synaptic_pre,
		0, 129600);
// synapses_1
SynapticPathway synapses_1_pre(
		_dynamic_array_synapses_1__synaptic_pre,
		0, 32400);
// synapses_2
SynapticPathway synapses_2_pre(
		_dynamic_array_synapses_2__synaptic_pre,
		0, 32400);
// synapses_3
SynapticPathway synapses_3_pre(
		_dynamic_array_synapses_3__synaptic_pre,
		0, 1);

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

	_array_neurongroup_1__spikespace = new int32_t[2];
    
	for(int i=0; i<2; i++) _array_neurongroup_1__spikespace[i] = 0;

	_array_neurongroup_1_i = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_neurongroup_1_i[i] = 0;

	_array_neurongroup_1_lastspike = new double[1];
    
	for(int i=0; i<1; i++) _array_neurongroup_1_lastspike[i] = 0;

	_array_neurongroup_1_not_refractory = new char[1];
    
	for(int i=0; i<1; i++) _array_neurongroup_1_not_refractory[i] = 0;

	_array_neurongroup_1_v = new double[1];
    
	for(int i=0; i<1; i++) _array_neurongroup_1_v[i] = 0;

	_array_neurongroup__spikespace = new int32_t[32401];
    
	for(int i=0; i<32401; i++) _array_neurongroup__spikespace[i] = 0;

	_array_neurongroup_i = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_neurongroup_i[i] = 0;

	_array_neurongroup_I = new double[32400];
    
	for(int i=0; i<32400; i++) _array_neurongroup_I[i] = 0;

	_array_neurongroup_lastspike = new double[32400];
    
	for(int i=0; i<32400; i++) _array_neurongroup_lastspike[i] = 0;

	_array_neurongroup_not_refractory = new char[32400];
    
	for(int i=0; i<32400; i++) _array_neurongroup_not_refractory[i] = 0;

	_array_neurongroup_v = new double[32400];
    
	for(int i=0; i<32400; i++) _array_neurongroup_v[i] = 0;

	_array_spikegeneratorgroup__lastindex = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikegeneratorgroup__lastindex[i] = 0;

	_array_spikegeneratorgroup__period_bins = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikegeneratorgroup__period_bins[i] = 0;

	_array_spikegeneratorgroup__spikespace = new int32_t[129601];
    
	for(int i=0; i<129601; i++) _array_spikegeneratorgroup__spikespace[i] = 0;

	_array_spikegeneratorgroup_i = new int32_t[129600];
    
	for(int i=0; i<129600; i++) _array_spikegeneratorgroup_i[i] = 0;

	_array_spikegeneratorgroup_period = new double[1];
    
	for(int i=0; i<1; i++) _array_spikegeneratorgroup_period[i] = 0;

	_array_spikemonitor__source_idx = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_spikemonitor__source_idx[i] = 0;

	_array_spikemonitor_count = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_spikemonitor_count[i] = 0;

	_array_spikemonitor_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_N[i] = 0;

	_array_synapses_1_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_1_N[i] = 0;

	_array_synapses_1_sources = new int32_t[128850];
    
	for(int i=0; i<128850; i++) _array_synapses_1_sources[i] = 0;

	_array_synapses_1_targets = new int32_t[128850];
    
	for(int i=0; i<128850; i++) _array_synapses_1_targets[i] = 0;

	_array_synapses_2_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_2_N[i] = 0;

	_array_synapses_2_sources = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_synapses_2_sources[i] = 0;

	_array_synapses_2_targets = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_synapses_2_targets[i] = 0;

	_array_synapses_3_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_3_N[i] = 0;

	_array_synapses_3_sources = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_synapses_3_sources[i] = 0;

	_array_synapses_3_targets = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_synapses_3_targets[i] = 0;

	_array_synapses_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_N[i] = 0;

	_array_synapses_sources = new int32_t[645000];
    
	for(int i=0; i<645000; i++) _array_synapses_sources[i] = 0;

	_array_synapses_targets = new int32_t[645000];
    
	for(int i=0; i<645000; i++) _array_synapses_targets[i] = 0;

	_dynamic_array_spikegeneratorgroup__timebins.resize(5820222);
    
	for(int i=0; i<5820222; i++) _dynamic_array_spikegeneratorgroup__timebins[i] = 0;


	// Arrays initialized to an "arange"
	_array_neurongroup_1_i = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_neurongroup_1_i[i] = 0 + i;

	_array_neurongroup_i = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_neurongroup_i[i] = 0 + i;

	_array_spikegeneratorgroup_i = new int32_t[129600];
    
	for(int i=0; i<129600; i++) _array_spikegeneratorgroup_i[i] = 0 + i;

	_array_spikemonitor__source_idx = new int32_t[32400];
    
	for(int i=0; i<32400; i++) _array_spikemonitor__source_idx[i] = 0 + i;


	// static arrays
	_static_array__array_synapses_1_sources = new int32_t[128850];
	_static_array__array_synapses_1_targets = new int32_t[128850];
	_static_array__array_synapses_2_sources = new int32_t[32400];
	_static_array__array_synapses_2_targets = new int32_t[32400];
	_static_array__array_synapses_3_sources = new int32_t[32400];
	_static_array__array_synapses_3_targets = new int32_t[32400];
	_static_array__array_synapses_sources = new int32_t[645000];
	_static_array__array_synapses_targets = new int32_t[645000];
	_static_array__dynamic_array_spikegeneratorgroup__timebins = new int32_t[5820222];
	_static_array__dynamic_array_spikegeneratorgroup_neuron_index = new double[5820222];
	_static_array__dynamic_array_spikegeneratorgroup_spike_number = new int32_t[5820222];
	_static_array__dynamic_array_spikegeneratorgroup_spike_time = new double[5820222];

	// Random number generator states
	for (int i=0; i<1; i++)
	    _mersenne_twister_states.push_back(new rk_state());
}

void _load_arrays()
{
	using namespace brian;

	ifstream f_static_array__array_synapses_1_sources;
	f_static_array__array_synapses_1_sources.open("static_arrays/_static_array__array_synapses_1_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_1_sources.is_open())
	{
		f_static_array__array_synapses_1_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_1_sources), 128850*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_1_sources." << endl;
	}
	ifstream f_static_array__array_synapses_1_targets;
	f_static_array__array_synapses_1_targets.open("static_arrays/_static_array__array_synapses_1_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_1_targets.is_open())
	{
		f_static_array__array_synapses_1_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_1_targets), 128850*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_1_targets." << endl;
	}
	ifstream f_static_array__array_synapses_2_sources;
	f_static_array__array_synapses_2_sources.open("static_arrays/_static_array__array_synapses_2_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_2_sources.is_open())
	{
		f_static_array__array_synapses_2_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_2_sources), 32400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_2_sources." << endl;
	}
	ifstream f_static_array__array_synapses_2_targets;
	f_static_array__array_synapses_2_targets.open("static_arrays/_static_array__array_synapses_2_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_2_targets.is_open())
	{
		f_static_array__array_synapses_2_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_2_targets), 32400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_2_targets." << endl;
	}
	ifstream f_static_array__array_synapses_3_sources;
	f_static_array__array_synapses_3_sources.open("static_arrays/_static_array__array_synapses_3_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_3_sources.is_open())
	{
		f_static_array__array_synapses_3_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_3_sources), 32400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_3_sources." << endl;
	}
	ifstream f_static_array__array_synapses_3_targets;
	f_static_array__array_synapses_3_targets.open("static_arrays/_static_array__array_synapses_3_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_3_targets.is_open())
	{
		f_static_array__array_synapses_3_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_3_targets), 32400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_3_targets." << endl;
	}
	ifstream f_static_array__array_synapses_sources;
	f_static_array__array_synapses_sources.open("static_arrays/_static_array__array_synapses_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_sources.is_open())
	{
		f_static_array__array_synapses_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_sources), 645000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_sources." << endl;
	}
	ifstream f_static_array__array_synapses_targets;
	f_static_array__array_synapses_targets.open("static_arrays/_static_array__array_synapses_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_targets.is_open())
	{
		f_static_array__array_synapses_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_targets), 645000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_targets." << endl;
	}
	ifstream f_static_array__dynamic_array_spikegeneratorgroup__timebins;
	f_static_array__dynamic_array_spikegeneratorgroup__timebins.open("static_arrays/_static_array__dynamic_array_spikegeneratorgroup__timebins", ios::in | ios::binary);
	if(f_static_array__dynamic_array_spikegeneratorgroup__timebins.is_open())
	{
		f_static_array__dynamic_array_spikegeneratorgroup__timebins.read(reinterpret_cast<char*>(_static_array__dynamic_array_spikegeneratorgroup__timebins), 5820222*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_spikegeneratorgroup__timebins." << endl;
	}
	ifstream f_static_array__dynamic_array_spikegeneratorgroup_neuron_index;
	f_static_array__dynamic_array_spikegeneratorgroup_neuron_index.open("static_arrays/_static_array__dynamic_array_spikegeneratorgroup_neuron_index", ios::in | ios::binary);
	if(f_static_array__dynamic_array_spikegeneratorgroup_neuron_index.is_open())
	{
		f_static_array__dynamic_array_spikegeneratorgroup_neuron_index.read(reinterpret_cast<char*>(_static_array__dynamic_array_spikegeneratorgroup_neuron_index), 5820222*sizeof(double));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_spikegeneratorgroup_neuron_index." << endl;
	}
	ifstream f_static_array__dynamic_array_spikegeneratorgroup_spike_number;
	f_static_array__dynamic_array_spikegeneratorgroup_spike_number.open("static_arrays/_static_array__dynamic_array_spikegeneratorgroup_spike_number", ios::in | ios::binary);
	if(f_static_array__dynamic_array_spikegeneratorgroup_spike_number.is_open())
	{
		f_static_array__dynamic_array_spikegeneratorgroup_spike_number.read(reinterpret_cast<char*>(_static_array__dynamic_array_spikegeneratorgroup_spike_number), 5820222*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_spikegeneratorgroup_spike_number." << endl;
	}
	ifstream f_static_array__dynamic_array_spikegeneratorgroup_spike_time;
	f_static_array__dynamic_array_spikegeneratorgroup_spike_time.open("static_arrays/_static_array__dynamic_array_spikegeneratorgroup_spike_time", ios::in | ios::binary);
	if(f_static_array__dynamic_array_spikegeneratorgroup_spike_time.is_open())
	{
		f_static_array__dynamic_array_spikegeneratorgroup_spike_time.read(reinterpret_cast<char*>(_static_array__dynamic_array_spikegeneratorgroup_spike_time), 5820222*sizeof(double));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_spikegeneratorgroup_spike_time." << endl;
	}
}

void _write_arrays()
{
	using namespace brian;

	ofstream outfile__array_defaultclock_dt;
	outfile__array_defaultclock_dt.open("results\\_array_defaultclock_dt_954160716723284944", ios::binary | ios::out);
	if(outfile__array_defaultclock_dt.is_open())
	{
		outfile__array_defaultclock_dt.write(reinterpret_cast<char*>(_array_defaultclock_dt), 1*sizeof(_array_defaultclock_dt[0]));
		outfile__array_defaultclock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_dt." << endl;
	}
	ofstream outfile__array_defaultclock_t;
	outfile__array_defaultclock_t.open("results\\_array_defaultclock_t_5595926809420031807", ios::binary | ios::out);
	if(outfile__array_defaultclock_t.is_open())
	{
		outfile__array_defaultclock_t.write(reinterpret_cast<char*>(_array_defaultclock_t), 1*sizeof(_array_defaultclock_t[0]));
		outfile__array_defaultclock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_t." << endl;
	}
	ofstream outfile__array_defaultclock_timestep;
	outfile__array_defaultclock_timestep.open("results\\_array_defaultclock_timestep_-2813826139499328", ios::binary | ios::out);
	if(outfile__array_defaultclock_timestep.is_open())
	{
		outfile__array_defaultclock_timestep.write(reinterpret_cast<char*>(_array_defaultclock_timestep), 1*sizeof(_array_defaultclock_timestep[0]));
		outfile__array_defaultclock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_timestep." << endl;
	}
	ofstream outfile__array_neurongroup_1__spikespace;
	outfile__array_neurongroup_1__spikespace.open("results\\_array_neurongroup_1__spikespace_7887940249966485082", ios::binary | ios::out);
	if(outfile__array_neurongroup_1__spikespace.is_open())
	{
		outfile__array_neurongroup_1__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_1__spikespace), 2*sizeof(_array_neurongroup_1__spikespace[0]));
		outfile__array_neurongroup_1__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_1_i;
	outfile__array_neurongroup_1_i.open("results\\_array_neurongroup_1_i_7605822074949008300", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_i.is_open())
	{
		outfile__array_neurongroup_1_i.write(reinterpret_cast<char*>(_array_neurongroup_1_i), 1*sizeof(_array_neurongroup_1_i[0]));
		outfile__array_neurongroup_1_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_i." << endl;
	}
	ofstream outfile__array_neurongroup_1_lastspike;
	outfile__array_neurongroup_1_lastspike.open("results\\_array_neurongroup_1_lastspike_-5350603279028959773", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_lastspike.is_open())
	{
		outfile__array_neurongroup_1_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_1_lastspike), 1*sizeof(_array_neurongroup_1_lastspike[0]));
		outfile__array_neurongroup_1_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_1_not_refractory;
	outfile__array_neurongroup_1_not_refractory.open("results\\_array_neurongroup_1_not_refractory_8940264560477323351", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_not_refractory.is_open())
	{
		outfile__array_neurongroup_1_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_1_not_refractory), 1*sizeof(_array_neurongroup_1_not_refractory[0]));
		outfile__array_neurongroup_1_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_1_v;
	outfile__array_neurongroup_1_v.open("results\\_array_neurongroup_1_v_8062063899918039706", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_v.is_open())
	{
		outfile__array_neurongroup_1_v.write(reinterpret_cast<char*>(_array_neurongroup_1_v), 1*sizeof(_array_neurongroup_1_v[0]));
		outfile__array_neurongroup_1_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_v." << endl;
	}
	ofstream outfile__array_neurongroup__spikespace;
	outfile__array_neurongroup__spikespace.open("results\\_array_neurongroup__spikespace_4502034366888998833", ios::binary | ios::out);
	if(outfile__array_neurongroup__spikespace.is_open())
	{
		outfile__array_neurongroup__spikespace.write(reinterpret_cast<char*>(_array_neurongroup__spikespace), 32401*sizeof(_array_neurongroup__spikespace[0]));
		outfile__array_neurongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_i;
	outfile__array_neurongroup_i.open("results\\_array_neurongroup_i_-201368727552719126", ios::binary | ios::out);
	if(outfile__array_neurongroup_i.is_open())
	{
		outfile__array_neurongroup_i.write(reinterpret_cast<char*>(_array_neurongroup_i), 32400*sizeof(_array_neurongroup_i[0]));
		outfile__array_neurongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_i." << endl;
	}
	ofstream outfile__array_neurongroup_I;
	outfile__array_neurongroup_I.open("results\\_array_neurongroup_I_-1527785412871071075", ios::binary | ios::out);
	if(outfile__array_neurongroup_I.is_open())
	{
		outfile__array_neurongroup_I.write(reinterpret_cast<char*>(_array_neurongroup_I), 32400*sizeof(_array_neurongroup_I[0]));
		outfile__array_neurongroup_I.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_I." << endl;
	}
	ofstream outfile__array_neurongroup_lastspike;
	outfile__array_neurongroup_lastspike.open("results\\_array_neurongroup_lastspike_-8500635387313631829", ios::binary | ios::out);
	if(outfile__array_neurongroup_lastspike.is_open())
	{
		outfile__array_neurongroup_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_lastspike), 32400*sizeof(_array_neurongroup_lastspike[0]));
		outfile__array_neurongroup_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_not_refractory;
	outfile__array_neurongroup_not_refractory.open("results\\_array_neurongroup_not_refractory_8971687207942736866", ios::binary | ios::out);
	if(outfile__array_neurongroup_not_refractory.is_open())
	{
		outfile__array_neurongroup_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_not_refractory), 32400*sizeof(_array_neurongroup_not_refractory[0]));
		outfile__array_neurongroup_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_v;
	outfile__array_neurongroup_v.open("results\\_array_neurongroup_v_-4902888903980008277", ios::binary | ios::out);
	if(outfile__array_neurongroup_v.is_open())
	{
		outfile__array_neurongroup_v.write(reinterpret_cast<char*>(_array_neurongroup_v), 32400*sizeof(_array_neurongroup_v[0]));
		outfile__array_neurongroup_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_v." << endl;
	}
	ofstream outfile__array_spikegeneratorgroup__lastindex;
	outfile__array_spikegeneratorgroup__lastindex.open("results\\_array_spikegeneratorgroup__lastindex_-3893325769909697373", ios::binary | ios::out);
	if(outfile__array_spikegeneratorgroup__lastindex.is_open())
	{
		outfile__array_spikegeneratorgroup__lastindex.write(reinterpret_cast<char*>(_array_spikegeneratorgroup__lastindex), 1*sizeof(_array_spikegeneratorgroup__lastindex[0]));
		outfile__array_spikegeneratorgroup__lastindex.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikegeneratorgroup__lastindex." << endl;
	}
	ofstream outfile__array_spikegeneratorgroup__period_bins;
	outfile__array_spikegeneratorgroup__period_bins.open("results\\_array_spikegeneratorgroup__period_bins_-240001172185228164", ios::binary | ios::out);
	if(outfile__array_spikegeneratorgroup__period_bins.is_open())
	{
		outfile__array_spikegeneratorgroup__period_bins.write(reinterpret_cast<char*>(_array_spikegeneratorgroup__period_bins), 1*sizeof(_array_spikegeneratorgroup__period_bins[0]));
		outfile__array_spikegeneratorgroup__period_bins.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikegeneratorgroup__period_bins." << endl;
	}
	ofstream outfile__array_spikegeneratorgroup__spikespace;
	outfile__array_spikegeneratorgroup__spikespace.open("results\\_array_spikegeneratorgroup__spikespace_6524060160275609623", ios::binary | ios::out);
	if(outfile__array_spikegeneratorgroup__spikespace.is_open())
	{
		outfile__array_spikegeneratorgroup__spikespace.write(reinterpret_cast<char*>(_array_spikegeneratorgroup__spikespace), 129601*sizeof(_array_spikegeneratorgroup__spikespace[0]));
		outfile__array_spikegeneratorgroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikegeneratorgroup__spikespace." << endl;
	}
	ofstream outfile__array_spikegeneratorgroup_i;
	outfile__array_spikegeneratorgroup_i.open("results\\_array_spikegeneratorgroup_i_-2444727454765945867", ios::binary | ios::out);
	if(outfile__array_spikegeneratorgroup_i.is_open())
	{
		outfile__array_spikegeneratorgroup_i.write(reinterpret_cast<char*>(_array_spikegeneratorgroup_i), 129600*sizeof(_array_spikegeneratorgroup_i[0]));
		outfile__array_spikegeneratorgroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikegeneratorgroup_i." << endl;
	}
	ofstream outfile__array_spikegeneratorgroup_period;
	outfile__array_spikegeneratorgroup_period.open("results\\_array_spikegeneratorgroup_period_-3042915671958074878", ios::binary | ios::out);
	if(outfile__array_spikegeneratorgroup_period.is_open())
	{
		outfile__array_spikegeneratorgroup_period.write(reinterpret_cast<char*>(_array_spikegeneratorgroup_period), 1*sizeof(_array_spikegeneratorgroup_period[0]));
		outfile__array_spikegeneratorgroup_period.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikegeneratorgroup_period." << endl;
	}
	ofstream outfile__array_spikemonitor__source_idx;
	outfile__array_spikemonitor__source_idx.open("results\\_array_spikemonitor__source_idx_8685406582271274957", ios::binary | ios::out);
	if(outfile__array_spikemonitor__source_idx.is_open())
	{
		outfile__array_spikemonitor__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor__source_idx), 32400*sizeof(_array_spikemonitor__source_idx[0]));
		outfile__array_spikemonitor__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_count;
	outfile__array_spikemonitor_count.open("results\\_array_spikemonitor_count_5158481842732358786", ios::binary | ios::out);
	if(outfile__array_spikemonitor_count.is_open())
	{
		outfile__array_spikemonitor_count.write(reinterpret_cast<char*>(_array_spikemonitor_count), 32400*sizeof(_array_spikemonitor_count[0]));
		outfile__array_spikemonitor_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_count." << endl;
	}
	ofstream outfile__array_spikemonitor_N;
	outfile__array_spikemonitor_N.open("results\\_array_spikemonitor_N_1912224996366120681", ios::binary | ios::out);
	if(outfile__array_spikemonitor_N.is_open())
	{
		outfile__array_spikemonitor_N.write(reinterpret_cast<char*>(_array_spikemonitor_N), 1*sizeof(_array_spikemonitor_N[0]));
		outfile__array_spikemonitor_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_N." << endl;
	}
	ofstream outfile__array_synapses_1_N;
	outfile__array_synapses_1_N.open("results\\_array_synapses_1_N_6471754983761313034", ios::binary | ios::out);
	if(outfile__array_synapses_1_N.is_open())
	{
		outfile__array_synapses_1_N.write(reinterpret_cast<char*>(_array_synapses_1_N), 1*sizeof(_array_synapses_1_N[0]));
		outfile__array_synapses_1_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_N." << endl;
	}
	ofstream outfile__array_synapses_1_sources;
	outfile__array_synapses_1_sources.open("results\\_array_synapses_1_sources_-7829561515575125646", ios::binary | ios::out);
	if(outfile__array_synapses_1_sources.is_open())
	{
		outfile__array_synapses_1_sources.write(reinterpret_cast<char*>(_array_synapses_1_sources), 128850*sizeof(_array_synapses_1_sources[0]));
		outfile__array_synapses_1_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_sources." << endl;
	}
	ofstream outfile__array_synapses_1_targets;
	outfile__array_synapses_1_targets.open("results\\_array_synapses_1_targets_8168904546791635459", ios::binary | ios::out);
	if(outfile__array_synapses_1_targets.is_open())
	{
		outfile__array_synapses_1_targets.write(reinterpret_cast<char*>(_array_synapses_1_targets), 128850*sizeof(_array_synapses_1_targets[0]));
		outfile__array_synapses_1_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_targets." << endl;
	}
	ofstream outfile__array_synapses_2_N;
	outfile__array_synapses_2_N.open("results\\_array_synapses_2_N_8500655032637595440", ios::binary | ios::out);
	if(outfile__array_synapses_2_N.is_open())
	{
		outfile__array_synapses_2_N.write(reinterpret_cast<char*>(_array_synapses_2_N), 1*sizeof(_array_synapses_2_N[0]));
		outfile__array_synapses_2_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_N." << endl;
	}
	ofstream outfile__array_synapses_2_sources;
	outfile__array_synapses_2_sources.open("results\\_array_synapses_2_sources_-5069644662031806512", ios::binary | ios::out);
	if(outfile__array_synapses_2_sources.is_open())
	{
		outfile__array_synapses_2_sources.write(reinterpret_cast<char*>(_array_synapses_2_sources), 32400*sizeof(_array_synapses_2_sources[0]));
		outfile__array_synapses_2_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_sources." << endl;
	}
	ofstream outfile__array_synapses_2_targets;
	outfile__array_synapses_2_targets.open("results\\_array_synapses_2_targets_-958979106120846631", ios::binary | ios::out);
	if(outfile__array_synapses_2_targets.is_open())
	{
		outfile__array_synapses_2_targets.write(reinterpret_cast<char*>(_array_synapses_2_targets), 32400*sizeof(_array_synapses_2_targets[0]));
		outfile__array_synapses_2_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_targets." << endl;
	}
	ofstream outfile__array_synapses_3_N;
	outfile__array_synapses_3_N.open("results\\_array_synapses_3_N_-5496661708016990037", ios::binary | ios::out);
	if(outfile__array_synapses_3_N.is_open())
	{
		outfile__array_synapses_3_N.write(reinterpret_cast<char*>(_array_synapses_3_N), 1*sizeof(_array_synapses_3_N[0]));
		outfile__array_synapses_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_N." << endl;
	}
	ofstream outfile__array_synapses_3_sources;
	outfile__array_synapses_3_sources.open("results\\_array_synapses_3_sources_3265899633949975867", ios::binary | ios::out);
	if(outfile__array_synapses_3_sources.is_open())
	{
		outfile__array_synapses_3_sources.write(reinterpret_cast<char*>(_array_synapses_3_sources), 32400*sizeof(_array_synapses_3_sources[0]));
		outfile__array_synapses_3_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_sources." << endl;
	}
	ofstream outfile__array_synapses_3_targets;
	outfile__array_synapses_3_targets.open("results\\_array_synapses_3_targets_1439487125793934393", ios::binary | ios::out);
	if(outfile__array_synapses_3_targets.is_open())
	{
		outfile__array_synapses_3_targets.write(reinterpret_cast<char*>(_array_synapses_3_targets), 32400*sizeof(_array_synapses_3_targets[0]));
		outfile__array_synapses_3_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_targets." << endl;
	}
	ofstream outfile__array_synapses_N;
	outfile__array_synapses_N.open("results\\_array_synapses_N_-2116626880215195689", ios::binary | ios::out);
	if(outfile__array_synapses_N.is_open())
	{
		outfile__array_synapses_N.write(reinterpret_cast<char*>(_array_synapses_N), 1*sizeof(_array_synapses_N[0]));
		outfile__array_synapses_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_N." << endl;
	}
	ofstream outfile__array_synapses_sources;
	outfile__array_synapses_sources.open("results\\_array_synapses_sources_-8270417606458630937", ios::binary | ios::out);
	if(outfile__array_synapses_sources.is_open())
	{
		outfile__array_synapses_sources.write(reinterpret_cast<char*>(_array_synapses_sources), 645000*sizeof(_array_synapses_sources[0]));
		outfile__array_synapses_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_sources." << endl;
	}
	ofstream outfile__array_synapses_targets;
	outfile__array_synapses_targets.open("results\\_array_synapses_targets_183549852485673974", ios::binary | ios::out);
	if(outfile__array_synapses_targets.is_open())
	{
		outfile__array_synapses_targets.write(reinterpret_cast<char*>(_array_synapses_targets), 645000*sizeof(_array_synapses_targets[0]));
		outfile__array_synapses_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_targets." << endl;
	}

	ofstream outfile__dynamic_array_spikegeneratorgroup__timebins;
	outfile__dynamic_array_spikegeneratorgroup__timebins.open("results\\_dynamic_array_spikegeneratorgroup__timebins_-708039708570660286", ios::binary | ios::out);
	if(outfile__dynamic_array_spikegeneratorgroup__timebins.is_open())
	{
        if (! _dynamic_array_spikegeneratorgroup__timebins.empty() )
        {
			outfile__dynamic_array_spikegeneratorgroup__timebins.write(reinterpret_cast<char*>(&_dynamic_array_spikegeneratorgroup__timebins[0]), _dynamic_array_spikegeneratorgroup__timebins.size()*sizeof(_dynamic_array_spikegeneratorgroup__timebins[0]));
		    outfile__dynamic_array_spikegeneratorgroup__timebins.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikegeneratorgroup__timebins." << endl;
	}
	ofstream outfile__dynamic_array_spikegeneratorgroup_neuron_index;
	outfile__dynamic_array_spikegeneratorgroup_neuron_index.open("results\\_dynamic_array_spikegeneratorgroup_neuron_index_-8933473983180009189", ios::binary | ios::out);
	if(outfile__dynamic_array_spikegeneratorgroup_neuron_index.is_open())
	{
        if (! _dynamic_array_spikegeneratorgroup_neuron_index.empty() )
        {
			outfile__dynamic_array_spikegeneratorgroup_neuron_index.write(reinterpret_cast<char*>(&_dynamic_array_spikegeneratorgroup_neuron_index[0]), _dynamic_array_spikegeneratorgroup_neuron_index.size()*sizeof(_dynamic_array_spikegeneratorgroup_neuron_index[0]));
		    outfile__dynamic_array_spikegeneratorgroup_neuron_index.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikegeneratorgroup_neuron_index." << endl;
	}
	ofstream outfile__dynamic_array_spikegeneratorgroup_spike_number;
	outfile__dynamic_array_spikegeneratorgroup_spike_number.open("results\\_dynamic_array_spikegeneratorgroup_spike_number_257112887645716129", ios::binary | ios::out);
	if(outfile__dynamic_array_spikegeneratorgroup_spike_number.is_open())
	{
        if (! _dynamic_array_spikegeneratorgroup_spike_number.empty() )
        {
			outfile__dynamic_array_spikegeneratorgroup_spike_number.write(reinterpret_cast<char*>(&_dynamic_array_spikegeneratorgroup_spike_number[0]), _dynamic_array_spikegeneratorgroup_spike_number.size()*sizeof(_dynamic_array_spikegeneratorgroup_spike_number[0]));
		    outfile__dynamic_array_spikegeneratorgroup_spike_number.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikegeneratorgroup_spike_number." << endl;
	}
	ofstream outfile__dynamic_array_spikegeneratorgroup_spike_time;
	outfile__dynamic_array_spikegeneratorgroup_spike_time.open("results\\_dynamic_array_spikegeneratorgroup_spike_time_233408196504261584", ios::binary | ios::out);
	if(outfile__dynamic_array_spikegeneratorgroup_spike_time.is_open())
	{
        if (! _dynamic_array_spikegeneratorgroup_spike_time.empty() )
        {
			outfile__dynamic_array_spikegeneratorgroup_spike_time.write(reinterpret_cast<char*>(&_dynamic_array_spikegeneratorgroup_spike_time[0]), _dynamic_array_spikegeneratorgroup_spike_time.size()*sizeof(_dynamic_array_spikegeneratorgroup_spike_time[0]));
		    outfile__dynamic_array_spikegeneratorgroup_spike_time.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikegeneratorgroup_spike_time." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_i;
	outfile__dynamic_array_spikemonitor_i.open("results\\_dynamic_array_spikemonitor_i_-8916492619875036586", ios::binary | ios::out);
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
	outfile__dynamic_array_spikemonitor_t.open("results\\_dynamic_array_spikemonitor_t_9135113005138901362", ios::binary | ios::out);
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
	ofstream outfile__dynamic_array_synapses_1__synaptic_post;
	outfile__dynamic_array_synapses_1__synaptic_post.open("results\\_dynamic_array_synapses_1__synaptic_post_-8163906951239737829", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_1__synaptic_pre.open("results\\_dynamic_array_synapses_1__synaptic_pre_677616995506519622", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_1_delay.open("results\\_dynamic_array_synapses_1_delay_176656000250379594", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_1_N_incoming.open("results\\_dynamic_array_synapses_1_N_incoming_7114623557202500549", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_1_N_outgoing.open("results\\_dynamic_array_synapses_1_N_outgoing_2070522699254968986", ios::binary | ios::out);
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
	ofstream outfile__dynamic_array_synapses_2__synaptic_post;
	outfile__dynamic_array_synapses_2__synaptic_post.open("results\\_dynamic_array_synapses_2__synaptic_post_-2741882388151547759", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_2__synaptic_pre.open("results\\_dynamic_array_synapses_2__synaptic_pre_-3308338727543627658", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_2_delay.open("results\\_dynamic_array_synapses_2_delay_-6087983448278196477", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_2_N_incoming.open("results\\_dynamic_array_synapses_2_N_incoming_1746725752611577464", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_2_N_outgoing.open("results\\_dynamic_array_synapses_2_N_outgoing_7116993802472217918", ios::binary | ios::out);
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
	ofstream outfile__dynamic_array_synapses_3__synaptic_post;
	outfile__dynamic_array_synapses_3__synaptic_post.open("results\\_dynamic_array_synapses_3__synaptic_post_5210732753418481802", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_3__synaptic_pre.open("results\\_dynamic_array_synapses_3__synaptic_pre_4897233832764333617", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_3_delay.open("results\\_dynamic_array_synapses_3_delay_2629365237200138871", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_3_N_incoming.open("results\\_dynamic_array_synapses_3_N_incoming_2023638717961199710", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_3_N_outgoing.open("results\\_dynamic_array_synapses_3_N_outgoing_-6211457089500215066", ios::binary | ios::out);
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
	ofstream outfile__dynamic_array_synapses__synaptic_post;
	outfile__dynamic_array_synapses__synaptic_post.open("results\\_dynamic_array_synapses__synaptic_post_5178332902888403844", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses__synaptic_pre.open("results\\_dynamic_array_synapses__synaptic_pre_-8464007885532328135", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_delay.open("results\\_dynamic_array_synapses_delay_8486692492166456534", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_N_incoming.open("results\\_dynamic_array_synapses_N_incoming_3789372399964286177", ios::binary | ios::out);
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
	outfile__dynamic_array_synapses_N_outgoing.open("results\\_dynamic_array_synapses_N_outgoing_451691131791390266", ios::binary | ios::out);
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
	if(_static_array__array_synapses_sources!=0)
	{
		delete [] _static_array__array_synapses_sources;
		_static_array__array_synapses_sources = 0;
	}
	if(_static_array__array_synapses_targets!=0)
	{
		delete [] _static_array__array_synapses_targets;
		_static_array__array_synapses_targets = 0;
	}
	if(_static_array__dynamic_array_spikegeneratorgroup__timebins!=0)
	{
		delete [] _static_array__dynamic_array_spikegeneratorgroup__timebins;
		_static_array__dynamic_array_spikegeneratorgroup__timebins = 0;
	}
	if(_static_array__dynamic_array_spikegeneratorgroup_neuron_index!=0)
	{
		delete [] _static_array__dynamic_array_spikegeneratorgroup_neuron_index;
		_static_array__dynamic_array_spikegeneratorgroup_neuron_index = 0;
	}
	if(_static_array__dynamic_array_spikegeneratorgroup_spike_number!=0)
	{
		delete [] _static_array__dynamic_array_spikegeneratorgroup_spike_number;
		_static_array__dynamic_array_spikegeneratorgroup_spike_number = 0;
	}
	if(_static_array__dynamic_array_spikegeneratorgroup_spike_time!=0)
	{
		delete [] _static_array__dynamic_array_spikegeneratorgroup_spike_time;
		_static_array__dynamic_array_spikegeneratorgroup_spike_time = 0;
	}
}

