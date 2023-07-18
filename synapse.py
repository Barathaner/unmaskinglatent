from brian2 import *
import matplotlib.pyplot as plt
import numpy as np

start_scope()

N = 25  # number of neurons
tau = 10*ms  # time constant
vr = -70*mV  # reset potential
vt = -60*mV  # threshold
delta_vt = 5*mV  # spike sharpness
duration = 1*second

# Neuron model
eqs = '''
dv/dt = (-(v-vr) + delta_vt*exp((v-vt)/delta_vt))/tau : volt (unless refractory)
'''

neurons = NeuronGroup(N, eqs, threshold='v>vt', reset='v=vr', refractory=5*ms, method='euler')
neurons.v = 'vr + rand() * (vt - vr)'

# Monitor the neurons
spikemon = SpikeMonitor(neurons)

run(duration)

firing_rates = np.array(spikemon.count) / duration  # Firing rates in Hz

# Reshape the firing rates
sqrt_N = int(np.sqrt(N))
if sqrt_N * sqrt_N != N:
    print("Warning: Cannot reshape array of size", N, "into a square matrix.")
else:
    firing_rates = firing_rates.reshape((sqrt_N, sqrt_N))

plt.figure(figsize=(10, 6))
plt.imshow(firing_rates, aspect='auto', cmap='hot', interpolation='nearest')
plt.colorbar(label='Firing rate (Hz)')
plt.show()
