class Solution
{
public:
    int i=0, j=0, k=0;
    
    bool call(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& memo)
    {
        if(i==s1.length() and j==s2.length() and k==s3.length())
        {
            return true;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        
        bool x=false, y=false;
        
        if(i!=s1.length())
        {
            if(s1[i]==s3[k])
            {
                x=call(s1, s2, s3, i+1, j, k+1, memo);
            }
        }
        if(j!=s2.length())
        {
            if(s2[j]==s3[k])
            {
                y=call(s1, s2, s3, i, j+1, k+1, memo);
            }
        }
        
        return memo[i][j]=x||y;
    }
    
    bool isInterleave(string s1, string s2, string s3)
    {
        int a=s1.length(), b=s2.length();
        
        vector<vector<int>>memo(a+1, vector<int>(b+1, -1));
        
        return call(s1, s2, s3, 0, 0, 0, memo);
    }
};
