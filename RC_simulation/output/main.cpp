#include <stdlib.h>
#include "objects.h"
#include <ctime>
#include <time.h>

#include "run.h"
#include "brianlib/common_math.h"
#include "randomkit.h"

#include "code_objects/neurongroup_1_resetter_codeobject.h"
#include "code_objects/neurongroup_1_stateupdater_codeobject.h"
#include "code_objects/neurongroup_1_thresholder_codeobject.h"
#include "code_objects/neurongroup_resetter_codeobject.h"
#include "code_objects/neurongroup_stateupdater_codeobject.h"
#include "code_objects/neurongroup_thresholder_codeobject.h"
#include "code_objects/spikegeneratorgroup_codeobject.h"
#include "code_objects/spikemonitor_codeobject.h"
#include "code_objects/synapses_1_pre_codeobject.h"
#include "code_objects/synapses_1_pre_push_spikes.h"
#include "code_objects/before_run_synapses_1_pre_push_spikes.h"
#include "code_objects/synapses_1_synapses_create_array_codeobject.h"
#include "code_objects/synapses_2_pre_codeobject.h"
#include "code_objects/synapses_2_pre_push_spikes.h"
#include "code_objects/before_run_synapses_2_pre_push_spikes.h"
#include "code_objects/synapses_2_synapses_create_array_codeobject.h"
#include "code_objects/synapses_3_pre_codeobject.h"
#include "code_objects/synapses_3_pre_push_spikes.h"
#include "code_objects/before_run_synapses_3_pre_push_spikes.h"
#include "code_objects/synapses_3_synapses_create_array_codeobject.h"
#include "code_objects/synapses_pre_codeobject.h"
#include "code_objects/synapses_pre_push_spikes.h"
#include "code_objects/before_run_synapses_pre_push_spikes.h"
#include "code_objects/synapses_synapses_create_array_codeobject.h"


#include <iostream>
#include <fstream>
#include <string>


        std::string _format_time(float time_in_s)
        {
            float divisors[] = {24*60*60, 60*60, 60, 1};
            char letters[] = {'d', 'h', 'm', 's'};
            float remaining = time_in_s;
            std::string text = "";
            int time_to_represent;
            for (int i =0; i < sizeof(divisors)/sizeof(float); i++)
            {
                time_to_represent = int(remaining / divisors[i]);
                remaining -= time_to_represent * divisors[i];
                if (time_to_represent > 0 || text.length())
                {
                    if(text.length() > 0)
                    {
                        text += " ";
                    }
                    text += (std::to_string(time_to_represent)+letters[i]);
                }
            }
            //less than one second
            if(text.length() == 0) 
            {
                text = "< 1s";
            }
            return text;
        }
        void report_progress(const double elapsed, const double completed, const double start, const double duration)
        {
            if (completed == 0.0)
            {
                std::cout << "Starting simulation at t=" << start << " s for duration " << duration << " s";
            } else
            {
                std::cout << completed*duration << " s (" << (int)(completed*100.) << "%) simulated in " << _format_time(elapsed);
                if (completed < 1.0)
                {
                    const int remaining = (int)((1-completed)/completed*elapsed+0.5);
                    std::cout << ", estimated " << _format_time(remaining) << " remaining.";
                }
            }

            std::cout << std::endl << std::flush;
        }
        


int main(int argc, char **argv)
{
        

	brian_start();
        

	{
		using namespace brian;

		
                
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.001;
        _dynamic_array_spikegeneratorgroup_spike_number.resize(5820222);
        
                        
                        for(int i=0; i<_dynamic_array_spikegeneratorgroup_spike_number.size(); i++)
                        {
                            _dynamic_array_spikegeneratorgroup_spike_number[i] = _static_array__dynamic_array_spikegeneratorgroup_spike_number[i];
                        }
                        
        _dynamic_array_spikegeneratorgroup_neuron_index.resize(5820222);
        
                        
                        for(int i=0; i<_dynamic_array_spikegeneratorgroup_neuron_index.size(); i++)
                        {
                            _dynamic_array_spikegeneratorgroup_neuron_index[i] = _static_array__dynamic_array_spikegeneratorgroup_neuron_index[i];
                        }
                        
        _dynamic_array_spikegeneratorgroup_spike_time.resize(5820222);
        
                        
                        for(int i=0; i<_dynamic_array_spikegeneratorgroup_spike_time.size(); i++)
                        {
                            _dynamic_array_spikegeneratorgroup_spike_time[i] = _static_array__dynamic_array_spikegeneratorgroup_spike_time[i];
                        }
                        
        _dynamic_array_spikegeneratorgroup__timebins.resize(5820222);
        _array_spikegeneratorgroup__lastindex[0] = 0;
        _array_spikegeneratorgroup_period[0] = 0.0;
        
                        
                        for(int i=0; i<_num__array_neurongroup_lastspike; i++)
                        {
                            _array_neurongroup_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_not_refractory; i++)
                        {
                            _array_neurongroup_not_refractory[i] = true;
                        }
                        
        _array_neurongroup_1_lastspike[0] = - 10000.0;
        _array_neurongroup_1_not_refractory[0] = true;
        
                        
                        for(int i=0; i<_num__array_neurongroup_I; i++)
                        {
                            _array_neurongroup_I[i] = 0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_sources; i++)
                        {
                            _array_synapses_sources[i] = _static_array__array_synapses_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_targets; i++)
                        {
                            _array_synapses_targets[i] = _static_array__array_synapses_targets[i];
                        }
                        
        _run_synapses_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_num__array_synapses_1_sources; i++)
                        {
                            _array_synapses_1_sources[i] = _static_array__array_synapses_1_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_1_targets; i++)
                        {
                            _array_synapses_1_targets[i] = _static_array__array_synapses_1_targets[i];
                        }
                        
        _run_synapses_1_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_num__array_synapses_2_sources; i++)
                        {
                            _array_synapses_2_sources[i] = _static_array__array_synapses_2_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_2_targets; i++)
                        {
                            _array_synapses_2_targets[i] = _static_array__array_synapses_2_targets[i];
                        }
                        
        _run_synapses_2_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_num__array_synapses_3_sources; i++)
                        {
                            _array_synapses_3_sources[i] = _static_array__array_synapses_3_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_3_targets; i++)
                        {
                            _array_synapses_3_targets[i] = _static_array__array_synapses_3_targets[i];
                        }
                        
        _run_synapses_3_synapses_create_array_codeobject();
        _array_defaultclock_timestep[0] = 0;
        _array_defaultclock_t[0] = 0.0;
        _array_spikegeneratorgroup__lastindex[0] = 0;
        
                        
                        for(int i=0; i<_dynamic_array_spikegeneratorgroup__timebins.size(); i++)
                        {
                            _dynamic_array_spikegeneratorgroup__timebins[i] = _static_array__dynamic_array_spikegeneratorgroup__timebins[i];
                        }
                        
        _array_spikegeneratorgroup__period_bins[0] = 0.0;
        _before_run_synapses_1_pre_push_spikes();
        _before_run_synapses_2_pre_push_spikes();
        _before_run_synapses_3_pre_push_spikes();
        _before_run_synapses_pre_push_spikes();
        magicnetwork.clear();
        magicnetwork.add(&defaultclock, _run_neurongroup_1_stateupdater_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_stateupdater_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_1_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_spikegeneratorgroup_codeobject);
        magicnetwork.add(&defaultclock, _run_spikemonitor_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_1_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_resetter_codeobject);
        magicnetwork.run(100.0, report_progress, 1.0);
        #ifdef DEBUG
        _debugmsg_spikemonitor_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_1_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_2_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_3_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_pre_codeobject();
        #endif

	}
        

	brian_end();
        

	return 0;
}