#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int x : st)
        {
            if (x != INT_MIN && st.count(x - 1))
                continue;

            int count = 1;
            int curr = x;

            while (curr != INT_MAX && st.count(curr + 1))
            {
                curr++;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solution.longestConsecutive(nums);
    cout << "Longest consecutive sequence: " << result << endl;
    return 0;
}