#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int com = target - nums[i];
            if (mp.find(com) != mp.end())
            {
                return {mp[com], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}