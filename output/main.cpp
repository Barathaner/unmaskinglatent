#include <stdlib.h>
#include "objects.h"
#include <ctime>
#include <time.h>

#include "run.h"
#include "brianlib/common_math.h"
#include "randomkit.h"

#include "code_objects/neurongroup_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_stateupdater_codeobject.h"
#include "code_objects/poissongroup_spike_thresholder_codeobject.h"
#include "code_objects/after_run_poissongroup_spike_thresholder_codeobject.h"
#include "code_objects/spikemonitor_codeobject.h"
#include "code_objects/statemonitor_codeobject.h"
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
#include "code_objects/synapses_4_pre_codeobject.h"
#include "code_objects/synapses_4_pre_push_spikes.h"
#include "code_objects/before_run_synapses_4_pre_push_spikes.h"
#include "code_objects/synapses_4_synapses_create_array_codeobject.h"
#include "code_objects/synapses_pre_codeobject.h"
#include "code_objects/synapses_pre_push_spikes.h"
#include "code_objects/before_run_synapses_pre_push_spikes.h"
#include "code_objects/synapses_synapses_create_generator_codeobject.h"


#include <iostream>
#include <fstream>
#include <string>




int main(int argc, char **argv)
{
        

	brian_start();
        

	{
		using namespace brian;

		
                
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        
                        
                        for(int i=0; i<_num__array_neurongroup_lastspike; i++)
                        {
                            _array_neurongroup_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_not_refractory; i++)
                        {
                            _array_neurongroup_not_refractory[i] = true;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_v; i++)
                        {
                            _array_neurongroup_v[i] = - 0.06;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_g_ampa; i++)
                        {
                            _array_neurongroup_g_ampa[i] = 0.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_g_gaba; i++)
                        {
                            _array_neurongroup_g_gaba[i] = 0.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_poissongroup_rates; i++)
                        {
                            _array_poissongroup_rates[i] = _static_array__array_poissongroup_rates[i];
                        }
                        
        _run_synapses_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_num__array_synapses_1_sources; i++)
                        {
                            _array_synapses_1_sources[i] = _static_array__array_synapses_1_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_1_targets; i++)
                        {
                            _array_synapses_1_targets[i] = _static_array__array_synapses_1_targets[i];
                        }
                        
        _run_synapses_1_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_1_w.size(); i++)
                        {
                            _dynamic_array_synapses_1_w[i] = 0.4;
                        }
                        
        
                        
                        for(int i=0; i<_dynamic_array_synapses_1_delay.size(); i++)
                        {
                            _dynamic_array_synapses_1_delay[i] = 0.0001;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_2_sources; i++)
                        {
                            _array_synapses_2_sources[i] = _static_array__array_synapses_2_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_2_targets; i++)
                        {
                            _array_synapses_2_targets[i] = _static_array__array_synapses_2_targets[i];
                        }
                        
        _run_synapses_2_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_2_w.size(); i++)
                        {
                            _dynamic_array_synapses_2_w[i] = 0.4;
                        }
                        
        
                        
                        for(int i=0; i<_dynamic_array_synapses_2_delay.size(); i++)
                        {
                            _dynamic_array_synapses_2_delay[i] = 0.0001;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_3_sources; i++)
                        {
                            _array_synapses_3_sources[i] = _static_array__array_synapses_3_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_3_targets; i++)
                        {
                            _array_synapses_3_targets[i] = _static_array__array_synapses_3_targets[i];
                        }
                        
        _run_synapses_3_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_3_w.size(); i++)
                        {
                            _dynamic_array_synapses_3_w[i] = 5.1;
                        }
                        
        
                        
                        for(int i=0; i<_dynamic_array_synapses_3_delay.size(); i++)
                        {
                            _dynamic_array_synapses_3_delay[i] = 0.0001;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_4_sources; i++)
                        {
                            _array_synapses_4_sources[i] = _static_array__array_synapses_4_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_4_targets; i++)
                        {
                            _array_synapses_4_targets[i] = _static_array__array_synapses_4_targets[i];
                        }
                        
        _run_synapses_4_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_4_w.size(); i++)
                        {
                            _dynamic_array_synapses_4_w[i] = 5.1;
                        }
                        
        
                        
                        for(int i=0; i<_dynamic_array_synapses_4_delay.size(); i++)
                        {
                            _dynamic_array_synapses_4_delay[i] = 0.0001;
                        }
                        
        _array_statemonitor__indices[0] = 0;
        _array_defaultclock_timestep[0] = 0;
        _array_defaultclock_t[0] = 0.0;
        _before_run_synapses_1_pre_push_spikes();
        _before_run_synapses_2_pre_push_spikes();
        _before_run_synapses_3_pre_push_spikes();
        _before_run_synapses_4_pre_push_spikes();
        _before_run_synapses_pre_push_spikes();
        magicnetwork.clear();
        magicnetwork.add(&defaultclock, _run_statemonitor_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_stateupdater_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_spike_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_poissongroup_spike_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_spikemonitor_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_4_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_4_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_spike_resetter_codeobject);
        magicnetwork.run(1.0, NULL, 10.0);
        _after_run_neurongroup_spike_thresholder_codeobject();
        _after_run_poissongroup_spike_thresholder_codeobject();
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
        _debugmsg_synapses_4_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_pre_codeobject();
        #endif

	}
        

	brian_end();
        

	return 0;
}