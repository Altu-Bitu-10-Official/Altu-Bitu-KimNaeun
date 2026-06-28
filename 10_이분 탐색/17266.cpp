#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, h;

    cin >> n >> m;
    vector<int> road(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> road[i];
    }

    h = road[0];
    for (int i = 1; i < m; i++) {
        int tmp = road[i] - road[i - 1];
        if (tmp > h) {
            h = tmp;
        }
    }
    int tmp = n - road[m - 1];
    if (tmp > h) {
        h = tmp;
    }

    cout << h << '\n';

    return 0;
}