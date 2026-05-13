#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, ans = 0;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int len = 0;

		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				len = max(dp[j], len);
			}
		}
		dp[i] = len + 1;

		if (ans < dp[i]) {
			ans = dp[i];
		}
	}

	cout << ans << "\n";


	return 0;
}