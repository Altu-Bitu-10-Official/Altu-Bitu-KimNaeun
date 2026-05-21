#include <iostream>
#include <queue>

using namespace std;

int n, x, y, m;
int cnt = 0;
int board[101][101] = { 0, };
bool visited[101] = { false, };

//bfs 기본코드
int bfs(int from) {
	queue<int> q;
	q.push(from);
	visited[from] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt++;
		for (int i = 1; i <= n;i++) {
			if (board[now][i] == 1 && !visited[i]) {
				visited[i] = true;
				q.push(i);
				if (i == y) {
					return cnt;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> x >> y;
	cin >> m;

	for (int i = 0; i < m;i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = board[b][a] = 1;
	}

	int ans = bfs(x);
	
	cout << ans << "\n";

	return 0;
}