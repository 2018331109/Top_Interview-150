class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        int oc=5;
        while(n/oc)
        {
            cnt+=(n/oc);
            oc*=5;
        }
        return cnt;
        
    }
};
