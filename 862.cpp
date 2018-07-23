/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/23
 *  Name:
 *      862.cpp
 */

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;
#endif

const int maxn = 50010;
long long q[maxn];
int id[maxn];
int cnt, n;

inline int query(const long long &t, const int &p, const int &ans) {
    int l = max(0, cnt - 1 - ans), r = cnt - 1, m;
    if (q[l] > t)
        return n + 1;
    while (l < r) {
        m = (l + r + 1) >> 1;
        if (q[m] <= t) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return p - id[r];
}

inline void insert(const long long &m, const int &t) {
    while (0 < cnt && m <= q[cnt-1])
        cnt--;
    id[cnt] = t;
    q[cnt++] = m;
}
class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        n = a.size(), cnt = 0;
        int ans = n + 1;
        insert(0, -1);
        long long sum = 0;
        for (int i = 0; i < int(a.size()); i++) {
            sum += a[i];
            if (a[i] > 0)
                ans = min(ans, query(sum - k, i, ans));
            insert(sum, i);
        }
        if (ans == n+1)
            ans = -1;
        return ans;
    }
};

#ifdef LOCAL
int main() {


    return 0;
}
#endif
