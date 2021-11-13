import numpy as np
import matplotlib.pyplot as plt
import math as m
fg =1
n = 10
t0 = 1
tn = 2
y0 =0.1
t = np.linspace(t0,tn,n+1)
ye = np.AdBash3(t0,tn,n,y0)
yb = np.beuler(t0,tn,n,y0)
ypc = np.PreCorr3(t0,tn,n,y0)
fig =plt.figure()
plt.plot(t,ye,color='red',label='Adams-Bashforth 3')
plt.plot(t,yb,color='black',label='Backward Euler')
plt.plot(t,yb,color='cyan',label='Predictor/Corrector 3/4')
t = np.linspace(t0,tn,11)
ysol = sol(t,t0,y0)
plt.plot(t,ysol,color ='green',label='Exact')
plt.title('courbe ')
axis([0,tn,-10,40])
plt.legend(loc='lower left')

plt.legend()
plt.show()
