class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mod = INT_MAX;
        long long res = INT_MIN;
        long long pref = 1;
        long long suff = 1;

        for(int i = 0; i < n; i++) {
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref = (pref * nums[i]) % mod;
            suff = (suff * nums[n - i - 1]) % mod;

            res = max(res, max(pref, suff));
        }

        return res;
    }
};