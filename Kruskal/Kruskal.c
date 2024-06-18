#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
  int u, v;  // 간선을 연결하는 두 노드
  int weight;  // 간선의 가중치
} Edge;

typedef struct {
  int n;  // 노드의 개수
  int m;  // 간선의 개수
  Edge edges[MAX_EDGES];  // 간선 배열
} Graph;

int parent[MAX_NODES];  // 각 노드의 부모 노드 저장

int find(int x) {
  if (parent[x] != x)
    parent[x] = find(parent[x]);
  return parent[x];
} // 경로 압축 기법

void unionSet(int x, int y) {
  int xRoot = find(x);
  int yRoot = find(y);
  parent[xRoot] = yRoot;
} // 두 집합을 하나로 합침

int cmpEdge(const void* a, const void* b) {
  Edge* edgeA = (Edge*)a;
  Edge* edgeB = (Edge*)b;
  return edgeA->weight - edgeB->weight;
} // qsort()를 위한 비교 함수

int kruskal(Graph* g) {
  int totalWeight = 0;
  int edgeCount = 0;

  // 간선 배열을 가중치 순으로 정렬
  qsort(g->edges, g->m, sizeof(Edge), cmpEdge);

  // 각 노드의 부모 노드를 자기 자신으로 초기화
  for (int i = 0; i < g->n; i++)
    parent[i] = i;

  // 간선 선택 및 집합 병합
  for (int i = 0; i < g->m; i++) {
    int u = g->edges[i].u;
    int v = g->edges[i].v;
    int weight = g->edges[i].weight;

    // 두 노드의 부모 노드가 다르다면 (사이클 형성 X)
    if (find(u) != find(v)) {
      unionSet(u, v);
      totalWeight += weight;
      edgeCount++;

      // 모든 노드가 하나의 집합에 속하면 종료
      if (edgeCount == g->n - 1)
        break;
    }
  }

  return totalWeight;
}

int main() {
  Graph g;
  g.n = 6;
  g.m = 9;

  // 각 Edge 구조체의 u, v, weight는 각각 노드 u, v를 연결하는 간선의 가중치
  g.edges[0] = (Edge){0, 1, 4};
  g.edges[1] = (Edge){0, 5, 2};
  g.edges[2] = (Edge){1, 2, 8};
  g.edges[3] = (Edge){1, 5, 7};
  g.edges[4] = (Edge){2, 3, 2};
  g.edges[5] = (Edge){2, 4, 4};
  g.edges[6] = (Edge){2, 5, 1};
  g.edges[7] = (Edge){3, 4, 6};
  g.edges[8] = (Edge){4, 5, 5};

  int minWeight = kruskal(&g);
  printf("Minimum Spanning Tree Weight: %d\n", minWeight);

  return 0;
}
