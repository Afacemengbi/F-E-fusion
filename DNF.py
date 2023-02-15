#RC
from brian2 import *
import brian2 as b2
from brian2.monitors import statemonitor
import numpy as np
from struct import unpack

start_scope()
# set_device('cpp_standalone', directory = './RC_simulation/output')
# setup for C++ compilation preferences
#codegen.cpp_compiler = 'gcc' #Compiler to use (uses default if empty);Should be gcc or msvc.
#prefs.devices.cpp_standalone.extra_make_args_unix = ['-j']
#prefs.devices.cpp_standalone.openmp_threads = 1
##-----------------------------------------------------------------------------------------
##basic simulation setup
##-----------------------------------------------------------------------------------------
b2.defaultclock.dt = 1 * b2.ms # 0.1
b2.core.default_float_dtype = float32 ### can be chaged to float32 in brian 2.2.
b2.core.default_integer_dtype = int32

start_scope()

indices = np.load('./dataset/input_spike_train_index.npy')
times = np.load('./dataset/input_spike_train_time.npy')

print('load data successful!')

Gs = SpikeGeneratorGroup(480*270,indices,times*ms)

#loihi LIF 神经元
## standard neuron parameters
v_rest_excite = 0
v_reset_excite = 0
v_thresh_excite = 1.25*2**13
v_thresh_transfer = 0 # -40
t_refrac_excite = 1 * b2.ms # 5.0
t_refrac_inhibite = 0 * b2.ms # 2.0
v_thresh_excite_str = 'v > v_thresh_excite'
v_thresh_transfer_str = 'v > v_thresh_transfer'

neuron_eqs_excite = '''
        rnd_v = v/2**7 : 1
        rnd_I = I/2**5 : 1
        rrnd_I = I/2**3 : 1
        dv/dt = -rnd_v/(0.1*ms) + rrnd_I/(0.1*ms): 1 (unless refractory)
        dI/dt = -rnd_I/(0.1*ms): 1
        '''
neuron_eqs_transfer = '''
        v : 1
        '''
## time
## reset dynamics for excitatory and inhibitory neuron
reset_excite = 'v = v_reset_excite'
reset_transfer = 'v = 0'
## synapse conductance model
spike_pre_excite = ' I += 2**9'
spike_post_transfer = 'v += 1'

G1 = NeuronGroup(240*135, neuron_eqs_excite, threshold = v_thresh_excite_str, refractory = t_refrac_excite, reset = reset_excite)
transfer_neuron = NeuronGroup(1, neuron_eqs_transfer, threshold = v_thresh_transfer_str, refractory = t_refrac_inhibite, reset = reset_transfer)
G1.I = 0

input_e_i = np.load('./struct/input_e_i.npy')
input_e_j = np.load('./struct/input_e_j.npy')
ee_i = np.load('./struct/ee_i.npy')
ee_j = np.load('./struct/ee_j.npy')
e_transfer_i = np.load('./struct/e_transfer_i.npy')
e_transfer_j = np.load('./struct/e_transfer_j.npy')
transfer_e_i = np.load('./struct/transfer_e_i.npy')
transfer_e_j = np.load('./struct/transfer_e_j.npy')

on_pre = spike_pre_excite
S5 = Synapses(Gs,G1, on_pre=on_pre,on_post = '')
S5.connect(i = input_e_i,j = input_e_j)

on_pre = spike_pre_excite
S1 = Synapses(G1,G1, on_pre = on_pre, on_post = '')
S1.connect(i = ee_i,j = ee_j)

S2 = Synapses(G1,transfer_neuron, on_pre = 'v_post += 1', on_post = '')
S2.connect(i = e_transfer_i,j = e_transfer_j)

S3 = Synapses(transfer_neuron,G1, on_pre = 'I_post -= v_pre*2**6', on_post = '')
S3.connect(i = transfer_e_i,j = transfer_e_j)

# S3 = Synapses(G1,G1, on_pre = 'I_post -= v_pre*2**6', on_post = '')
# S3.connect(condition='i!=j', p=1)

M1 = SpikeMonitor(G1)
# M2 = SpikeMonitor(transfer_neuron)
# M3 = StateMonitor(G1[0:10],('v', 'I'),record=True)
# M4 = StateMonitor(transfer_neuron,'v',record=True)

run(100000*ms,report = 'text',report_period = 1*second)

np.save('./recorder/indexe',np.array(M1.i))
np.save('./recorder/timee',np.array(M1.t))
# np.save('./recorder/index',np.array(M2.i))
# np.save('./recorder/time', np.array(M2.t))
# np.save('./recorder/v', np.array(M3.v))
# np.save('./recorder/t', np.array(M3.t))
# np.save('./recorder/tv',np.array(M4.v))
# np.save('./recorder/tt',np.array(M4.t))
                     
print('done')