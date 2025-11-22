#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return {};

        // 1) ordem por pós-visit (stack)
        vector<char> vis(n, 0);
        vector<int> order;
        order.reserve(n);
        function<void(int)> dfs1 = [&](int u) {
            vis[u] = 1;
            for (int v : graph[u]) if (!vis[v]) dfs1(v);
            order.push_back(u);
        };
        for (int i = 0; i < n; ++i) if (!vis[i]) dfs1(i);

        // 2) grafo reverso + atribuição de componentes (Kosaraju)
        vector<vector<int>> rev(n);
        for (int u = 0; u < n; ++u)
            for (int v : graph[u]) rev[v].push_back(u);

        vector<int> compId(n, -1);
        int cid = 0;
        function<void(int)> dfs2 = [&](int u) {
            compId[u] = cid;
            for (int v : rev[u]) if (compId[v] == -1) dfs2(v);
        };
        for (int i = n-1; i >= 0; --i) {
            int u = order[i];
            if (compId[u] == -1) { dfs2(u); ++cid; }
        }

        // 3) detectar SCCs cíclicas (size>1 ou self-loop)
        vector<int> compSize(cid, 0);
        for (int u = 0; u < n; ++u) ++compSize[compId[u]];
        vector<char> compCyclic(cid, 0);
        for (int u = 0; u < n; ++u) {
            if (compSize[compId[u]] > 1) compCyclic[compId[u]] = 1;
            else {
                for (int v : graph[u]) if (v == u) { compCyclic[compId[u]] = 1; break; }
            }
        }

        // 4) BFS no reverso a partir de nós em SCC cíclicas -> marca unsafe
        vector<char> unsafe(n, 0);
        queue<int> q;
        for (int u = 0; u < n; ++u)
            if (compCyclic[compId[u]] && !unsafe[u]) { unsafe[u] = 1; q.push(u); }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : rev[v]) if (!unsafe[u]) { unsafe[u] = 1; q.push(u); }
        }

        // 5) coletar safe nodes
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (!unsafe[i]) ans.push_back(i);
        return ans;
    }
};