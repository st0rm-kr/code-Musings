#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace l332 {
class Solution {
public:
  std::vector<std::string>
  findItinerary(std::vector<std::vector<std::string>> &tickets) {
    for (auto &edge : tickets) {
      g[edge[0]].push_back(Edge(edge[1]));
    }
    for (auto &[_, edges] : g) {
      std::sort(edges.begin(), edges.end());
    }
    dfs("JFK");
    std::reverse(path.begin(), path.end());
    return path;
  }

private:
  struct Edge {
    std::string to;
    bool used;
    Edge(const std::string &to) : to(to), used(false) {}
    bool operator<(const Edge &rhs) const { return to < rhs.to; }
  };

private:
  std::unordered_map<std::string, std::vector<Edge>> g;
  std::vector<std::string> path;

  void dfs(const std::string &cur) {
    auto &edges = g[cur];
    for (auto &edge : edges) {
      if (edge.used)
        continue;
      edge.used = true;
      dfs(edge.to);
    }
    path.push_back(cur);
  }
};
} // namespace l332