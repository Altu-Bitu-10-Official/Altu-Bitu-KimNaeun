#include <iostream>
#include <string>

using namespace std;
const int MAX = 20;

void calc(pair<string, int> input, int& x) {
	if (input.first == "add") {
		x |= 1 << input.second;
	}
	if (input.first == "remove") {
		x &= ~(1 << input.second);
	}
	if (input.first == "check") {
		if (x & (1 << input.second)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	if (input.first == "toggle") {
		x ^= (1 << input.second);
	}
	if (input.first == "all") {
		x = (1 << 21) - 1;
	}
	if (input.first == "empty") {
		x = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, x = 0;
	cin >> m;
	pair<string, int> input;

	while (m--) {
		cin >> input.first;
		if (input.first != "all" and input.first != "empty") {
			cin >> input.second;
		}

		calc(input, x);
	}

	return 0;
}