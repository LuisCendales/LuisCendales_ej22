import os
import numpy as np
import matplotlib.pyplot as plt


a = os.system("g++ mh.cpp -o mh.x")
a = os.system("./mh.x > mh.dat")

f= np.loadtxt("mh.dat")

y=f[:,1]

plt.figure()
plt.hist(y,density=True,bins=100)
plt.savefig("mh.png")
plt.close()