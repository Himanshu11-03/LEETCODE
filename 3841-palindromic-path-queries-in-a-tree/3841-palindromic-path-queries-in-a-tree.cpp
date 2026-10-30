
class Solution {
public:
    static const int LOG = 20;

    int lowestCommonAncestor(
        int u, int v,
        vector<int>& depth,
        vector<vector<int>>& up
    ) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {
            if (diff & (1 << i))
                u = up[u][i];
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n);
        vector<int> depth(n, 0);
        vector<vector<int>> up(n, vector<int>(LOG, 0));

        int timer = 0;

        function<void(int,int)> dfs = [&](int u, int p) {
            tin[u] = timer++;

            up[u][0] = p;

            for (int i = 1; i < LOG; i++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }

            for (int v : adj[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer - 1;
        };

        dfs(0, 0);

        int sz = 1;
        while (sz < n) sz <<= 1;

        vector<int> tree(2 * sz, 0);

        for (int u = 0; u < n; u++) {
            tree[sz + tin[u]] = 1 << (s[u] - 'a');
        }

        for (int i = sz - 1; i > 0; i--) {
            tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
        }

        auto update = [&](int u, char c) {
            int idx = sz + tin[u];

            tree[idx] = 1 << (c - 'a');

            for (idx >>= 1; idx > 0; idx >>= 1) {
                tree[idx] = tree[idx * 2] ^ tree[idx * 2 + 1];
            }
        };

        auto queryRange = [&](int l, int r) {
            int res = 0;

            l += sz;
            r += sz + 1;

            while (l < r) {
                if (l & 1)
                    res ^= tree[l++];

                if (r & 1)
                    res ^= tree[--r];

                l >>= 1;
                r >>= 1;
            }

            return res;
        };

        // XOR of characters on root-to-node path
        auto getRootPath = [&](int u) {
            int res = 0;

            while (u != 0) {
                res ^= queryRange(tin[u], tout[u]);
                // Not used: see corrected prefix method below
                break;
            }

            return res;
        };

        // Dynamic root path XOR:
        // subtree XOR of u is NOT root path XOR.
        // Use Euler tour difference updates instead.
        
        vector<int> diff(2 * sz, 0);

        auto rangeXorUpdate = [&](int l, int r, int val) {
            // Difference array in XOR form
            // Apply XOR to [l, r]
            l += sz;
            r += sz;

            while (l <= r) {
                if (l & 1) diff[l++] ^= val;
                if (!(r & 1)) diff[r--] ^= val;
                l >>= 1;
                r >>= 1;
            }
        };

        auto pointQuery = [&](int pos) {
            int res = 0;
            pos += sz;

            while (pos > 0) {
                res ^= diff[pos];
                pos >>= 1;
            }

            return res;
        };

        // Build initial root path XOR using Euler subtree updates
        for (int u = 0; u < n; u++) {
            rangeXorUpdate(
                tin[u], tout[u],
                1 << (s[u] - 'a')
            );
        }

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);

            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int change = oldMask ^ newMask;

                s[u] = c;

                update(u, c);

                rangeXorUpdate(tin[u], tout[u], change);
            }
            else {
                ss >> v;

                int lca = lowestCommonAncestor(
                    u, v, depth, up
                );

                int mask =
                    pointQuery(tin[u]) ^
                    pointQuery(tin[v]) ^
                    (1 << (s[lca] - 'a'));

                ans.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
