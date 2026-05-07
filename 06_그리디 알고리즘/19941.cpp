#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, cnt = 0;
	cin >> n >> k;
	string space;
	vector<int> ham(n + 1, 0);
	vector<int> person;

	cin >> space;

	for (int i = 0; i < n; i++) {
		if (space[i] == 'H') {
			ham[i+1] = 1;
		}
		else if(space[i] == 'P') {
			person.push_back(i+1);
		}
	}

	for (int i = person.size() - 1; i >= 0; i--) {
		int tmp = person[i];
		for (int j = 1; j <= k; j++) {
			if (tmp + j <= n && ham[tmp + j] == 1) {
				ham[tmp + j] -= 1;
				cnt++;
				break;
			}
			else if (tmp - j >= 1 && ham[tmp - j] == 1) {
				ham[tmp - j] -= 1;
				cnt++;
				break;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}