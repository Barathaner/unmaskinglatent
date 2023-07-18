from brian2 import *

def map_2d_to_1d(coord, shape):
    return np.ravel_multi_index(coord, shape)


# ###########################################
# Defining network model parameters
# ###########################################

NE = 3200          # Number of excitatory cells
NI = NE/4          # Number of inhibitory cells
rows, cols = int(np.sqrt(NE)), int(np.sqrt(NE)) # assuming your network is square shaped

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
bgcurrent =20.0*pA   # External current

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
Pe = neurons[:NE]
Pi = neurons[NE:]

# ###########################################
# Connecting the network
# ###########################################

con_e = Synapses(Pe, neurons, on_pre='g_ampa += 0.3*nS')
con_e.connect(p=epsilon)
con_ii = Synapses(Pi, Pi, on_pre='g_gaba += 3*nS')
con_ii.connect(p=epsilon)

viereck=map_2d_to_1d((10,10),(rows,cols))
viereck1=map_2d_to_1d((11,10),(rows,cols))
viereck2=map_2d_to_1d((12,10),(rows,cols))
viereck3=map_2d_to_1d((13,10),(rows,cols))
viereck4=map_2d_to_1d((14,10),(rows,cols))
viereck5=map_2d_to_1d((15,10),(rows,cols))
viereck6=map_2d_to_1d((16,10),(rows,cols))
viereck7=map_2d_to_1d((17,10),(rows,cols))
viereck8=map_2d_to_1d((18,10),(rows,cols))
viereck9=map_2d_to_1d((19,10),(rows,cols))
viereck10=map_2d_to_1d((20,10),(rows,cols))
viereck=Pe[viereck:viereck+10]
viereck1=Pe[viereck1:viereck1+10]
viereck2=Pe[viereck2:viereck2+10]
viereck3=Pe[viereck3:viereck3+10]
viereck4=Pe[viereck4:viereck4+10]
viereck5=Pe[viereck5:viereck5+10]
viereck6=Pe[viereck6:viereck6+10]
viereck7=Pe[viereck7:viereck7+10]
viereck8=Pe[viereck8:viereck8+10]
viereck9=Pe[viereck9:viereck9+10]
viereck10=Pe[viereck10:viereck10+10]

viereckr=map_2d_to_1d((10,30),(rows,cols))
viereckr1=map_2d_to_1d((11,30),(rows,cols))
viereckr2=map_2d_to_1d((12,30),(rows,cols))
viereckr3=map_2d_to_1d((13,30),(rows,cols))
viereckr4=map_2d_to_1d((14,30),(rows,cols))
viereckr5=map_2d_to_1d((15,30),(rows,cols))
viereckr6=map_2d_to_1d((16,30),(rows,cols))
viereckr7=map_2d_to_1d((17,30),(rows,cols))
viereckr8=map_2d_to_1d((18,30),(rows,cols))
viereckr9=map_2d_to_1d((19,30),(rows,cols))
viereckr10=map_2d_to_1d((20,30),(rows,cols))
viereckr=Pe[viereckr:viereckr+10]
viereckr1=Pe[viereckr1:viereckr1+10]
viereckr2=Pe[viereckr2:viereckr2+10]
viereckr3=Pe[viereckr3:viereckr3+10]
viereckr4=Pe[viereckr4:viereckr4+10]
viereckr5=Pe[viereckr5:viereckr5+10]
viereckr6=Pe[viereckr6:viereckr6+10]
viereckr7=Pe[viereckr7:viereckr7+10]
viereckr8=Pe[viereckr8:viereckr8+10]
viereckr9=Pe[viereckr9:viereckr9+10]
viereckr10=Pe[viereckr10:viereckr10+10]


# connvvr = Synapses(viereck, viereckr, on_pre='g_ampa += 1*nS')
# connvvr.connect()
# connvvr1 = Synapses(viereck1, viereckr1, on_pre='g_ampa += 1*nS')
# connvvr1.connect()
# connvvr2 = Synapses(viereck2, viereckr2, on_pre='g_ampa += 1*nS')
# connvvr2.connect()
# connvvr3 = Synapses(viereck3, viereckr3, on_pre='g_ampa += 1*nS')
# connvvr3.connect()
# connvvr4 = Synapses(viereck4, viereckr4, on_pre='g_ampa += 1*nS')
# connvvr4.connect()
# connvvr5 = Synapses(viereck5, viereckr5, on_pre='g_ampa += 1*nS')
# connvvr5.connect()
# connvvr6 = Synapses(viereck6, viereckr6, on_pre='g_ampa += 1*nS')
# connvvr6.connect()
# connvvr7 = Synapses(viereck7, viereckr7, on_pre='g_ampa += 1*nS')
# connvvr7.connect()
# connvvr8 = Synapses(viereck8, viereckr8, on_pre='g_ampa += 1*nS')
# connvvr8.connect()
# connvvr9 = Synapses(viereck9, viereckr9, on_pre='g_ampa += 1*nS')
# connvvr9.connect()
# connvvr10 = Synapses(viereck10, viereckr10, on_pre='g_ampa += 1*nS')
# connvvr10.connect()

# connivvr = Synapses(viereck, viereckr, on_pre='g_gaba += 0.5*nS')
# connivvr.connect()
# connivvr1 = Synapses(viereck1, viereckr1, on_pre='g_gaba += 0.5*nS')
# connivvr1.connect()
# connivvr2 = Synapses(viereck2, viereckr2, on_pre='g_gaba += 0.5*nS')
# connivvr2.connect()
# connivvr3 = Synapses(viereck3, viereckr3, on_pre='g_gaba += 0.5*nS')
# connivvr3.connect()
# connivvr4 = Synapses(viereck4, viereckr4, on_pre='g_gaba += 0.5*nS')
# connivvr4.connect()
# connivvr5 = Synapses(viereck5, viereckr5, on_pre='g_gaba += 0.5*nS')
# connivvr5.connect()
# connivvr6 = Synapses(viereck6, viereckr6, on_pre='g_gaba += 0.5*nS')
# connivvr6.connect()
# connivvr7 = Synapses(viereck7, viereckr7, on_pre='g_gaba += 0.5*nS')
# connivvr7.connect()
# connivvr8 = Synapses(viereck8, viereckr8, on_pre='g_gaba += 0.5*nS')
# connivvr8.connect()
# connivvr9 = Synapses(viereck9, viereckr9, on_pre='g_gaba += 0.5*nS')
# connivvr9.connect()
# connivvr10 = Synapses(viereck10, viereckr10, on_pre='g_gaba += 0.5*nS')
# connivvr10.connect()


# Defining the spike times
start_time_1 = 0.01  # Start time for the first assembly in seconds
start_time_2 = start_time_1 + 0.01  # Start time for the second assembly 10ms after the first

interval = 0.02  # Time interval between spikes in seconds
duration = 4.0  # Total duration in seconds (4 runs * 1 second per run)

times_1 = np.arange(start_time_1, duration, interval)  # Spike times for the first assembly
times_2 = np.arange(start_time_2, duration, interval)  # Spike times for the second assembly

# Repeating the indices for each spike time
indices_1 = np.repeat(np.arange(10), len(times_1))
indices_2 = np.repeat(np.arange(10), len(times_2))

# Repeating the times for each neuron
times_1 = np.tile(times_1, 10)
times_2 = np.tile(times_2, 10)

# Converting times to Brian2 units
times_1 = times_1 * second
times_2 = times_2 * second
# Creating the SpikeGeneratorGroup


#Poi = SpikeGeneratorGroup(10, indices_1.astype(int), times_1)  # First assembly
Poi = PoissonGroup(10,rates=80*Hz)

S = Synapses(Poi, viereck, on_pre='g_ampa += 1*nS')
S.connect()
S1 = Synapses(Poi, viereck1, on_pre='g_ampa += 1*nS')
S1.connect()
S2 = Synapses(Poi, viereck2, on_pre='g_ampa += 1*nS')
S2.connect()
S3 = Synapses(Poi, viereck3, on_pre='g_ampa += 1*nS')
S3.connect()
S4 = Synapses(Poi, viereck4, on_pre='g_ampa += 1*nS')
S4.connect()
S5 = Synapses(Poi, viereck5, on_pre='g_ampa += 1*nS')
S5.connect()
S6 = Synapses(Poi, viereck6, on_pre='g_ampa += 1*nS')
S6.connect()
S7 = Synapses(Poi, viereck7, on_pre='g_ampa += 1*nS')
S7.connect()
S8 = Synapses(Poi, viereck8, on_pre='g_ampa += 1*nS')
S8.connect()
S9 = Synapses(Poi, viereck9, on_pre='g_ampa += 1*nS')
S9.connect()
S10 = Synapses(Poi, viereck10, on_pre='g_ampa += 1*nS')
S10.connect()




#Poix = SpikeGeneratorGroup(10, indices_2.astype(int), times_2)  # Second assembly
Poix = PoissonGroup(10,rates=50*Hz)

Sx = Synapses(Poix, viereckr, on_pre='g_ampa += 1*nS')
Sx.connect()
S1x = Synapses(Poix, viereckr1, on_pre='g_ampa += 1*nS')
S1x.connect()
S2x = Synapses(Poix, viereckr2, on_pre='g_ampa += 1*nS')
S2x.connect()
S3x = Synapses(Poix, viereckr3, on_pre='g_ampa += 1*nS')
S3x.connect()
S4x = Synapses(Poix, viereckr4, on_pre='g_ampa += 1*nS')
S4x.connect()
S5x = Synapses(Poix, viereckr5, on_pre='g_ampa += 1*nS')
S5x.connect()
S6x = Synapses(Poix, viereckr6, on_pre='g_ampa += 1*nS')
S6x.connect()
S7x = Synapses(Poix, viereckr7, on_pre='g_ampa += 1*nS')
S7x.connect()
S8x = Synapses(Poix, viereckr8, on_pre='g_ampa += 1*nS')
S8x.connect()
S9x = Synapses(Poix, viereckr9, on_pre='g_ampa += 1*nS')
S9x.connect()
S10x = Synapses(Poix, viereckr10, on_pre='g_ampa += 1*nS')
S10x.connect()

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

con_ie = Synapses(neurons, neurons, model=eqs_stdp_inhib,
                  on_pre='''Apre += 1.
                         w = clip(w+(Apost-alpha)*eta, 0, gmax)
                         g_gaba += w*nS''',
                  on_post='''Apost += 1.
                          w = clip(w+Apre*eta, 0, gmax)
                       ''')
con_ie.connect(p=epsilon)
con_ie.w = 1e-10

eqs_stdp_excit = '''
w : 1
dApre/dt=-Apre/tau_stdp : 1 (event-driven)
dApost/dt=-Apost/tau_stdp : 1 (event-driven)
'''
alpha = 3*Hz*tau_stdp*2  # Target rate parameter
gmax = 100               # Maximum excitatory weight

con_ee = Synapses(Pe, Pe, model=eqs_stdp_inhib,
                  on_pre='''Apre += 1.
                         w = clip(w+(Apost-alpha)*eta, 0, gmax)
                         g_ampa += w*nS''',
                  on_post='''Apost += 1.
                          w = clip(w+Apre*eta, 0, gmax)
                       ''')
con_ee.connect(p=epsilon)
con_ee.w = 1e-5


# ###########################################
# Setting up monitors
# ###########################################
sm = SpikeMonitor(Pe)
M = StateMonitor(neurons, 'v', record=0)
# ###########################################
# Run with plasticity
# ###########################################
outputrates=[]
eta = 1e-2
Poi.active=True
Poix.active=False
# Learning rate
run(simtime)
outputrates.append(sm.count/simtime)



Poi.active=True
Poix.active=True
sm = SpikeMonitor(neurons)
run(simtime)
outputrates.append(sm.count/simtime)


Poi.active=True
Poix.active=True

sm = SpikeMonitor(neurons)
run(simtime)
outputrates.append(sm.count/simtime)

Poi.active=True
Poix.active=False
con_ie.active=False
sm = SpikeMonitor(neurons)
run(simtime)
outputrates.append(sm.count/simtime)
# ###########################################
# Make plots
# ###########################################


import seaborn as sns

# Run your network simulation code first

# After running the simulation
spike_counts= sm.count[:3136]   # This gives the number of spikes for each neuron
spike_rate = spike_counts / simtime  # We ran for 1 second, adjust as needed
print("AVG:"+str(np.average(spike_rate)))# Now let's reshape this into the shape of the network
spike_rate_grid = np.reshape(outputrates[0][:3136], (rows, cols))

# And plot
plt.figure(figsize=(10,10))
sns.heatmap(spike_rate_grid, square=True,vmin=0, vmax=55, cmap='hot', cbar_kws={'label': 'Spikes/sec'})
plt.title('Spike rate heatmap')
plt.show()
print(spike_rate_grid)
spike_rate_grid = np.reshape(outputrates[1][:3136], (rows, cols))
plt.figure(figsize=(10,10))
sns.heatmap(spike_rate_grid, square=True,  cmap='hot',cbar_kws={'label': 'Spikes/sec'})
plt.title('Spike rate heatmap')
plt.show()

spike_rate_grid = np.reshape(outputrates[2][:3136], (rows, cols))
plt.figure(figsize=(10,10))
sns.heatmap(spike_rate_grid, square=True,  cmap='hot',cbar_kws={'label': 'Spikes/sec'})
plt.title('Spike rate heatmap')
plt.show()



spike_rate_grid = np.reshape(outputrates[3][:3136], (rows, cols))
plt.figure(figsize=(10,10))
sns.heatmap(spike_rate_grid, square=True,  cmap='hot',cbar_kws={'label': 'Spikes/sec'})
plt.title('Spike rate heatmap')
plt.show()

plot(M.t/ms,M.v[0])



