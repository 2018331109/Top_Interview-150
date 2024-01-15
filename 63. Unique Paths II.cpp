/*
class Solution {
public:
    int dp[102][102];
    int cnt=0;
    int n, m;
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==1)
        {
            return 0;
        }
        if(row==n-1 && col==m-1)
        {
            return 1;
        }
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int a=dfs(grid, row+1, col);
        int b=dfs(grid, row, col+1);
        return dp[row][col]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0);
    }
};
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(grid[0][0])
        {
            return 0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //for the first row and first column
                if(i==0 || j==0)
                {
                    if(grid[i][j] == 1 || (i-1>=0 && grid[i-1][j]==0) || (j-1>=0 && grid[i][j-1]==0))
                    {
                        grid[i][j]=0;
                    }
                    else
                    {
                        grid[i][j]=1;
                    }
                }

                // for internal cells
                else if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                }
                else
                {
                    grid[i][j]+=grid[i-1][j]+ grid[i][j-1];
                }


            }
        }

        return grid[n-1][m-1];
    }
};
