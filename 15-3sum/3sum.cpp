class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);

                    do {
                        j++;
                    } while(j < k && nums[j - 1] == nums[j]);

                    do {
                        k--;
                    } while(j < k && nums[k + 1] == nums[k]);

                }
            }
        }

        return res;
    }
};