#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, x, idx = 0;
	char c;
	bool is_valid = true;
	cin >> n >> k;

	vector<char> ans;
	int same[26] = { 0 };

	for (int i = 0; i < n; i++) {
		ans.push_back('?');
	}

	for (int i = 0; i < 26; i++) {
		same[i] = 0;
	}
	
	for (int i = 0; i < k; i++) {
		cin >> x >> c;
		idx = (idx + x ) % n;
		if (ans[idx] != '?') {
			if (ans[idx] != c) {
				is_valid = false;
			}
		}
		else {
			if (same[c - 'A'] > 0) {
				is_valid = false;
			}
			else {
				ans[idx] = c;
				same[c - 'A'] = 1;
			}
		}
	}

	if (is_valid) {
		for (int i = 0; i < n; i++) {
			cout << ans[idx];
			if (idx == 0) {
				idx = n - 1;
			}
			else {
				idx--;
			}
		}
		cout << "\n";
	}
	else {
		cout << "!" << "\n";
	}


	return 0;
}