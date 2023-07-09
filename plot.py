import matplotlib.pyplot as plt

file_name = input("File Name: ")

f = open(file_name, "r")
lines = f.readlines()

path = []
paths = []

for line in lines:
	line = line.rstrip()
	if (line == "-"):
		paths.append(path)
		path = []
	else:
		line = float(line)
		path.append(line)


for i in paths:
	plt.plot(i)
plt.xlabel("Time Steps")
plt.ylabel("Stock Price")
plt.show()
