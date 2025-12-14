class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long largest = 0;
        long long smallest = 0;
        if (nums.size() == 1)
            return 0;
        if (k == nums.size())
            return 0;
        if (k >= 1) {
            for (int i = 0; i < k; i++) {
                largest += nums[i];
            }
            for (int i = 0; i < k; i++) {
                smallest += nums[nums.size() - i - 1];
            }
            int ans = (largest - smallest);
            return ans;
        }
        return 0;
    }
};