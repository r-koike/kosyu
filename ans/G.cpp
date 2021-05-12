#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string to_string(const string &s) {
    return '"' + s + '"';
}
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A> string to_string(A v) {
    bool first = true;
    string ret = "{";
    for (const auto &x : v) {
        string s = to_string(x);
        if (!first) {
            ret += ", ";
        }
        first = false;
        ret += s;
    }
    ret += "}";
    return ret;
}
template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void name_disp(string s) {
    printf("%s:\n", s.c_str());
}
void val_disp() {
}
template <typename First, typename... Lest> void val_disp(First F, Lest... L) {
    printf("%s\n", to_string(F).c_str());
    val_disp(L...);
}

#define disp(...)                                                                             \
    printf("*-----\n");                                                                       \
    name_disp(#__VA_ARGS__);                                                                  \
    val_disp(__VA_ARGS__)

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