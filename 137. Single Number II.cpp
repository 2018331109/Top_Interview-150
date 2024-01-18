class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int cnt=0;
            for(auto it:nums)
            {
                if(1<<i & it)
                {
                    cnt++;
                }
            }
            if(cnt%3)
            {
                ans+=(1<<i);
            }
            
        }
        return ans;
    }
};
