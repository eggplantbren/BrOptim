import numpy as np
import matplotlib.pyplot as plt

output = np.atleast_2d(np.loadtxt("output.txt"))

plt.plot(output[:,0], output[:,1], ".", markersize=1, alpha=0.2)
plt.show()
