class Solution {
public:
	void dfs(int i, int j, int visited[][301], int m, int n) {
		//Base Case
		if (i < 0 || j < 0) {
			return;
		}
		if (visited[i][j] == 1) {
			//Make it visited
			visited[i][j] = 2;
		}
		if (visited[i][j] == 2) {
			return;
		}
		if (visited[i][j] == 0)
		{
			return;
		}
		if (i == m || j == n) {
			return;
		}
		//Recursive case
		dfs(i, j + 1, visited, m, n);
		dfs(i + 1, j, visited, m, n);
		dfs(i, j - 1, visited, m, n);
		dfs(i - 1, j, visited, m, n);
	}
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int visited[301][301] = {0};
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = grid[i][j] - '0';
			}
		}
		int countIslands = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 1) {
					//Not visited and island
					countIslands++;
					dfs(i, j, visited, m, n);
				}
			}
		}
		return countIslands;

	}
};