import numpy as np
import matplotlib.pyplot as plt

output = np.atleast_2d(np.loadtxt("output.txt"))

# Objective function
quality = np.sort(output[:,-1])

# Take top 5%
subset = output[:,-1] > quality[int(0.95*len(quality))]
subset = output[subset, :]

plt.figure(1)
plt.plot(output[:,0], output[:,1], ".", markersize=1, alpha=0.2)

plt.figure(2)
plt.hist(subset[:,0], 100)
plt.show()
