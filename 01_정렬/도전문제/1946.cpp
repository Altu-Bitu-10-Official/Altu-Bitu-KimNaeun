#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checkPeople(vector<pair<int, int>>& score) {
	int len = score.size();
	int m = 1, c = 0;

	for (int i = 1; i < len; i++) {
		if (score[c].second > score[i].second) {
			m++;
			c = i;
		}
	}

	return m;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n, m;
	cin >> t;

	vector<pair<int, int>> score;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			score.push_back({ a, b });
		}

		sort(score.begin(), score.end());

		cout << checkPeople(score) << '\n';

		score.clear();
	}

	return 0;
}