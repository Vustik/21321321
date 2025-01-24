#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addRow(int**& a, int& r, int c, int* x, int p) {
    int** t = new int* [r + 1];
    for (int i = 0, j = 0; i < r + 1; ++i) {
        if (i == p) t[i] = x;
        else t[i] = a[j++];
    }
    delete[] a;
    a = t;
    ++r;
}

void delRow(vector<vector<int>>& a, int p) {
    a.erase(a.begin() + p);
}

vector<vector<int>> to2D(vector<int>& a, int c) {
    int r = a.size() / c;
    vector<vector<int>> b(r, vector<int>(c));
    for (int i = 0; i < a.size(); ++i) b[i / c][i % c] = a[i];
    return b;
}

vector<int> to1D(vector<vector<int>>& a) {
    vector<int> b;
    for (auto& r : a) b.insert(b.end(), r.begin(), r.end());
    return b;
}

void dynArray() {
    vector<pair<string, string>> d;
    int o; string x, y;
    while (cin >> o) {
        if (o == 1) { cin >> x >> y; d.push_back({ x, y }); }
        if (o == 2) { cin >> x; for (auto& p : d) if (p.first == x) cout << p.second << endl; }
        if (o == 3) { cin >> y; for (auto& p : d) if (p.second == y) cout << p.first << endl; }
        if (o == 4) { cin >> x >> y; for (auto& p : d) if (p.first == x) p.second = y; }
    }
}
