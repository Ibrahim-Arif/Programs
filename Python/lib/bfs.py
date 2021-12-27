from queue import PriorityQueue

class Graph:
    def __init__(self):
        self.edges = {}
        self.weights = {}
        self.graph = {
            "A": [(130, ("A", "O")), (110, ("A", "S")), (420, ("A", "C"))],
            "O": [(105, ("O", "A")), (108, ("O", "S"))],
            "S": [(101, ("S", "O")), (111, ("S", "A")), (80, ("S", "R")), (99, ("S", "F"))],
            "C": [(494, ("C", "A")), (146, ("C", "R"))],
            "R": [(80, ("R", "S")), (146, ("R", "C")), (97, ("R", "P"))],
            "F": [(99, ("F", "S")), (211, ("F", "B"))],
            "B": [(211, ("B", "F")), (101, ("B", "P"))],
            "P": [(101, ("P", "B")), (97, ("P", "R")), (138, ("P", "C"))]}

        self.fill_edges()
        self.fill_weights()

    def fill_edges(self):
        for key in self.graph:
            neighbours = []
            for each_tuple in self.graph[key]:
                neighbours.append(each_tuple[1][1])
            self.edges[key] = neighbours

    def fill_weights(self):
        for key in self.graph:
            neighbours = self.graph[key]
            for each_tuple in neighbours:
                self.weights[each_tuple[1]] = each_tuple[0]

    def neighbors(self, node):
        return self.edges[node]

    def get_cost(self, from_node, to_node):
        return self.weights[(from_node, to_node)]
    
def bfs(graph, start, goal):
    explored = []
    queue = PriorityQueue()
    queue.put((0,start))
    while queue:
        cost, node = queue.get()
        # print('node being explored: ', node)
        # print("explored : ", explored)
        if node not in explored:
            explored.append(node)
            if node == goal:
                break
            neighbours = graph.neighbors(node)
            for neighbour in neighbours:
                total_cost = graph.get_cost(node, neighbour)
                queue.put((total_cost,neighbour))
    return explored

print("BFS Traversal : ", bfs(Graph(), "A", "B"))