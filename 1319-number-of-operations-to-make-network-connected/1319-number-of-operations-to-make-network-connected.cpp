class DisJointSet {
public:
    vector<int> rank, parent, size;

    DisJointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {

            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {

            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisJointSet s(n);

        int cntExtra = 0;

        for (auto &it : connections) {

            int u = it[0];
            int v = it[1];

            if (s.findUPar(u) == s.findUPar(v)) {

                cntExtra++;
            }
            else {

                s.unionBySize(u, v);
            }
        }

        int comp = 0;

        for (int i = 0; i < n; i++) {

            if (s.findUPar(i) == i)
                comp++;
        }

        int need = comp - 1;

        if (cntExtra >= need)
            return need;

        return -1;
    }
};