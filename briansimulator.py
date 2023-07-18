from brian2 import *
import matplotlib.pyplot as plt
import numpy as np
import getopt, sys, timeit
from scipy.io import mmread
# ###########################################
# Defining network model parameters
# ###########################################
start_scope()
simtime = 10.0
fast = False
num_timesteps_delay = 1

from brian2 import *
from scipy.io import mmread

# Setting standalone mode for speed
set_device('cpp_standalone')

mytimestep=0.1
defaultclock.dt = mytimestep*ms

NE = 3200
NI = NE/4
rows, cols = int(np.sqrt(NE)), int(np.sqrt(NE)) # assuming your network is square shaped

# gl = 10.0*nS
we = 0.4 #*gl
wi = 5.1 #*gl
tau_mem = 20.0*ms
tau_ampa  = 5.0*ms
tau_gaba = 10.0*ms

el = -60.*mV
er = -80.*mV
vt = -50.*mV
vr = -60.*mV
#memc = 200.0*pfarad
bgcurrent = 20.0*mV


eqs = '''
dv/dt  = (-(v-el)-(g_ampa*v+g_gaba*(v-er))+bgcurrent)/tau_mem : volt (unless refractory)
dg_ampa/dt = -g_ampa/tau_ampa : 1
dg_gaba/dt = -g_gaba/tau_gaba : 1
'''

P = NeuronGroup(NE+NI, model=eqs, threshold='v>vt', reset='v = vr', refractory=5.0*ms, method='euler')
P.v = el
P.g_ampa = 0.
P.g_gaba = 0.
Pe = P[:NE]
Pi = P[NE:]
Poi = PoissonGroup(100,rates=100*Hz)
S = Synapses(Poi, P[:99], on_pre='g_ampa += 0.3*nS')
S.connect()
#Ce = Synapses(P, P, on_pre='ge += we')
conn_ee = Synapses(Pe,Pe,model="w:1",on_pre='g_ampa += w', method='euler')
conn_ei = Synapses(Pe,Pi,model="w:1",on_pre='g_ampa += w', method='euler')
conn_ie = Synapses(Pi,Pe,model="w:1",on_pre='g_gaba += w', method='euler')
conn_ii = Synapses(Pi,Pi,model="w:1",on_pre='g_gaba += w', method='euler')


ee_mat = mmread('./ee.wmat')
ei_mat = mmread('./ei.wmat')
ie_mat = mmread('./ie.wmat')
ii_mat = mmread('./ii.wmat')

conn_ee.connect(i=ee_mat.row, j=ee_mat.col)
conn_ee.w=we
conn_ee.delay = num_timesteps_delay*mytimestep*ms

conn_ei.connect(i=ei_mat.row, j=ei_mat.col)
conn_ei.w=we
conn_ei.delay = num_timesteps_delay*mytimestep*ms

conn_ie.connect(i=ie_mat.row, j=ie_mat.col)
conn_ie.w=wi
conn_ie.delay = num_timesteps_delay*mytimestep*ms

conn_ii.connect(i=ii_mat.row, j=ii_mat.col)
conn_ii.w=wi
conn_ii.delay = num_timesteps_delay*mytimestep*ms

#conn_ei.connect(Pe, Pi, scale*array(mmread('../pynn.ei.wmat').todense(),dtype=float))
#conn_ie.connect(Pi, Pe, scale*array(mmread('../pynn.ie.wmat').todense(),dtype=float))
#conn_ii.connect(Pi, Pi, scale*array(mmread('../pynn.ii.wmat').todense(),dtype=float))

# ###########################################
# Setting up monitors
# ###########################################

sm = SpikeMonitor(Pe)
M = StateMonitor(P, 'v', record=0)
# ###########################################
# Run without plasticity
# ###########################################
eta = 1e-2          # Learning rate
run(1*second)

# ###########################################
# Make plots
# ###########################################


import seaborn as sns

# Run your network simulation code first

# After running the simulation
spike_counts = sm.count[:3136]  # This gives the number of spikes for each neuron
spike_rate = spike_counts / 1*second  # We ran for 1 second, adjust as needed
print("AVG:"+str(np.average(spike_rate)))# Now let's reshape this into the shape of the network
spike_rate_grid = np.reshape(spike_rate, (rows, cols))

# And plot
plt.figure(figsize=(10,10))
sns.heatmap(spike_rate_grid, square=True, cmap='hot', cbar_kws={'label': 'Spikes/sec'})
plt.title('Spike rate heatmap')
plt.show()
print(spike_rate_grid)


plot(M.t/ms,M.v[0])
