#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

bool is_prime[MAX + 1];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x, y;

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (!is_prime[i]) {
			for (int j = i * 2; j <= MAX; j += i) {
				is_prime[j] = true;
			}
		}
	}

	while (true) {
		cin >> n;
		bool is_valid = false;
		if (n == 0) {
			break;
		}

		for (int i = 3; i < n; i += 2) {
			y = n - i;
			if (!is_prime[i] and !is_prime[y]) {
				cout << n << " = " << i << " + " << y << "\n";
				is_valid = true;
				break;
			}
		}

		if (!is_valid) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}

	return 0;
}