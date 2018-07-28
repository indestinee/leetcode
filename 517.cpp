/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/26
 *  Name:
 *      517.cpp
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size(), ans = 0;
        long long sum = 0, avg;
        for (auto m: machines)
            sum += m;
        avg = sum / n;
        if (avg * n != sum)
            return -1;
        
        long long s1 = 0, s2 = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s1 += avg;
            s2 += machines[i];
            ans = max(ans, int(s));
            if (s2 > s1) {
                ans = max(ans, int(s + s2 - s1));
                s = 0;
            } else {
                s = s1 - s2;
            }
        }
        return ans;
    }
};

#ifdef LOCAL
int main() {
    auto s = Solution();


    return 0;
}
#endif
