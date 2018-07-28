/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/27
 *  Name:
 *      4.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3fffffff;
inline int ok(vector<int> &a, vector<int> &b, int m, double &ans) {
    int n = a.size(), tot = a.size() + b.size(), t = ((tot+1)>>1) - m;

    int l = (m==0) ? -inf : a[m-1];
    int r = (m==n) ? inf : a[m];
    
    // printf("[%d, %d], m/n = %d/%d, t/b = %d/%u b[t-1] = %d\n", l, r, m, n, t, b.size(), b[t-1]);
    int bt1 = (t == (b.size())) ? inf : b[t];
    t--;

    
    //  [l, r]
    if (b[t] >= l && b[t] <= r) {
        if (tot & 1) {
            ans = b[t];
            return 0;
        } else {
            ans = (min(bt1, r) + b[t]) / 2.0;
            return 0;
        }
    }

    if (b[t] > r) {
        return 1;
    }
    if (b[t] < l) {
        if (bt1 < l) {
            return -1;
        } else {
            if (tot & 1) {
                ans = l;
                return 0;
            } else {
                ans = (min(bt1, r) + l) / 2.0;
                return 0;
            }
        }
    }
}
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> *small, *big;
        if (a.size() > b.size()) {
            small = &b;
            big = &a;
        } else {
            small = &a;
            big = &b;
        }
        int l = 0, r = small->size(), m, res;
        double value;
        while (l <= r) {
            m = (l + r) >> 1;
            res = ok(*small, *big, m, value);
            // printf("res = %d\n", res);
            if (res > 0) {
                l = m + 1;
            } else if (res < 0) {
                r = m - 1;
            } else {
                return value;
            }
        }
    }
};


#ifdef LOCAL
int main() {


    return 0;
}
#endif

