#include "code_objects/neurongroup_2_stateupdater_codeobject.h"
#include "objects.h"
#include "brianlib/common_math.h"
#include "brianlib/stdint_compat.h"
#include<cmath>
#include<ctime>
#include<iostream>
#include<fstream>
#include<climits>

////// SUPPORT CODE ///////
namespace {
        
    static inline int64_t _timestep(double t, double dt)
    {
        return (int64_t)((t + 1e-3*dt)/dt);
    }
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



void _run_neurongroup_2_stateupdater_codeobject()
{
    using namespace brian;


    ///// CONSTANTS ///////////
    const int32_t N = 4000;
const double bgcurrent = 0.02;
const size_t _numdt = 1;
const double el = - 0.06;
const double er = - 0.08;
const size_t _numg_ampa = 4000;
const size_t _numg_gaba = 4000;
const size_t _numlastspike = 4000;
const size_t _numnot_refractory = 4000;
const size_t _numt = 1;
const double tau_ampa = 0.005;
const double tau_gaba = 0.01;
const double tau_mem = 0.02;
const size_t _numv = 4000;
    ///// POINTERS ////////////
        
    double*   _ptr_array_defaultclock_dt = _array_defaultclock_dt;
    double* __restrict  _ptr_array_neurongroup_2_g_ampa = _array_neurongroup_2_g_ampa;
    double* __restrict  _ptr_array_neurongroup_2_g_gaba = _array_neurongroup_2_g_gaba;
    double* __restrict  _ptr_array_neurongroup_2_lastspike = _array_neurongroup_2_lastspike;
    char* __restrict  _ptr_array_neurongroup_2_not_refractory = _array_neurongroup_2_not_refractory;
    double*   _ptr_array_defaultclock_t = _array_defaultclock_t;
    double* __restrict  _ptr_array_neurongroup_2_v = _array_neurongroup_2_v;


    //// MAIN CODE ////////////
    // scalar code
    const size_t _vectorisation_idx = -1;
        
    const double dt = _ptr_array_defaultclock_dt[0];
    const double t = _ptr_array_defaultclock_t[0];
    const int32_t _lio_1 = _timestep(0.005, dt);
    const double _lio_2 = 1.0f*(- dt)/tau_ampa;
    const double _lio_3 = 1.0f*(- dt)/tau_gaba;
    const double _lio_4 = 1.0f*dt/tau_mem;
    const double _lio_5 = bgcurrent + el;
    const double _lio_6 = - er;


    const int _N = N;
    
    for(int _idx=0; _idx<_N; _idx++)
    {
        // vector code
        const size_t _vectorisation_idx = _idx;
                
        double g_ampa = _ptr_array_neurongroup_2_g_ampa[_idx];
        double g_gaba = _ptr_array_neurongroup_2_g_gaba[_idx];
        const double lastspike = _ptr_array_neurongroup_2_lastspike[_idx];
        char not_refractory = _ptr_array_neurongroup_2_not_refractory[_idx];
        double v = _ptr_array_neurongroup_2_v[_idx];
        not_refractory = _timestep(t - lastspike, dt) >= _lio_1;
        const double _g_ampa = (_lio_2 * g_ampa) + g_ampa;
        const double _g_gaba = (_lio_3 * g_gaba) + g_gaba;
        double _v;
        if(!not_refractory)
            _v = v;
        else 
            _v = (_lio_4 * (_lio_5 - (((g_ampa * v) + (g_gaba * (_lio_6 + v))) + v))) + v;
        g_ampa = _g_ampa;
        g_gaba = _g_gaba;
        if(not_refractory)
            v = _v;
        _ptr_array_neurongroup_2_g_ampa[_idx] = g_ampa;
        _ptr_array_neurongroup_2_g_gaba[_idx] = g_gaba;
        _ptr_array_neurongroup_2_not_refractory[_idx] = not_refractory;
        _ptr_array_neurongroup_2_v[_idx] = v;

    }

}


