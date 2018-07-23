/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/23
 *  Name:
 *      65.cpp
 */

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;
#endif

inline bool is_digital(const char &c) {
    return c >= '0' && c <= '9';
}
inline bool is_symbol(const char &c) {
    return c == '.' || c == 'e' || c == 'E';
}
inline bool is_e(const char &c) {
    return c == 'e' || c == 'E';
}
inline bool is_pn(const char &c) {
    return c == '+' || c == '-';
}
class Solution {
public:
    bool isNumber(string s) {

        int x = 0;
        for (auto c: s) {
            if (c == ' ' || c == '\t') {
                x++;
            } else {
                break;
            }
        }
        s = string(s.c_str() + x);

        while (s.length() > 0 && 
                (s[s.length() - 1] == ' ' || s[s.length() - 1] == '\t'))
            s.pop_back();
    
        if (s.length() > 0 && is_pn(s[0]))
            s = string(s.c_str() + 1);

        if (s.length() == 0)
            return 0;
        int e = 0, d = 0;
        if (s == ".")
            return 0;
        if (s.length() > 1 && s[0] == '.' && is_e(s[1]))
            return 0;
        if (s.length() > 0 && is_e(s[0]))
            return 0;
        for (auto c: s) {
            if (e == 1) {
                if (is_pn(c)) {
                    e++;
                    continue;
                }
            }
            if (!is_digital(c) && !is_symbol(c))
                return false;
            if (c == '.') {
                if (d || e) 
                    return false;
                d = true;
            } else if (c == 'e' || c == 'E') {
                if (e)
                    return false;
                e = 1;
            } else {
                if (e)
                    e = 3;
            }
        }
        return e == 3 || e == 0;
    }
};

#ifdef LOCAL
int main() {
    auto s = Solution();
    cout << s.isNumber("1e") << endl;
    cout << s.isNumber("1e12") << endl;
    cout << s.isNumber("1e.12") << endl;
    cout << s.isNumber("1e12.") << endl;
    cout << s.isNumber("11.e2") << endl;
    cout << s.isNumber("1e21e12") << endl;
    cout << s.isNumber("1.123.23") << endl;
    cout << s.isNumber("1.") << endl;
    cout << s.isNumber(".") << endl;
    cout << s.isNumber("  .  ") << endl;
    cout << s.isNumber(" e. ") << endl;
    cout << s.isNumber(" .e ") << endl;
    cout << s.isNumber("1.e1") << endl;
    cout << s.isNumber("+e1") << endl;
    cout << s.isNumber("E1") << endl;

    return 0;
}
#endif
