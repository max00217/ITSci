import networkx as nx
import imageio
import os

import matplotlib.pyplot as plt

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

  def kruskal(self, pos):
    self.edges.sort()
    total_weight = 0
    mst_edges = []
    step = 0

    for weight, u, v in self.edges:
      if self.find(u) != self.find(v):
        self.union(u, v)
        total_weight += weight
        mst_edges.append((u, v, weight))
        step += 1
        self.draw_graph(mst_edges, step, pos)

    return total_weight, mst_edges

  def draw_graph(self, mst_edges, step, pos):
    G = nx.Graph()
    G.add_weighted_edges_from(self.edges)

    plt.figure()
    nx.draw(G, pos, with_labels=True, node_color='skyblue', edge_color='black', node_size=500, font_size=16)
    nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): d['weight'] for u, v, d in G.edges(data=True)})

    mst = nx.Graph()
    mst.add_weighted_edges_from(mst_edges)
    nx.draw_networkx_edges(mst, pos, edge_color='r', width=2)
    plt.title(f"Step {step}")
    plt.savefig(f"step_{step}.png")
    plt.close()

# 테스트 케이스
g = Graph(9)
g.add_edge(0, 1, 4)
g.add_edge(0, 2, 3)
g.add_edge(1, 2, 1)
g.add_edge(1, 3, 2)
g.add_edge(2, 3, 4)

# 노드 위치 고정
G = nx.Graph()
G.add_weighted_edges_from(g.edges)
pos = nx.circular_layout(G)  # 원형 레이아웃 사용

total_weight, mst_edges = g.kruskal(pos)
print("Minimum Spanning Tree Weight:", total_weight)

# GIF 생성
images = []
for step in range(1, len(mst_edges) + 1):
  images.append(imageio.imread(f"step_{step}.png"))
imageio.mimsave('kruskal_algorithm.gif', images, duration=1)
