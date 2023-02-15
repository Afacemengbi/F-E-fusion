#include "code_objects/before_run_synapses_2_pre_push_spikes.h"
#include "objects.h"
#include "brianlib/common_math.h"
#include "brianlib/stdint_compat.h"
#include<cmath>
#include<ctime>
#include<iostream>
#include<fstream>
#include<climits>

void _before_run_synapses_2_pre_push_spikes()
{
    using namespace brian;
    ///// CONSTANTS ///////////
    const size_t _num_spikespace = 32401;
const size_t _num_source_dt = 1;
double* const _array_synapses_2_delay = _dynamic_array_synapses_2_delay.empty()? 0 : &_dynamic_array_synapses_2_delay[0];
const size_t _numdelay = _dynamic_array_synapses_2_delay.size();
    ///// POINTERS ////////////
        
    int32_t* __restrict  _ptr_array_neurongroup__spikespace = _array_neurongroup__spikespace;
    double*   _ptr_array_defaultclock_dt = _array_defaultclock_dt;
    double* __restrict  _ptr_array_synapses_2_delay = _array_synapses_2_delay;

    std::vector<double> &real_delays = _dynamic_array_synapses_2_delay;
    double* real_delays_data = real_delays.empty() ? 0 : &(real_delays[0]);
    int32_t* sources = synapses_2_pre.sources.empty() ? 0 : &(synapses_2_pre.sources[0]);
    const size_t n_delays = real_delays.size();
    const size_t n_synapses = synapses_2_pre.sources.size();
    synapses_2_pre.prepare(32400,
                           1,
                           real_delays_data, n_delays, sources,
                           n_synapses,
                           _ptr_array_defaultclock_dt[0]);

}
