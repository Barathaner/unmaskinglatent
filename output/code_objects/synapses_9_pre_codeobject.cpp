#include "code_objects/synapses_9_pre_codeobject.h"
#include "objects.h"
#include "brianlib/common_math.h"
#include "brianlib/stdint_compat.h"
#include<cmath>
#include<ctime>
#include<iostream>
#include<fstream>
#include<climits>
#include "brianlib/stdint_compat.h"
#include "synapses_classes.h"

////// SUPPORT CODE ///////
namespace {
        
    template < typename T1, typename T2 > struct _higher_type;
    template < > struct _higher_type<int,int> { typedef int type; };
    template < > struct _higher_type<int,long> { typedef long type; };
    template < > struct _higher_type<int,long long> { typedef long long type; };
    template < > struct _higher_type<int,float> { typedef float type; };
    template < > struct _higher_type<int,double> { typedef double type; };
    template < > struct _higher_type<int,long double> { typedef long double type; };
    template < > struct _higher_type<long,int> { typedef long type; };
    template < > struct _higher_type<long,long> { typedef long type; };
    template < > struct _higher_type<long,long long> { typedef long long type; };
    template < > struct _higher_type<long,float> { typedef float type; };
    template < > struct _higher_type<long,double> { typedef double type; };
    template < > struct _higher_type<long,long double> { typedef long double type; };
    template < > struct _higher_type<long long,int> { typedef long long type; };
    template < > struct _higher_type<long long,long> { typedef long long type; };
    template < > struct _higher_type<long long,long long> { typedef long long type; };
    template < > struct _higher_type<long long,float> { typedef float type; };
    template < > struct _higher_type<long long,double> { typedef double type; };
    template < > struct _higher_type<long long,long double> { typedef long double type; };
    template < > struct _higher_type<float,int> { typedef float type; };
    template < > struct _higher_type<float,long> { typedef float type; };
    template < > struct _higher_type<float,long long> { typedef float type; };
    template < > struct _higher_type<float,float> { typedef float type; };
    template < > struct _higher_type<float,double> { typedef double type; };
    template < > struct _higher_type<float,long double> { typedef long double type; };
    template < > struct _higher_type<double,int> { typedef double type; };
    template < > struct _higher_type<double,long> { typedef double type; };
    template < > struct _higher_type<double,long long> { typedef double type; };
    template < > struct _higher_type<double,float> { typedef double type; };
    template < > struct _higher_type<double,double> { typedef double type; };
    template < > struct _higher_type<double,long double> { typedef long double type; };
    template < > struct _higher_type<long double,int> { typedef long double type; };
    template < > struct _higher_type<long double,long> { typedef long double type; };
    template < > struct _higher_type<long double,long long> { typedef long double type; };
    template < > struct _higher_type<long double,float> { typedef long double type; };
    template < > struct _higher_type<long double,double> { typedef long double type; };
    template < > struct _higher_type<long double,long double> { typedef long double type; };
    template < typename T1, typename T2 >
    static inline typename _higher_type<T1,T2>::type
    _brian_mod(T1 x, T2 y)
    {{
        return x-y*floor(1.0*x/y);
    }}
    template < typename T1, typename T2 >
    static inline typename _higher_type<T1,T2>::type
    _brian_floordiv(T1 x, T2 y)
    {{
        return floor(1.0*x/y);
    }}
    #ifdef _MSC_VER
    #define _brian_pow(x, y) (pow((double)(x), (y)))
    #else
    #define _brian_pow(x, y) (pow((x), (y)))
    #endif

}

////// HASH DEFINES ///////



void _run_synapses_9_pre_codeobject()
{
    using namespace brian;


    ///// CONSTANTS ///////////
    int32_t* const _array_synapses_9__synaptic_pre = _dynamic_array_synapses_9__synaptic_pre.empty()? 0 : &_dynamic_array_synapses_9__synaptic_pre[0];
const size_t _num_synaptic_pre = _dynamic_array_synapses_9__synaptic_pre.size();
const double mV = 0.001;
const size_t _numv = 4000;
const size_t _numnot_refractory = 4000;
int32_t* const _array_synapses_9__synaptic_post = _dynamic_array_synapses_9__synaptic_post.empty()? 0 : &_dynamic_array_synapses_9__synaptic_post[0];
const size_t _num_postsynaptic_idx = _dynamic_array_synapses_9__synaptic_post.size();
    ///// POINTERS ////////////
        
    int32_t* __restrict  _ptr_array_synapses_9__synaptic_pre = _array_synapses_9__synaptic_pre;
    double* __restrict  _ptr_array_neurongroup_1_v = _array_neurongroup_1_v;
    char* __restrict  _ptr_array_neurongroup_1_not_refractory = _array_neurongroup_1_not_refractory;
    int32_t* __restrict  _ptr_array_synapses_9__synaptic_post = _array_synapses_9__synaptic_post;



    // This is only needed for the _debugmsg function below

    // scalar code
    const size_t _vectorisation_idx = -1;
        
    const double _lio_1 = 0.1 * mV;


    
    {
    std::vector<int> *_spiking_synapses = synapses_9_pre.peek();
    const int _num_spiking_synapses = _spiking_synapses->size();

    
    {
        for(int _spiking_synapse_idx=0;
            _spiking_synapse_idx<_num_spiking_synapses;
            _spiking_synapse_idx++)
        {
            const size_t _idx = (*_spiking_synapses)[_spiking_synapse_idx];
            const size_t _vectorisation_idx = _idx;
                        
            const int32_t _postsynaptic_idx = _ptr_array_synapses_9__synaptic_post[_idx];
            const char not_refractory = _ptr_array_neurongroup_1_not_refractory[_postsynaptic_idx];
            double v = _ptr_array_neurongroup_1_v[_postsynaptic_idx];
            if(not_refractory)
                v += _lio_1;
            _ptr_array_neurongroup_1_v[_postsynaptic_idx] = v;

        }
    }
    }

}

void _debugmsg_synapses_9_pre_codeobject()
{
    using namespace brian;
    std::cout << "Number of synapses: " << _dynamic_array_synapses_9__synaptic_pre.size() << endl;
}

