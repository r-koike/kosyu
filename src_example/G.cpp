#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/* ↓ここを編集する． */

/* ↑ここを編集する． */

int main() {
    int i = 777;
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    string str = "hello";
    pair<int, int> p = {0, 1};
    vector<int> vec = {0, 1, 2, 3};
    vector<string> vec_str = {"hello", "world", "!"};
    vector<pair<int, int>> vec_pair = {{0, 1}, {2, 3}, {4, 5}};
    pair<vector<int>, vector<int>> pair_vecvec = {{0, 1, 2, 3}, {4, 5, 6, 7}};
    vector<pair<vector<int>, vector<int>>> vec_pair_vecvec = {
        {{0}, {1, 2}}, {{3}, {}}, {{4}, {5}}};
    vector<vector<vector<int>>> vec_vec_vec = {{{0}, {1, 2}}, {{3}, {4}, {5, 6}}, {{}}};

    disp(i);
    disp(x1, x2, x3, x4, x5);
    disp(str, p);
    disp(vec, vec_str, vec_pair);
    disp(pair_vecvec);
    disp(vec_pair_vecvec);
    disp(vec_vec_vec);

    return 0;
};