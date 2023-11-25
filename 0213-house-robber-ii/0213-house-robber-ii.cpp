class Solution {
public:
    int findMaxLoot(vector<int>& nums, int start, int end) {
        int prevMax = nums[start];
        int currMax = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i) {
            int temp = currMax;
            currMax = max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }

        return currMax;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int max1 = findMaxLoot(nums, 0, nums.size() - 2);
        int max2 = findMaxLoot(nums, 1, nums.size() - 1);

        return max(max1, max2);
    }
};
