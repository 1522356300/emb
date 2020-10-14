#/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as pt

x=np.arange(0,360)
print(x)
y= np.sin(2*x*np.pi/180.0)
z=np.cos(x*np.pi/180.0)

pt.plot(x, y, color='blue', label="$SIN(2x)$")
pt.plot(x, z, color='red', label="$COS(X)$")
pt.xlim(0, 360)
pt.xlim(-1.2,1.2)
pt.title("SIN & COS FUNCTION")

pt.legend()
pt.show()
