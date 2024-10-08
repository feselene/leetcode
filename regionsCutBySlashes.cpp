class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(4 * n * n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = 4 * (i * n + j);
                if (grid[i][j] == '/') {
                    dsu.unionSets(index, index + 3);
                    dsu.unionSets(index + 1, index + 2);
                } else if (grid[i][j] == '\\') {
                    dsu.unionSets(index, index + 1);
                    dsu.unionSets(index + 2, index + 3);
                } else {
                    dsu.unionSets(index, index + 1);
                    dsu.unionSets(index + 1, index + 2);
                    dsu.unionSets(index + 2, index + 3);
                }
                if (i + 1 < n) dsu.unionSets(index + 2, index + 4 * n);
                if (j + 1 < n) dsu.unionSets(index + 1, index + 7);
            }
        }
        return dsu.countComponents();
    }

private:
    class DSU {
        vector<int> parent;
        int components;
    public:
        DSU(int n) : parent(n), components(n) {
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unionSets(int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY) {
                parent[rootY] = rootX;
                components--;
            }
        }
        int countComponents() { return components; }
    };
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> pixelGrid(3 * n, vector<int>(3 * n, 0));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '/') {
                    pixelGrid[i * 3][j * 3 + 2] = 1;
                    pixelGrid[i * 3 + 1][j * 3 + 1] = 1;
                    pixelGrid[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    pixelGrid[i * 3][j * 3] = 1;
                    pixelGrid[i * 3 + 1][j * 3 + 1] = 1;
                    pixelGrid[i * 3 + 2][j * 3 + 2] = 1;
                }

        int regions = 0;
        for (int i = 0; i < 3 * n; ++i)
            for (int j = 0; j < 3 * n; ++j)
                if (pixelGrid[i][j] == 0) {
                    dfs(pixelGrid, i, j);
                    regions++;
                }
        return regions;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] == 1) return;
        grid[i][j] = 1;
        dfs(grid, i + 1, j); dfs(grid, i - 1, j);
        dfs(grid, i, j + 1); dfs(grid, i, j - 1);
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> pixelGrid(3 * n, vector<int>(3 * n, 0));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '/') {
                    pixelGrid[i * 3][j * 3 + 2] = 1;
                    pixelGrid[i * 3 + 1][j * 3 + 1] = 1;
                    pixelGrid[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    pixelGrid[i * 3][j * 3] = 1;
                    pixelGrid[i * 3 + 1][j * 3 + 1] = 1;
                    pixelGrid[i * 3 + 2][j * 3 + 2] = 1;
                }

        int regions = 0;
        for (int i = 0; i < 3 * n; ++i)
            for (int j = 0; j < 3 * n; ++j)
                if (pixelGrid[i][j] == 0) {
                    bfs(pixelGrid, i, j);
                    regions++;
                }
        return regions;
    }

    void bfs(vector<vector<int>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] == 1) continue;
            grid[i][j] = 1;
            q.push({i + 1, j}); q.push({i - 1, j});
            q.push({i, j + 1}); q.push({i, j - 1});
        }
    }
};
