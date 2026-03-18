#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, sum;
	cin >> t;
	string clothe, type;
	map<string, int> closet;

	for(int i = 0; i < t; i++) {
		cin >> n;
		sum = 1; 

		for (int j = 0; j < n; j++) {
			cin >> clothe >> type;
			closet[type] += 1;
		}

		int len = closet.size();
		for (auto iter = closet.begin(); iter != closet.end(); iter++) {
			sum *= ((iter->second) + 1);
		}
		cout << sum - 1 << '\n';

		closet.clear();
	}

	return 0;
}