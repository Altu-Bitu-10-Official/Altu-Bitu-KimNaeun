#include <iostream>
#include <queue>

using namespace std;

int n, m, cnt = 0;
int graph[101][101] = { 0, };
int visited[101] = { false, };

int dfs(int a) {
	for (int i = 1; i <= n; i++) {
		if (graph[a][i] == 1 && !visited[i]) {
			visited[i] = true;
			cnt++;
			dfs(i);
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m;i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	visited[1] = true;
	int ans = dfs(1);

	cout << ans << "\n";

	return 0;
}