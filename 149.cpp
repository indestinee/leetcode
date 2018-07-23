/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/23
 *  Name:
 *      149.cpp
 */

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
#endif


int gcd(const int &x, const int &y) {
    return y?gcd(y, x%y):x;
}
inline bool cmp(const Point &a, const Point &b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
inline int n2(const int &x) {
    return x * (x - 1) / 2;
}
inline bool equ(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}
class Solution {
public:
    int maxPoints(vector<Point>& q) {
        if (q.empty())
            return 0;
        sort(q.begin(), q.end(), cmp);
        int n = q.size();

        vector<Point> p;
        vector<int> cnt;

        int m = 0;
        p.push_back(q[0]);
        cnt.push_back(1);

        for (int i = 1; i < n; i++) {
            if (equ(p[m], q[i])) {
                cnt[m]++;
            } else {
                p.push_back(q[i]);
                cnt.push_back(1);
                m++;
            }
        }
        
        n = p.size();
        map<pair<long long, long long>, pair<int, set<int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long dx = p[i].x - p[j].x, dy = p[i].y - p[j].y,
                     g = gcd(dx, dy);
                dx /= g, dy /= g;
                if (dx < 0) dx = -dx, dy = -dy;
                if (dx == 0) dy = 1;
                if (dy == 0) dx = 1;

                long long u;
                if (dx != 0) {
                    //  (0 - p[i].x) * dy / dx + p[i].y
                    u = -p[i].x * dy + p[i].y * dx;
                } else {
                    //  (0 - p[i].y) * dx / dy + p[i].x
                    u = -p[i].y * dx + p[i].x * dy;
                }
                
                auto addr = make_pair(dx << 32 | dy, u);
                auto data = mp.find(addr);
                if (data == mp.end()) {
                    set<int> s;
                    if (i > 1)
                        s.insert(i);
                    if (j > 1)
                        s.insert(j);
                    mp[addr] = make_pair(cnt[i]*cnt[j] + 
                            n2(cnt[i]) + n2(cnt[j]), s);
                } else {
                    auto s = data->second.second;
                    if (i > 1 && data->second.second.find(i) == data->second.second.end()) {
                        data->second.second.insert(i);
                        data->second.first += n2(cnt[i]);
                    } 
                    if (j > 1 && data->second.second.find(j) == data->second.second.end()) {
                        data->second.second.insert(j);
                        data->second.first += n2(cnt[j]);
                    } 
                    data->second.first += cnt[i] * cnt[j];
                }
            }
        }

        int maxi = 0;
        for (auto i: mp)
            maxi = max(maxi, i.second.first);

        
        //  n * (n-1) / 2 = maxi;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, cnt[i]);
        }
    
        ans = max(ans, int(sqrt(maxi*2)+0.5 + 1));

        return ans;
    }
};
#ifdef LOCAL
int main() {


    return 0;
}
#endif
