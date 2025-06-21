class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxv = prices[n-1];
        // vector<int> maxis(n);
        // for(int i=n-1;i>=0;i--){
        //     maxv=max(prices[i], maxv);
        //     maxis[i] = maxv;
        // }
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     ans = max(ans,maxis[i]-prices[i]);
        int ans=0;
        for(int i=n-1;i>=0;i--){
            maxv = max(maxv, prices[i]);
            ans = max(ans, maxv - prices[i]);
        }
        return ans;
    }
};