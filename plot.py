import matplotlib.pyplot as plt

file_name = input("File Name: ")

f = open(file_name, "r")
lines = f.readlines()

path = []
paths = []

for line in lines:
    line = line.rstrip()
    elements = line.split()
    if (len(elements) == 5):
        print(elements)
        price = elements[0] 
        strike = elements[1]
        vol = elements[2] 
        time = elements[3]
        callprice = elements[4]
        break
    if (line == "-"):
	    paths.append(path)
	    path = []
    else:
	    line = float(line)
	    path.append(line)


for i in paths:
	plt.plot(i)

graph_title = "Stock Price: " + str(price) + " Strike: " + str(strike) + " Vol: " + str(vol) + " Days until Expiration: " + str(time) + "\nCall Price: " + str(callprice)
plt.title(graph_title)
plt.xlabel("Time Steps")
plt.ylabel("Stock Price")
plt.savefig("Example/example.png")
plt.show()
