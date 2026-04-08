#include <iostream>
#include <string>

using namespace std;
pair<char, int> king, stone, next_king, next_stone;

void chessMove(string x) {
	next_king = king;
	next_stone = stone;
	if (x == "R") {
		next_king.first += 1;
		next_stone.first += 1;
	}
	if (x == "L") {
		next_king.first -= 1;
		next_stone.first -= 1;
	}
	if (x == "B") {
		next_king.second -= 1;
		next_stone.second -= 1;
	}
	if (x == "T") {
		next_king.second += 1;
		next_stone.second += 1;
	}
	if (x == "RT") {
		next_king.first += 1;
		next_king.second += 1;
		next_stone.first += 1;
		next_stone.second += 1;
	}
	if (x == "LT") {
		next_king.first -= 1;
		next_king.second += 1;
		next_stone.first -= 1;
		next_stone.second += 1;
	}
	if (x == "RB") {
		next_king.first += 1;
		next_king.second -= 1;
		next_stone.first += 1;
		next_stone.second -= 1;
	}
	if (x == "LB") {
		next_king.first -= 1;
		next_king.second -= 1;
		next_stone.first -= 1;
		next_stone.second -= 1;
	}

	if (next_king.first >= 'A' and next_king.first <= 'H' and next_king.second >= 1 and next_king.second <= 8) {
		if (next_king == stone) {
			if (next_stone.first >= 'A' and next_stone.first <= 'H' and next_stone.second >= 1 and next_stone.second <= 8) {
				king = next_king;
				stone = next_stone;
			}
			else {
				return;
			}
		}
		king = next_king;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string k, s, x;
	int n;
	cin >> k >> s >> n;
	king.first = k[0];
	king.second = stoi(k.substr(1));
	stone.first = s[0];
	stone.second = stoi(s.substr(1));

	while (n--) {
		cin >> x;

		chessMove(x);
	}

	cout << king.first << king.second << "\n";
	cout << stone.first << stone.second << "\n";

	return 0;
}