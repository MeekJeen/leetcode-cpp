/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while(start + 1 < end)
        {
            if(nums[mid] == target) return mid;
            else if (nums[mid] >= nums[start]) {
                if(target >= nums[start] && target < nums[mid])
                    end = mid;
                else
                    start = mid;
            }
            else {
                if(target <= nums[end] && target > nums[mid])
                    start = mid;
                else
                    end = mid;
            }
            mid = start + (end - start) / 2;
        }
        if (nums[start] == target) return start;
        else if (nums[end] == target) return end;
        return -1;
    }
};
// @lc code=end

