#include "code_objects/neurongroup_stateupdater_codeobject.h"
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



void _run_neurongroup_stateupdater_codeobject()
{
    using namespace brian;


    ///// CONSTANTS ///////////
    const size_t _numv = 32400;
const size_t _numdt = 1;
const size_t _numlastspike = 32400;
const size_t _numnot_refractory = 32400;
const size_t _numI = 32400;
const size_t _numt = 1;
    ///// POINTERS ////////////
        
    double* __restrict  _ptr_array_neurongroup_v = _array_neurongroup_v;
    double*   _ptr_array_defaultclock_dt = _array_defaultclock_dt;
    double* __restrict  _ptr_array_neurongroup_lastspike = _array_neurongroup_lastspike;
    char* __restrict  _ptr_array_neurongroup_not_refractory = _array_neurongroup_not_refractory;
    double* __restrict  _ptr_array_neurongroup_I = _array_neurongroup_I;
    double*   _ptr_array_defaultclock_t = _array_defaultclock_t;


    //// MAIN CODE ////////////
    // scalar code
    const size_t _vectorisation_idx = -1;
        
    const double dt = _ptr_array_defaultclock_dt[0];
    const double t = _ptr_array_defaultclock_t[0];
    const int32_t _lio_1 = _timestep(0.001, dt);
    const double _lio_2 = exp(1.0f*((- 0.3125) * dt)/0.001);
    const double _lio_3 = 1.0f*((- 0.078125) * dt)/0.001;
    const double _lio_4 = 1.25 * exp(1.0f*((- 0.3125) * dt)/0.001);
    const double _lio_5 = - exp(1.0f*(0.3125 * dt)/0.001);
    const double _lio_6 = 1.0f*(0.078125 * dt)/0.001;
    const double _lio_7 = exp(_lio_3);
    const double _lio_8 = 1.0f*((_lio_4 * (_lio_5 + exp(_lio_6))) * exp(_lio_3))/(- 0.234375);


    const int _N = 32400;
    
    for(int _idx=0; _idx<_N; _idx++)
    {
        // vector code
        const size_t _vectorisation_idx = _idx;
                
        double v = _ptr_array_neurongroup_v[_idx];
        const double lastspike = _ptr_array_neurongroup_lastspike[_idx];
        char not_refractory = _ptr_array_neurongroup_not_refractory[_idx];
        double I = _ptr_array_neurongroup_I[_idx];
        not_refractory = _timestep(t - lastspike, dt) >= _lio_1;
        const double _I = _lio_2 * I;
        double _v;
        if(!not_refractory)
            _v = v;
        else 
            _v = (_lio_7 * v) + (_lio_8 * I);
        I = _I;
        if(not_refractory)
            v = _v;
        _ptr_array_neurongroup_I[_idx] = I;
        _ptr_array_neurongroup_not_refractory[_idx] = not_refractory;
        _ptr_array_neurongroup_v[_idx] = v;

    }

}


