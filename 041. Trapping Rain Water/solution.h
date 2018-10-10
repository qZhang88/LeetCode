#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    int trap(int A[], int n) {
        if (n<3) return 0;
        int count{0};
        for (int i=0, j=n-1, maxI=A[i], maxJ=A[j]; i<j; maxI=max(maxI, A[i]), maxJ=max(maxJ, A[j]))
            if (maxI < maxJ) count += maxI - A[i++];
            else count += maxJ - A[j--];
        return count;
    }
};


class SolutionII {
public:
    int trap(vector<int>& height) {
        int max = 0;
        for (auto iter = height.cbegin(); iter != height.cend(); iter++)
            if (*iter > max) max = *iter;

        int count = 0;
        for (int h = 1; h <= max; h++) {
            int tmp = 0;
            bool in_trap = false;
            for (auto iter = height.cbegin(); iter != height.cend(); iter++) {
                if (*iter >= h) {
                    if (!in_trap) in_trap = true;
                    else if (tmp) {
                        count += tmp;
                        tmp = 0;
                        in_trap = false;
                    }
                }
                else if (in_trap) ++tmp;
            }
        }
        return count;
    }
};
