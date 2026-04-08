#include <iostream>

using namespace std;

const int E_MAX = 15;
const int S_MAX = 28;
const int M_MAX = 19;

int main() {
	int e, s, m, ans;
	cin >> e >> s >> m;

	for (int i = 1; i <= 10000; i++) {
		int e_temp = i % E_MAX;
		int s_temp = i % S_MAX;
		int m_temp = i % M_MAX;
		if (e_temp == 0) e_temp = E_MAX;
		if (s_temp == 0) s_temp = S_MAX;
		if (m_temp == 0) m_temp = M_MAX;
		if (e_temp == e and s_temp == s and m_temp == m) {
			ans = i;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}