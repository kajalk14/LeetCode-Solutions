class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0, r=0, len=INT_MAX, sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                len=min(len, r-l+1);
                sum=sum-nums[l++];
            }
            r++;
        }
        return len==INT_MAX?0:len;
    }
};