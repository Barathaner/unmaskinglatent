from brian2 import *
import matplotlib.pyplot as plt
import numpy as np
from brian2 import *

start_scope()
# ###########################################
# Defining network model parameters
# ###########################################

NE = 8000          # Number of excitatory cells
NI = NE/4          # Number of inhibitory cells
rows, cols = int(np.sqrt(NE+NI)), int(np.sqrt(NE+NI)) # assuming your network is square shaped

tau_ampa = 5.0*ms   # Glutamatergic synaptic time constant
tau_gaba = 10.0*ms  # GABAergic synaptic time constant
epsilon = 0.02      # Sparseness of synaptic connections

tau_stdp = 20*ms    # STDP time constant

simtime = 1000*ms # Simulation time

# ###########################################
# Neuron model
# ###########################################

gl = 10.0*nsiemens   # Leak conductance
el = -60*mV          # Resting potential
er = -80*mV          # Inhibitory reversal potential
vt = -50.*mV         # Spiking threshold
memc = 200.0*pfarad  # Membrane capacitance
bgcurrent = 10*pA   # External current

eqs_neurons='''
dv/dt=(-gl*(v-el)-(g_ampa*v+g_gaba*(v-er))+bgcurrent)/memc : volt (unless refractory)
dg_ampa/dt = -g_ampa/tau_ampa : siemens
dg_gaba/dt = -g_gaba/tau_gaba : siemens
'''

# ###########################################
# Initialize neuron group
# ###########################################

neurons = NeuronGroup(NE+NI, model=eqs_neurons, threshold='v > vt',
                      reset='v=el', refractory=5*ms, method='euler')
# Randomly permute the indices
indices = np.random.permutation(len(neurons))

# Split the indices into two groups, one with 8000 and one with 2000 neurons
excitatory = indices[:NE]
inhibitory = indices[NE:]
# ###########################################
# Connecting the network
# ###########################################
firsta = np.repeat(excitatory, len(neurons.i))
firstab = np.tile(neurons.i, len(excitatory))

con_e = Synapses(neurons, neurons, on_pre='g_ampa += 0.3*nS')
con_e.connect(i=firsta,j=firstab,p=epsilon)



firsta = np.repeat(inhibitory, len(inhibitory))
firstab = np.tile(inhibitory, len(inhibitory))
print(len(firsta))
con_ii = Synapses(neurons, neurons, on_pre='g_gaba += 3*nS')
con_ii.connect(i=firsta,j=firstab,p=epsilon)

cellassembly=neurons[1000:2000]
we=0.1*mV
P = PoissonInput(cellassembly, 'v', 100, 100*Hz, weight=we)
# ###########################################
# Inhibitory Plasticity
# ###########################################

eqs_stdp_inhib = '''
w : 1
dApre/dt=-Apre/tau_stdp : 1 (event-driven)
dApost/dt=-Apost/tau_stdp : 1 (event-driven)
'''
alpha = 3*Hz*tau_stdp*2  # Target rate parameter
gmax = 100               # Maximum inhibitory weight

firsta = np.repeat(inhibitory, len(excitatory))
firstab = np.tile(excitatory, len(inhibitory))
con_ie = Synapses(neurons, neurons, model=eqs_stdp_inhib,
                on_pre='''Apre += 1.
                        w = clip(w+(Apost-alpha)*eta, 0, gmax)
                        g_gaba += w*nS''',
                on_post='''Apost += 1.
                        w = clip(w+Apre*eta, 0, gmax)
                    ''')
con_ie.connect(i=firsta, j=firstab,p=epsilon)
con_ie.w = 1e-10
# ###########################################
# Setting up monitors
# ###########################################
outputrates=[]
sm = SpikeMonitor(neurons)
M = StateMonitor(neurons, 'v', record=0)
# ###########################################
# Run with plasticity
# ###########################################
eta = 1e-2          # Learning rate
run(simtime, report='text')
outputrates.append(sm.count/simtime)
we=0*mV
sm = SpikeMonitor(neurons)
run(simtime, report='text')
outputrates.append(sm.count/simtime)
# ###########################################
# Make plots
# ###########################################
average_rate = np.mean(outputrates, axis=0)

import seaborn as sns

# Run your network simulation code first

# After running the simulation
spike_counts = sm.count  # This gives the number of spikes for each neuron
spike_rate = spike_counts / 4*simtime  # We ran for 1 second, adjust as needed
print("AVG:"+str(np.average(average_rate)))# Now let's reshape this into the shape of the network
spike_rate_grid = np.reshape(outputrates[1], (rows, cols))

# And plot
plt.figure(figsize=(10,10))
sns.heatmap(spike_rate_grid, square=True, cmap='hot', cbar_kws={'label': 'Spikes/sec'})
plt.title('Spike rate heatmap')
plt.show()
print(spike_rate_grid)


plot(M.t/ms,M.v[0])
