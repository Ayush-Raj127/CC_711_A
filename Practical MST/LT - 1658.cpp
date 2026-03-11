class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;
        for (int num : nums) {
            total += num;
        }

        long subarr = total - x;
        if (subarr < 0) return -1;
        
        int left = 0;
        int right = 0;
        long long sum = 0;
        int mx = -1;

        for (right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > subarr) {
                sum = sum - nums[left];
                left++;
            }

            if (sum == subarr) {
                mx = max (mx, right - left + 1);
            }
        }

        if (mx == -1) return -1;

        return nums.size() - mx;
    }
};