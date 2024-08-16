class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1, el2;
        int n = nums.size();
        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++) {
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }
        
        if(cnt1 >= int(n/3) + 1) res.push_back(el1);
        if(cnt2 >= (int)n/3 + 1 && el1 != el2) res.push_back(el2);
        sort(res.begin(), res.end());

        return res;
    }
};