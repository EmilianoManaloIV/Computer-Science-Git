#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct Edge {
  string from, to;
  int weight;
};

unordered_map<string, vector<pair<string, int>>>
makeGraph(const vector<Edge> &edges) {
  unordered_map<string, vector<pair<string, int>>> graph;
  for (auto &e : edges) {
    graph[e.from].push_back({e.to, e.weight});
    graph[e.to].push_back({e.from, e.weight}); // undirected
  }
  return graph;
}
pair<int, vector<string>>
dijkstra(unordered_map<string, vector<pair<string, int>>> &graph, string start,
         string end) {
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
  unordered_map<string, int> dist;
  unordered_map<string, string> prev;

  for (auto &node : graph)
    dist[node.first] = INT_MAX;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    auto top = pq.top();
    int d = top.first;
    string u = top.second;
    pq.pop();

    if (u == end)
      break;

    for (auto &vw : graph[u]) {
      string v = vw.first;
      int w = vw.second;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  vector<string> path;
  for (string at = end; at != ""; at = prev.count(at) ? prev[at] : "") {
    path.push_back(at);
    if (at == start)
      break;
  }
  reverse(path.begin(), path.end());
  return {dist[end], path};
}


// Union-Find for Kruskal's
struct DSU {
  unordered_map<string, string> parent;
  string find(string x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }
  void unite(string x, string y) { parent[find(x)] = find(y); }
  void add(string x) {
    if (!parent.count(x))
      parent[x] = x;
  }
};

int kruskal(const vector<Edge> &edges, vector<Edge> &mstEdges) {
  DSU dsu;
  for (const auto &e : edges) {
    dsu.add(e.from);
    dsu.add(e.to);
  }
  vector<Edge> sorted = edges;
  sort(sorted.begin(), sorted.end(),
       [](auto &a, auto &b) { return a.weight < b.weight; });
  int total = 0;
  for (auto &e : sorted) {
    if (dsu.find(e.from) != dsu.find(e.to)) {
      dsu.unite(e.from, e.to);
      total += e.weight;
      mstEdges.push_back(e);
    }
  }
  return total;
}

void printPath(const string &from, const string &to,
               const pair<int, vector<string>> &result) {
  cout << "Shortest path from " << from << " to " << to << " (" << result.first
       << " miles): ";
  for (size_t i = 0; i < result.second.size(); ++i) {
    cout << result.second[i];
    if (i + 1 < result.second.size())
      cout << " → ";
  }
  cout << "\n";
}

int main() {
  vector<Edge> edges = {
      {"SFO", "BOS", 2703}, {"SFO", "ORD", 1847}, {"ORD", "BOS", 868},
      {"ORD", "JFK", 743},  {"JFK", "BOS", 189},  {"SFO", "DFW", 1465},
      {"DFW", "ORD", 803},  {"DFW", "MIA", 1124}, {"MIA", "JFK", 1093},
      {"MIA", "BOS", 1257}, {"SFO", "LAX", 338},  {"LAX", "DFW", 1234},
      {"LAX", "MIA", 2341}};

  auto graph = makeGraph(edges);

  // (a) Shortest ORD → LAX
  auto pathA = dijkstra(graph, "ORD", "LAX");
  printPath("ORD", "LAX", pathA);

  // (b) Shortest JFK → SFO
  auto pathB = dijkstra(graph, "JFK", "SFO");
  printPath("JFK", "SFO", pathB);

  // (c) Minimum Spanning Tree
  vector<Edge> mstEdges;
  int mstCost = kruskal(edges, mstEdges);
  cout << "\nMinimum Spanning Tree edges:\n";
  for (auto &e : mstEdges) {
    cout << e.from << " — " << e.to << " (" << e.weight << ")\n";
  }
  cout << "Total MST cost: " << mstCost << "\n";

  return 0;
}
