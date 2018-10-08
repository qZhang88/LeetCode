#include <string>

using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0;

        for (char c; pi < p.size(); ++si) {
            c=p.at(pi);

            // p start with "c*"
            if (pi + 1 < p.size() and p.at(pi+1) == '*') {
                if (isMatch(s.substr(si, s.size()), p.substr(pi + 2, p.size()))) return true;
            }
            else ++pi;

            if (!(si < s.size() && (c == s.at(si) || c == '.'))) return false;
        }
        return si == s.size();
    }
};

/* original solution in C

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        for (char c=*p; c != '\0'; ++s, c=*p) {
            if (p[1] != '*') ++p;
            else if (isMatch(s, p+2)) return true;
            if (!(c == *s || (c == '.' && *s != '\0'))) return false;
        }
        return *s == '\0';
    }
};

*/
