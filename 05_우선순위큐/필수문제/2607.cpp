#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0;
	string x, y;
	int x_nums[26] = { 0 };

	cin >> n >> x;

	for (int i = 0; i < x.size(); i++) {
		x_nums[x[i] - 'A'] += 1;
	}


	while(--n) {
		cin >> y;

		int y_nums[26] = { 0 };

		for (int i = 0; i < y.size(); i++) {
			y_nums[y[i] - 'A'] += 1;
		}

		if (max(x.size(), y.size()) - min(x.size(), y.size()) <= 1) {
			int tmp = 0;
			for (int i = 0; i < 26; i++) {
				tmp += abs(x_nums[i] - y_nums[i]);
			}

			if (tmp == 0 or tmp == 1 or (tmp == 2 and x.size() == y.size())) {
				cnt++;
			}
		}
	}

	cout << cnt << "\n";


	return 0;
}