#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x, i = 1;
	queue<int> cards;

	cin >> n;

	for (int j = 1; j <= n; j++) {
		cards.push(j);
	}

	while(cards.size() > 1) {
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}

	cout << cards.front() << "\n";

	return 0;
}