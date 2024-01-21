// O(n^2) SUBMISSION
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n=s.length();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        int ans=1;
        int start=0;
        for(int i=0;i<n;i++)
        {
            // every single character is a palindrome;
            dp[i][i]=1;

            // checking for length 2;
            if(i+1<n)
            {
                if(s[i]==s[i+1])
                {
                    dp[i][i+1]=1;
                    ans=2;
                    start=i;

                }
            }

        }

        // filling  up the dp table;
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j=i+len-1;
                dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);

                if(dp[i][j] and len>ans)
                {
                    ans=len;
                    start=i;
                }
            }
        }

        return s.substr(start, ans);
    }
};

