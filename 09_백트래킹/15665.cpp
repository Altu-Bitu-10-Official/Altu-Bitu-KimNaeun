#include <iostream>
#include <set>

using namespace std;
const int MAX_N = 7;

int n, m;
int sequence[MAX_N];
set<int> input;

void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }

    cout << "\n";
}

void backtrack(int cnt) {
    if (cnt == m) {
        printSequence();
        return;
    }

    for (int it : input) {
        sequence[cnt] = it;
        backtrack(cnt + 1);
    }

}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        input.insert(x);
    }

    backtrack(0);

    return 0;
}