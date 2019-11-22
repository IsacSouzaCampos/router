import matplotlib.pyplot as plt
import numpy as np
import csv

x = []
y = []


x2 = []
x3 = []

with open('result.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(int(row[1]))

plt.plot(x,y, label='Time')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Complexity Graphic')
plt.legend()
plt.show()
