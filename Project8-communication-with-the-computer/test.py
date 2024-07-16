import matplotlib.pyplot as plt
import numpy as np

x =  np.arange(0,10,0.1)
y = np.sin(x)

fig = plt.figure()
plt.plot(x,y)
plt.savefig(r'C:\Users\itclass02\Documents\yasmin-intro-lab-automation\Project8-communication-with-the-computer\yas.png')