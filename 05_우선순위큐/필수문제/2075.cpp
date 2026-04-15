#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, greater<int>> nums;

	cin >> n;

	for (int i = 0; i < n*n; i++) {
		cin >> x;
		if (nums.size() >= n and nums.top() < x) {
			nums.pop();
			nums.push(x);
		}
		else if (nums.size() < n) {
			nums.push(x);
		}
	}

	cout << nums.top() << "\n";


	return 0;
}