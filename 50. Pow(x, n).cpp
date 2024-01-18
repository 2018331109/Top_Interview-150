class Solution {
public:
    double bxp(double base, int pow)
    {
        double p=pow;
        double res=1.0;
        while(pow)
        {
            if(pow%2)
            {
                res*=base;
            }
            pow/=2;
            base*=base;
        }
        return res=p<0?1.0/res:res;
    }
    double myPow(double x, int n) {
        return bxp(x, n);
        
    }
};
