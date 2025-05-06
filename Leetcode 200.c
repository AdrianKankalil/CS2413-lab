#include <stdbool.h>

void dfs(char** grid, int i, int j, int m, int n) {
    // Base case: if out of bounds or water, return
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;

    // Mark the cell as visited
    grid[i][j] = '0';

    // Visit all 4 adjacent directions
    dfs(grid, i + 1, j, m, n); // down
    dfs(grid, i - 1, j, m, n); // up
    dfs(grid, i, j + 1, m, n); // right
    dfs(grid, i, j - 1, m, n); // left
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0) return 0;

    int count = 0;
    int m = gridSize;
    int n = gridColSize[0]; // assumes all rows have same number of columns

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, m, n); // mark all land in this island
            }
        }
    }

    return count;
}
