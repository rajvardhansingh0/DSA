#include <vector>

std::vector<int> findRedundantConnection(const std::vector<std::vector<int>>& edges) {
    int n = 0;
    for (const auto& edge : edges) {
        n = std::max(n, std::max(edge[0], edge[1]));
    }
    std::vector<int> parent(n + 1);
    std::vector<int> sz(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    auto find = [&](auto self, int i) -> int {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = self(self, parent[i]);
    };
    auto unite = [&](int i, int j) {
        i = find(find, i);
        j = find(find, j);
        if (i != j) {
            if (sz[i] < sz[j]) {
                std::swap(i, j);
            }
            parent[j] = i;
            sz[i] += sz[j];
            return true;
        }
        return false;
    };
    for (const auto& edge : edges) {
        if (!unite(edge[0], edge[1])) {
            return edge;
        }
    }
    return {};
}