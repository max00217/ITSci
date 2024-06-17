class Graph:
  def __init__(self, vertices):
    self.vertices = vertices
    self.edges = []
    self.parent = list(range(vertices))
    self.rank = [0] * vertices

  def add_edge(self, u, v, weight):
    self.edges.append((weight, u, v))

  def find(self, x):
    if self.parent[x] != x:
      self.parent[x] = self.find(self.parent[x])
    return self.parent[x]

  def union(self, x, y):
    x_root = self.find(x)
    y_root = self.find(y)

    if x_root == y_root:
      return

    if self.rank[x_root] < self.rank[y_root]:
      self.parent[x_root] = y_root
    elif self.rank[x_root] > self.rank[y_root]:
      self.parent[y_root] = x_root
    else:
      self.parent[y_root] = x_root
      self.rank[x_root] += 1

  def kruskal(self):
    self.edges.sort()
    total_weight = 0

    for weight, u, v in self.edges:
      if self.find(u) != self.find(v):
        self.union(u, v)
        total_weight += weight

    return total_weight


# 테스트 케이스
g = Graph(6)
g.add_edge(0, 1, 4)
g.add_edge(0, 5, 2)
g.add_edge(1, 2, 8)
g.add_edge(1, 5, 7)
g.add_edge(2, 3, 2)
g.add_edge(2, 4, 4)
g.add_edge(2, 5, 1)
g.add_edge(3, 4, 6)
g.add_edge(4, 5, 5)

print("Minimum Spanning Tree Weight:", g.kruskal())
