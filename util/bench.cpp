#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> vec;
    int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            x += i + j;
            x %= n;
            vec.push_back(x);
        }
    }
    sort(vec.begin(), vec.end());

    return 0;
}