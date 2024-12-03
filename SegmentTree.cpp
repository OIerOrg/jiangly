#include <bits/stdc++.h>

struct SegmentTree {
    int n;
    std::vector<int> sum, max;
    void init(int _n) {
        n = _n;
        sum.assign(4 * n, 0);
        max.assign(4 * n, 0);
    }
    void pull(int p) {
        sum[p] = sum[2 * p] + sum[2 * p + 1];
        max[p] = std::max(max[2 * p + 1], max[2 * p] + sum[2 * p + 1]);
    }
    void modify(int p, int l, int r, int pos, int v) {
        if (r - l == 1) {
            sum[p] = v;
            max[p] = std::max(0, v);
            return;
        }
        int m = (l + r) / 2;
        if (pos < m) {
            modify(2 * p, l, m, pos, v);
        } else {
            modify(2 * p + 1, m, r, pos, v);
        }
        pull(p);
    }
    void modify(int pos, int v) {
        modify(1, 0, n, pos, v);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    return 0;
}
