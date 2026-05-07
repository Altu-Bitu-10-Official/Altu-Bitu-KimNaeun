#include <iostream>
#include <vector>
#define MAX 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	long long ans = 0;
	cin >> n;
	vector<int> dis;

	while (n--) {
		cin >> x;
		dis.push_back(x);
	}

	for (int i = dis.size() - 1; i >= 0; i--) {
		if (ans <= dis[i]) {
			ans = dis[i];
			ans = dis[i];
		}
		else {
			if (ans % dis[i] == 0) {
				continue;
			}
			else {
				long long tmp = dis[i];
				while (tmp < ans) {
					tmp += dis[i];
				}
				ans = tmp;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}