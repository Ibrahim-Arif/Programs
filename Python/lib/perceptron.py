class Node:
    weight = 0
    nodeValue = 0

def __init__(self):
    self.weight = 0.5
    self.nodeValue = 0

class Perceptron:
    true = 1
    nodes = []
    learningRate = 0.1
    output = 0
    stepFunc = 0
    weightedSum = 0
    target = 0
    nodeLength = 0

    def __init__(self, stepFunc, target, nodeLength):
        self.nodes = [Node() for i in range(nodeLength)]
        self.stepFunc = stepFunc
        self.weightedSum = 0.11
        self.target = target
        self.nodeLength = nodeLength

    def inputData(self, inputData):
        for i in range(self.nodeLength):
            self.nodes[i].nodeValue = inputData[i]

    def calculateWeightedSum(self):
        self.weightedSum = 0;
        for i in range(self.nodeLength):
            self.weightedSum = (self.nodes[i].weight) * (self.nodes[i].nodeValue) + (self.nodes[i].weight) * (
                self.nodes[i].nodeValue)

    def train(self):
        while (self.true):
            if (self.activate()):
                self.output = 1

                if (self.output != self.target):
                    for i in range(self.nodeLength):
                        self.nodes[i].weight = self.nodes[i].weight + self.calculateError(self.nodes[i].nodeValue)
                else:
                    break
            else:
                self.output = -1

            if (self.output != self.target):
                for i in range(self.nodeLength):
                    self.nodes[i].weight = self.nodes[i].weight + self.calculateError(self.nodes[i].nodeValue)
            else:
                break

    def predict(self, input):
        self.inputData(input)
        print(input);
        if (self.activate()):
            print("bomber")
        else:
            print("fighter")

    def activate(self):
        self.calculateWeightedSum()
        if (self.weightedSum > self.stepFunc):
            return 1
        else:
            return 0

    def calculateError(self, inp):
        deltaI = 0
        deltaI = self.learningRate * (self.target - self.output) * inp
        return deltaI


target = [1, 1, -1, 1, -1, 1, -1, 1, -1, -1];
input = [
    [1.0, 0.1],
    [2.0, 0.2],
    [0.1, 0.3],
    [2.0, 0.3],
    [0.2, 0.4],
    [3.0, 0.4],
    [0.1, 0.5],
    [1.5, 0.5],
    [0.5, 0.6],
    [1.6, 0.7]
]


perc = Perceptron(0.55, 1, 2)
for l in range(len(input) - 2):
    perc.target = target[l]
    perc.inputData(input[l])
    perc.train()

perc.predict(input[5])
