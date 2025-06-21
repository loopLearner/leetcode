class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = -1;
        int sell = -1;
        int n = prices.size();
        if(n==1) return 0;
        if(prices[0]<prices[1]) {
            buy = 0;
            ans-=prices[buy];
        }
        for(int i=0;i<n-1;i++){
            if(buy>sell){
                if(prices[i]>prices[i+1]){
                    sell = i;
                    ans+=prices[sell];
                }
            }
            else{
                if(prices[i]<prices[i+1]){
                    buy = i;
                    ans-=prices[buy];
                }
            }
        }
        if(buy>sell){
            sell = n-1;
            ans+=prices[n-1];
        }
        // cout << buy << " " << sell;
        return ans;
    }
};