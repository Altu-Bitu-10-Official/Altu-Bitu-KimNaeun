#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str_1, str_2;
	stack<char> ans;
	int i, j, n, m, temp, carry = 0;

	cin >> str_1 >> str_2;
	
	i = str_1.size() - 1;
	j = str_2.size() - 1;

	while (i >= 0 or j >= 0 or carry != 0) {
		if (i >= 0) {
			n = str_1[i] - '0';
		}
		else {
			n = 0;
		}

		if (j >= 0) {
			m = str_2[j] - '0';
		}
		else {
			m = 0;
		}
		temp = n + m + carry;
		carry = 0;

		if (temp >= 10) {
			carry = 1;
		}

		ans.push((temp % 10) + '0');
		i -= 1;
		j -= 1;
		temp = 0;
	}

	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}

	return 0;
}