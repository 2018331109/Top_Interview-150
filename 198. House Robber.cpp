//IN PLACE DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        nums[1]=max(nums[0], nums[1]);
        for(int i=2;i<n;i++)
        {
            nums[i]=max(nums[i-1], nums[i-2]+nums[i]);
        }

        return nums[n-1];
        
    }
};

//USING EXTRA SPACE

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1, 0);
        dp[1]=nums[0];

        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        return dp[n];
        
    }
};
